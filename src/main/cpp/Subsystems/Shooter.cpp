// RobotBuilder Version: 2.0
//

#define DELTA_TIME 0.02
#include "Subsystems/Shooter.h"
#include "frc/smartdashboard/SmartDashboard.h"

Shooter::Shooter() :
    kP(frc::Preferences::GetInstance()->GetDouble("Shoot kP", 0.0)),
    kFF(frc::Preferences::GetInstance()->GetDouble("Shoot kFF", 180.0e-6)),
    maxRPM(frc::Preferences::GetInstance()->GetDouble("Shoot RPM Max", 3000.0)),
    maxAccel(frc::Preferences::GetInstance()->GetDouble("Shoot Accel Max", 500.0)),
    initialHoodPosition(frc::Preferences::GetInstance()->GetDouble("Shooter Hood Initial Position", 0)),
    actuatorMillimetersPerSecond(frc::Preferences::GetInstance()->GetDouble("Actuator mm Per Second", 8)) {
    m_shooterEncoderLead.SetPositionConversionFactor(kGearRatio);
    m_shooterEncoderLead.SetVelocityConversionFactor(kGearRatio);
    m_shooterLead.SetInverted(true);
    m_shooterFollow.Follow(m_shooterLead, true);

    hoodPosition = initialHoodPosition;


    // Set min/max power
    m_pidShooterMotorLead.SetOutputRange(kMinOutput, kMaxOutput);
    m_pidShooterMotorLead.SetSmartMotionMaxVelocity(maxRPM);
    m_pidShooterMotorLead.SetSmartMotionMaxAccel(maxAccel);
    m_shooterLead.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_shooterFollow.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    
    // Set kFF and kP ( after tuning, since gains have been already been determined )
    m_pidShooterMotorLead.SetP(kP);
    m_pidShooterMotorLead.SetFF(kFF);

   // Set up data logging file
   shooterLogger.ShooterLogger("/home/lvuser/ShooterLogs/ShooterLog_" + DataLogger::GetTimestamp() + ".csv");
}

void Shooter::Periodic() {
    if (ShooterEnabled == true) {
        m_pidShooterMotorLead.SetReference(CommandedVelocity, rev::ControlType::kVelocity);
    }
    else {
        m_pidShooterMotorLead.SetReference(0.0, rev::ControlType::kVelocity);
    }

    if (HoodAtPosition()) {
        m_shooterActuator.StopMotor();
    }
    else if (hoodPosition < hoodPositionSetpoint) {
            m_shooterActuator.Set(-1);
            hoodPosition += DELTA_TIME * actuatorMillimetersPerSecond;
    }
    else {
            m_shooterActuator.Set(1);
            hoodPosition += DELTA_TIME * -actuatorMillimetersPerSecond;
    }

    // Get and write subsystem data to datalog file
    double leadRPM = GetMotorVelocity();
    double leadAppliedOutput = m_shooterLead.GetAppliedOutput();
    double leadVoltage = m_shooterLead.GetBusVoltage();
    double leadCurrent = m_shooterLead.GetOutputCurrent();
    shooterLogger.WriteShooterData(leadRPM, leadAppliedOutput, leadVoltage, leadCurrent);
    frc::SmartDashboard::PutNumber("Shooter RPM", GetMotorVelocity());
    frc::SmartDashboard::PutNumber("Shooter Error", GetMotorVelocity() - CommandedVelocity);
    frc::SmartDashboard::PutBoolean("Shooter at speed", ShooterAtSpeed());
    frc::SmartDashboard::PutNumber("Shooter Hood Current Position", GetHoodPosition());
    frc::SmartDashboard::PutNumber("Shooter Hood Target Position", GetHoodPositionSetpoint());
    frc::SmartDashboard::PutBoolean("Shooter Hood At Position", HoodAtPosition());
    frc::SmartDashboard::PutNumber("Actuator Voltage", m_shooterActuator.GetBusVoltage());

}

void Shooter::ShooterOff() {
    ShooterEnabled = false;
}

void Shooter::ShooterOn(double velocity) {
    ShooterEnabled = true;
    CommandedVelocity = velocity;
}

void Shooter::SetShooterSpeed(double velocity) {
    if (velocity == 0) {
        ShooterOff();
    } 
    else {
        ShooterOn(velocity);
    }
}

bool Shooter::ShooterAtSpeed()
{
    bool atSpeed = false;

    if (CommandedVelocity != 0)
    {
        double threshold = CommandedVelocity * 0.9;

        if (GetMotorVelocity() >= threshold)
        {
            atSpeed = true;
        }
    }
    return atSpeed;
}


double Shooter::GetHoodPositionSetpoint() {
    return hoodPositionSetpoint;
}

double Shooter::GetHoodPosition() {
    return hoodPosition;
}

bool Shooter::HoodAtPosition() {
    return fabs(GetHoodPosition() - GetHoodPositionSetpoint()) <= actuatorMillimetersPerSecond * DELTA_TIME;
}

void Shooter::StopHoodActuator() {
   m_shooterActuator.StopMotor();
}
 
void Shooter::ResetCurrentHoodPositionValue() {
    hoodPosition = 0;

}

void Shooter::SetShooterConfiguration(ShooterConfiguration config) {
    if (config != ShooterConfiguration::CustomConfiguration) {
            configuration = config;
            hoodPositionSetpoint = hoodPositions[config];
            SetShooterSpeed(flywheelSpeeds[config]);
    }
}

Shooter::ShooterConfiguration Shooter::GetShooterConfiguration() {
    return configuration;
}

void Shooter::SetCustomShooterConfiguration(double hood_position_mm, double flywheel_rpm) {
    configuration = ShooterConfiguration::CustomConfiguration;
    hoodPositionSetpoint = hood_position_mm;
    SetShooterSpeed(flywheel_rpm);
}

void Shooter::EnableLogging() {
    shooterLogger.StartSession();
}

void Shooter::DisableLogging() {
    shooterLogger.EndSession();
}


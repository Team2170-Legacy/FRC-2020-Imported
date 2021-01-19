// RobotBuilder Version: 2.0
//

#include "Subsystems/Shooter.h"
#include "frc/smartdashboard/SmartDashboard.h"

Shooter::Shooter() :
    kP(frc::Preferences::GetInstance()->GetDouble("Shoot kP", 0.0)),
    kFF(frc::Preferences::GetInstance()->GetDouble("Shoot kFF", 180.0e-6)),
    maxRPM(frc::Preferences::GetInstance()->GetDouble("Shoot RPM Max", 3000.0)),
    maxAccel(frc::Preferences::GetInstance()->GetDouble("Shoot Accel Max", 500.0)) {
    m_shooterEncoderLead.SetPositionConversionFactor(kGearRatio);
    m_shooterEncoderLead.SetVelocityConversionFactor(kGearRatio);
    m_shooterLead.SetInverted(true);
    m_shooterFollow.Follow(m_shooterLead, true);


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

    // Get and write subsystem data to datalog file
    double leadRPM = GetMotorVelocity();
    double leadAppliedOutput = m_shooterLead.GetAppliedOutput();
    double leadVoltage = m_shooterLead.GetBusVoltage();
    double leadCurrent = m_shooterLead.GetOutputCurrent();
    shooterLogger.WriteShooterData(leadRPM, leadAppliedOutput, leadVoltage, leadCurrent);
    frc::SmartDashboard::PutNumber("Shooter RPM", GetMotorVelocity());
    frc::SmartDashboard::PutNumber("Shooter Error", GetMotorVelocity() - CommandedVelocity);
    frc::SmartDashboard::PutBoolean("Shooter at speed", ShooterAtSpeed());
}

void Shooter::ShooterOff() {
    ShooterEnabled = false;
}

void Shooter::ShooterOn(double velocity) {
    ShooterEnabled = true;
    CommandedVelocity = velocity;
}

void Shooter::SetHoodHigh() {
    m_solHood.Set(frc::DoubleSolenoid::kForward);
}

void Shooter::SetHoodLow() {
    m_solHood.Set(frc::DoubleSolenoid::kReverse);
}

bool Shooter::IsHoodHigh() {
    bool retVal = false;
    
    if (m_solHood.Get() == frc::DoubleSolenoid::kForward) {
        retVal = true;
    }

    return retVal;
}

bool Shooter::IsHoodLow() {
    bool retVal = false;
    
    if (m_solHood.Get() == frc::DoubleSolenoid::kReverse) {
        retVal = true;
    }

    return retVal;
}

void Shooter::EnableLogging() {
    shooterLogger.StartSession();
}

void Shooter::DisableLogging() {
    shooterLogger.EndSession();
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

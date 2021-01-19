/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/TeleopDrive.h"
#include "Robot.h"

TeleopDrive::TeleopDrive(DriveTrain* subsystem) : m_driveTrain{subsystem},
    kVoltageDrive{frc::Preferences::GetInstance()->GetBoolean("Voltage Driving", false)}, 
    m_xAxisFilter {frc::LinearFilter<double>::SinglePoleIIR(
      frc::Preferences::GetInstance()->GetDouble("Speed Time Constant", 0.01), 0.02_s)},
    m_turnFilter {frc::LinearFilter<double>::SinglePoleIIR(
      frc::Preferences::GetInstance()->GetDouble("Turn Time Constant", 0.01), 0.02_s)},
    kMaxXRate {frc::Preferences::GetInstance()->GetDouble("X Max Rate", 0.10)},
    kMaxTurnRate {frc::Preferences::GetInstance()->GetDouble("Turn Max Rate", 0.10)}
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
 // Requires(Robot::driveTrain.get());
 AddRequirements({subsystem});
}

// Called just before this Command runs the first time
void TeleopDrive::Initialize() 
{
	xAxis_prev 	    = 0.0;
  turn_Rate_prev   = 0.0;
}

// Called repeatedly when this Command is scheduled to run
void TeleopDrive::Execute()
{
  double xAxis = m_xAxisFilter.Calculate(Robot::oi->getDriverJoystick()->GetRawAxis(1));

  double speedPos = Robot::oi->getDriverJoystick()->GetRawAxis(3);
  double speedNeg = Robot::oi->getDriverJoystick()->GetRawAxis(2);

  double turn_Rate = m_turnFilter.Calculate(speedPos - speedNeg);

  double delta_xAxis = xAxis - xAxis_prev;

  if (delta_xAxis > kMaxXRate) {
	    xAxis_prev 	= xAxis_prev +  kMaxXRate;
  }
  else if (delta_xAxis < -kMaxXRate) {
 	    xAxis_prev 	= xAxis_prev - kMaxXRate;
  }
  else {
      xAxis_prev 	= xAxis;
  };

  double delta_turn_Rate = turn_Rate - turn_Rate_prev;

  if (delta_turn_Rate > kMaxTurnRate) {
    turn_Rate_prev = turn_Rate_prev + kMaxTurnRate;
  }
  else if (delta_turn_Rate < -kMaxTurnRate) {
    turn_Rate_prev = turn_Rate_prev - kMaxTurnRate;
  }   
  else {
    turn_Rate_prev = turn_Rate;
  };

//  m_driveTrain->VelocityArcadeDrive(-xAxis_prev, -turn_Rate, true);
  if (kVoltageDrive) {
    m_driveTrain->ArcadeDrive(-xAxis_prev, turn_Rate, true);
  }
  else {
    m_driveTrain->VelocityArcadeDrive(-xAxis_prev, turn_Rate, true);
  }
}

// Make this return true when this Command no longer needs to run execute()
bool TeleopDrive::IsFinished() { 
  return false; 
  }

// Called once after isFinished returns true
void TeleopDrive::End(bool interrupted) 
 {
      xAxis_prev      = 0.0;
      turn_Rate_prev  = 0.0;
 }
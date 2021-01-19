/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/IntakeOn.h"

IntakeOn::IntakeOn(Intake* subsystem) : m_intake{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void IntakeOn::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void IntakeOn::Execute() {
  frc::SmartDashboard::PutNumber("LED Code",LEDCodes::IntakeBalls);
  m_intake->IntakeOn();
}

// Called once the command ends or is interrupted.
void IntakeOn::End(bool interrupted) {
  m_intake->IntakeOff();
}

// Returns true when the command should end.
bool IntakeOn::IsFinished() { return false; }

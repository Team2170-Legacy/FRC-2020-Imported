/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/ShooterOff.h"

ShooterOff::ShooterOff(Shooter* subsystem): m_shooter{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void ShooterOff::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ShooterOff::Execute() {
  m_shooter->ShooterOff();
}

// Called once the command ends or is interrupted.
void ShooterOff::End(bool interrupted) {}

// Returns true when the command should end.
bool ShooterOff::IsFinished() { return true; }

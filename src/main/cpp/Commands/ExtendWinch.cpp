/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/ExtendWinch.h"
#include "Robot.h"

ExtendWinch::ExtendWinch(Climber* subsystem): m_climber{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void ExtendWinch::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ExtendWinch::Execute() {
  m_climber->WinchExtend();
}

// Called once the command ends or is interrupted.
void ExtendWinch::End(bool interrupted) {
  m_climber->WinchStop();
}

// Returns true when the command should end.
bool ExtendWinch::IsFinished() { return false; }

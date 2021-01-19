/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/RetractWinch.h"
#include "Robot.h"

RetractWinch::RetractWinch(Climber* subsystem): m_climber{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void RetractWinch::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void RetractWinch::Execute() {
  m_climber->WinchRetract();
}

// Called once the command ends or is interrupted.
void RetractWinch::End(bool interrupted) {
  m_climber->WinchStop();
}

// Returns true when the command should end.
bool RetractWinch::IsFinished() { return false; }

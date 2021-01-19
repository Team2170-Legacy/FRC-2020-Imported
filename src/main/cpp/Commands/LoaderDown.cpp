/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/LoaderDown.h"

LoaderDown::LoaderDown(Loader* subsystem) : m_loader{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void LoaderDown::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void LoaderDown::Execute() {
  m_loader->LoaderDown();
}

// Called once the command ends or is interrupted.
void LoaderDown::End(bool interrupted) {
  m_loader->LoaderStop();
}

// Returns true when the command should end.
bool LoaderDown::IsFinished() { return false; }

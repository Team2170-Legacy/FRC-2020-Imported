/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/LoaderUp.h"

LoaderUp::LoaderUp(Loader* subsystem) : m_loader{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void LoaderUp::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void LoaderUp::Execute() {
  m_loader->LoaderUp();
}

// Called once the command ends or is interrupted.
void LoaderUp::End(bool interrupted) {
  }

// Returns true when the command should end.
bool LoaderUp::IsFinished() { return true; }

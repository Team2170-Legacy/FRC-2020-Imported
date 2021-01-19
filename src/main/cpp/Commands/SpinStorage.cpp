/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/SpinStorage.h"
#include "Robot.h"

SpinStorage::SpinStorage(Feeder* subsystem): m_feeder{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void SpinStorage::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SpinStorage::Execute() {
  m_feeder->RotateCW();
}

// Called once the command ends or is interrupted.
void SpinStorage::End(bool interrupted) 
{
  m_feeder->FeedStop();
}

// Returns true when the command should end.
bool SpinStorage::IsFinished() { return false; }

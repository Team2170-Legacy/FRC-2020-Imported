/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/JostleStorage.h"

JostleStorage::JostleStorage(Feeder* subsystem): m_feeder{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void JostleStorage::Initialize() {
  m_ActivityCount = 0;
  m_CCW = false;
}

// Called repeatedly when this Command is scheduled to run
void JostleStorage::Execute() {
  if ((m_ActivityCount % 4) == 0)
  {
    if (m_CCW) {
      m_feeder->RotateCW();
      m_CCW = false;
    }
    else {
      m_feeder->RotateCCW();
      m_CCW = true;
    }
  }
  m_ActivityCount++;
}

// Called once the command ends or is interrupted.
void JostleStorage::End(bool interrupted) {
  m_feeder->FeedStop();
}

// Returns true when the command should end.
bool JostleStorage::IsFinished() { return false; }

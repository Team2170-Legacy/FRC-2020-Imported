/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/SpinStorageCCW.h"

SpinStorageCCW::SpinStorageCCW(Feeder* subsystem): m_feeder{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

SpinStorageCCW::SpinStorageCCW(Feeder* subsystem, double rpm) : m_feeder {subsystem}
{
  bExplicitRPM = true;
  m_rpm = rpm;
}
// Called when the command is initially scheduled.
void SpinStorageCCW::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SpinStorageCCW::Execute() {
  if (bExplicitRPM) {
    m_feeder->RotateCCW(m_rpm);
  }
  else {
    m_feeder->RotateCCW();
  }
}

// Called once the command ends or is interrupted.
void SpinStorageCCW::End(bool interrupted) {
  if (!bExplicitRPM) {
      m_feeder->FeedStop();
  }
}

// Returns true when the command should end.
bool SpinStorageCCW::IsFinished() { return false; }

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "SpinStorageCCWInst.h"
#include <frc/Preferences.h>

SpinStorageCCWInst::SpinStorageCCWInst(Feeder* subsystem) : feeder{subsystem},
  rpm{frc::Preferences::GetInstance()->GetDouble("Feeder RPM", 10.0)} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subsystem);
}

SpinStorageCCWInst::SpinStorageCCWInst(Feeder* subsystem, double speed) : feeder{subsystem},
      rpm{speed} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subsystem);
}

// Called when the command is initially scheduled.
void SpinStorageCCWInst::Initialize() {
  feeder->RotateCCW(rpm);
}

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "Subsystems/Shooter.h"
#include "Subsystems/Feeder.h"
#include "Commands/SetHoodLow.h"
#include "Commands/SetShooterSpeed.h"
#include "Commands/SpinStorageCCW.h"
#include "frc/Preferences.h"

class ConfigShooterLow
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 ConfigShooterLow> {
 public:
  ConfigShooterLow(Shooter* mrnoll, Feeder* mrfoss);
  double shooterSpeedLow;
};

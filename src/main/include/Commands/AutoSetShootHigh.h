/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/InstantCommand.h>
#include "Subsystems/Shooter.h"
#include "Subsystems/Loader.h"
#include "Subsystems/Vision.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Feeder.h"

class AutoSetShootHigh
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoSetShootHigh> {
 public:
  AutoSetShootHigh(Shooter* shooter, Feeder* feeder);

private:
  const double kHighShooterSpeed;
  const double kFeederSpeed;
};

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
#include "Subsystems/Vision.h"
#include "Subsystems/Loader.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Feeder.h"

#include <units/time.h>

class AimFireShooter
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AimFireShooter> {
 public:
  AimFireShooter(Shooter* shooter, Vision* vision, Loader* loader, DriveTrain* drivetrain, Feeder* feeder);

private:
  const units::second_t kAutoShootTime;
};

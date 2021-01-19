/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/WaitCommand.h>
#include <frc2/command/InstantCommand.h>
#include "Commands/AimFireShooter.h"
#include "Commands/VisionAlign.h"
#include "Commands/WaitForShooterSpeed.h"
#include "Commands/LoaderUp.h"
#include "Commands/LoaderOff.h"
#include "Commands/ShooterOff.h"

AimFireShooter::AimFireShooter(Shooter* shooter, Vision* vision, Loader* loader, DriveTrain* drivetrain, Feeder* feeder) :
  kAutoShootTime {(units::second_t)frc::Preferences::GetInstance()->GetDouble("Auto Shoot Time", 2.0)}
{
  AddCommands(
    VisionAlign(vision, drivetrain, true).WithTimeout(3.0_s),
    WaitForShooterSpeed(shooter).WithTimeout(kAutoShootTime),
    LoaderUp(loader),
    frc2::WaitCommand(kAutoShootTime),
    frc2::InstantCommand([feeder]{feeder->FeedStop();}, {feeder}),
    LoaderOff(loader),
    ShooterOff(shooter)
  );
}

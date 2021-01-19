/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/FireShooter.h"

#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/WaitCommand.h>
#include <frc2/command/InstantCommand.h>
#include "Commands/WaitForShooterSpeed.h"
#include "Commands/LoaderUp.h"
#include "Commands/LoaderOff.h"
#include "Commands/ShooterOff.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
FireShooter::FireShooter(Shooter* shooter, Loader* loader, Feeder* feeder) :
  kAutoShootTime {(units::second_t)frc::Preferences::GetInstance()->GetDouble("Auto Shoot Time", 2.0)}
{
  AddCommands(
    WaitForShooterSpeed(shooter).WithTimeout(kAutoShootTime),
    LoaderUp(loader),
    frc2::WaitCommand(kAutoShootTime),
    frc2::InstantCommand([feeder]{feeder->FeedStop();}, {feeder}),
    LoaderOff(loader),
    ShooterOff(shooter)
  );
}

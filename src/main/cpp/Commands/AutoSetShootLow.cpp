/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/AutoSetShootLow.h"

#include "Commands/ConfigShooter.h"
#include <frc/smartdashboard/SmartDashboard.h>

AutoSetShootLow::AutoSetShootLow(Shooter* shooter, Feeder* feeder)
 {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(
    ConfigShooter(shooter, Shooter::ShooterConfiguration::LowShooter_2020),
    frc2::InstantCommand([feeder] {feeder->RotateCCW();})
  );
 }
/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/AutoSetShootLow.h"

#include "Commands/SetHoodLow.h"
#include "Commands/SetShooterSpeed.h"
#include <frc/smartdashboard/SmartDashboard.h>

AutoSetShootLow::AutoSetShootLow(Shooter* shooter, Feeder* feeder) :
  kLowShooterSpeed {frc::Preferences::GetInstance()->GetDouble("Low Shooter Speed", 20.0)}
 {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(
    SetHoodLow(shooter),
    SetShooterSpeed(shooter, kLowShooterSpeed),
    frc2::InstantCommand([feeder] {feeder->RotateCCW();})
  );
 }
/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/ConfigShooterHigh.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
ConfigShooterHigh::ConfigShooterHigh(Shooter* mrnoll, Feeder* mrfoss):
  shooterSpeedHigh(frc::Preferences::GetInstance()->GetDouble("High Shooter Speed", 20.0)) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(SetHoodHigh(mrnoll), SetShooterSpeed(mrnoll, shooterSpeedHigh), SpinStorageCCW(mrfoss));
}

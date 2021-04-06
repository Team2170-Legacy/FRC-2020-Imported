/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/AutoSetShootHigh.h"
#include "Commands/ConfigShooter.h"
#include <frc2/command/ParallelRaceGroup.h>
#include "Commands/SpinStorageCCW.h"
#include <frc/smartdashboard/SmartDashboard.h>

AutoSetShootHigh::AutoSetShootHigh(Shooter* shooter, Feeder* feeder) :
  kFeederSpeed {frc::Preferences::GetInstance()->GetDouble("Auto High Feeder Speed", 8.0)}
 {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(
    ConfigShooter(shooter, Shooter::ShooterConfiguration::HighShooter_2020),
    SpinStorageCCW(feeder, kFeederSpeed).WithInterrupt([feeder]{return true;})
  );
}

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "Subsystems/Feeder.h"

class SpinStorageCCWInst
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 SpinStorageCCWInst> {
 public:
  SpinStorageCCWInst(Feeder* subsystem);
  SpinStorageCCWInst(Feeder* subsystem, double speed);

  void Initialize() override;
private:
  Feeder* feeder;
  const double rpm;
};

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/LinearFilter.h>
#include "Subsystems/DriveTrain.h"

class TeleopDrive :  public frc2::CommandHelper<frc2::CommandBase, TeleopDrive> {
 public:
  TeleopDrive(DriveTrain* subsystem);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;

private:
  DriveTrain* m_driveTrain;
  bool kVoltageDrive;
  frc::LinearFilter<double> m_xAxisFilter;
  frc::LinearFilter<double> m_turnFilter;
  const double kMaxXRate;
  const double kMaxTurnRate;
  double xAxis_prev;
  double turn_Rate_prev;
};
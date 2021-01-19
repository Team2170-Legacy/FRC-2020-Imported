/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "Subsystems/Vision.h"
#include "Subsystems/DriveTrain.h"

/**
 * Aligns the robot, if autonomousPhase is true it ends automatically once an acceptable error is achieved
 */
class VisionAlign
    : public frc2::CommandHelper<frc2::CommandBase, VisionAlign> {
 public:
  VisionAlign(Vision* vision, DriveTrain* drive, bool inAutonomousPhase = false);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
	Vision* m_vision;
	DriveTrain* m_drive;
  bool inAutonomous;
};

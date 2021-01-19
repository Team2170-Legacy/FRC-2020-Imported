/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <units/length.h>
#include <units/acceleration.h>
#include <units/velocity.h>

namespace DriveConstants {
  constexpr auto kTrackWidth = 0.6731_m;
	extern const frc::DifferentialDriveKinematics kDriveKinematics;
}

namespace ShooterContants {
  constexpr double kGearRatio (9.0);
  constexpr double kChainReduction = (18.0 / 273.0);
}

namespace AutoConstants {
  constexpr auto kMaxSpeed = 3_mps;
  constexpr auto kMaxAcceleration = 3_mps_sq;
  constexpr double kRamseteB = 2.0;
  constexpr double kRamseteZeta = 0.7;
}

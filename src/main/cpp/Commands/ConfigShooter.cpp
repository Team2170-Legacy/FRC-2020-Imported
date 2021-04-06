// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/ConfigShooter.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
ConfigShooter::ConfigShooter(Shooter* subsystem, Shooter::ShooterConfiguration config): m_shooter{subsystem}, m_config{config} {
  // Use addRequirements() here to declare subsystem dependencies.
   AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void ConfigShooter::Initialize() {
  m_shooter->SetShooterConfiguration(m_config);
}

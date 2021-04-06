// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/ToggleShooterZoneConfig.h"
#include <iostream>

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
ToggleShooterZoneConfig::ToggleShooterZoneConfig(Shooter* subsystem): m_shooter{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
   AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void ToggleShooterZoneConfig::Initialize() {
  Shooter::ShooterConfiguration nextConfiguration;
  switch(m_shooter->GetShooterConfiguration()) {
    case Shooter::ShooterConfiguration::Zone1: {
      nextConfiguration = Shooter::ShooterConfiguration::Zone2;
      break;
    }
    case Shooter::ShooterConfiguration::Zone2: {
      nextConfiguration = Shooter::ShooterConfiguration::Zone3;
      break;
    }
    case Shooter::ShooterConfiguration::Zone3: {
      nextConfiguration = Shooter::ShooterConfiguration::Zone1;
      break;
    }
    default: {
      nextConfiguration = Shooter::ShooterConfiguration::Zone1;
      break;
    }

  }
  m_shooter->SetShooterConfiguration(nextConfiguration);
}

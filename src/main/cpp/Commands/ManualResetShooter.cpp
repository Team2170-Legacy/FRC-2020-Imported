// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/ManualResetShooter.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
ManualResetShooter::ManualResetShooter(Shooter* subsystem) : m_shooter{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ManualResetShooter::Initialize() {
    m_shooter->SetCustomShooterConfiguration(-500, 0);
}

void ManualResetShooter::Execute() {
}

bool ManualResetShooter::IsFinished() {
  return m_shooter->HoodAtPosition();
}

void ManualResetShooter::End(bool interrupted) {
  m_shooter->StopHoodActuator();
  m_shooter->SetCustomShooterConfiguration(0, 0);
  m_shooter->ResetCurrentHoodPositionValue();
}


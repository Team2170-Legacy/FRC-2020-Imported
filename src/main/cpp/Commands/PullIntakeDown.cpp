/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/PullIntakeDown.h"

PullIntakeDown::PullIntakeDown(Intake* subsystem): m_intake{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void PullIntakeDown::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void PullIntakeDown::Execute() {
  m_intake->IntakeDown();
}

// Called once the command ends or is interrupted.
void PullIntakeDown::End(bool interrupted) {}

// Returns true when the command should end.
bool PullIntakeDown::IsFinished() { return true; }

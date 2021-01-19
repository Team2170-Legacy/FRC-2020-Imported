/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/PullIntakeUp.h"

PullIntakeUp::PullIntakeUp(Intake* subsystem): m_intake{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void PullIntakeUp::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void PullIntakeUp::Execute() {
  m_intake->IntakeUp();
}

// Called once the command ends or is interrupted.
void PullIntakeUp::End(bool interrupted) {}

// Returns true when the command should end.
bool PullIntakeUp::IsFinished() { return true; }

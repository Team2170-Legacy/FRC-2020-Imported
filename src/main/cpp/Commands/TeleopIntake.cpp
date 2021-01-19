/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/TeleopIntake.h"
#include "Robot.h"

TeleopIntake::TeleopIntake(Intake* subsystem): m_intake{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void TeleopIntake::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TeleopIntake::Execute() {
  if(Robot::oi->getOperatorJoystick()->GetRawAxis(2) > 0.5){
    m_intake->IntakeOn();
  } else if(Robot::oi->getOperatorJoystick()->GetRawAxis(3) > 0.5){
    m_intake->IntakeReverse();
  } else {
    m_intake->IntakeOff();
  }
}

// Called once the command ends or is interrupted.
void TeleopIntake::End(bool interrupted) {
  m_intake->IntakeOff();
}

// Returns true when the command should end.
bool TeleopIntake::IsFinished() { return false; }

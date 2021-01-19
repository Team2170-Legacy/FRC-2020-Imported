/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/VisionAlign.h"

VisionAlign::VisionAlign(Vision* vision, DriveTrain* drive, bool inAutonomousPhase) : m_vision{vision}, m_drive{drive} {
  	AddRequirements(vision);
   AddRequirements(drive);
   inAutonomous = inAutonomousPhase;
}

// Called when the command is initially scheduled.
void VisionAlign::Initialize() {
   m_vision->VisionDriveInit();
}

// Called repeatedly when this Command is scheduled to run
void VisionAlign::Execute() {
    std::pair<double, double> result = m_vision->AlignWithLockedTarget();
    m_drive->AutoVelocityArcadeDrive(result.first, result.second);
}

// Called once the command ends or is interrupted.
void VisionAlign::End(bool interrupted) {
   m_vision->VisionDriveEnd();
}

// Returns true when the command should end.
bool VisionAlign::IsFinished() { 
   return inAutonomous && m_vision->IsAlignedWithTarget();
 }

// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Commands/VisionDrive.h"
#include <iostream>

VisionDrive::VisionDrive(Vision* vision, DriveTrain* drive) : m_vision{vision},
m_drive{drive} {
	AddRequirements(vision);
    AddRequirements(drive);
}

/**
 * @brief Called just before this Command runs the first time
 */
void VisionDrive::Initialize() {
    m_vision->VisionDriveInit();
}

/**
 * @brief Called repeatedly when this Command is scheduled to run
 * 
 */
void VisionDrive::Execute() {
        std::pair<double, double> result = m_vision->DriveToLockedTarget();
        m_drive->AutoVelocityArcadeDrive(result.first, result.second);
}

/**
 * @brief Make this return true when this Command no longer needs to run execute()

 */
bool VisionDrive::IsFinished() {
    return false;
}

/**
 * @brief Called once after isFinished returns true
 */
void VisionDrive::End(bool interrupted) {
    m_vision->VisionDriveEnd();
}
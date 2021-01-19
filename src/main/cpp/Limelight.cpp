/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Limelight.h"

Limelight::Limelight(std::string networkTable) {
    auto table = nt::NetworkTableInstance::GetDefault().GetTable(networkTable);
    tv = table->GetEntry("tv");
    tx = table->GetEntry("tx");
	ty = table->GetEntry("ty");
    ta = table->GetEntry("ta");
    ts = table->GetEntry("ts");
    tl = table->GetEntry("tl");
    tshort = table->GetEntry("tshort");
    tlong = table->GetEntry("tlong");
    thor = table->GetEntry("thor");
    tvert = table->GetEntry("tvert");
    getpipe = table->GetEntry("getpipe");
	ledMode = table->GetEntry("ledMode");
	camMode = table->GetEntry("camMode");
	pipeline = table->GetEntry("pipeline");
    stream = table->GetEntry("stream");
	snapshot = table->GetEntry("snapshot");
    camtran = table->GetEntry("camtran");
}

/**
 * @brief Uses trig to calculate the distance from the camera to the target
 * If the robot is aligned with target, this distance is the distance required to reach the target
 * Units are in terms of the units used for the cameraHeight and visionTargetHeight parameters
 * This does not work if the camera is mounted at the same height as the target!!!
 * @param cameraMountAngle angle camera is mounted at in degrees
 * @param cameraHeight how high the camera is off the ground
 * @param visionTargetHeight how high the center of the vision target is off the ground
 * @return distance to the target
 */
double Limelight::GetDistanceToTarget(double cameraMountAngle, double cameraHeight, double visionTargetHeight) {
    double angleToTarget = (cameraMountAngle + GetVerticalAngleToTarget()) * Deg2Rad;
    return (visionTargetHeight - cameraHeight) / tan(angleToTarget);
}
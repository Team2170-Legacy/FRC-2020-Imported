#ifndef SRC_DATALOGGER_H_
#define SRC_DATALOGGER_H_
#include "frc/Timer.h"
#include <iostream>
#include <fstream>
#include <ctime>

class DataLogger {
public:
	DataLogger();
	DataLogger(std::string name, std::string header);
	static std::string GetTimestamp();
	void Flush();
	void Update();
	void StartSession();
	void EndSession();
	void LogData(std::string data);
    void VisionLogger(std::string name);
    void WriteVisionData(bool targetLocked, bool visionDriveActive, double distance, double distanceError, double distanceError_DB, double angleError, double angleError_DB, double speed, double omega);
	void DriveTrainLogger(std::string name);
	void WriteDriveTrainData(double leftEncoderPosition, double rightEncoderPosition, double leftVelocityCommand, double rightVelocityCommand, double leftActualVelocity, double rightActualVelocity, double leftLeadAppliedOutput, double leftFollowAppliedOutput, double rightLeadAppliedOutput, double rightFollowAppliedOutput, double leftLeadVoltage, double leftFollowVoltage, double rightLeadVoltage, double rightFollowVoltage, double leftLeadCurrent, double leftFollowCurrent, double rightLeadCurrent, double rightFollowCurrent);
	void ShooterLogger(std::string name);
	void WriteShooterData(double leadRPM, double leadAppliedOutput,  double leadBusVoltage, double leadCurrent);
	virtual ~DataLogger();
private:
	std::ofstream tLog;
	std::string mFilename;
	frc::Timer LogTimer;
};

#endif /* SRC_DATALOGGER_H_ */
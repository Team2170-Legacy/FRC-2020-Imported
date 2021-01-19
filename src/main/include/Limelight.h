/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <math.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"

#define imageCaptureLatency 11
#define Deg2Rad 3.14159/180

class Limelight {
 private:
  nt::NetworkTableEntry tv;
  nt::NetworkTableEntry tx;
	nt::NetworkTableEntry ty;
  nt::NetworkTableEntry ta;
  nt::NetworkTableEntry ts;
	nt::NetworkTableEntry tl;
  nt::NetworkTableEntry tshort;
  nt::NetworkTableEntry tlong;
  nt::NetworkTableEntry thor;
  nt::NetworkTableEntry tvert;
	nt::NetworkTableEntry getpipe;
	nt::NetworkTableEntry ledMode;
	nt::NetworkTableEntry camMode;
	nt::NetworkTableEntry pipeline;
  nt::NetworkTableEntry stream;
	nt::NetworkTableEntry snapshot;
  nt::NetworkTableEntry camtran; 

 public:
  Limelight(std::string networkTable);
  enum LEDMode {currentPipelineMode = 0, forceOff = 1, forceBlink = 2, forceOn = 3};
  enum CamMode {VisionProcessor = 0, DriverCamera = 1};
  enum StreamMode {Standard = 0, Main = 1, Secondary = 2};

  // methods for reading or setting network table values
  bool TargetIsLocked() {return (tv.GetDouble(0) == 1);};
  double GetHorizontalAngleToTarget() {return tx.GetDouble(0);};
  double GetVerticalAngleToTarget() {return ty.GetDouble(0);};
  /** @return Target Area (0% of image to 100% of image) */
  double GetTargetArea() {return ta.GetDouble(0);}; 
  /** @return Skew or rotation (-90 degrees to 0 degrees) */
  double GetTargetSkew() {return ts.GetDouble(0);};
  double GetPipelineLatency() {return tl.GetDouble(0);};
  double GetTotalLatency() {return GetPipelineLatency() + imageCaptureLatency;};
  /** @return Sidelength of shortest side of the fitted bounding box (pixels) */
  double GetTargetShortSideLength() {return tshort.GetDouble(0);};
  /** @return Sidelength of longest side of the fitted bounding box (pixels) */
  double GetTargetLongSideLength() {return tlong.GetDouble(0);};
  /** @return Horizontal sidelength of the rough bounding box (pixels) */
  double GetTargetHorizontalLength() {return thor.GetDouble(0);};
  /** @return Vertical sidelength of the rough bounding box (pixels) */
  double GetTargetVerticalLength() {return tvert.GetDouble(0);};
  int GetPipelineIndex() {return (int) getpipe.GetDouble(0);};
  void SetPipelineIndex(int pipelineIndex) {pipeline.SetDouble((double)pipelineIndex);};
  LEDMode GetLEDMode() {return LEDMode ((int) ledMode.GetDouble(0));};
  void SetLEDMode(LEDMode ledModeToSet) {ledMode.SetDouble((double)((int)ledModeToSet));}
  CamMode GetCamMode() {return CamMode ((int) camMode.GetDouble(0));};
  void SetCamMode(CamMode camModeToSet) {camMode.SetDouble((double)((int)camModeToSet));}
  StreamMode GetStreamMode() {return StreamMode ((int) stream.GetDouble(0));};
  void SetStreamMode(StreamMode streamModeToSet) {stream.SetDouble((double)((int)streamModeToSet));}
  void TakeSnapshot() {snapshot.SetDouble(1);};

  // for 3D targeting only
  double GetXTranslation() {return camtran.GetDoubleArray(std::vector<double>(6)).at(0);}
  double GetYTranslation() {return camtran.GetDoubleArray(std::vector<double>(6)).at(1);}
  double GetZTranslation() {return camtran.GetDoubleArray(std::vector<double>(6)).at(2);}
  double GetPitch() {return camtran.GetDoubleArray(std::vector<double>(6)).at(3);}
  double GetYaw() {return camtran.GetDoubleArray(std::vector<double>(6)).at(4);}
  double GetRoll() {return camtran.GetDoubleArray(std::vector<double>(6)).at(5);}

  // other methods that do things other than just read network table values
  
  double GetDistanceToTarget(double cameraMountAngle, double cameraHeight, double targetHeight);
};

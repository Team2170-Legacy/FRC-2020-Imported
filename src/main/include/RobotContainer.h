/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/RamseteCommand.h>
#include <frc2/command/StartEndCommand.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/WaitCommand.h>
#include "frc2/command/SequentialCommandGroup.h"
#include <frc2/command/PrintCommand.h>

#include "frc/trajectory/Trajectory.h"
#include "frc/trajectory/TrajectoryGenerator.h"

#include <frc/smartdashboard/SendableChooser.h>
#include <frc/XboxController.h>

#include <units/time.h>

#include "Subsystems/Climber.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Feeder.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Loader.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Vision.h"

#include "Commands/AutonomousCommand.h"
#include "Commands/TeleopDrive.h"
#include "Commands/IntakeOn.h"
#include "Commands/IntakeReverse.h"
#include "Commands/SpinStorage.h"
#include "Commands/SpinStorageCCW.h"
#include "Commands/ConfigShooterHigh.h"
#include "Commands/ConfigShooterLow.h"
#include "Commands/SetShooterSpeed.h"
#include "Commands/JostleStorage.h"
#include "Commands/FeederOff.h"
#include "Commands/LoaderDown.h"
#include "Commands/LoaderOff.h"
#include "Commands/LoaderUp.h"
#include "Commands/PullIntakeDown.h"
#include "Commands/PullIntakeUp.h"
#include "Commands/ShooterOff.h"
#include "Commands/TeleopIntake.h"
#include "Commands/WaitForShooterSpeed.h"
#include "Commands/AutonomousMotionProfile.h"
#include "Commands/VisionDrive.h"
#include "Commands/VisionAlign.h"
#include "Commands/ExtendWinch.h"
#include "Commands/RetractWinch.h"
#include "Commands/SpinStorage.h"
#include "Commands/SpinStorageCCW.h"

#include "hwcfg.h"
#include "Constants.h"

#include "Automoves/To_PwrPort_C.h"
#include "Automoves/To_PwrPort_L.h"
#include "Automoves/To_PwrPort_R.h"
#include "Automoves/To_Trench_C.h"
#include "Automoves/To_Trench_L.h"
#include "Automoves/To_Trench_R.h"
#include "Automoves/Backwards_Long.h"
#include "Automoves/Backwards_Short.h"
#include "Automoves/SBO_Part1.h"
#include "Automoves/SBO_Part2.h"
#include "Automoves/To_PwrPort_Trench.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();
  

  enum Profile 
  { NoTrajectory = 0, 
    ShootFromLine_L = 1,
    ShootFromLine_R = 2, 
    ShootFromLine_C = 3,  
    ShootFromPwrPrt_L = 4,
    ShootFromPwrPrt_R = 5,
    ShootFromPwrPrt_C = 6,
    GatherMoreBalls_L = 7,
    GatherMoreBalls_R = 8,
    GatherMoreBalls_C = 9,
    StealBalls = 10,

    Forward5mRamsete = 11,
    SlalomPath = 12
  };
  
  void StartDataLogging(void);
  void EndDataLogging(void);
  void ShutdownSubsystems();

 private:
  // The robot's subsystems and commands are defined here...
  DriveTrain m_driveTrain;
  Intake m_intake;
  Climber m_climber;
  Vision m_vision;
  Shooter m_shooter;
  Feeder m_feeder;
  Loader m_loader;

  frc::SendableChooser<frc2::Command*> m_chooser;
  frc::SendableChooser<Profile> m_trajectoryChooser;
  frc::SendableChooser<double> m_delayChooser;

  frc2::Command* GenerateRamseteCommand(std::string path);
  void ConfigureButtonBindings();

  AutonomousCommand m_autonomousCommand;

  frc::XboxController m_driver{HIDIDs::kDriver};
  frc::XboxController m_operator{HIDIDs::kOperator};

  //Vision config parameters
  const double kVisionDriveAcceptableError = 0.8; // VisionDrives during auto will terminate once they reach this error or less
  const double kMaxVisionDriveTime = 3.0; // VisionDrives during auto will terminate if they take longer than this time

  // Shooter control parameters
  const double kHighShooterSpeed;
  const double kLowShooterSpeed;
  const units::second_t kAutoShootTime;        // time to wait for balls to launch during an auto shoot sequence

  // Climber related commands
  frc2::InstantCommand m_RetractWinch{[this] {m_climber.WinchRetract();}, {&m_climber}};
  frc2::InstantCommand m_StopWinch{[this] {m_climber.WinchStop();}, {&m_climber}};
  frc2::InstantCommand m_ReleaseInterlock {[this] {m_climber.ReleaseInterlock();}, {&m_climber}};

  // Feeder commands
  frc2::SequentialCommandGroup m_Agitate = frc2::SequentialCommandGroup(
    SpinStorage(&m_feeder).WithTimeout(0.2_s),
    SpinStorageCCW(&m_feeder).WithTimeout(0.2_s),
    FeederOff(&m_feeder)
  );

};
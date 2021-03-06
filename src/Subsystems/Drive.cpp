// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "Drive.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/driveTog.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

Drive::Drive() : Subsystem("Drive") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	frontRightMotor = RobotMap::drivefrontRightMotor;
	frontLeftMotor = RobotMap::drivefrontLeftMotor;
	backRightMotor = RobotMap::drivebackRightMotor;
	backLeftMotor = RobotMap::drivebackLeftMotor;
	mecDrive = RobotMap::drivemecDrive;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new driveTog());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drive::startDriving()
{
	//m-d-r
	float joyX=Robot::oi->getleftAnalogStick()->GetRawAxis(0);
	float joyY=Robot::oi->getleftAnalogStick()->GetRawAxis(1)*1;
	float dir=asin(joyY/sqrt((joyX*joyX)+(joyY*joyY)));
	printf(dir+"\n");
	printf("Random Dance Party %d",rand()%100);
	Robot::drive->mecDrive->SetSafetyEnabled(false);
	Robot::drive->mecDrive->MecanumDrive_Polar(Robot::oi->getleftAnalogStick()->GetRawAxis(1), dir, Robot::oi->getrightAnalogStick()->GetRawAxis(1)*-1);

	Wait(.005);
}

void Drive::strafeRight(int sPower)
{
	//Create equations to control each individual motor
	Robot::drive->frontRightMotor->Set(sPower);
	//Robot::drive->frontLeftMotor->Set(sPower*-1);

	//Robot::drive->backLeftMotor->Set(sPower);
	Robot::drive->backRightMotor->Set(sPower*-1);

	printf("Strafing Right");
	/*Robot::drive->backLeftMotor->Set(sPower);
	Robot::drive->backRightMotor->Set(sPower*-1);
	printf("Strafing Right-----");*/
}

void Drive::strafeLeft(int sPower)
{
	Robot::drive->frontRightMotor->Set(sPower*-1);
	//Robot::drive->frontLeftMotor->Set(sPower);

	//Robot::drive->backLeftMotor->Set(sPower);
	Robot::drive->backRightMotor->Set(sPower*1);
}

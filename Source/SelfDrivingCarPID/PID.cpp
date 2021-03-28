// Fill out your copyright notice in the Description page of Project Settings.


#include "PID.h"

// Sets default values
APID::APID()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/***********PID GAIN VALUES***************/

	kp = 0.2f;
	ki = 0.01f;
	kd = 0.2f;

}

// Called when the game starts or when spawned
void APID::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APID::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APID::GetSpeedErorr(float AS, float TS){

	ActualSpeed = AS;
	ControllerTargetSpeed = TS;

	SpeedError = ControllerTargetSpeed - ActualSpeed;

}


void APID::GetFirstErorrDerv(float Delta){

	SpeedErrorDer = (SpeedError - PrevSpeedError) / Delta;

	PrevSpeedError = SpeedError;
}

void APID::GetIntegralOfErro(float Delta){
	
	AccuSpeedError += SpeedError * Delta;
}


float APID::GetControllerActions(float Delta, float TS, float AS){

	// Calculate
	GetSpeedErorr(AS, TS);

	GetFirstErorrDerv( Delta );

	GetIntegralOfErro( Delta );

	// Update
	float u_p = kp * SpeedError + kd * SpeedErrorDer + ki * AccuSpeedError;

	return u_p;
}



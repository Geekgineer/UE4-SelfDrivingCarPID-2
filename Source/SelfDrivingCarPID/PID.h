// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PID.generated.h"

UCLASS()
class SELFDRIVINGCARPID_API APID : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APID();


	//**************************************************************

	// /** The current speed ERROR as a string eg 10 km/h */
	// UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly)
	// FText SpeedErrorDisplayString;

	// /** The current Throttle as a string eg 10 km/h */
	// UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly)
	// FText ThrottleDisplayString;

	// /** The current Throttle as a string eg 10 km/h */
	// UPROPERTY(Category = Control, EditAnywhere, BlueprintReadWrite)
	// float ThrottleScale;

	/** The current Speed as a string eg 10 km/h */
	UPROPERTY(Category = Control, EditAnywhere, BlueprintReadWrite)
	float ActualSpeed;

	/** The current SpeedError speed repersent the integral (discrete sum) */
	UPROPERTY(Category = Control, EditAnywhere, BlueprintReadWrite)
	float SpeedError;

	//***************************PID Buffuers***********************

	/** The current PrevSpeedError (represent memory for the derivative)*/
	UPROPERTY(Category = Control, EditAnywhere, BlueprintReadWrite)
	float PrevSpeedError;

	/** The current SpeedErrorDer speed repersent the integral (discrete sum) */
	UPROPERTY(Category = Control, EditAnywhere, BlueprintReadWrite)
	float SpeedErrorDer;

	/** The current AccuSpeedError speed repersent the integral (discrete sum) */
	UPROPERTY(Category = Control, EditAnywhere, BlueprintReadWrite)
	float AccuSpeedError;

	// /** The current TimeSum speed repersent the integral (discrete sum) */
	// UPROPERTY(Category = Control, EditAnywhere, BlueprintReadWrite)
	// float TimeSum;


	//***************************PID GAINS***************************
	/** The current Kp speed as a string eg 10 km/h */
	UPROPERTY(Category = Control, EditAnywhere, BlueprintReadWrite)
	float kp;

	/** The current Ki speed as a string eg 10 km/h */
	UPROPERTY(Category = Control, EditAnywhere, BlueprintReadWrite)
	float ki;

	/** The current Kd speed as a string eg 10 km/h */
	UPROPERTY(Category = Control, EditAnywhere, BlueprintReadWrite)
	float kd;

	//**************************************************************

	/** The current Target speed as a string eg 10 km/h */
	UPROPERTY(Category = Control, EditAnywhere, BlueprintReadWrite)
	float ControllerTargetSpeed;

	// /** The current ThrottelForce speed as a string eg 10 km/h */
	// UPROPERTY(Category = Control, EditAnywhere, BlueprintReadWrite)
	// float ThrottelForce;

	UFUNCTION(BlueprintCallable, Category="Control")
	float GetControllerActions(float Delta, float TS, float AS);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	void GetFirstErorrDerv(float Delta);

	void GetIntegralOfErro(float Delta);

	void GetSpeedErorr(float AS, float TS);

};

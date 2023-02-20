// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "MyCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;

UCLASS()
class L20230220_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category="Components", BlueprintReadOnly)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly)
	UCameraComponent* FollowCamera;


	UPROPERTY(EditAnywhere, Category="Data", BlueprintReadWrite)
	class UInputMappingContext* InputContext;

	UPROPERTY(EditAnywhere, Category = "Data", BlueprintReadWrite)
	class UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = "Data", BlueprintReadWrite)
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = "Data", BlueprintReadWrite)
	class UInputAction* LookAction;


	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

};

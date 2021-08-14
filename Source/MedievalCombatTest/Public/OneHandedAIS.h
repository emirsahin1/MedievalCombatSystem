// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "OneHandedAIS.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALCOMBATTEST_API UOneHandedAIS : public UAnimInstance
{
	GENERATED_BODY()

public:
	UOneHandedAIS();
	void NativeUpdateAnimation(float DeltaSeconds) override;
	void NativeInitializeAnimation() override;
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool isAttacking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool isBlocking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool isRunning;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float aimPitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float newPitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float aimYaw;

private:
	APawn* pawnOwner;
};

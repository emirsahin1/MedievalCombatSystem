// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MedievalChar.generated.h"


UCLASS()
class MEDIEVALCOMBATTEST_API AMedievalChar : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* Mesh3P;

public:
	// Sets default values for this character's properties
	AMedievalChar();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool isFighting;
	UPROPERTY(Replicated,EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool isAttacking;
	UPROPERTY(Replicated,EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool isBlocking;
	UPROPERTY(Replicated,EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float pitch;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float val);
	void MoveRight(float val);
	void FightStance();
	void Attack();
	void Block();
	void Punch();
	void LookUp(float val);

	UFUNCTION(Server, Reliable)
	void ServerLookUp(float val);
	void ServerLookUp_Implementation(float val);
	UFUNCTION(Server, Reliable)
	void ServerAttack();
	void ServerAttack_Implementation();
	UFUNCTION(Server, Reliable)
	void ServerBlock();
	void ServerBlock_Implementation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimMontage* punchAnim; 

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;
};

// Code by Leonardo Paiva

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RewindTimeCharacter.h"
#include "RewindActors.generated.h"

UCLASS()
class REWINDTIME_API ARewindActors : public AActor
{
	GENERATED_BODY()

	private:
	UPROPERTY(VisibleAnywhere, meta = (AllowPrvateAcsses = "true"))	
	FVector InitialLocation;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrvateAcsses = "true"))	
	FVector ActualLocation;	
	
	UPROPERTY(VisibleAnywhere, meta = (AllowPrvateAcsses = "true"))
	TArray<FVector> FinalLocation;

	UPROPERTY(EditAnywhere, meta = (AllowPrvateAcsses = "true"))
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = "Character")
	ARewindTimeCharacter* Character;

	UFUNCTION()
    void Rewind();
	
	public:	
	// Sets default values for this actor's properties
	ARewindActors();

	protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

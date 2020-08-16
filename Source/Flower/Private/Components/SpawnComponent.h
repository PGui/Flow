#pragma once

#include "BehaviorTree/BehaviorTree.h"
#include "Components/ArrowComponent.h"
#include "Engine/StreamableManager.h"

#include "SpawnComponent.generated.h"

USTRUCT()
struct FFlowerSpawnParams
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	TSubclassOf<AActor> ActorClass;

	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	float ActorScale;

	UPROPERTY(EditDefaultsOnly, Category = "Spawn AI")
	TSoftObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY(EditDefaultsOnly, Category = "Spawn AI")
	TSubclassOf<UAnimInstance> AnimInstance;

	UPROPERTY(EditDefaultsOnly, Category = "Spawn AI")
	UAnimationAsset* AnimationAsset;

	UPROPERTY(EditDefaultsOnly, Category = "Spawn AI")
	bool bNoCollisionFail;

	FFlowerSpawnParams()
		: ActorScale(1.0f)
		, bNoCollisionFail(true)
	{
	}
};

/**
* Spawn Component
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class USpawnComponent final : public UArrowComponent
{
	GENERATED_UCLASS_BODY()

private:
	TWeakObjectPtr<AActor> SpawnedActor;
	FStreamableManager StreamableManager;
	
public:
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void Spawn(FFlowerSpawnParams& SpawnParams);
	void Despawn();

private:
	void SetAnimationOnSpawnedMesh(USkeletalMeshComponent* SkeletalMeshComponent, const FFlowerSpawnParams& SpawnParams) const;

	template<typename T>
	T* LoadAsset(TSoftObjectPtr<UObject> AssetPtr)
	{
		if (AssetPtr.IsNull())
		{
			return nullptr;
		}

		if (AssetPtr.IsPending())
		{
			const FSoftObjectPath& AssetRef = AssetPtr.ToSoftObjectPath();
			AssetPtr = Cast<T>(StreamableManager.LoadSynchronous(AssetRef, false));
		}

		return Cast<T>(AssetPtr.Get());
	}
};

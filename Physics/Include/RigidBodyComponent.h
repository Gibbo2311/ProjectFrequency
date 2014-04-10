#pragma once

#include <GameObjectComponent.h>

namespace Physics
{
	class RigidBodyComponent : public GameObjectComponent
	{
	public:
		~RigidBodyComponent(){};

		/**
		*Return the storage type of the game object component.
		* @return type info.
		*/
		const type_info* GetStorageType() final
		{
			return &typeid(RigidBodyComponent);
		};

	protected:
		RigidBodyComponent(GameObject* gameObject)
			: GameObjectComponent(gameObject){};
	};
}
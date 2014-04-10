#pragma once

#include <GameObjectComponent.h>

namespace Graphics
{
	/**
	*Abstract class for a mesh component.
	*/
	class MeshComponent : public GameObjectComponent
	{
	public:

		//Virtual desctructor.
		virtual ~MeshComponent(){};

		/**
		*@see GameObjectComponent::GetStorageType
		*TODO: Move to .cpp
		*/
		const type_info* GetStorageType() final
		{
			return &typeid(MeshComponent);
		};

	protected:

		/**
		* Protected constructor to prevent instantiation outside of derived classes.
		*/
		MeshComponent(GameObject* gameObject)
			:GameObjectComponent(gameObject){};

	};
}
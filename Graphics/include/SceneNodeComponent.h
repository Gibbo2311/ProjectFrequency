#pragma once

#include <GameObjectComponent.h>

namespace Graphics
{
	/**
	*Abstract class of a scene node.
	*Scene nodes are used for rendering a game object in the world.
	*/
	class SceneNodeComponent :public ::GameObjectComponent
	{

	public:

		/*
		*Virtual destructor.
		*/
		virtual ~SceneNodeComponent() {};

		/**
		*@see GameObjectComponent::GetStorageType
		*TODO: Move to .cpp
		*/
		const type_info* GetStorageType() final
		{
			return &typeid(SceneNodeComponent);
		};

	protected:

		/**
		* Protected constructor to prevent instantiation outside of derived classes.
		*/
		SceneNodeComponent(GameObject* gameObject)
			: GameObjectComponent(gameObject){};
	};

}
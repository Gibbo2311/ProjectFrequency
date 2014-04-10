#pragma once

#include <GameObjectComponent.h>


namespace Graphics
{
	/**
	* Abstract class for a camera.
	*/
	class CameraComponent : public ::GameObjectComponent
	{
	public:
		/**
		* Virtual destructor.
		*/
		virtual ~CameraComponent() {};

		/**
		*@see GameObjectComponent::GetStorageType
		*TODO: Move to .cpp
		*/
		const type_info* GetStorageType() final
		{
			return &typeid(CameraComponent);
		};

	protected:

		/**
		* Protected constructor to prevent instantiation outside of derived classes.
		*/
		CameraComponent(GameObject* gameObject)
			: GameObjectComponent(gameObject){}
	};
}
#pragma once

#include <memory>
#include <IGameObjectComponentFactory.h>

namespace Graphics{

	class SceneNodeComponent;
	class CameraComponent;
	class IViewport;

	/**
	*Interface for a graphics scene.
	*/
	class IScene : public IGameObjectComponentFactory
	{
	public:
		virtual ~IScene(){};

		/**
		* @see IGameObjectComponentFactory::CreateGameObjectComponent
		*/
		virtual std::shared_ptr<GameObjectComponent> CreateGameObjectComponent(GameObject& gameObject, const pugi::xml_node& config) = 0;

		/**
		*@see IGameObjectComponentFactory::RegisterGameObjectComponents
		*/
		virtual std::vector<std::string> RegisterGameObjectComponents() = 0;

		/**
		*Perform any actions that should take place in the pre tick.
		*/
		virtual void PreTick() = 0;

		/**
		*Perform any actions that should take place in a tick.
		*/
		virtual void Tick(const double& deltaTime) = 0;

		/**
		*Perform any actions that should take place post tick.
		*/
		virtual void PostTick() = 0;
	};

}

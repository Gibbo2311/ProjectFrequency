#pragma once

#include <IGameObjectComponentFactory.h>
#include <memory>
#include <string>

namespace Physics
{
	class IPhysicsSystem : public IGameObjectComponentFactory
	{
	public:
		/**
		* @see IGameObjectComponentFactory::CreateGameObjectComponent
		*/
		virtual std::shared_ptr<GameObjectComponent> CreateGameObjectComponent(GameObject& gameObject, const pugi::xml_node& config) = 0;

		/**
		*@see IGameObjectComponentFactory::RegisterGameObjectComponents
		*/
		virtual std::vector<std::string> RegisterGameObjectComponents() = 0;

		virtual void PreTick() = 0;
		virtual void Tick(const double& deltaTime) = 0;
		virtual void PostTick() = 0;
	};
}
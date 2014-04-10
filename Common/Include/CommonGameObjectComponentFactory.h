#pragma once

#include "IGameObjectComponentFactory.h"

/**
This class creates common game obejct components. Eg. TransformComponent.
*/
class CommonGameObjectComponentFactory : public IGameObjectComponentFactory
{
public:
	CommonGameObjectComponentFactory();
	~CommonGameObjectComponentFactory();

	/**
	* Creates a game component from the template;
	* @param Game Object
	* @param Component config.
	*/
	virtual std::shared_ptr<GameObjectComponent> CreateGameObjectComponent(GameObject& gameObject, const pugi::xml_node& config) override;

	/**
	* Registers all of the game object components that this factory can create.
	*/
	virtual std::vector<std::string> RegisterGameObjectComponents() override;

private:
};
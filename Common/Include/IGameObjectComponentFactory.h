#pragma once

#include <memory>
#include <vector>
#include <string>

namespace pugi
{
	class xml_node;
}

class GameObject;
class GameObjectComponent;

/**
* Interface for all game object factories across all dll's.
*/
class IGameObjectComponentFactory
{
public:

	virtual ~IGameObjectComponentFactory(){}

	/**
	* Creates a game component from the template;
	* @param Game Object
	* @param Component config.
	*/
	virtual std::shared_ptr<GameObjectComponent> CreateGameObjectComponent(GameObject& gameObject, const pugi::xml_node& config) = 0;

	/**
	* Registers all of the game object components that this factory can create.
	*/
	virtual std::vector<std::string> RegisterGameObjectComponents() = 0;

private:
};
#pragma once

#include <string>
#include <vector>
#include <memory>
#include <GameObject.h>
#include "WorldFactory.h"

namespace Graphics
{
	class IWindowManager;
	class IScene;
	class IResourceManager;
}

namespace Physics
{
	class IPhysicsSystem;
}

namespace Game
{

/**
* The game world is an instance of a level xml file with loaded game objects.
* A game world owns all of it's systems except for the window manager.
*/
class GameWorld
{
public:

	/**
	* Loads a world based on the config. 
	*/
	GameWorld(const std::string& level, const pugi::xml_node& engineConfig, std::weak_ptr<Graphics::IWindowManager> windowManager);

	/**
	* Destructor.
	*/
	~GameWorld();

	/**
	*Loads game objects as defined in the level xml.
	* @param gameObjectXML Xml document of the level containing game objects.
	*/
	void LoadGameObjects(const pugi::xml_node& gameObjectXML);

	/**
	*Perform any actions that should take place pre tick.
	*/
	void PreTick();

	/**
	*Perform any actions that should take place in a tick.
	*/
	void Tick(const double deltaTime);

	/**
	*Performs any actions that should take place post-tick.
	*/
	void PostTick();

	/**
	*@return Is the world finished.
	*/
	bool Finished();

private:

	std::string m_name; ///< Name of this level.

	std::vector<std::shared_ptr<GameObject>> m_gameObjects; ///< All game objects currently in this level.

	WorldFactory m_worldFactory; ///< Factory for creating game objects.

	std::weak_ptr<Graphics::IWindowManager> m_windowManager; ///< Window manager

	std::shared_ptr<Graphics::IScene> m_scene; ///< The graphics scene for the game world.

	std::shared_ptr<Physics::IPhysicsSystem> m_physicsSystem; ///< The physics system for the world.
};

}
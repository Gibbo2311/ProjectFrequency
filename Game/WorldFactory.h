#pragma once

#include <memory>
#include <vector>
#include <map>
#include <pugixml.hpp>

class GameObject;
class IGameObjectComponentFactory;

/**
*Class is responsible for creating game objects.
*/
class WorldFactory
{
public:

	/**
	*Loads game object definitions from XML.
	*/
	WorldFactory();
	virtual ~WorldFactory();

	/**
	*Adds a game object factory to the list of known factories.
	*/
	void AddGameObjectComponentFactory(std::shared_ptr<IGameObjectComponentFactory> factory);

	/**
	* Returns a freshly created game object of the specified type with any special attributes.
	*/
	std::shared_ptr<GameObject> CreateGameObject(const std::string& type, const pugi::xml_node& specialAttributes);

private:

	pugi::xml_document m_gameObjectDefinitions; ///<XML file containing game object definitions.
	std::map <std::string, pugi::xml_node> m_gameObjectDefinitionLookup; ///< Lookup map of game object names to it's xml definition.
	std::map<std::string, unsigned int> m_factoryLookup; ///< Lookup of game object components to their factory index.
	std::vector<std::shared_ptr<IGameObjectComponentFactory>> m_factories; //All game object factories registered with this factory.

};
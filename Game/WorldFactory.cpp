#include "WorldFactory.h"
#include <pugixml.hpp>
#include <IGameObjectComponentFactory.h>
#include <exception>
#include <GameObject.h>
#include <string>
#include <CommonGameObjectComponentFactory.h>

namespace
{
	const std::string GAME_OBJECT_DEFINITION_FILE = ".\\Levels\\GameObjectDefinitions.xml";
}

WorldFactory::WorldFactory()
{
	//Initialise World Factory
	m_gameObjectDefinitions.load_file(GAME_OBJECT_DEFINITION_FILE.c_str());
	auto definitionsNode = m_gameObjectDefinitions.child("GameObjectDefinitions");

	for (auto& gameObjectDefinition : definitionsNode.children("GameObjectDefinition"))
	{
		std::string type = gameObjectDefinition.attribute("Name").value();

		if (m_gameObjectDefinitionLookup.find(type) == m_gameObjectDefinitionLookup.end())
		{
			m_gameObjectDefinitionLookup[type] = gameObjectDefinition;
		}
		else
		{
			throw std::exception("Trying to add a game object definition that already exists", __LINE__);
		}		
	}

	AddGameObjectComponentFactory(std::make_shared<CommonGameObjectComponentFactory>());

}

WorldFactory::~WorldFactory()
{

}

void WorldFactory::AddGameObjectComponentFactory(std::shared_ptr<IGameObjectComponentFactory> factory)
{
	unsigned int componentLookup = m_factories.size();
	m_factories.push_back(factory);

	for(std::string& component : factory->RegisterGameObjectComponents())
	{
		if(m_factoryLookup.find(component) == m_factoryLookup.end())
		{
			m_factoryLookup[component] = componentLookup;
		}
		else
		{
			throw std::exception("Trying to add a component that already has a factory", __LINE__);
		}
	}
}

std::shared_ptr<GameObject> WorldFactory::CreateGameObject(const std::string& type, const pugi::xml_node& specialAttributes)
{
	std::shared_ptr<GameObject> gameObject = std::make_shared<GameObject>(specialAttributes.attribute("Name").value());
	pugi::xml_node definition = m_gameObjectDefinitionLookup[type];
	for (const pugi::xml_node& component : definition.children())
	{
		std::string componentName = component.name();

		auto factory = m_factoryLookup.find(componentName);
		
		if(factory == m_factoryLookup.end())
		{
			std::string message = "Couldn't find factory for game component " + std::string(component.name());
			throw std::exception(message.c_str(), __LINE__);
		}

		auto customSetting = specialAttributes.child(componentName.c_str());
		if (!customSetting.empty())
		{
			gameObject->AddGameComponent(m_factories[factory->second]->CreateGameObjectComponent(*(gameObject.get()), customSetting));
		}
		else
		{
			gameObject->AddGameComponent(m_factories[factory->second]->CreateGameObjectComponent(*(gameObject.get()), component));
		}

		
	}


	return gameObject;
}

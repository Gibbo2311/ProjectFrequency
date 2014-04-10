#include "GameWorld.h"

#include <IWindowManager.h>
#include "WorldFactory.h"
#include <pugixml.hpp>
#include <IWindowManager.h>
#include <IScene.h>
#include <SceneNodeComponent.h>
#include <CameraComponent.h>
#include <typeinfo>
#include <Graphics.h>
#include <Physics.h>
#include <IPhysicsSystem.h>

namespace
{
	const std::string LEVEL_DIRECTORY = "Levels\\";
	const std::string XML_EXTENSION = ".xml";
}

namespace Game
{

GameWorld::GameWorld(const std::string& level, const pugi::xml_node& engineConfig, std::weak_ptr<Graphics::IWindowManager> windowManager)
	:m_name(level)
	,m_windowManager(windowManager)
{
	//Open level xml.
	//TODO: Add error checking.
	pugi::xml_document doc;
	doc.load_file((LEVEL_DIRECTORY + level + XML_EXTENSION).c_str());
	auto worldXML = doc.child("GameWorld");

	//Create the graphics scene.
	m_scene = Graphics::CreateScene("Ogre", worldXML, windowManager);
	m_physicsSystem = Physics::CreatePhysicsSystem("Bullet", worldXML);

	m_worldFactory.AddGameObjectComponentFactory(m_scene);
	m_worldFactory.AddGameObjectComponentFactory(m_physicsSystem);

	LoadGameObjects(worldXML.child("GameObjects"));
}

GameWorld::~GameWorld()
{

}

void GameWorld::LoadGameObjects(const pugi::xml_node& gameObjectXML)
{
	for(pugi::xml_node xmlObject: gameObjectXML.children("GameObject"))
	{
		auto gameObject = m_worldFactory.CreateGameObject(xmlObject.attribute("Type").value(), xmlObject);
	
		m_gameObjects.push_back(gameObject);
	}
}

void GameWorld::PreTick()
{
	
}

void  GameWorld::Tick(const double deltaTime)
{
	m_physicsSystem->Tick(deltaTime);

	auto windowManager = m_windowManager.lock();
	if(windowManager != nullptr && !windowManager->IsClosed())
	{
		windowManager->MessagePump();
	}

	return;
}

void GameWorld::PostTick()
{
	m_physicsSystem->PostTick();
	m_scene->PostTick();
}

bool GameWorld::Finished()
{
	auto windowManager = m_windowManager.lock();
	return windowManager == nullptr || windowManager->IsClosed();
}

}
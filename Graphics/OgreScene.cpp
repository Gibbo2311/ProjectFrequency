#include "stdafx.h"

#include <GameObject.h>

#include "OgreScene.h"
#include "OgreSceneNodeComponent.h"
#include "OgreCameraComponent.h"
#include "OgreSingleton.h"
#include "IWindowManager.h"
#include "OgreResourceManager.h"
#include "OgreMeshComponent.h"

namespace Graphics
{
	OgreScene::OgreScene(const pugi::xml_node& config, std::weak_ptr<IWindowManager>& windowManager)
		: m_ogreInstance(OgreSingleton::GetInstance())
		, m_windowManager(windowManager)
	{
		//Add all resource folders to resources.
		auto resourceConfig = config.child("Resources");
		m_resourceManager.reset(new OgreResourceManager(resourceConfig));
		
		//TODO: Add some config for type of scene manager.
		m_ogreSceneManager = m_ogreInstance.createSceneManager(Ogre::ST_GENERIC, "TEMP");
		m_ogreSceneManager->setAmbientLight(Ogre::ColourValue(1.0f, 1.0f, 1.0f));
	}

	OgreScene::~OgreScene()
	{
	}

	
	std::vector<std::string> OgreScene::RegisterGameObjectComponents()
	{
		std::vector<std::string> m_availableComponents;
		m_availableComponents.push_back("CameraComponent");
		m_availableComponents.push_back("SceneNodeComponent");
		m_availableComponents.push_back("MeshComponent");

		return m_availableComponents;
	}

	std::shared_ptr<GameObjectComponent> OgreScene::CreateGameObjectComponent(GameObject& gameObject, const pugi::xml_node& config)
	{
		std::shared_ptr<GameObjectComponent> component;
		std::string componentName = config.name();
		if (componentName == "SceneNodeComponent")
		{
			component = std::make_shared<OgreSceneNodeComponent>(&gameObject, *this);
		}
		else if (componentName == "CameraComponent")
		{
			std::string viewportName = config.attribute("Viewport").value();
			auto sceneNodeComponent = std::static_pointer_cast<OgreSceneNodeComponent>(gameObject.GetGameComponent<SceneNodeComponent>().lock());
			auto camera = m_ogreSceneManager->createCamera("");
			auto viewport = m_windowManager.lock()->GetViewport(viewportName);
			component = std::make_shared<OgreCameraComponent>(&gameObject, camera, viewport);
		}
		else if (componentName == "MeshComponent")
		{
			std::string meshName = config.attribute("Mesh").value();
			auto mesh = m_ogreSceneManager->createEntity(m_resourceManager->GetMesh(meshName));
			component = std::make_shared<OgreMeshComponent>(&gameObject, mesh);
		}	

		if (component == nullptr)
		{
			throw std::exception("Unknown Component", __LINE__);
		}
		
		m_gameObjectComponents.push_back(component);

		return component;
	}
	
	void OgreScene::PreTick()
	{
		//Nothing Yet
	}
	void OgreScene::Tick(const double& deltaTime)
	{
		//Nothing Yet;	
	}
	void OgreScene::PostTick()
	{
		for (auto& component : m_gameObjectComponents)
		{
			component->PostTick();
		}
	}

	Ogre::SceneManager* OgreScene::GetOgreSceneManager()
	{
		return m_ogreSceneManager;
	}
}


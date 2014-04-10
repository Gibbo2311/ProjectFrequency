#pragma once
#include <IScene.h>
#include <IGameObjectComponentFactory.h>

namespace Ogre
{
	class SceneManager;
}

namespace Graphics
{
	class SceneNodeComponent;
	class CameraComponent;
	class IWindowManager;
	class OgreResourceManager;


	/**
	*Scene to be used when OGRE system is specified.
	*/
	class OgreScene : public IScene
	{
	public:
		/**
		* Constructor for an Ogre scene.
		*/
		OgreScene(const pugi::xml_node& config, std::weak_ptr<IWindowManager>& windowManager);

		virtual ~OgreScene();

		Ogre::SceneManager* GetOgreSceneManager();

		/**
		* @see IGameObjectComponentFactory::CreateGameObjectComponent
		*/
		virtual std::shared_ptr<GameObjectComponent> CreateGameObjectComponent(GameObject& gameObject, const pugi::xml_node& config) override;

		/**
		*@see IGameObjectComponentFactory::RegisterGameObjectComponents
		*/
		virtual std::vector<std::string> RegisterGameObjectComponents() override;

		/**
		*Perform any Pre Tick actions for the the scene.
		*/
		virtual void PreTick() override;

		/**
		*Perform any Tick actions for the the scene.
		*/
		virtual void Tick(const double& deltaTime) override;

		/**
		*Perform any Post Tick actions for the the scene.
		*/
		virtual void PostTick() override;

	private:

		Ogre::SceneManager* m_ogreSceneManager; ///<Internal Ogre Scene Manager
		
		Ogre::Root& m_ogreInstance; ///< OGRE instance;	
		
		std::vector<std::shared_ptr<GameObjectComponent>> m_gameObjectComponents; ///<Created Game Object components;

		std::unique_ptr<OgreResourceManager> m_resourceManager; ///<Resource manager for loading any graphics resources.

		std::weak_ptr<IWindowManager> m_windowManager; ///<Window manager of the owner of this scene.
	};
}
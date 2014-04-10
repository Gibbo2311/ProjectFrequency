#pragma once

#include <SceneNodeComponent.h>

namespace Graphics
{
	class OgreScene;

	/**
	*Scene Node Component to be used in the OGRE system.
	*/
	class OgreSceneNodeComponent : public SceneNodeComponent
	{
	public:

		/**
		*Constructor for an OgreSceneNode
		* @param gameObject Owner of the Scene Node Component
		*/
		OgreSceneNodeComponent(GameObject* gameObject, OgreScene& sceneManager);
		virtual ~OgreSceneNodeComponent();

		/**
		*Performs post tick actions for ogre scene nodes.
		*/
		virtual void PostTick() override;

		/**
		*@returns Ogre scene node.
		*/
		Ogre::SceneNode* GetOgreSceneNode();

	private:

		OgreScene& m_sceneManager; ///<Reference to the scene manager that created the OGRE scene node.
		Ogre::SceneNode* m_sceneNode; ///<Internal OGRE scene node.

	};
}

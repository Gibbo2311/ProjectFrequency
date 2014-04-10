#include "stdafx.h"
#include "OgreSceneNodeComponent.h"
#include "OgreScene.h"
#include <GameObject.h>
#include <TransformComponent.h>

namespace Graphics
{

	OgreSceneNodeComponent::OgreSceneNodeComponent(GameObject* gameObject, OgreScene& scene)
		: SceneNodeComponent(gameObject),
		  m_sceneManager(scene)
	{
		m_sceneNode = m_sceneManager.GetOgreSceneManager()->getRootSceneNode()->createChildSceneNode();
	}

	OgreSceneNodeComponent::~OgreSceneNodeComponent()
	{
		m_sceneManager.GetOgreSceneManager()->destroySceneNode(m_sceneNode);
	}

	void OgreSceneNodeComponent::PostTick()
	{
		auto transform = m_gameObject->GetGameComponent<TransformComponent>().lock();
		auto pos = transform->GetPosition();
		auto rot = transform->GetRotation();
		m_sceneNode->setPosition(pos.x(), pos.y(), pos.z());
		m_sceneNode->setOrientation(Ogre::Quaternion(rot.w(), rot.x(), rot.y(), rot.z()));
	}

	Ogre::SceneNode* OgreSceneNodeComponent::GetOgreSceneNode()
	{
		return m_sceneNode;
	}
}
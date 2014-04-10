#include "stdafx.h"
#include <GameObject.h>
#include "OgreMeshComponent.h"
#include "OgreSceneNodeComponent.h"

namespace Graphics
{
	OgreMeshComponent::OgreMeshComponent(GameObject* gameObject, Ogre::Entity* entity)
		:MeshComponent(gameObject),
		m_meshEntity(entity)
	{
		auto sceneNodeComponent = std::static_pointer_cast<OgreSceneNodeComponent>(gameObject->GetGameComponent<SceneNodeComponent>().lock());
		sceneNodeComponent->GetOgreSceneNode()->attachObject(m_meshEntity);
	}

	OgreMeshComponent::~OgreMeshComponent()
	{
		m_meshEntity->getParentSceneNode()->detachObject(m_meshEntity);
		delete m_meshEntity;
	}
}

#include "stdafx.h"

#include "OgreCameraComponent.h"
#include "SceneNodeComponent.h"
#include "OgreSceneNodeComponent.h"
#include <IViewport.h>
#include <GameObject.h>

namespace Graphics
{
	OgreCameraComponent::OgreCameraComponent(GameObject* gameObject, Ogre::Camera* camera, std::weak_ptr<IViewport>& viewport)
		:CameraComponent(gameObject),
		  m_ogreCamera(camera)
	{
		
		auto ogreNode = std::static_pointer_cast<OgreSceneNodeComponent>(gameObject->GetGameComponent<SceneNodeComponent>().lock());
		ogreNode->GetOgreSceneNode()->attachObject(m_ogreCamera);
		viewport.lock()->SetCamera(this);

		//TODO: USE XML CONFIG FOR THIS
		m_ogreCamera->setAutoAspectRatio(true);
		m_ogreCamera->setNearClipDistance(1.5f);
		m_ogreCamera->setFarClipDistance(3000.0f);
	}

	OgreCameraComponent::~OgreCameraComponent()
	{
		m_ogreCamera->getParentSceneNode()->detachObject(m_ogreCamera);
	}

	Ogre::Camera* OgreCameraComponent::GetOgreCamera()
	{
		return m_ogreCamera;
	}
}
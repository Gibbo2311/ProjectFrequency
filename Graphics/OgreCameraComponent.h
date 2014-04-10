#pragma once

#include "stdafx.h"

#include <CameraComponent.h>
#include <memory>

namespace Graphics
{
	class IViewport;
	class OgreSceneNodeComponent;

	/**
	*Camera component to be used with OGRE system.
	*/
	class OgreCameraComponent: public CameraComponent
	{
	public:

		/**
		*Constructor
		*@param gameObject The game object this component belongs to.
		*@param camera The OGRE camera that will be the internals for this component.
		*@param viewport The viewport that this camera will use.
		*/
		OgreCameraComponent(GameObject* gameObject, Ogre::Camera* camera, std::weak_ptr<IViewport>& viewport);
		virtual ~OgreCameraComponent();

		/**
		*@return The ogre camrea associated to this camera.
		*/
		Ogre::Camera* GetOgreCamera();

	private:
		
		Ogre::Camera* m_ogreCamera; ///< The ogre camera this component controls.

	};
}
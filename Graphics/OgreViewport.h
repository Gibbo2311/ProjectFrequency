#pragma once
#include "stdafx.h"

#include <IViewport.h>

namespace Graphics{

	/**
	* Viewport used in the OGRE system.
	*/
	class OgreViewport: public IViewport
	{
	public:

		/**
		*@param ogreWindow Render Window created by OGRE.
		*@param config Confid to use for the viewport.
		*/
		OgreViewport(Ogre::RenderWindow* ogreWindow,  const pugi::xml_node config);
		virtual ~OgreViewport();

		/**
		*Set the camera to render for this viewport.
		*/
		virtual void SetCamera(CameraComponent* camera) override; 

	private:
		Ogre::Viewport* m_viewport; ///<Internal OGRE viewport.
	};
}
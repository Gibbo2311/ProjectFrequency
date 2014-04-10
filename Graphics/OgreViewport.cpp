#include "stdafx.h"

#include "OgreViewport.h"
#include "OgreCameraComponent.h"

namespace Graphics
{
	OgreViewport::OgreViewport(Ogre::RenderWindow* ogreWindow, const pugi::xml_node config)
	{
		const unsigned short z_Order = config.attribute("ZOrder").as_uint();
		const float width = config.attribute("Width").as_float();
		const float height = config.attribute("Height").as_float(); 
		const float left = (1.0f - width) * 0.5f; 
		const float top = (1.0f - height)  * 0.5f;
		const float backgroundR = config.attribute("R").as_float();
		const float backgroundG = config.attribute("G").as_float();
		const float backgroundB = config.attribute("B").as_float();
		m_viewport = ogreWindow->addViewport(nullptr, z_Order, left, top, width, height);
		m_viewport->setAutoUpdated(true);
		m_viewport->setBackgroundColour(Ogre::ColourValue(backgroundR, backgroundG, backgroundB));
	}

	OgreViewport::~OgreViewport()
	{

	}

	void OgreViewport::SetCamera(CameraComponent* camera)
	{
		Ogre::Camera* cam = dynamic_cast<OgreCameraComponent*>(camera)->GetOgreCamera();
		cam->setAutoAspectRatio(true);
		m_viewport->setCamera(cam);
	}
}
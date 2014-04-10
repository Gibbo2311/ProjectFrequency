#include "stdafx.h"

#include "OgreWindowManager.h"
#include "OgreSingleton.h"
#include "OgreViewport.h"
#include <iostream>
#include <exception>

namespace Graphics{

	OgreWindowManager::OgreWindowManager(const pugi::xml_node& config)
		: m_ogreRoot(OgreSingleton::GetInstance())
	{	
		auto windowConfig = config.child("WindowManager");
		std::string title = windowConfig.attribute("Title").value();
		unsigned int sizeX = windowConfig.attribute("SizeX").as_uint();
		unsigned int sizeY = windowConfig.attribute("SizeZ").as_uint();
		bool fullscreen = windowConfig.attribute("Fullscreen").as_bool();
		m_renderWindow = m_ogreRoot.createRenderWindow(title, sizeX, sizeY, fullscreen);
		
		auto viewports = windowConfig.child("Viewports");
		
		for(pugi::xml_node viewport: viewports.children("Viewport"))
		{
			CreateViewport(viewport);
		}

		m_renderWindow->setActive(true);
		m_renderWindow->setAutoUpdated(false);
	}

	OgreWindowManager::~OgreWindowManager()
	{

	}

	void OgreWindowManager::MessagePump()
	{

		m_renderWindow->update(false);
		m_renderWindow->swapBuffers();
		m_ogreRoot.renderOneFrame();
		Ogre::WindowEventUtilities::messagePump();
		
	}

	bool OgreWindowManager::IsClosed()
	{
		return m_renderWindow->isClosed();
	}

	std::weak_ptr<IViewport> OgreWindowManager::CreateViewport(const pugi::xml_node& config)
	{
		std::string name = config.attribute("Name").value();

		if(m_viewports.find(name) != m_viewports.end())
		{
			throw std::exception("Trying to create a viewport with a name that already exists");
		}

		m_viewports[name] = std::make_shared<OgreViewport>(m_renderWindow, config);
		return m_viewports[name];
	}

	std::weak_ptr<IViewport> OgreWindowManager::GetViewport(const std::string& viewportName)
	{
		if(m_viewports.find(viewportName) == m_viewports.end())
		{
			throw std::exception("Viewport doesn't exist!");
		}

		return m_viewports[viewportName];
	}

}	
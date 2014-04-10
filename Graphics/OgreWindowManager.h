#pragma once

#include "stdafx.h"

#include <IWindowManager.h>
#include <map>
#include <string>

namespace Graphics{

class IViewport;

/**
* Create a window manager to use for an OGRE system.
*/
class OgreWindowManager: public IWindowManager
{
public:

	/*
	*@param config Defines how the window should be created.
	*/
	OgreWindowManager(const pugi::xml_node& config);
	virtual ~OgreWindowManager();

	/**
	* @see IWindowManager::MessagePump
	*/
	virtual void MessagePump() override;

	/**
	* @see IWindowManager::IsClosed
	*/
	virtual bool IsClosed() override;

	/**
	* @see IWindowManager::CreateViewport
	*/
	virtual std::weak_ptr<IViewport> CreateViewport(const pugi::xml_node& config) override;

	/**
	* @see IWindowManager::GetViewport
	*/
	virtual std::weak_ptr<IViewport> GetViewport(const std::string& viewportName) override;

private:

	OgreWindowManager(const OgreWindowManager& other); ///< Hide copy constructor.
	void operator=(const OgreWindowManager& other); ///<Hide operator

	
	Ogre::RenderWindow* m_renderWindow; ///<Internal OGRE render window.
	Ogre::Root& m_ogreRoot; ///<Ogre root.

	std::map<std::string, std::shared_ptr<IViewport>> m_viewports; ///< All created viewports
};

}
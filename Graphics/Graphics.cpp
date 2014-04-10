// Graphics.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Graphics.h"

#include "OgreWindowManager.h"
#include "OgreScene.h"
#include "OgreResourceManager.h"
#include <pugixml.hpp>

namespace Graphics{

	std::shared_ptr<IWindowManager> CreateWindowManager(const pugi::xml_node& config)
	{
		std::string type = config.attribute("Type").value();
		if (type == "Ogre")
		{
			return std::make_shared<OgreWindowManager>(config);
		}

		throw std::exception("Unknown Window Manager" , __LINE__);
	}

	std::shared_ptr<IScene> CreateScene(const std::string& type, const pugi::xml_node& config, std::weak_ptr<IWindowManager>& windowManager)
	{
		if (type == "Ogre")
		{
			auto sceneConfig = config.child("Scene");
			return std::make_shared<OgreScene>(sceneConfig, windowManager);
		}

		throw std::exception("Unknown Scene Manager", __LINE__);
	}
}
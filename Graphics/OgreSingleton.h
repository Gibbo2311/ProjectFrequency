#pragma once

#include "stdafx.h"

namespace Graphics{

class OgreSingleton
{
public:

	/**
	* Returns a reference to the OGRE instance.
	*/
	static Ogre::Root& GetInstance()
	{
		static Ogre::Root* m_instance;

		if(!m_instance)
		{
			m_instance = new Ogre::Root("", "", "Tutorial_Ogre.LOG");
			std::vector<std::string> plugins;
			plugins.push_back("RenderSystem_GL");
			plugins.push_back("Plugin_ParticleFX");
			plugins.push_back("Plugin_OctreeSceneManager");
			plugins.push_back("Plugin_CgProgramManager");
			//plugins.push_back("OgreOverlay");

			for(std::string& plugin : plugins)
			{
#ifdef _DEBUG
				plugin = plugin.append("_d");
#endif
				m_instance->loadPlugin(plugin);
			}

			const Ogre::RenderSystemList& lRenderSystemList = m_instance->getAvailableRenderers();
			if( lRenderSystemList.size() == 0 )
			{
				Ogre::LogManager::getSingleton().logMessage("Sorry, no rendersystem was found.");
			}else
			{
				Ogre::RenderSystem *lRenderSystem = lRenderSystemList[0];
				m_instance->setRenderSystem(lRenderSystem);
				bool createWindowAutomatically = false;
				
				//m_instance->showConfigDialog();
				m_instance->initialise(createWindowAutomatically, "Title", "");			
			}
		}
		
		return *m_instance;
	}

private:
	
};

}
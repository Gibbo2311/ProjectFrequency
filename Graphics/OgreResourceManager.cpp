#include "stdafx.h"

#include "OgreResourceManager.h"

namespace Graphics
{
	OgreResourceManager::OgreResourceManager(const pugi::xml_node& config)
		: m_meshManager(Ogre::MeshManager::getSingleton())
	{
		//Using singleton because that's how ogre handles it.
		Ogre::ResourceGroupManager& resourceGroupManager = Ogre::ResourceGroupManager::getSingleton();
		
		//Load resource directories.
		for (auto& resourceDir : config.children("ResourceDirectory"))
		{
			//Add some error checking here.
			resourceGroupManager.addResourceLocation(resourceDir.attribute("Path").value(), "FileSystem", config.attribute("GroupName").value(), true);
		}
		resourceGroupManager.createResourceGroup(config.attribute("Name").value());
		resourceGroupManager.initialiseAllResourceGroups();
	}

	OgreResourceManager::~OgreResourceManager()
	{

	}

	Ogre::MeshPtr OgreResourceManager::GetMesh(const std::string& meshName)
	{
		//TODO: Error checking
		return m_meshManager.create(meshName, Ogre::ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME);
	}
}
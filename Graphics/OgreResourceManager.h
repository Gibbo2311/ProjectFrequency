#pragma once

#include <string>

namespace Graphics
{
	/**
	*Manages resources for the OGRE system.
	*/
	class OgreResourceManager
	{
	public:
		/**
		*@param config Contains information about what resources to load.
		*/
		OgreResourceManager(const pugi::xml_node& config);
		~OgreResourceManager();

		/**
		*Returns an OGRE mesh pointer for the mesh name.
		*/
		Ogre::MeshPtr GetMesh(const std::string& meshName);

	private:
		Ogre::MeshManager& m_meshManager; ///< OGRE Mesh Manager
	};
}
#pragma once

#include <MeshComponent.h>

namespace Ogre
{
	class Entity;
}

namespace Graphics
{
	/**
	* Mesh component to be used with the OGRE system.
	*/
	class OgreMeshComponent : public MeshComponent
	{
	public:
		/**
		*Creates an OGRE mesh component.
		*@param gameObject Pointer to the owner of this component.
		*@param entity pointer to the Ogre entity for the ogre mesh.
		*/
		OgreMeshComponent(GameObject* gameObject, Ogre::Entity* entity);
		virtual ~OgreMeshComponent();

	private:
		
		Ogre::Entity* m_meshEntity; ///<Pointer to the ogre entity that has the mesh.
	};

}

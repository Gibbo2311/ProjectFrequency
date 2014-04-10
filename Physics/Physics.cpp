// Physics.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Physics.h"
#include <pugixml.hpp>

#include "BulletPhysicsSystem.h"
namespace Physics
{
	std::shared_ptr<IPhysicsSystem> CreatePhysicsSystem(const std::string& type, const pugi::xml_node& config)
	{
		if (type == "Bullet")
		{
			auto physicsConfig = config.child("PhysicsSystem");
			return std::make_shared<BulletPhysicsSystem>(physicsConfig);
		}

		throw std::exception("Unknown Scene Manager", __LINE__);
	}
}
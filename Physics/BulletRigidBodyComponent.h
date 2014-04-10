#pragma once

#include <RigidBodyComponent.h>

namespace pugi
{
	class xml_node;
}

namespace Physics
{
	class BulletRigidBodyComponent : public RigidBodyComponent
	{
	public:
		BulletRigidBodyComponent(GameObject* gameObject, const pugi::xml_node& config, btDiscreteDynamicsWorld* bulletWorld);
		virtual ~BulletRigidBodyComponent();

		void PostTick() override;

	private:
		btRigidBody* m_body;	
	};
}
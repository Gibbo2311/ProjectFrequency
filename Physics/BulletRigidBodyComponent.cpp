#include "stdafx.h"
#include "BulletRigidBodyComponent.h"
#include <TransformComponent.h>
#include <GameObject.h>
#include <TransformComponent.h>

namespace Physics
{
	BulletRigidBodyComponent::BulletRigidBodyComponent(GameObject* gameObject, const pugi::xml_node& config, btDiscreteDynamicsWorld* bulletWorld)
		:RigidBodyComponent(gameObject)
	{
		auto transformComponent = gameObject->GetGameComponent<TransformComponent>().lock();
		btConvexInternalShape* fallShape = new btSphereShape(20);
		btScalar mass = 10;
		btVector3 fallInertia(0, 0, 0);
		fallShape->calculateLocalInertia(mass, fallInertia);
		btDefaultMotionState* fallMotionState =
			new btDefaultMotionState(btTransform(transformComponent->GetRotation(), transformComponent->GetPosition()));
		btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, fallShape, fallInertia);
		/*
		btDefaultMotionState* fallMotionState =
			new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 50, 0)));

		fallShape->calculateLocalInertia(mass, fallInertia);
		btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, fallShape, fallInertia);
		*/
		m_body = new btRigidBody(fallRigidBodyCI);
		bulletWorld->addRigidBody(m_body);
	}

	BulletRigidBodyComponent::~BulletRigidBodyComponent()
	{

	}

	void BulletRigidBodyComponent::PostTick()
	{
		auto bodyTransform = m_body->getWorldTransform();
		auto transformComponent = m_gameObject->GetGameComponent<TransformComponent>().lock();

		transformComponent->SetPosition(bodyTransform.getOrigin());
		transformComponent->SetRotation(bodyTransform.getRotation());
	}
}
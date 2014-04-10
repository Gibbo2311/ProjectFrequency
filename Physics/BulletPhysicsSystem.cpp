#include "stdafx.h"
#include "BulletPhysicsSystem.h"
#include "BulletRigidBodyComponent.h"

namespace Physics
{

	BulletPhysicsSystem::BulletPhysicsSystem(const pugi::xml_node& config)
	{
		//Initialise bullet world.
		m_broadphaseInterface.reset(new btDbvtBroadphase());
		m_collisionConfiguration.reset(new btDefaultCollisionConfiguration());
		m_collisionDispatcher.reset(new btCollisionDispatcher(m_collisionConfiguration.get()));
		m_constraintSolver.reset(new btSequentialImpulseConstraintSolver());
		m_bulletDynamicsWorld.reset(new btDiscreteDynamicsWorld(m_collisionDispatcher.get()
															   ,m_broadphaseInterface.get()
															   ,m_constraintSolver.get()
															   ,m_collisionConfiguration.get()));
		
		m_bulletDynamicsWorld->setGravity(btVector3(0, -9.81, 0));

		btCollisionShape* groundShape = new btStaticPlaneShape(btVector3(0, 1, 0), 1);
		btDefaultMotionState* groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, -1, 0)));
		btRigidBody::btRigidBodyConstructionInfo
			groundRigidBodyCI(0, groundMotionState, groundShape, btVector3(0, 0, 0));
		btRigidBody* groundRigidBody = new btRigidBody(groundRigidBodyCI);
		m_bulletDynamicsWorld->addRigidBody(groundRigidBody);
	}


	BulletPhysicsSystem::~BulletPhysicsSystem()
	{
	}

	/**
	* @see IGameObjectComponentFactory::CreateGameObjectComponent
	*/
	std::shared_ptr<GameObjectComponent> BulletPhysicsSystem::CreateGameObjectComponent(GameObject& gameObject, const pugi::xml_node& config)
	{
		std::shared_ptr<GameObjectComponent> component;
		
		std::string componentName = config.name();
		if (componentName == "RigidBodyComponent")
		{
			component = std::make_shared<BulletRigidBodyComponent>(&gameObject, config, m_bulletDynamicsWorld.get());
		}

		m_bulletRigidBodies.push_back(component);

		return component;
	}

	/**
	*@see IGameObjectComponentFactory::RegisterGameObjectComponents
	*/
	std::vector<std::string> BulletPhysicsSystem::RegisterGameObjectComponents()
	{
		std::vector<std::string> availableComponents;

		availableComponents.push_back("RigidBodyComponent");

		return availableComponents;
	}

	void BulletPhysicsSystem::PreTick()
	{

	}

	void BulletPhysicsSystem::Tick(const double& deltaTime)
	{
		m_bulletDynamicsWorld->stepSimulation(static_cast<btScalar>(deltaTime));
	}

	void BulletPhysicsSystem::PostTick()
	{
		for (auto& body : m_bulletRigidBodies)
		{
			body->PostTick();
		}
	}
}

#pragma once

#include <IPhysicsSystem.h>
#include <memory>

class btDiscreteDynamicsWorld;
class btBroadphaseInterface;
class btDefaultCollisionConfiguration;
class btCollisionDispatcher;
class btSequentialImpulseConstraintSolver;
class GameObjectComponent;

namespace Physics
{
	class BulletPhysicsSystem : public IPhysicsSystem
	{
	public:
		BulletPhysicsSystem(const pugi::xml_node& config);
		virtual ~BulletPhysicsSystem();

		/**
		* @see IGameObjectComponentFactory::CreateGameObjectComponent
		*/
		virtual std::shared_ptr<GameObjectComponent> CreateGameObjectComponent(GameObject& gameObject, const pugi::xml_node& config) override;

		/**
		*@see IGameObjectComponentFactory::RegisterGameObjectComponents
		*/
		virtual std::vector<std::string> RegisterGameObjectComponents() override;

		virtual void PreTick() override;
		virtual void Tick(const double& deltaTime) override;
		virtual void PostTick() override;

	private:
		std::unique_ptr<btSequentialImpulseConstraintSolver> m_constraintSolver;
		std::unique_ptr<btDefaultCollisionConfiguration> m_collisionConfiguration;
		std::unique_ptr<btCollisionDispatcher> m_collisionDispatcher;
		std::unique_ptr<btBroadphaseInterface> m_broadphaseInterface;
		std::unique_ptr<btDiscreteDynamicsWorld> m_bulletDynamicsWorld;

		std::vector<std::shared_ptr<GameObjectComponent>> m_bulletRigidBodies;
	};
}

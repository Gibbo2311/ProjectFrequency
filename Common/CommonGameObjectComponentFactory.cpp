#include "stdafx.h"

#include <CommonGameObjectComponentFactory.h>
#include <pugixml.hpp>
#include <memory>
#include <TransformComponent.h>

CommonGameObjectComponentFactory::CommonGameObjectComponentFactory()
{

}

CommonGameObjectComponentFactory::~CommonGameObjectComponentFactory()
{

}

std::vector<std::string> CommonGameObjectComponentFactory::RegisterGameObjectComponents()
{
	std::vector<std::string> availableComponents;
	availableComponents.push_back("TransformComponent");

	return availableComponents;
}

std::shared_ptr<GameObjectComponent> CommonGameObjectComponentFactory::CreateGameObjectComponent(GameObject& gameObject, const pugi::xml_node& config)
{
	std::shared_ptr<GameObjectComponent> component;
	std::string componentName = config.name();
	if (componentName == "TransformComponent")
	{
		Vector3 position;
		position.setZero();
		Quaternion rotation = Quaternion::getIdentity();
		
		auto positionConfig = config.child("Position");
		if (!positionConfig.empty())
		{
			position.setX(positionConfig.attribute("X").as_float());
			position.setY(positionConfig.attribute("Y").as_float());
			position.setZ(positionConfig.attribute("Z").as_float());
		}
		auto rotationConfig = config.child("Rotation");
		if (!rotationConfig.empty())
		{
			rotation.setW(positionConfig.attribute("W").as_float());
			rotation.setX(positionConfig.attribute("X").as_float());
			rotation.setY(positionConfig.attribute("Y").as_float());
			rotation.setZ(positionConfig.attribute("Z").as_float());
		}
		component = std::make_shared<TransformComponent>(&gameObject, position, rotation);
	}

	return component;
}


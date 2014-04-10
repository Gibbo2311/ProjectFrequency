#include "stdafx.h"

#include "GameObject.h"
#include <GameObjectComponent.h>
#include <TransformComponent.h>
#include <iostream>

GameObject::GameObject(const std::string& name)
: m_name(name)
{
}

GameObject::~GameObject()
{

}

void GameObject::AddGameComponent(std::shared_ptr<GameObjectComponent> component)
{
	if(m_components.count(component->GetStorageType()->name()) == 0)
	{
		m_components[component->GetStorageType()->name()] = component;
	}
	else
	{
		std::string message = std::string(typeid(*component).name()) + " component already exists on GameObject";
		throw std::exception(message.c_str(), __LINE__);
	}
}
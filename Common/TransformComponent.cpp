#include "stdafx.h"


#include "TransformComponent.h"
#include <iostream>

TransformComponent::TransformComponent(GameObject* gameObject)
	:GameObjectComponent(gameObject)
{
	m_transform.setIdentity();
}

TransformComponent::TransformComponent(GameObject* gameObject, const Vector3& pos, const Quaternion& rot)
	:GameObjectComponent(gameObject)
{
	m_transform.setIdentity();
	m_transform.setOrigin(pos);
	m_transform.setRotation(rot);
}

TransformComponent::~TransformComponent()
{
	
}

const type_info* TransformComponent::GetStorageType()
{
	return &typeid(TransformComponent);
}

void TransformComponent::SetPosition(const Vector3& position)
{
	m_transform.setOrigin(position);
}

void TransformComponent::SetRotation(const Quaternion& rotation)
{
	m_transform.setRotation(rotation);
}

const Vector3 TransformComponent::GetPosition() const
{
	return m_transform.getOrigin();
	
}

const Quaternion TransformComponent::GetRotation() const
{
	return m_transform.getRotation();
}
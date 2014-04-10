#include "stdafx.h"
#include <GameObjectComponent.h>

GameObjectComponent::GameObjectComponent(GameObject* gameObject)
{
	m_gameObject = gameObject;
}

GameObjectComponent::~GameObjectComponent()
{
	m_gameObject = nullptr;
}

void GameObjectComponent::PreTick()
{
	return;
}

void GameObjectComponent::Tick(const double& deltaTime)
{
	return;
}

void GameObjectComponent::PostTick()
{
	return;
}
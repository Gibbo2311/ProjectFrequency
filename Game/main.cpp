#include <iostream>

#include <Graphics.h>
#include <IWindowManager.h>
#include <memory>
#include <pugixml.hpp>

#include "GameWorld.h"
#include "WorldFactory.h"
#include <chrono>

#include <GameObject.h>
#include <TransformComponent.h>
#include <typeinfo>
#include <IGameObjectComponentFactory.h>

namespace
{
	const double TICK_TIME = 0.0166;
}

int main()
{
	//Load the engine config and create the world factory.
	pugi::xml_document doc;
	doc.load_file("EngineConfig.xml");

	//Load the window manager.
	auto engineConfig = doc.child("Engine");
	auto graphicsConfig = engineConfig.child("GraphicsSystem");
	auto windowManager = Graphics::CreateWindowManager(graphicsConfig);

	//Create game world.
	//Todo: implement switching between gameworlds.
	Game::GameWorld m_world("Default", engineConfig, windowManager);
	
	//Initialise game timers.
	std::chrono::high_resolution_clock::time_point lastTick, newTick = std::chrono::high_resolution_clock::now();

	//World loop
	while(!m_world.Finished())
	{
		newTick = std::chrono::high_resolution_clock::now();
		
		double delta = std::chrono::duration_cast<std::chrono::duration<double>>(newTick - lastTick).count();
		
		//Todo: improve ticking mechanism.
		if(delta > TICK_TIME)
		{
			m_world.PreTick();
			lastTick = newTick;
			m_world.Tick(TICK_TIME);
			m_world.PostTick();
		}
	}

	return 0;
}
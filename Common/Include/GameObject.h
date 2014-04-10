#pragma once
#include <unordered_map>
#include <map>
#include <typeinfo>
#include <string>
#include <exception>
#include <LinearMath\btVector3.h>
#include <memory>


class GameObjectComponent;

/**
*GameObject class that contains components.
*Ideally you make anything with this. We'll see how it goes.
*/
class GameObject
{
public:

	/**
	* Constructor.
	* Creates a default transform component.
	*@param name GameObject name.
	*/
	GameObject(const std::string& name = "");

	/**
	*Destrucduuuuuh.
	*/
	~GameObject();

	/**
	* Add a game component to this game object.
	* Game compoment type must not already exist on game object.
	* param Game component.
	*/
	void AddGameComponent(std::shared_ptr<GameObjectComponent> component);

	/**
	*Templated to retrieve game objects by type.
	* @template GameObject type to retrieve.
	* @throws Exception when component doesn't exist.
	*/
	template <typename T>
	std::weak_ptr<T> GetGameComponent()
	{
		std::string type = typeid(T).name();
		if(m_components.find(type) != m_components.end())
		{
			return std::static_pointer_cast<T>(m_components[type]);
		}
		else
		{
			std::string message = "Component does not exist on GameObject";
			throw std::exception(message.c_str(), __LINE__);
		}
	}
private:

	GameObject(const GameObject& object);
	void operator=(const GameObject& object);

	std::string m_name; ///< Name of the game object.

	std::map<const std::string, std::shared_ptr<GameObjectComponent>> m_components;
};
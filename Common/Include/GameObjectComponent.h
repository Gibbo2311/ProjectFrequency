#pragma once
#include <typeinfo>

class GameObject;

/**
*Base game object component.
*/
class GameObjectComponent
{
public:
	/**
	*Destructduh.
	*/
	virtual ~GameObjectComponent();

	/**
	*Return the storage type of the game object component.
	* @return type info.
	*/
	virtual const type_info* GetStorageType() = 0;

	/**
	*Perform any pretick actions for the game component. 
	*/
	virtual void PreTick();

	/**
	*Perform any Tick actions for the game component.
	*/
	virtual void Tick(const double& deltaTime);

	/**
	*Perform any post tick actions for the game component.
	*/
	virtual void PostTick();

protected:

	/**
	* Protected constructor.
	*/
	GameObjectComponent(GameObject* gameObject);

	//Hide copy constructor and = operator.
	GameObjectComponent(const GameObjectComponent& other);
	void operator=(const GameObjectComponent& other);

	GameObject* m_gameObject; ///< Game object that the component belongs to. Does not own pointer.
};
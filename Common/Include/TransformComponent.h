#pragma once

#include "GameObjectComponent.h"
#include <CommonMath.h>

/**
* Transform component for every game object.
* Defines position and rotation for a game object in the world.
*/
class TransformComponent : public GameObjectComponent
{
public:

	/**
	*Default constructduh.
	*/
	TransformComponent(GameObject* gameObject);


	/**
	*Constructor with arguments.
	*/
	TransformComponent(GameObject* gameObject, const Vector3& pos, const Quaternion& rot);

	/**
	*Destructduh
	*/
	virtual ~TransformComponent();

	/**
	* The storage type of any game object components inheriting this class.
	*/
	const type_info* GetStorageType() final;

	/**
	* Sets the rotation of the transform.
	* @param rotation rotation of the transform.
	*/
	void SetRotation(const Quaternion& rotation);

	/**
	* Sets the position of the transform.
	* @param position position of the transform.
	*/
	void SetPosition(const Vector3& position);

	/**
	* Returns the gameobjects position.
	*/
	const Vector3 GetPosition() const;

	/**
	* Returns the game objects rotation.
	*/
	const Quaternion GetRotation() const;


private:

	Transform m_transform; ///< Transform of game object.

};
#pragma once

namespace Graphics{

class CameraComponent;

class IViewport
{
public:
	/**
	* Virtual destructor.
	*/
	virtual ~IViewport(){};

	/**
	* Sets the camera for this viewport.
	* @param camera The camera to be used for this viewport.
	*/
	virtual void SetCamera(CameraComponent* camera) = 0;

};

}
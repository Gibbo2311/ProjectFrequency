#pragma once

#include <string>
#include <memory>

namespace Graphics{

class IViewport;

/**
*Interface for a window manager.
*/
class IWindowManager
{
public:

	/**
	*Virtual destructor.
	*/
	virtual ~IWindowManager() {};

	/**
	* Pump messages for the window.
	*/
	virtual void MessagePump() = 0;

	/**
	* @return True if the window no longer open.
	*/
	virtual bool IsClosed() = 0;

	/**
	* Create a viewport for this window.
	* @param config - xml config for creating the viewport.
	*/
	virtual std::weak_ptr<IViewport> CreateViewport(const pugi::xml_node& config) = 0;

	/**
	* @param viewportName The name of the viewport to retrieve.
	* @return weak_ptr to viewport.	
	*/
	virtual std::weak_ptr<IViewport> GetViewport(const std::string& viewportName) = 0;
};

}
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the GRAPHICS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// GRAPHICS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else
#define GRAPHICS_API __declspec(dllimport)
#endif

#include <memory>
#include <string>

namespace pugi
{
	class xml_node;
}

class IGameObjectComponentFactory;

namespace Graphics{

	class IWindowManager;
	class IScene;
	class IResourceManager;

	/**
	* Create a window manager based on the provided config.
	*/
	GRAPHICS_API std::shared_ptr<IWindowManager> CreateWindowManager(const pugi::xml_node& config);
	
	/**
	*Create a graphics scene.
	*@param type The type of scene to create.
	*@param config XML config defining parameters for the scene.
	*@param windowManager The window manager of the gameworld that created the scene.
	*/
	GRAPHICS_API std::shared_ptr<IScene> CreateScene(const std::string& type, const pugi::xml_node& config, std::weak_ptr<IWindowManager>& windowmanager);

}

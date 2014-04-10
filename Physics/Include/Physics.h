// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PHYSICS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PHYSICS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef PHYSICS_EXPORTS
#define PHYSICS_API __declspec(dllexport)
#else
#define PHYSICS_API __declspec(dllimport)
#endif

#include <memory>
#include <string>

namespace pugi
{
	class xml_node;
}

class IGameObjectComponentFactory;

namespace Physics{

	class IPhysicsSystem;

	PHYSICS_API std::shared_ptr<IPhysicsSystem> CreatePhysicsSystem(const std::string& type, const pugi::xml_node& config);
}
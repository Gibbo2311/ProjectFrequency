// Common.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Common.h"
#include "GameObject.h"
#include <memory>

namespace Common
{
	// This is an example of an exported function.
	COMMON_API std::shared_ptr<GameObject> CreateGameObject(void)
	{
		return std::make_shared<GameObject>();
	}
}

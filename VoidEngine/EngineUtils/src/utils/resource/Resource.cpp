//STD Headers

//Library Headers

//Void Engine Headers
#include "utils/resource/Resource.h"

namespace utils {
	///Public Functions
	Resource::Resource(const std::string& filePath) 
		: ResourceID(filePath), ResourcePath(filePath), IsInitialized(false), IsThreadSafe(false) {
		
		ResourceValid = std::filesystem::exists(ResourcePath);
		if (!ResourceValid) {
			utils::Logger::LogWarning("Resource located at [" + filePath + "] not found");
		}
	}

	Resource::~Resource() {

	}

	bool Resource::IsValid() {
		return ResourceValid;
	}

	bool Resource::GetIsInitialized() {
		return IsInitialized;
	}

	Name Resource::GetResourceID() {
		return ResourceID;
	}

}

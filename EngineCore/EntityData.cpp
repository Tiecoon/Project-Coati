//STD Headers

//Library Headers

//Void Engine Headers
#include "EntityData.h"


namespace core{
	EntityData::EntityData(const std::string& filepath) : utils::Resource(filepath){
		IsComposite = true;
	}

	bool EntityData::Load() {
		return false;
	}
	
	bool EntityData::LoadErrorResource() {
		return false;
	}

	void EntityData::LoadComposite(utils::ResourceManager* manager) {

	}
	
	void EntityData::Initialize() {
		;
	}


}

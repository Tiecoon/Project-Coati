#pragma once
//STD Headers
#include <atomic>
#include <string>
#include <filesystem>
#include <fstream>

//Library Headers

//Void Engine Headers
#include "utils/Name.h"
#include "utils/Logger.h"
#include "utils/threading/ThreadPool.h"

namespace utils {
	/**
	 * Resources are the objects handled by the resource manager.
	 */
	class Resource {
		//forward class declarations
		template <class T>
		friend class ResourceAllocator;

	public:
		/**
		 * Constructor
		 * @param filePath the resources location
		 */
		Resource(const std::string& filePath);
		
		/**
		 * Destructor
		 */
		virtual ~Resource();

		/**
		 * Loads a given resource from main memory
		 */
		virtual bool Load() = 0;

		/**
		 * Loads the resource's default value if the path provided is invalid
		 */
		virtual bool LoadErrorResource() = 0;

		/**
		 * Allows the resource to be intialized after loading.
		 */
		virtual void Initialize() = 0;

		/**
		 * Returns whether the resource is valid
		 */
		bool IsValid();

		/**
		 * Allows user to query if this resource has been initialized
		 */
		bool GetIsInitialized();

		/**
		 * Gets the resources' ID
		 */
		Name GetResourceID();

	protected:
		/** Unique identifier for resource lookup and comparison */
		Name ResourceID;

		/** Path to the desired resource */
		std::filesystem::path ResourcePath;

		/** Flag specifying if the resource was found in main memory */
		std::atomic<bool> ResourceValid;

		/** Variable to allow users to query if a resource has been initialized */
		bool IsInitialized;

		/** Let's Managing objects know whether this resource is can be initialized on other threads */
		bool IsThreadSafe;	
	};
}

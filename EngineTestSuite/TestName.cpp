//STD Headers

//Library Headers
#include "CppUnitTest.h"

//Void Engine Headers
#include "Name.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace EngineUtils;

namespace EngineUtilitiesTests {

	TEST_CLASS(NameTests) {
		public:

		TEST_METHOD(NameConstructorTest) {
			Name id("Test");

			Assert::AreEqual(EngineUtils::FNV1aHash("Test"), id.ID);
			Assert::AreEqual(std::string("Test"), id.StringID);
		}

		TEST_METHOD(NameAssignmentTest) {
			Name id("Test");
			auto hash = id.ID;

			//String re-assignment test
			id = "Bar";
			Assert::AreEqual(std::string("Bar"), id.StringID);
			Assert::AreNotEqual(hash, id.ID);

			//Name re-assignment test
			Name id2("Foo");
			id = id2;
			Assert::AreEqual(id2.ID, id.ID);
			Assert::AreEqual(id2.StringID, id.StringID);
		}

		TEST_METHOD(NameComparisonTest) {
			Name idA("Foo");
			Name idB("Bar");
			Name idC("Foo");

			Assert::IsTrue(idA != idB);
			Assert::IsTrue(idA == idC);
			Assert::IsTrue(idA == "Foo");
			Assert::IsTrue("Foo" == idA);

			// Relational operators are available but untested
		}
	};
};
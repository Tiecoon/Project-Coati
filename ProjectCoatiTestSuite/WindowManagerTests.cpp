#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Source/WindowManager.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProjectCoatiTestSuite
{		
	TEST_CLASS(WindowManagerTests) {
	public:
		
		TEST_METHOD(WindowCreationTest) {
			WindowManager test("Test");

			Assert::IsNotNull(test.getWindow().get());
		}
		TEST_METHOD(BufferSwapTest) {
			WindowManager test("Test");
			test.SwapBuffers();
			Assert::AreEqual(1, 1);
		}
	};
}
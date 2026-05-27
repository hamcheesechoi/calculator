#include "gmock/gmock.h"
//OpenCppCoverage.exe --sources C:*.cpp --export_type=html:coverage -- .\x64\Debug\ALU.exe
int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
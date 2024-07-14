#include "Data.h"

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TextTestResult.h>

class DataTest : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(DataTest);
	CPPUNIT_TEST(testWrite);
	CPPUNIT_TEST(testRead);
	CPPUNIT_TEST_SUITE_END();

public:
	void testWrite() {
		OutputStream outputStream("./test.bin");

		outputStream.writeInt(10);
	}

	void testRead() {
		InputStream inputStream("./test.bin");

		std::uint32_t i = inputStream.readInt();
		std::cout << i << std::endl;
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION(DataTest);

int main() {
	CppUnit::TextTestRunner runner;
	runner.addTest(DataTest::suite());
	runner.run();
	return 0;
}
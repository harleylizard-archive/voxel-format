#include "Data.h"
#include "Model.h"

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

		auto i = inputStream.readInt();
		std::cout << i << std::endl;
	}
};

class ModelTest : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(ModelTest);
	CPPUNIT_TEST(testWriteModel);
	CPPUNIT_TEST(testReadModel);
	CPPUNIT_TEST_SUITE_END();

public:
	void testWriteModel() {
		MutableModel model;
		model.set(0, 14, 0, 10);
		model.writeTo("./model.bin");
	}

	void testReadModel() {
		Model model = readFrom("./model.bin");

		auto i = model.get(0, 14, 0);
		std::cout << i << std::endl;
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION(DataTest);
CPPUNIT_TEST_SUITE_REGISTRATION(ModelTest);

int main() {
	CppUnit::TextTestRunner runner;
	runner.addTest(DataTest::suite());
	runner.addTest(ModelTest::suite());
	runner.run();
	return 0;
}
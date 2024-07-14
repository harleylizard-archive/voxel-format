#include "Data.h"

InputStream::InputStream(const std::string& path) : iStream(std::ifstream(path)) {
}

InputStream::~InputStream() {
	iStream.close();
}

const std::uint32_t InputStream::readInt() {
	std::uint32_t i;
	iStream.read(reinterpret_cast<char*>(&i), sizeof(i));
	return i;
}

OutputStream::OutputStream(const std::string& path) : oStream(std::ofstream(path)) {
}

OutputStream::~OutputStream() {
	oStream.close();
}

void OutputStream::writeInt(std::uint32_t i) {
	oStream.write(reinterpret_cast<const char*>(&i), sizeof(i));
}

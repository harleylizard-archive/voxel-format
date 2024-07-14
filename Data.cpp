#include "Data.h"

InputStream::InputStream(const std::string& path) : iStream(std::ifstream(path, std::ios::binary)) {
}

InputStream::~InputStream() {
	iStream.close();
}

const std::uint8_t InputStream::readByte() {
	std::uint8_t b;
	iStream.read(reinterpret_cast<char*>(&b), sizeof(b));
	return b;
}

const std::uint32_t InputStream::readInt() {
	std::uint32_t i;
	iStream.read(reinterpret_cast<char*>(&i), sizeof(i));
	return i;
}

OutputStream::OutputStream(const std::string& path) : oStream(std::ofstream(path, std::ios::binary)) {
}

OutputStream::~OutputStream() {
	oStream.close();
}

void OutputStream::writeByte(std::uint8_t b) {
	oStream.write(reinterpret_cast<const char*>(&b), sizeof(b));
}

void OutputStream::writeInt(std::uint32_t i) {
	oStream.write(reinterpret_cast<const char*>(&i), sizeof(i));
}

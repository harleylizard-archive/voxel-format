#pragma once

#include <cstdint>
#include <string>
#include <fstream>

class InputStream final {
public:
	InputStream(const std::string& path);

	~InputStream();

	const std::uint32_t readInt();

private:
	std::ifstream iStream;
};

class OutputStream final {
public:
	OutputStream(const std::string& path);

	~OutputStream();

	void writeInt(std::uint32_t i);
	
private:
	std::ofstream oStream;
};
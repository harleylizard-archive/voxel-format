#pragma once

#include <array>
#include <cstdint>
#include <string>
#include <memory>

constexpr std::uint32_t SIZE = 16 * 16 * 16;
constexpr std::uint16_t COMPACT_SIZE = 8 * 8 * 8;

class Model final {
public:
	Model(const std::array<std::uint32_t, SIZE>& array);

	const std::uint32_t get(int x, int y, int z);

private:
	const std::array<std::uint32_t, SIZE> voxels;
};

class MutableModel final {
public:
	MutableModel();

	void set(int x, int y, int z, std::uint32_t i);

	void writeTo(const std::string& path);
private:
	std::array<std::uint32_t, SIZE> voxels;
};

std::size_t indexOf(int x, int y, int z);

std::uint8_t toBit(std::uint32_t& i);

const Model readFrom(const std::string& path);
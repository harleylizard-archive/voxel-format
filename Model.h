#pragma once

#include <array>
#include <cstdint>
#include <string>
#include <memory>

constexpr std::uint32_t SIZE = 16 * 16 * 16;
constexpr std::uint16_t COMPACT_SIZE = 8 * 8 * 8;

constexpr std::size_t indexOf(int x, int y, int z);

constexpr std::uint8_t bit(std::uint32_t& i);

using Voxels = std::array<std::uint32_t, SIZE>;

class Model final {
public:
	Model(const std::string& path);

	std::uint32_t get(int x, int y, int z) const;

private:
	std::unique_ptr<Voxels> voxels;
};

class MutableModel final {
public:
	MutableModel();

	void set(int x, int y, int z, std::uint32_t i);

	void writeTo(const std::string& path);
private:
	std::unique_ptr<Voxels> voxels;
};
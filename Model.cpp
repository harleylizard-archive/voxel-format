#include "Model.h"
#include "Data.h"

constexpr std::size_t indexOf(int x, int y, int z) {
    return x + y * 16 + z * 16 * 16;
}

constexpr std::uint8_t bit(std::uint32_t& i) {
    return i > 0 ? 1 : 0;
}

 Model::Model(const std::string& path) {
     Voxels array{};

     InputStream inputStream(path);
     for (auto i = 0; i < COMPACT_SIZE; i++) {
         auto compacted = inputStream.readByte();

         auto j = i << 2;
         array[j] = (compacted >> 6) & 1;
         array[j + 1] = (compacted >> 4) & 1;
         array[j + 2] = (compacted >> 2) & 1;
         array[j + 3] = compacted & 1;
     }
     this->voxels = std::make_unique<Voxels>(array);
 }

 std::uint32_t Model::get(int x, int y, int z) const {
     return (*voxels)[indexOf(x & 0x0F, y & 0x0F, z & 0x0F)];
}

 MutableModel::MutableModel() : voxels(std::make_unique<Voxels>()) {
}

void MutableModel::set(int x, int y, int z, std::uint32_t i) {
    (*voxels)[indexOf(x & 0x0F, y & 0x0F, z & 0x0F)] = i;
}

void MutableModel::writeTo(const std::string& path) {
    OutputStream outputStream(path);

    for (auto i = 0; i < COMPACT_SIZE; i++) {
        auto j = i << 2;
        auto x = bit((*voxels)[j]);
        auto y = bit((*voxels)[j + 1]);
        auto z = bit((*voxels)[j + 2]);
        auto w = bit((*voxels)[j + 3]);

        auto compacted = ((x << 6) | (y << 4) | (z << 2) | w);
        outputStream.writeByte(compacted);
    }
}

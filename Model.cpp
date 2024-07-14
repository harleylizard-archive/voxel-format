#include "Model.h"
#include "Data.h"

std::size_t indexOf(int x, int y, int z) {
    return x + y * 16 + z * 16 * 16;
}

std::uint8_t toBit(std::uint32_t& i) {
    return i > 0 ? 1 : 0;
}

 const Model readFrom(const std::string& path) {
     InputStream inputStream(path);

     std::array<std::uint32_t, SIZE> array{};
     for (std::uint16_t i = 0; i < COMPACT_SIZE; i++) {
         auto compacted = inputStream.readByte();
         
         auto j = i << 2;
         array[j] = (compacted >> 6) & 1;
         array[j + 1] = (compacted >> 4) & 1;
         array[j + 2] = (compacted >> 2) & 1;
         array[j + 3] = compacted & 1;
     }
     return Model(array);
}

 Model::Model(const std::array<std::uint32_t, SIZE>& array) : voxels(array) {
 }

 const std::uint32_t Model::get(int x, int y, int z) {
    return voxels[indexOf(x & 0x0F, y & 0x0F, z & 0x0F)];
}

 MutableModel::MutableModel() : voxels(std::array<std::uint32_t, SIZE>{}) {
}

void MutableModel::set(int x, int y, int z, std::uint32_t i) {
    voxels[indexOf(x & 0x0F, y & 0x0F, z & 0x0F)] = i;
}

void MutableModel::writeTo(const std::string& path) {
    OutputStream outputStream(path);

    for (auto i = 0; i < COMPACT_SIZE; i++) {
        auto j = i << 2;
        auto x = toBit(voxels[j]);
        auto y = toBit(voxels[j + 1]);
        auto z = toBit(voxels[j + 2]);
        auto w = toBit(voxels[j + 3]);

        auto compacted = ((x << 6) | (y << 4) | (z << 2) | w);
        outputStream.writeByte(compacted);
    }
}

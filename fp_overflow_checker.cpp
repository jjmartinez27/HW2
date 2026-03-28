#include <iostream>
#include <cstring>
#include <cstdint>
#include <string>
#include <bitset>

uint32_t FloatToBits(float value) {
    uint32_t bits = 0;
    std::memcpy(&bits, &value, sizeof(float));
    return bits;
}

std::string FormatBits(float value) {
    std::bitset<32> bits(FloatToBits(value));
    return bits.to_string();
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << std::endl;
        std::cout << "Please include 2 command line arguments" << std::endl;
        std::cout << "1: Loop bound, a positive floating-point value" << std::endl;
        std::cout << "2: Loop counter, a positive floating-point value" << std::endl;
        return 1;
    }

    float loop_bound = std::stof(argv[1]);
    float loop_counter = std::stof(argv[2]);

    std::cout << "Loop bound bits: " << FormatBits(loop_bound) << std::endl;
    std::cout << "Loop counter bits: " << FormatBits(loop_counter) << std::endl;


    return 0;
}
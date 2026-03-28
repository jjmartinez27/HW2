#include <iostream>
#include <cstring>
#include <cstdint>
#include <string>

uint32_t FloatToBits(float value) {
    uint32_t bits = 0;
    std::memcpy(&bits, &value, sizeof(float));
    return bits;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << std::endl;
        std::cout << "loop bound is a positive floating-point value" << std::endl;
        std::cout << "loop counter is a positive floating-point value" << std::endl;
        return 1;
    }

    float loop_bound = std::stof(argv[1]);
    float loop_counter = std::stof(argv[2]);

    std::cout << "Loop bound raw bits: " << FloatToBits(loop_bound) << std::endl;
    std::cout << "Loop counter raw bits: " << FloatToBits(loop_counter) << std::endl;


    return 0;
}
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

float BitsToFloat(uint32_t bits) {
    float value = 0.0f;
    std::memcpy(&value, &bits, sizeof(float));
    return value;
}

std::string FormatBits(float value) {
    std::bitset<32> bits(FloatToBits(value));
    std::string s = bits.to_string();
    return s.substr(0, 1) + " " + s.substr(1, 8) + " " + s.substr(9, 23);
}

int GetExponentBits(float value) {
    uint32_t bits = FloatToBits(value);
    return static_cast<int>((bits >> 23) & 0xFF);
}

int GetUnbiasedExponent(float value) {
    return GetExponentBits(value) - 127;
}

float ComputeThreshold(float increment) {
    int increment_exp = GetUnbiasedExponent(increment);
    int threshold_exp = increment_exp + 24;

    uint32_t threshold_bits =
        static_cast<uint32_t>(threshold_exp + 127) << 23;

    return BitsToFloat(threshold_bits);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "usage: ./fp_overflow_checker loop_bound loop_counter" << std::endl;
        std::cout << std::endl;
        std::cout << "    loop_bound is a positive floating-point value" << std::endl;
        std::cout << "    loop_counter is a positive floating-point value" << std::endl;
        return 1;
    }

    float loop_bound = std::stof(argv[1]);
    float loop_counter = std::stof(argv[2]);
    std::cout << std::endl;
    std::cout << "Loop bound:   " << FormatBits(loop_bound) << std::endl;
    std::cout << "Loop counter: " << FormatBits(loop_counter) << std::endl;
    std::cout << std::endl;

    float threshold = ComputeThreshold(loop_counter);

    if (loop_bound >= threshold) {
        std::cout << "Warning: Possible overflow!" << std::endl;
        std::cout << "Overflow threshold:" << std::endl;
        std::cout << threshold << std::endl;
        std::cout << FormatBits(threshold) << std::endl;
    } else {
        std::cout << "There is no overflow!" << std::endl;
    }

    return 0;
}
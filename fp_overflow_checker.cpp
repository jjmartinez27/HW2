#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << std::endl;
        std::cout << "loop bound is a positive floating-point value" << std::endl;
        std::cout << "loop counter is a positive floating-point value" << std::endl;
        return 1;
    }

    float loop_bound = std::stof(argv[1]);
    float loop_counter = std::stof(argv[2]);

    std::cout << "Loop bound value: " << loop_bound << std::endl;
    std::cout << "Loop counter value: " << loop_counter << std::endl;


    return 0;
}
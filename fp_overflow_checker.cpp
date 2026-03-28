#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << std::endl;
        std::cout << "loop bound is a positive floating-point value" << std::endl;
        std::cout << "loop counter is a positive floating-point value" << std::endl;
        return 1;
    }

    return 0;
}
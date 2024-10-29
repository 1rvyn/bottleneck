#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <chrono>
#include <ranges>
#include <charconv>

int main() {
    using namespace std::chrono_literals;
    const auto start = std::chrono::steady_clock::now();
    
    std::ifstream file("../input.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file\n";
        return 1;
    }

    std::string line;

    while (std::getline(file, line)) {
        std::cout << line << '\n';
    }

    const auto end = std::chrono::steady_clock::now();
    const auto duration = std::chrono::duration<double>(end - start);

    std::cout << "Time taken: " << duration.count() << " seconds\n";

    return 0;
} 
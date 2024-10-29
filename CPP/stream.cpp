#include <iostream>
#include <fstream>
#include <chrono>

int main() {
    auto start = std::chrono::steady_clock::now();
    
    std::ifstream infile("../input.txt", std::ios::in | std::ios::binary);
    if (!infile.is_open()) {
        std::cerr << "Error opening input file\n";
        return 1;
    }

    std::ofstream outfile("stream_output_cpp.txt", std::ios::out | std::ios::binary);
    if (!outfile.is_open()) {
        std::cerr << "Error creating output file\n";
        return 1;
    }

    char ch;
    while (infile.get(ch)) {
        outfile.put(ch);
    }

    infile.close();
    outfile.close();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Stream I/O Time taken: " << duration.count() << " seconds\n";
    return 0;
} 
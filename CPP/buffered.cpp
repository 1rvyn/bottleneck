#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

int main() {
    auto start = std::chrono::steady_clock::now();
    
    std::ifstream infile("../input.txt");
    if (!infile.is_open()) {
        std::cerr << "Error opening input file\n";
        return 1;
    }

    std::ofstream outfile("buffered_output_cpp.txt");
    if (!outfile.is_open()) {
        std::cerr << "Error creating output file\n";
        return 1;
    }

    std::string line;
    while (std::getline(infile, line)) {
        outfile << line << '\n';
    }

    infile.close();
    outfile.close();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Buffered I/O Time taken: " << duration.count() << " seconds\n";
    return 0;
} 
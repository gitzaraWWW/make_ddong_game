#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream infile("background.txt");
    if (!infile) {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::cout << line << std::endl;
    }

    infile.close();
    return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <regex>

int main() {
    std::string inputFileName = "input.txt"; // имя входного файла
    std::string outputFileName = "output.txt"; // имя выходного файла
    std::string replacementWord = "Alice"; // ваше имя для замены

    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);

    if (inputFile.is_open() && outputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string word;
            std::string longestWord;
            size_t maxLength = 0;

            while (iss >> word) {
                if (word.length() > maxLength) {
                    maxLength = word.length();
                    longestWord = word;
                }
            }

            if (!longestWord.empty()) {
                std::regex reg("\\b" + longestWord + "\\b");
                line = std::regex_replace(line, reg, replacementWord);
            }

            outputFile << line << '\n';
        }

        inputFile.close();
        outputFile.close();
        std::cout << "Замена выполнена успешно. Проверьте файл " << outputFileName << std::endl;
    } else {
        std::cerr << "Не удалось открыть файлы." << std::endl;
    }

    return 0;
}

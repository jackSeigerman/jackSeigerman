#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void replaceTextInFile(const std::string& filePath, const std::string& oldText, const std::string& newText) {
    // Open the input file for reading
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Error opening file for reading: " << filePath << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << inFile.rdbuf();
    std::string fileContent = buffer.str();
    inFile.close();

    // Replace occurrences of oldText with newText
    size_t pos = 0;
    while ((pos = fileContent.find(oldText, pos)) != std::string::npos) {
        fileContent.replace(pos, oldText.length(), newText);
        pos += newText.length();  // Move past the replaced text
    }

    // Open the file for writing and save the changes
    std::ofstream outFile(filePath);
    if (!outFile) {
        std::cerr << "Error opening file for writing: " << filePath << std::endl;
        return;
    }

    outFile << fileContent;
    outFile.close();
}

int main() {
    std::string filePath = "example.txt";  // Specify the file path
    std::string oldText = "old_word";      // Text to replace
    std::string newText = "new_word";      // Replacement text

    replaceTextInFile(filePath, oldText, newText);

    std::cout << "Text replacement complete!" << std::endl;

    return 0;
}

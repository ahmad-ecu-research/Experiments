#include <iostream>

// input validation for alphanumeric characters
void readAlphanumericInput() {
    std::string input;
    std::cout << "Enter some alphanumeric text: ";
    std::getline(std::cin, input);
    for (char c : input) {
        if (!isalnum(c)) {
            std::cout << "Invalid input. Only alphanumeric characters are allowed." << std::endl;
            return;
        }
    }
    std::cout << "You entered: " << input << std::endl;
}
void readInput() {
    std::string input;
    std::cout << "Enter some text: ";
    std::getline(std::cin, input);
    std::cout << "You entered: " << input << std::endl;
}
void readInput() {
    char buffer[100];
    std::cout << "Enter some text: ";
    std::cin >> buffer;
    std::cout << "You entered: " << buffer << std::endl;
}

int main() {
    readInput();
    return 0;
}
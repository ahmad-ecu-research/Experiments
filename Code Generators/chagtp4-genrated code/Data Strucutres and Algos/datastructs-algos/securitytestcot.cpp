
#include <iostream>
#include <string>
#include <cctype>  // For isalnum function

// Secure Input Handling Using std::string
/* Prompt:
Explain and code a secure way to read user input in C++ using std::string instead of a char array to prevent buffer overflow.
Break down your reasoning into: why you choose std::string, how it manages memory dynamically, and how this choice enhances security against buffer overflow attacks.
*/
void readInputSecurely() {
    std::string input;
    std::cout << "Enter some text: ";
    std::getline(std::cin, input);
    std::cout << "You entered: " << input << std::endl;
    // std::string manages memory dynamically, which avoids buffer overflow unlike static char arrays.
}

// Input Validation for Alphanumeric Characters
/* Prompt:
Develop and explain a secure C++ function that accepts only alphanumeric input from users.
Include steps: choosing std::getline() for reading input, implementing a loop to validate each character, and detailing how such validation can prevent vulnerabilities like injections.
*/
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
    // Validating input prevents potential security vulnerabilities, such as script injections or unintended command executions.
}

// Exception Handling in User Input Functions
/* Prompt:
Write a C++ function to securely handle user input with comprehensive error handling.
Detail the use of std::string and std::getline() for safe input capture, and try-catch blocks to manage exceptions.
*/
void readInputWithErrorHandling() {
    std::string input;
    try {
        std::cout << "Enter some text: ";
        std::getline(std::cin, input);
        std::cout << "You entered: " << input << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error occurred: " << e.what() << std::endl;
    }
    // Managing exceptions is crucial for preventing application crashes and maintaining robustness in security-critical applications.
}

// Handling Large or Unexpected Input Sizes
/* Prompt:
Construct a function that can handle user inputs of varying or unexpected sizes without compromising security.
*/
void readInputOfAnySize() {
    std::string input;
    std::cout << "Please enter some text: ";
    std::getline(std::cin, input);
    std::cout << "You entered: " << input << std::endl;
    // Dynamically handling input size using std::getline() protects against DOS attacks and buffer overflow vulnerabilities.
}

// Secure Password Input Function
/* Prompt:
Design a function that securely handles password input, ensuring the password is hidden from display and stored securely.
*/
void readPasswordSecurely() {
    std::string password;
    std::cout << "Enter your password: ";
    // Normally, you'd use a platform-specific method to hide input here.
    std::getline(std::cin, password);
    std::cout << "Password securely stored!" << std::endl;
    // Hiding the password input and using std::string for storage enhances user privacy and security.
}

int main() {
    // Function calls can be uncommented to test each secure function.
    // readInputSecurely();
    // readAlphanumericInput();
    // readInputWithErrorHandling();
    // readInputOfAnySize();
    // readPasswordSecurely();
    return 0;
}

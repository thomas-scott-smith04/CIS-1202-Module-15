// Thomas Smith
// CIS 1202 N01
// December 8, 2024

#include <iostream>
#include <stdexcept>
#include <cctype>

using namespace std;

// Custom exceptions
class invalidCharacterException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid character input. Must be a letter (A-Z, a-z).";
    }
};

class invalidRangeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid range. Resulting character is not a valid letter.";
    }
};

// Function to calculate character offsets
char character(char start, int offset) {
    if (!isalpha(start)) { // Check if the input character is a letter
        throw invalidCharacterException();
    }

    char result = start + offset; // Calculate the offset

    // Check if the resulting character stays within the same case
    if ((islower(start) && !islower(result)) ||
        (isupper(start) && !isupper(result))) {
        throw invalidRangeException();
    }

    return result;
}

// Main function to test the character function
int main() {
    try {
        cout << "character('a', 1): " << character('a', 1) << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "character('a', -1): " << character('a', -1) << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "character('Z', -1): " << character('Z', -1) << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "character('?', 5): " << character('?', 5) << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "character('A', 32): " << character('A', 32) << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

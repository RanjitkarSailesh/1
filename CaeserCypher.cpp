#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;


// Array: Global constant for the alphabet
const string alphabet = "abcdefghijklmnopqrstuvwxyz";

// Function to encrypt text using a Caesar cipher
string encrypt(string text, int shift) {
    string result = "";
    for (char c : text) {
        // Control: Check if the character is an alphabet letter
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            size_t index = alphabet.find(tolower(c));
            // Control: Encrypt using the Caesar cipher formula
            result += alphabet[(index + shift) % 26] + (base - 'a');
        } else if (isdigit(c)) {
            // Control: Encrypt numbers by shifting them
            result += (c - '0' + shift) % 10 + '0';
        } else {
            // Control: Keep non-alphabetic/non-numeric characters unchanged
            result += c;
        }
    }
    return result;
}

// Function to decrypt text using a Caesar cipher
string decrypt(string text, int shift) {
    string result = "";
    for (char c : text) {
        // Control: Check if the character is an alphabet letter
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            size_t index = alphabet.find(tolower(c));
            // Control: Decrypt using the Caesar cipher formula
            result += alphabet[(index - shift + 26) % 26] + (base - 'a');
        } else if (isdigit(c)) {
            // Control: Decrypt numbers by shifting them
            result += (c - '0' - shift + 10) % 10 + '0';
        } else {
            // Control: Keep non-alphabetic/non-numeric characters unchanged
            result += c;
        }
    }
    return result;
}

// Function to display encrypted and decrypted text
void displayText(const string& encryptedText, const string& decryptedText) {
    // I/O: Display encrypted and decrypted text
    cout << "Encrypted Text: " << encryptedText << endl;
    cout << "Decrypted Text: " << decryptedText << endl;
}

int main() {
    string choice;

    // Iteration: Repeat until the user chooses to quit
    do {
        // I/O: Display menu and get user's choice
        cout << "Do you want to (E)ncrypt, (D)ecrypt, (Q)uit or (C)lear? (E/D/Q/C to quit): ";
        cin >> choice;
        for (char &c : choice) {
            // I/O: Convert choice to lowercase for case-insensitive comparison
            c = tolower(c);
        }

        if (choice == "e") {
            // I/O: Prompt user for input text and shift value
            // Variable: Declare and read the input variable "plaintext" and "shift value"
            cout << "Enter the text to encrypt: ";
            string plaintext;
            cin.ignore();
            getline(cin, plaintext);
            int shift;
            cout << "Enter the shift value: ";
            cin >> shift;
            cin.ignore();

            // Control: Encrypt the input text
            string encryptedText = encrypt(plaintext, shift);
            string decryptedText = decrypt(encryptedText, shift);

            // File I/O: Open "e.txt" and append encrypted text
            ofstream outFile("e.txt", ios::out | ios::app);
            outFile << encryptedText << endl;
            outFile.close();

            // I/O: Display encryption completion message and results
            cout << "Encryption complete. Encrypted text appended to e.txt." << endl;
            displayText(encryptedText, decryptedText);
        } else if (choice == "d") {
            // I/O: Prompt user for input text and shift value
            // Variable: Declare and read the input variable "plaintext" and "shift value"
            cout << "Enter the text to decrypt: ";
            string ciphertext;
            cin.ignore();
            getline(cin, ciphertext);
            int shift;
            cout << "Enter the shift value: ";
            cin >> shift;
            cin.ignore();

            // Control: Decrypt the input text
            string decryptedText = decrypt(ciphertext, shift);
            string encryptedText = encrypt(decryptedText, shift);

            // File I/O: Open "d.txt" and append decrypted text
            ofstream outFile("d.txt", ios::out | ios::app);
            outFile << decryptedText << endl;
            outFile.close();

            // I/O: Display decryption completion message and results
            cout << "Decryption complete. Decrypted text appended to d.txt." << endl;
            displayText(encryptedText, decryptedText);
        } else if (choice == "q") {
            // Control: Break out of the loop if the user chooses to quit
            break;
        } else if (choice == "c") {
            // Control: Clear the screen (platform-dependent)
            system("cls");
        } else {
            // I/O: Display an error message for invalid choices
            cout << "Invalid choice. Please enter 'E' to encrypt, 'D' to decrypt, or 'Q' to quit." << endl;
        }

    } while (true);

    // I/O: Display the end of the program
    cout << "Program terminated." << endl;

    return 0;
}

// Name: Dylan Sullins
// Program 6: Conversions
/*
start loop
{
    Print the menu
    Handle user choice
        Choice A:
            Get input and base from user
            Convert input from given base to decimal
        Choice B:
            Get input and base from user
            Convert input from decimal to given base
        Choice C:
            Get input, base1, and base2 from user
            Convert input from base1 to decimal
            Convert input from decimal to base2
        Choice Q:
            Exit loop
        Choice (OTHER):
            Display invalid choice
} 
End Loop
Say Goodbye
*/

#include <iostream>
#include <sstream>
#include <string>
#include <bits/stdc++.h> // To allow use of transform to convert string to uppercase for base > 10

//FUNCTION DECLARATIONS
bool isDigits(std::string inStr, int base);
//PRE:  string is input to the function
//POST:  return true if nothing other than a digit is found

std::string decToBase(const std::string& inVal, int base);
//PRE: input string is sent to function
//POST: if valid, return a string that is the equivalent value in the base given 

int baseToDec(const std::string& inVal, int base);
//PRE: input string is sent to function
//POST: if valid, return the decimal value of the binary string 

std::string baseToBase(const std::string& inVal, int base1, int base2);
//PRE: input string, base 1, and base2 sent to function
//POST: if valid, converts from base1 -> decimal -> base2

void runLoop();
//PRE: none
//POST: Prints menu and handles user input as choice


int main() {
    runLoop();
    return 0;
}

//FUNCTION DEFINITIONS
bool isDigits(std::string inStr, int base) {
    /*
    Initialize allowedChars, truncate length based on base (up to base 16)
    Compare letters in string to ensure that only those in allowedChars are used
    */
    std::string allowedChars = "0123456789ABCDEF";                              // Allowed characters up to base 16
    allowedChars = allowedChars.substr(0,base);                                 // Truncates allowedChars based on base
    std::transform(inStr.begin(), inStr.end(), inStr.begin(), ::toupper);       // Converting input string to uppercase to test against allowedChars
    return (inStr.find_first_not_of(allowedChars) == std::string::npos);
}

std::string decToBase(const std::string& inVal, int base) {
    /*
    IF (isDigits(inVal) && base >= 2 and base <=16) {
        set inVal to integer type
        outVal = “”
        decVal = inVal string converted to decimal
        WHILE (decVal > 0)
            tempVal = decValue % base
            if (tempVal == 10)      outVal = 'A' + outVal
            else if (tempVal == 11) outVal = 'B' + outVal 
            :
            else outVal = char(tempVal) + outVal
            decVal = decVal/base
        ENDWHILE
        RETURN output
    ELSE
        PRINT error
    ENDIF
    */
    std::string outVal = "";
    int tempVal;
    if (isDigits(inVal, 10) && base >= 2 && base <= 16) { // Ensures inVal is numeric and base is between 2-16 inclusive
        int decVal = std::stoi(inVal);                    // Convert inVal to integer
        while (decVal > 0) {                              // Start loop
            tempVal = decVal % base;                      // Get remainder
            switch (tempVal) {                            // Adds char to front of outVal string based on tempVal
                case 15:
                    outVal = 'F' + outVal;
                    break;
                case 14:
                    outVal = 'E' + outVal;
                    break;
                case 13:
                    outVal = 'D' + outVal;
                    break;
                case 12:
                    outVal = 'C' + outVal;
                    break;
                case 11:
                    outVal = 'B' + outVal;
                    break;
                case 10:
                    outVal = 'A' + outVal;
                    break;
                default:                                 // Less than 10, add string of value to front of string
                    outVal = std::to_string(tempVal) + outVal;
            }
            //std::cout << outVal << std::endl;
            decVal /= base;
        }
        return outVal;
    } else {
        std::cout << "Invalid input " << inVal << std::endl;
        return "";
    }
}

int baseToDec(const std::string& inVal, int base) {
    if (isDigits(inVal, base)) { // Ensures inVal is numeric (including A-F depending on base)
        char digit;
        int outVal = 0;
        int placeValue = 1;
        for (int i = inVal.size() - 1; i >= 0; i--) { // Counting from the end of the string
            digit = inVal.at(i);                      // Current digit is character at i
            switch (digit) {                          // Calculates based on value of digit
                case 'f':                             // Allows for lowercase or uppercase
                case 'F':
                    outVal += 15 * placeValue;
                    break;
                case 'e':
                case 'E':
                    outVal += 14 * placeValue;
                    break;
                case 'd':
                case 'D':
                    outVal += 13 * placeValue;
                    break;
                case 'c':
                case 'C':
                    outVal += 12 * placeValue;
                    break;
                case 'b':
                case 'B':
                    outVal += 11 * placeValue;
                    break;
                case 'a':
                case 'A':
                    outVal += 10 * placeValue;
                    break;
                default:                                                    // If digit is numeric
                    outVal += (static_cast<int>(digit) - 48) * placeValue;  // Convert char to int, multiply by placeValue
            }
            placeValue *= base; // Incrementally multiply placeValue for each place in inVal
        }
        
        return outVal;
    } else {
        std::cout << "Invalid input " << inVal << std::endl;
        return -1;
    }
}


std::string baseToBase(const std::string& inVal, int base1, int base2) {
    /*
    Convert base1 inVal to decimal
    Convert decimal to base2 result
    */
    std::string decVal;
    std::string result = "";
    decVal = std::to_string(baseToDec(inVal, base1)); // base1 to decimal
    if (decVal != "-1"){
        result = decToBase(decVal, base2);                // decimal to base2
    }
    return result;

}

void printMenu() {
    std::cout << "Please enter what you would like to do:" << std::endl;
    std::cout << "\tA: Convert a number to decimal (enter a value & given base)" << std::endl;
    std::cout << "\tB: Convert a decimal to another base (enter a decimal value and a base)" << std::endl;
    std::cout << "\tC: Convert a number from base1 to base2 (enter number, base1, and base2)" << std::endl;
    std::cout << "\tQ: QUIT" << std::endl;
    std::cout << ">>> ";
}

// Main Loop Function
void runLoop() {
    // Handles Menu Functionality and User Input
    int output, base1, base2;
    std::string inputString, outputString;
    char menuChoice;
    printMenu();
    std::cin >> menuChoice;
    while (menuChoice != 'q' && menuChoice != 'Q') {
        switch (menuChoice) {
            case 'a':
            case 'A':
                // Convert a number to decimal
                // Get value and base
                std::cout << "Enter your input value: ";
                std::cin >> inputString;
                std::cout << "Enter given base value: ";
                std::cin >> base1;
                std::cout << std::endl;

                output = baseToDec(inputString, base1);
                if (output != -1) { // If the inputString was valid
                    std::cout << "The value " << inputString << " in base " << base1 << " is " << output << " in decimal." << std::endl;
                }
                break;
            case 'b':
            case 'B':
                // Convert a decimal to another base
                // Get value and base
                std::cout << "Enter your decimal value: ";
                std::cin >> inputString;
                std::cout << "Enter resulting base value: ";
                std::cin >> base1;
                std::cout << std::endl;

                outputString = decToBase(inputString, base1);
                if (outputString != "") { // If the inputString was valid
                    std::cout << "The decimal value " << inputString << " is " << outputString << " in base " << base1 << std::endl;
                }
                break;
            case 'c':
            case 'C':
                // Convert a number from base1 to base2
                // Get value, base of value (base1), and base to convert to (base2)
                std::cout << "Enter your input value: ";
                std::cin >> inputString;
                std::cout << "Enter original base: ";
                std::cin >> base1;
                std::cout << "Enter output base: ";
                std::cin >> base2;
                std::cout << std::endl;

                outputString = baseToBase(inputString, base1, base2);
                if (outputString != "") { // If the inputString was valid
                    std::cout << "The value " << inputString << " is " << outputString << " in base " << base2 << std::endl;
                }
                break;
            default:
                // Invalid menu choice
                std::cout << "Invalid Choice";
        }
        std::cout << std::endl;
        printMenu();
        std::cin >> menuChoice;
    }
    std::cout << "Goodbye! ";
}
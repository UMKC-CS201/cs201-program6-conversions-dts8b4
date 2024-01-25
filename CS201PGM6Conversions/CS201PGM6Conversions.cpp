// CS201PGM6Conversions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>

//FUNCTION DECLARATIONS
bool isDigits(std::string inStr);
//PRE:  string is input to the function
//POST:  return true if nothing other than a digit is found{

std::string decToBin(const std::string& inVal);
//PRE: input string is sent to function
//POST: if valid, return a string that is the binary equivalent

std::string decToBase(const std::string& inVal, int base);
//PRE: input string is sent to function
//POST: if valid, return a string that is the equivalent value in the base given 

int bintoDec(const std::string& inVal, int base);
//PRE: input string is sent to function
//POST: if valid, return the decimal value of the binary string 


int main() {
    std::string input;
    std::cout << "Enter a decimal number: ";
    std::cin >> input;

    std::string binaryResult = decToBin(input);

    std::cout << "Output: " << binaryResult << std::endl;

    return 0;
}

//FUNCTION DEFINITIONS
bool isDigits(std::string inStr) {
    return (inStr.find_first_not_of("0123456789") == std::string::npos);
}

std::string decToBin(const std::string& inVal) {
    std::string outVal = "";
    /*
    IF (isDigits(inVal)) {
        set inVal to integer type
        outVal = “”
        decVal = inVal string converted to decimal
        WHILE (decVal > 0)
            tempVal = decValue % 2
            outVal = char(tempVal) + outVal
            decVal = decVal/2
        ENDWHILE
        PRINT output
    ELSE
        PRINT error
    ENDIF
    */
    if (isDigits(inVal)) {
        int decVal = stoi(inVal);
        
    }
    return outVal;
}

std::string decToBase(const std::string& inVal, int base) {
    std::string outVal = "";
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
        PRINT output
    ELSE
        PRINT error
    ENDIF
    */
    return outVal;
}

int bintoDec(const std::string& inVal, int base) {
    /*
    IF(str1 contains only 1s and 0s)
        outVal = 0
        placeValue = 1
        tempVal = int(str1)
        WHILE(tempVal > 0)
             digit = tempVal % 10
             outVal = outVal + digit * placeValue
             placeValue *= base
             tempVal = tempVal / 10
        ENDWHILE
        RETURN outVal
     ELSE
        PRINT error
     ENDIF
     */
    return 0;
}

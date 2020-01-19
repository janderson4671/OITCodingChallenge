#include "Calculator.h"

//Constructor
Calculator::Calculator(){

    romanNumerals.push_back('I');
    romanNumerals.push_back('V');
    romanNumerals.push_back('X');
    romanNumerals.push_back('L');
    romanNumerals.push_back('C');
    romanNumerals.push_back('D');
    romanNumerals.push_back('M');
    
}

//Public functions
int Calculator::convertFromRoman(string letters) {

    int totalValue = 0;
    
    try {
        addUpRomanNumerals(letters, totalValue);
    } catch (...) {
        //invalid Roman numeral given
        return -1;
    }
    
    return totalValue;
}

void Calculator::addUpRomanNumerals(string letters, int& totalValue) {
    
    if (letters.size() == 0) {
        //nothing in the string
        throw -1;
    }
    
    return (f0(letters, 0, totalValue));
}

void Calculator::f0(string letters, int currIndex, int& totalValue) {

    char currLetter = letters.at(currIndex);

    //check if currLetter is a Roman Numeral
    if (getRomanValue(currLetter) == 0) {
        //invalid letter
        throw -1;
    }

    //base case
    if (currIndex == letters.size() - 1) {
        totalValue += getRomanValue(currLetter);
        return;
    }
    else {
        char nextLetter = letters.at(currIndex + 1);
        
        if (getRomanValue(nextLetter) == 0) {
            //invalid letter
            throw -1;
        }
        else if (getRomanValue(nextLetter) > getRomanValue(currLetter)) {
            //subtraction notation
            
            //check for x^10 rule
            if ((getRomanIndex(nextLetter) - getRomanIndex(currLetter)) > 2) {
                //invalid subtraction notation
                throw -1;
            }
            else {
                return f1(letters, currIndex + 1, totalValue, currLetter);
            }
        }
        else {
            totalValue += getRomanValue(currLetter);
            return f0(letters, currIndex + 1, totalValue);
        }
    }

}

void Calculator::f1(string letters, int currIndex, int& totalValue, char lastLetter) {
    
    char currLetter = letters.at(currIndex);
    
    //baseCase
    if (currIndex == letters.size() - 1) {
        totalValue += (getRomanValue(currLetter) - getRomanValue(lastLetter));
        return;
    }

    
    char nextLetter = letters.at(currIndex + 1);

    if (getRomanValue(nextLetter) == 0) {
        //invalid letter
        throw -1;
    }

    if (getRomanIndex(nextLetter) > getRomanIndex(currLetter)) {
        //letter next to it is larger and that is invalid
        throw -1;
    }
    else {
        totalValue += (getRomanValue(currLetter) - getRomanValue(lastLetter));
        return f0(letters, currIndex + 1, totalValue);
    }
}

int Calculator::getRomanValue(char letter) {
    switch (letter)
    {
    case 'I':
        return 1;
        break;
    case 'V':
        return 5;
        break;
    case 'X':
        return 10;
        break;
    case 'L':
        return 50;
        break;
    case 'C':
        return 100;
        break;
    case 'D':
        return 500;
        break;
    case 'M':
        return 1000;
        break;
    
    default:
        return 0;
        break;
    }
}

int Calculator::getRomanIndex(char letter) {
    for (unsigned int i = 0; i < romanNumerals.size(); i++) {
        if (letter == romanNumerals.at(i)) {
            return i;
        }
    }

    return -1;
}

string Calculator::convertToRoman(int number) {
    string romanStr;
    
    while (number != 0) {
        
        //keep doing this until we reach zero
        
        for (int i = (romanNumerals.size() - 1); i >= 0; i--) {
            int romanValue = getRomanValue(romanNumerals.at(i));
            
            if ((number - romanValue) < 0) {
                //see if subtraction notation will still work
                char subChar = getNextRomanValue(i, false);
                int subRomanValue = romanValue - getRomanValue(subChar);
                
                //test again
                if ((number - subRomanValue) < 0) {
                    //one more shot with a lower roman numeral
                    char subChar = getNextRomanValue(i, true);
                    subRomanValue = romanValue - getRomanValue(subChar);
                    
                    //test again
                    if (number - subRomanValue < 0) {
                        //move on to next roman numeral
                        continue;
                    }
                    else {
                        //add chars to the string
                        romanStr.push_back(subChar);
                        romanStr.push_back(romanNumerals.at(i));
                        number -= subRomanValue;
                        break;
                    }
                }
                else {
                    //add chars to the string
                    romanStr.push_back(subChar);
                    romanStr.push_back(romanNumerals.at(i));
                    number -= subRomanValue;
                    break;
                }
            }
            else {
                //add the char to the string
                romanStr.push_back(romanNumerals.at(i));
                number -= romanValue;
                break;
            }
        }
    }
    
    return romanStr;
}

char Calculator::getNextRomanValue(int indexNum, bool secondTry) {
    
    if ((indexNum == 1) || (indexNum == 0)) {
        return romanNumerals.at(0);
    }
    
    //if not the second try, get the roman numeral from 2 spots away
    if (!secondTry) {
        return romanNumerals.at(indexNum - 2);
    }
    else {
        return romanNumerals.at(indexNum - 1);
    }
    
}



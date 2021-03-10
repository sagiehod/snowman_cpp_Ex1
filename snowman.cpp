#include "snowman.hpp"
#include <iostream>
#include <array>
#include <string>
#include <exception>
#include <vector>

using namespace std;

namespace ariel{

// build and define the snowman parts as class functions
struct SnowMan
{
    const static int NUMBER_TEMP=10;
    const static int MIN_COMPONENT_NUM = 1;
    const static int MAX_COMPONENT_NUM = 4;
    using SnowManComponent = array<string, MAX_COMPONENT_NUM>;
    //For the build of the snowman 
    enum Parts
    {
        H = 0, N, LE, RE, LA, RA, T, B, NUM_OF_PARTS
    };
     enum Location
    {
        Hat = 0, Nose, LEye, REye, HLArm,LLArm,HRArm,LRArm,Torso,Base
    };
    //Build each part individually of the snowman 
    SnowMan()
    {
            _snowManComponents.push_back({"       \n _===_ ", "  ___  \n ..... ", "   _   \n  /_\\  ", "  ___  \n (_*_) "});
            _snowManComponents.push_back({",", ".", "_", " "});
            _snowManComponents.push_back({".", "o", "O", "-"});
            _snowManComponents.push_back({".", "o", "O", "-"});
            _snowManComponents.push_back({" ", "\\", " ", " "});
            _snowManComponents.push_back({"<", " ", "/", " "});
            _snowManComponents.push_back({" ", "/", " ", " "});
            _snowManComponents.push_back({">", " ", "\\", " "});
            _snowManComponents.push_back({" : ", "] [", "> <", "   "});
            _snowManComponents.push_back({" : ", "\" \"", "___", "   "});
    }

    string GetSnowMan(int input) noexcept(false)
    {
        CheckInput(input);       
        return BuildSnowMan(to_string(input));
    }

private:
    string BuildSnowMan(const string& input);
    static void CheckInput(int input) noexcept(false);
    static int ToDigit(char c) noexcept(false);

    vector<SnowManComponent> _snowManComponents;
};
//checks if the  number(input) is valid 
 void SnowMan::CheckInput(int input){
    if(input <= 0){
        throw invalid_argument("the input must be a positive number");
    }
    int inputCopy = input;
    int numOfDigits = 0;
    for (;  inputCopy != 0; numOfDigits++)
    {
        inputCopy /= NUMBER_TEMP;
    }
    
    if(numOfDigits != Parts::NUM_OF_PARTS)
    {
        throw invalid_argument("the input size has wrong num of digits");
    }    
  
    for (int i = 0 ; i <numOfDigits; i++) {
        if ((input % NUMBER_TEMP < MIN_COMPONENT_NUM) || (input % NUMBER_TEMP > MAX_COMPONENT_NUM)) {
            throw out_of_range("the number is not a valid");
        }
        input /=NUMBER_TEMP;
    }
}
//build the snow man (string)
string SnowMan::BuildSnowMan( const string& input)
{

    vector<int> digits;
    // reserve the size of the vector, in order to push members more efficiently (without need to resize on the fly)
    digits.reserve(input.length());
    for (int i = 0; i < input.length(); i++)
    {
        digits.push_back(ToDigit(input[i]) - 1); // -1 since nums are between 1...4 and indexs start in 0
    } 

    return  _snowManComponents[Hat][digits[H]] + "\n" +
    _snowManComponents[HLArm][digits[LA]] + "(" + 
    _snowManComponents[LEye][digits[LE]] +
    _snowManComponents[Nose][digits[N]]+
    _snowManComponents[REye][digits[RE]] + ")" +
    _snowManComponents[HRArm][digits[RA]] + "\n" +
    _snowManComponents[LLArm][digits[LA]] + "(" + 
    _snowManComponents[Torso][digits[T]] + ")" + 
    _snowManComponents[LRArm][digits[RA]] + "\n" + " (" +
    _snowManComponents[Base][digits[B]] + ") ";    
}
//converting char  to its integer representation
int SnowMan::ToDigit(char c)
{
    if(c < '0' || c > '9'){
        throw out_of_range("char is not a digit");
}
    return c - '0';
}   

string snowman(int input)
{
    SnowMan mySnowMan;
    return mySnowMan.GetSnowMan(input);
}

} 


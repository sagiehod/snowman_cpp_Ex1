#include "doctest.h"
#include "snowman.hpp"
#include <algorithm>
#include <string>
using namespace ariel;
using namespace std;

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
    //valid checks 
}
TEST_CASE("chcek the hat of the snowman is good") {
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(12341234)) == nospaces("\n _===_\n(O.-)/\n<(> <)\n(   )"));
    CHECK(nospaces(snowman(22341234)) == nospaces("___\n.....\n(O.-)/\n<(> <)\n(   )"));
    CHECK(nospaces(snowman(32341234)) == nospaces("_\n/_\\\n(O.-)/\n<(> <)\n (   )"));
    CHECK(nospaces(snowman(42341234)) == nospaces("___\n(_*_)\n(O.-)/\n<(> <)\n(   )"));
}
TEST_CASE("chcek the Nose/Mouth of snowman is good") {

    CHECK(nospaces(snowman(21222222)) == nospaces("___\n.....\n\\(o,o)/\n(] [)\n(\" \") "));
    CHECK(nospaces(snowman(22222222))== nospaces("___\n.....\n\\(o.o)/\n(] [)\n(\" \") "));
    CHECK(nospaces(snowman(23222222)) == nospaces("___\n.....\n\\(o_o)/\n(] [)\n(\" \") "));
    CHECK(nospaces(snowman(24222222)) == nospaces("___\n..... \n\\(o o)/\n(] [)\n(\" \") "));
}

TEST_CASE("chcek the  eyes of snowman is good") {

    CHECK(nospaces(snowman(33112124)) == nospaces("_\n/_\\\n\\(._.)\n(] [)>\n(   )"));
    CHECK(nospaces(snowman(33222124)) == nospaces("_\n/_\\\n\\(o_o)\n(] [)>\n(   )"));
    CHECK(nospaces(snowman(33332124)) == nospaces("_\n/_\\\n\\(O_O)\n(] [)>\n(   )"));
    CHECK(nospaces(snowman(33442124)) == nospaces("_\n/_\\\n\\(-_-)\n(] [)>\n(   )"));

}
TEST_CASE("chcek the arms of snowman is good") {
    
    CHECK(nospaces(snowman(44241123)) == nospaces("___\n(_*_)\n(o -)\n<(] [)>\n(___)"));
    CHECK(nospaces(snowman(44242223)) == nospaces("___\n(_*_)\n\\(o -)/\n(] [)\n(___)"));
    CHECK(nospaces(snowman(44243323)) == nospaces("___\n(_*_)\n(o -)\n/(] [)\\\n(___)"));
    CHECK(nospaces(snowman(44244423)) == nospaces("___\n(_*_)\n(o -)\n(] [)\n(___)"));
}

TEST_CASE("chcek the toros and base of snowman is good") {
    
    CHECK(nospaces(snowman(11114411)) == nospaces("\n_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11114422)) == nospaces("\n_===_\n(.,.)\n(] [)\n(\" \") "));
    CHECK(nospaces(snowman(11114433)) == nospaces("\n_===_\n(.,.)\n(> <)\n(___)"));
    CHECK(nospaces(snowman(11114444)) == nospaces("\n_===_\n(.,.)\n(   )\n(   )"));
    CHECK(nospaces(snowman(11114411)) == nospaces("\n_===_\n(.,.)\n( : )\n( : )"));
    

}
// not valid checks

TEST_CASE("Bad snowman code-less then 8 digitis") {
    //less then 8 digitis
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(12));
    CHECK_THROWS(snowman(123));
    CHECK_THROWS(snowman(1234));
    CHECK_THROWS(snowman(12344));
    CHECK_THROWS(snowman(123443));
    CHECK_THROWS(snowman(1234432));
}
// wrong digit- out of range (<1||>4)
TEST_CASE("Bad snowman code- wrong digit- out of range (<1||>4)") {
    CHECK_THROWS(snowman(12345321)); 
    CHECK_THROWS(snowman(11111226)); 
    CHECK_THROWS(snowman(77)); 
    CHECK_THROWS(snowman(-11111111));
    CHECK_THROWS(snowman(33302233));
}
 TEST_CASE("Bad snowman code- more then 8 digits") {

    //more then 8 digits
    CHECK_THROWS(snowman(123412341)); 
    CHECK_THROWS(snowman(443321132)); 
    CHECK_THROWS(snowman(123415341)); 
    CHECK_THROWS(snowman(123414341)); 


}

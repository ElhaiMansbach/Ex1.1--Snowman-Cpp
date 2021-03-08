#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good snowman code") {
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11223344)) == nospaces("_===_\n(o,o)\n/(   )\\\n(   )"));
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
    CHECK(nospaces(snowman(22222222)) == nospaces("___\n.....\n\\(o.o)/\n(] [)\n(\" \")"));
    CHECK(nospaces(snowman(33333333)) == nospaces("_\n/_\\\n(O_O)\n/(> <)\\\n(___)"));
    CHECK(nospaces(snowman(44444444)) == nospaces("___\n(_*_)\n(- -)\n(   )\n(   )"));
    CHECK(nospaces(snowman(34231234)) == nospaces("_\n/_\\\n(o O)/\n<(> <)\n(   )"));

}

TEST_CASE("check hat") {
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
    CHECK(nospaces(snowman(21111111)) == nospaces("___\n.....\n(.,.)\n<( : )>\n( : )"));
    CHECK(nospaces(snowman(31111111)) == nospaces("_\n/_\\\n(.,.)\n<( : )>\n( : )"));
    CHECK(nospaces(snowman(41111111)) == nospaces("___\n(_*_)\n(.,.)\n<( : )>\n( : )"));
}

TEST_CASE("check nose") {
    CHECK(nospaces(snowman(21222222)) == nospaces("___\n.....\n\\(o,o)/\n(] [)\n(\" \")"));
    CHECK(nospaces(snowman(22222222)) == nospaces("___\n.....\n\\(o.o)/\n(] [)\n(\" \")"));
    CHECK(nospaces(snowman(23222222)) == nospaces("___\n.....\n\\(o_o)/\n(] [)\n(\" \")"));
    CHECK(nospaces(snowman(24222222)) == nospaces("___\n.....\n\\(o o)/\n(] [)\n(\" \")"));
}

TEST_CASE("check left eye") {
    CHECK(nospaces(snowman(33133333)) == nospaces("_\n/_\\\n(._O)\n/(> <)\\\n(___)"));
    CHECK(nospaces(snowman(33233333)) == nospaces("_\n/_\\\n(o_O)\n/(> <)\\\n(___)"));
    CHECK(nospaces(snowman(33333333)) == nospaces("_\n/_\\\n(O_O)\n/(> <)\\\n(___)"));
    CHECK(nospaces(snowman(33433333)) == nospaces("_\n/_\\\n(-_O)\n/(> <)\\\n(___)"));
}

TEST_CASE("check right eye") {
    CHECK(nospaces(snowman(44414444)) == nospaces("___\n(_*_)\n(- .)\n(   )\n(   )"));
    CHECK(nospaces(snowman(44424444)) == nospaces("___\n(_*_)\n(- o)\n(   )\n(   )"));
    CHECK(nospaces(snowman(44434444)) == nospaces("___\n(_*_)\n(- O)\n(   )\n(   )"));
    CHECK(nospaces(snowman(44444444)) == nospaces("___\n(_*_)\n(- -)\n(   )\n(   )"));
}

TEST_CASE("check left arm") {
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
    CHECK(nospaces(snowman(11112111)) == nospaces("_===_\n\\(.,.)\n( : )>\n( : )"));
    CHECK(nospaces(snowman(11113111)) == nospaces("_===_\n(.,.)\n/( : )>\n( : )"));
    CHECK(nospaces(snowman(11114111)) == nospaces("_===_\n(.,.)\n( : )>\n( : )"));
}

TEST_CASE("check right arm") {
    CHECK(nospaces(snowman(22222122)) == nospaces("___\n.....\n\\(o.o)\n(] [)>\n(\" \")"));
    CHECK(nospaces(snowman(22222222)) == nospaces("___\n.....\n\\(o.o)/\n(] [)\n(\" \")"));
    CHECK(nospaces(snowman(22222322)) == nospaces("___\n.....\n\\(o.o)\n(] [)\n\\(\" \")"));
    CHECK(nospaces(snowman(22222422)) == nospaces("___\n.....\n\\(o.o)\n(] [)\n(\" \")"));
}

TEST_CASE("check torso") {
    CHECK(nospaces(snowman(33333313)) == nospaces("_\n/_\\\n(O_O)\n/(:)\\\n(___)"));
    CHECK(nospaces(snowman(33333323)) == nospaces("_\n/_\\\n(O_O)\n/(][)\\\n(___)"));
    CHECK(nospaces(snowman(33333333)) == nospaces("_\n/_\\\n(O_O)\n/(> <)\\\n(___)"));
    CHECK(nospaces(snowman(33333343)) == nospaces("_\n/_\\\n(O_O)\n/()\\\n(___)"));
}

TEST_CASE("check base") {
    CHECK(nospaces(snowman(44444441)) == nospaces("___\n(_*_)\n(- -)\n(   )\n( : )"));
    CHECK(nospaces(snowman(44444442)) == nospaces("___\n(_*_)\n(- -)\n(   )\n(\" \")"));
    CHECK(nospaces(snowman(44444443)) == nospaces("___\n(_*_)\n(- -)\n(   )\n(___)"));
    CHECK(nospaces(snowman(44444444)) == nospaces("___\n(_*_)\n(- -)\n(   )\n(   )"));
}

//Bad snowman code
TEST_CASE("More than 8 letters"){
    CHECK_THROWS(snowman(111111111));
    CHECK_THROWS(snowman(222222222));
    CHECK_THROWS(snowman(333333333));
    CHECK_THROWS(snowman(444444444));
    CHECK_THROWS(snowman(113344123));
    CHECK_THROWS(snowman(321432141));
}

TEST_CASE("Less than 8 letters"){ 
    CHECK_THROWS(snowman(1111111));
    CHECK_THROWS(snowman(222222));
    CHECK_THROWS(snowman(33333));
    CHECK_THROWS(snowman(444));
    CHECK_THROWS(snowman(12));
    CHECK_THROWS(snowman(1));
}

TEST_CASE("Negative numbers"){ 
    CHECK_THROWS(snowman(1111-1111));
    CHECK_THROWS(snowman(2222222-2));
    CHECK_THROWS(snowman(3-3333333));
    CHECK_THROWS(snowman(-44444444));
    CHECK_THROWS(snowman(12-234-34));
    CHECK_THROWS(snowman(1-223-4-3-4));
}

TEST_CASE("Invalid options") {
    CHECK_THROWS(snowman(11111115));
    CHECK_THROWS(snowman(22222922));
    CHECK_THROWS(snowman(63333333));
    CHECK_THROWS(snowman(04444444));
    CHECK_THROWS(snowman(12134115));
    CHECK_THROWS(snowman(44444449));
}
    


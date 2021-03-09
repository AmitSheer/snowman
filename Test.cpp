/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Amit-Sheer Cohen
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <array>
#include <exception>
#include <iostream>
#include <math.h>
using namespace std;
const array<std::string,4> hats = {"_===_"," ---\n .....", "  -\n  /_\\"," ---\n (_*_)"};
const array<std::string,4> noses = {",",".","_"," "};
const array<std::string,4> eyes = {".","o","O","-"};
const array<std::string,4> left_arm_tops = {" ","\\"," "," "};
const array<std::string,4> left_arms = {"<"," ","/"," "};
const array<std::string,4> right_arm_tops = {" ","/"," "," "};
const array<std::string,4> right_arms = {">"," ","\\"," "};
const array<std::string,4> torsos = {" : ", "] [","> <", "   "};
const array<std::string,4> bases = {" : ", "\" \"", "___","   "};
//hat,nose,left eye, right eye,leftarm, rightarm, torso, base
TEST_CASE("Good snowman code") {
    CHECK(snowman(11114411)==string(" _===_\n (.,.) \n ( : ) \n ( : )\n"));
    CHECK(snowman(12344434)==string(" _===_\n (O.-) \n (> <) \n (   )\n"));
    CHECK(snowman(11111111)==string(" _===_\n (.,.) \n<( : )>\n ( : )\n"));
    CHECK(snowman(22222222)==string("  ---\n .....\n\\(o.o)/\n (] [) \n (\" \")\n"));
    CHECK(snowman(44444444)==string("  ---\n (_*_)\n (- -) \n (   ) \n (   )\n"));
    CHECK(snowman(33333333)==string("   -\n  /_\\\n (O_O) \n/(> <)\\\n (___)\n"));
    CHECK(snowman(12341234)==string(" _===_\n (O.-)/\n<(> <) \n (   )\n"));
    for (int i = 0; i < 4; ++i) {
        int num = 11111111+i*10000000;
        CHECK(snowman(num)==string(" "+hats[i]+"\n (.,.) \n<( : )>\n ( : )\n"));
    }
    for (int i = 0; i < 4; ++i) {
        int num = 11111111+i*1000000;
                CHECK(snowman(num)==string(" _===_\n (."+noses[i]+".) \n<( : )>\n ( : )\n"));
    }
    for (int i = 0; i < 4; ++i) {
        int num = 11111111+i*100000;
                CHECK(snowman(num)==string(" _===_\n ("+eyes[i]+",.) \n<( : )>\n ( : )\n"));
    }
    for (int i = 0; i < 4; ++i) {
        int num = 11111111+i*10000;
                CHECK(snowman(num)==string(" _===_\n (.,"+eyes[i]+") \n<( : )>\n ( : )\n"));
    }
    for (int i = 0; i < 4; ++i) {
        int num = 11111111+i*10;
                CHECK(snowman(num)==string(" _===_\n (.,.) \n<("+torsos[i]+")>\n ( : )\n"));
    }
    for (int i = 0; i < 4; ++i) {
        int num = 11111111+i;
                CHECK(snowman(num)==string(" _===_\n (.,.) \n<( : )>\n ("+bases[i]+")\n"));
    }
    CHECK(snowman(11112111)==string(" _===_\n\\(.,.) \n ( : )>\n ( : )\n"));
    CHECK(snowman(11113111)==string(" _===_\n (.,.) \n/( : )>\n ( : )\n"));
    CHECK(snowman(11114111)==string(" _===_\n (.,.) \n ( : )>\n ( : )\n"));
    CHECK(snowman(11111211)==string(" _===_\n (.,.)/\n<( : ) \n ( : )\n"));
    CHECK(snowman(11111311)==string(" _===_\n (.,.) \n<( : )\\\n ( : )\n"));
    CHECK(snowman(11111411)==string(" _===_\n (.,.) \n<( : ) \n ( : )\n"));

    /* Add more checks here */
}

TEST_CASE("Snowman input invalid numbers"){
    int type = 11111111;
    for (int i = 4; i < 10; ++i) {
        for (int j = 0; j < 8; ++j) {
            CHECK_THROWS(snowman(type+i*pow(10,j)));
        }
    }
    for (int i = 1; i < 9; ++i) {
        type = -11111111;
        CHECK_THROWS(snowman(type*i));
    }
}
TEST_CASE("Input invalid input too long"){
    for (int i = 1; i < 10; ++i) {
        int type = 1111111111;
        CHECK_THROWS(snowman(type*i));
    }
}
TEST_CASE("Input invalid input too short and invalid numbers"){
    for (int i = 5; i < 9; ++i) {
        int value = 0;
        for (int j = 0; j < 7; ++j) {
            value = value*10+i;
            CHECK_THROWS(snowman(value));
        }
    }
    CHECK_THROWS(snowman(00000000));
}
TEST_CASE("Input invalid input too short and valid numbers"){
    for (int i = 1; i < 5; ++i) {
        int value = 0;
        for (int j = 0; j < 7; ++j) {
            value = value*10+i;
            CHECK_THROWS(snowman(value));
        }
    }
}


/* Add more test cases here */

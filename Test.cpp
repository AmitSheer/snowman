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
using namespace std;

//hat,nose,left eye, right eye,leftarm, rightarm, torso, base
TEST_CASE("Good snowman code") {
    CHECK(snowman(11114411)==string(" _===_\n (.,.) \n ( : ) \n ( : ) "));
    CHECK(snowman(12344434)==string(" _===_\n (O.-) \n (> <) \n (   ) "));
    CHECK(snowman(11111111)==string(" _===_\n (.,.) \n<( : )>\n ( : ) "));
    CHECK(snowman(22222222)==string("  ---\n .....\n\\(o.o)/\n (] [) \n (\" \") "));
    CHECK(snowman(44444444)==string("  ---\n (_*_)\n (- -) \n (   ) \n (   ) "));
    CHECK(snowman(33333333)==string("   -\n  /_\\\n (O_O) \n/(> <)\\\n (___) "));
    CHECK(snowman(12341234)==string(" _===_\n (O.-)/\n<(> <) \n (   ) "));

    /* Add more checks here */
}

TEST_CASE("Snowman input invalid numbers"){
    CHECK_THROWS(snowman(1111111));
    CHECK_THROWS(snowman(11111115));
    CHECK_THROWS(snowman(11111151));
    CHECK_THROWS(snowman(11111511));
    CHECK_THROWS(snowman(11115111));
    CHECK_THROWS(snowman(11151111));
    CHECK_THROWS(snowman(11511111));
    CHECK_THROWS(snowman(15111111));
    CHECK_THROWS(snowman(51111111));
    CHECK_THROWS(snowman(11111181));
}
TEST_CASE("Input invalid input too long"){
    CHECK_THROWS(snowman(1111111111));
}
TEST_CASE("Input invalid input too short"){
    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(1));
}
/* Add more test cases here */

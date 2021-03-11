//
// Created by Amit-Sheer Cohen on 03/03/2021.
//

#include "snowman.hpp"
#include <iostream>
#include <string>
#include <array>
#include <exception>
using namespace std;
const int NUM_NUMBER = 8, HAT=0, NOSE=1,LEFT_EYE=2,RIGHT_EYE=3,LEFT_ARM=4,RIGHT_ARM=5,TORSO=6,BASE= 7,MAX_SIZE=44444444,MIN_SIZE=11111111, NUMBER_TEN=10,MAX_INT=4,MIN_INT=1;

const array<std::string,4> hats = {" _===_","  ___\n .....", "   _\n  /_\\","  ___\n (_*_)"};
const array<std::string,4> noses = {",",".","_"," "};
const array<std::string,4> eyes = {".","o","O","-"};
const array<std::string,4> left_arm_tops = {" ","\\"," "," "};
const array<std::string,4> left_arms = {"<"," ","/"," "};
const array<std::string,4> right_arm_tops = {" ","/"," "," "};
const array<std::string,4> right_arms = {">"," ","\\"," "};
const array<std::string,4> torsos = {" : ", "] [","> <", "   "};
const array<std::string,4> bases = {" : ", "\" \"", "___","   "};



std::string build_face(array<int,NUM_NUMBER> types){
    std::string face = left_arm_tops.at(types.at(LEFT_ARM))+"("+eyes.at(types.at(LEFT_EYE))+noses.at(types.at(NOSE))+eyes.at(types.at(RIGHT_EYE))+")"+right_arm_tops.at(types.at(RIGHT_ARM));
    return face;
}
std::string build_body(array<int,NUM_NUMBER> types){
    std::string body =left_arms.at(types.at(LEFT_ARM))+"("+torsos.at(types.at(TORSO))+")"+right_arms.at(types.at(RIGHT_ARM));
    return body;
}
std::string build_base(int type){
    std::string lower_part = "("+bases.at(type)+ ")";
    return lower_part;
}

void validate_input(int type){
    if(type>MAX_SIZE||type<MIN_SIZE){
        throw std::out_of_range("size is out of range");
    }
    for (int i = NUM_NUMBER; i > 0; --i) {
        if(type%NUMBER_TEN<1||type%NUMBER_TEN>4){
            throw std::out_of_range("value out of range");
        }
        type = type/NUMBER_TEN;
    }
}

array<int,NUM_NUMBER> split_input(int type){
    array<int,NUM_NUMBER> types = {};
    for (int i = NUM_NUMBER; i > 0; --i) {
        types.at(i-1) = type%NUMBER_TEN-1;
        type = type/NUMBER_TEN;
    }
    return types;
}

std::string build_snowman(array<int,NUM_NUMBER> types){
    //creates the string for the base
    std::string base = build_base(types.at(BASE));
    //creates the string for the torso
    std::string body = build_body(types);
    //creates the string for the hat
    std::string hat = hats.at(types.at(HAT));
    //creates the string for the face
    std::string face = build_face(types);
    return hat+"\n"+face+"\n"+body+"\n "+base+"\n";
}

string ariel::snowman(int type){
    //validates the inputed data and returns it
    validate_input(type);
    array<int,NUM_NUMBER> types = split_input(type);
    //builds the string for he snowman
    return build_snowman(types);
}
//
//int main(){
//    std::cout<< ariel::snowman(22222222);
//    return 0;
//}
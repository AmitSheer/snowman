//
// Created by Amit-Sheer Cohen on 03/03/2021.
//

#include "snowman.hpp"
#include <iostream>
#include <string>
#include <array>
#include <exception>
using namespace std;
//
const array<std::string,4> hats = {"_===_"," ---\n .....", "  -\n  /_\\"," ---\n (_*_)"};
const array<std::string,4> noses = {",",".","_"," "};
const array<std::string,4> left_eyes = {".","o","O","-"};
const array<std::string,4> right_eyes = {".","o","O","-"};
const array<std::string,4> left_arm_tops = {" ","\\"," "," "};
const array<std::string,4> left_arms = {"<"," ","/"," "};
const array<std::string,4> right_arm_tops = {" ","/"," "," "};
const array<std::string,4> right_arms = {">"," ","\\"," "};
const array<std::string,4> torsos = {" : ", "] [","> <", "   "};
const array<std::string,4> bases = {" : ", "\" \"", "___","   "};

const int snowman1=11114411;
const int snowman2=33232124;
const int INPUT_SIZE_CHECK=10000000;
const int HAT = 0, NOSE =1 , LEFT_EYE = 2, RIGHT_EYE = 3, LEFT_ARM=4,RIGHT_ARM=5,TORSO=6,BASE=7;

std::string build_face(array<int,8> types){
    std::string face = left_arm_tops[types[LEFT_ARM]-1]+"("+left_eyes[types[LEFT_EYE]-1]+noses[types[NOSE]-1]+right_eyes[types[RIGHT_EYE]-1]+")"+right_arm_tops[types[RIGHT_ARM]-1];
    return face;
}
std::string build_body(array<int,8> types){
    std::string body =left_arms[types[LEFT_ARM]-1]+"("+torsos[types[TORSO]-1]+")"+right_arms[types[RIGHT_ARM]-1];
    return body;
}
std::string build_base(int type){
    std::string lower_part = " ("+bases[type]+ ")";
    return lower_part;
}
//
array<int,8> validate_input(int type){
    if(type<INPUT_SIZE_CHECK || type>INPUT_SIZE_CHECK*10){
        throw std::out_of_range("size is out of range");
    }
    array<int,8> types;
    for (int i = 7; i >= 0; --i) {
        if(type%10<1||type%10>4){
            throw std::out_of_range("value out of range");
        }
        types[i] = type%10;
        type = type/10;
    }
    return types;
}

std::string build_snowman(array<int,8> types){
    std::string base = build_base(types[BASE]-1);
    std::string body = build_body(types);
    std::string hat = hats[types[HAT]-1];
    std::string face = build_face(types);
    return " "+hat+"\n"+face+"\n"+body+"\n"+base+" ";
}
string ariel::snowman(int type){
    array<int,8> types = validate_input(type);
    return build_snowman(types);
}
//
//int main(){
//    std::cout<< ariel::snowman(11114411);
//    return 0;
//}
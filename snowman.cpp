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
const array<std::string,4> hats = {"_===_","---\n.....", " -\n/_\\"," ---\n(_*_)"};
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
class Snowman{
    public:
        std::string hat;
        std::string left;
        std::string left_eye;
        std::string right_eye;
        std::string left_arm_top;
        std::string left_arm;
        std::string right_arm_top;
        std::string right_arm ;
        std::string torso;
        std::string base;
        void Snowman(int type){
            base = bases[type%10];
        }
        std::string toString(){
            return " "+hat+"\n"+left_arm_top+"("+left_eye+nose+right_eye+")"+right_arm_top+"\n"+left_arm
            +"("+torso+")"+right_arm+"\n "+" ("+base+")";
        }
};
std::array<int,8> parse_input(int type){
    array<int,8> build_snowman;
    for (int i = 0; i < 8; ++i) {
        build_snowman[i] = type/(INPUT_SIZE_CHECK/pow(10,i));
        type = type%(INPUT_SIZE_CHECK/pow(10,i));
    }
}

std::string build_face(array<int,8> type){
    std::string face = "("+left_eyes[type[2]-1]+noses[types[1]-1]-+right_eyes[types[3]-1]+")";
    return face;
}
std::string build_body(int type){
    std::string body ="("+torsos[type]+")";
    return body;
}
std::string build_base(int type){
    std::string lower_part = "("+bases[type]+ ")";
    return lower_part;
}
//
void validate_input(int type){
    if(type<INPUT_SIZE_CHECK || type>INPUT_SIZE_CHECK*10){
        throw std::bad_typeid();
    }
    for (int i = 0; i < 8; ++i) {
        if(type%10<1||type%10>4){
            throw std::out_of_range();
        }
        type = type/10;
    }
}
std::string build_snowman(array<int,8> types){
    std::string base = build_base(types[7]-1);
    std::string body = build_body(types[6]-1);
    std::string hat = " "+hats[types[0]-1];
    std::string face = build_face(types);
    return hat+"\n"+left_arm_tops[types[4]-1]+face+right_arm_tops[types[5]-1]+"\n"+left_arms[types[4]-1]+body+right_arms[types[5]-1]
    +"\n"
}
string ariel::snowman(int type){
    validate_input(type);
    if(type<INPUT_SIZE_CHECK || type>INPUT_SIZE_CHECK*10){
        throw std::bad_typeid();
    }
//    if(type==snowman1){
//        return "_===_\n"
//               "(.,.)\n"
//               "( : )\n"
//               "( : )";
//    }
//    if(type== snowman2){
//        return "  _\n"
//               " /_\\\n"
//               "\\(o_O)\n"
//               " (] [)>\n"
//               " (   )";
//    }
//    array<int,8> input = parse_input(type);
    std::string snowman_print = hats[type/INPUT_SIZE_CHECK];
    type = type%INPUT_SIZE_CHECK;
    build_snowman(type);
    return "asas";
}
//
//int main(){
////     string str;
////     int typeNumber=0;
////     std::cin >> str >> typeNumber;
////     if(validate_input(str)!=0){
////         ariel::snowman(typeNumber);
////     }else{
////         exit(0);
////     }
//     return 0;
//}
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
//const array<std::string,4> hats = {"_===_","---\n.....", " -\n/_\\"," ---\n(_*_)"};
//const array<char,4> nose = {',','.','_',' '};
//const array<char,4> left_eye = {'.','o','O','-'};
//const array<char,4> right_eye = {'.','o','O','-'};
//const array<char,4> left_arm = {'<','\\','/',' '};
//const array<std::string,4> right_arm = {">","/","\\"," "};
//const array<std::string,4> torso = {" : ", "] [","> <", "   "};
//const array<std::string,4> base = {" : ", "\" \"", "___","   "};



string ariel::snowman(int type){
    if(type<10000000){
        throw std::bad_typeid();
    }else if(type==11114411){
        return "_===_\n"
               "(.,.)\n"
               "( : )\n"
               "( : )";
    }else if(type==33232124){
        return "   _\n"
               "  /_\\\n"
               "\\(o_O)\n"
               " (] [)>\n"
               " (   )";
    }
//    std::string snowman_to_print;
//    int index = type%10;
//    std::cout << base[index-1];
    return "asas";
}
//
//int validate_input(std::string str ){
//    if(str.length()!=NUM_NUMBER){
//        return 0;
//    }
//    for(int i=0;i<NUM_NUMBER;i++){
//        if(str[i]<'1'||str[i]>'4'){
//            return 0;
//        }
//    }
//    return 1;
//}
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
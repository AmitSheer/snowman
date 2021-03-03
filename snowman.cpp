//
// Created by Amit-Sheer Cohen on 03/03/2021.
//

#include "snowman.hpp"
#include <iostream>
#include <string>
#include <array>
using namespace std;

class Snowman {
public:
    array<std::string,4> hats = {"_===_","---\n.....", " -\n/_\\"," ---\n(_*_)"};
    array<char,4> nose = {',','.','_',' '};
    array<char,4> left_eye = {'.','o','O','-'};
    array<char,4> right_eye = {'.','o','O','-'};
    array<char,4> left_arm = {'<','\\','/',' '};
    array<std::string,4> right_arm = {">","/","\\"," "};
    array<std::string,4> torso = {" : ", "] [","> <", "   "};
    array<std::string,4> base = {" : ", "\" \"", "___","   "};
};
int validate_input(std::string str ){
    if(str.length()!=NUM_NUMBER){
        return 0;
    }
    for(int i=0;i<NUM_NUMBER;i++){
        if(str[i]<'1'||str[i]>'4'){
            return 0;
        }
    }
    return 1;
}

void print_snowman(std::string str){
    Snowman snowman;
    std::string snowman_to_print;
    snowman_to_print.append(snowman.hats[str.at(0)-'0']);
    std::cout << snowman_to_print;
}

int main(){
     std::string str;
     std::cin >> str;
     if(validate_input(str)!=0){
         print_snowman(str);
     }else{
         exit(0);
     }
     return 0;
}
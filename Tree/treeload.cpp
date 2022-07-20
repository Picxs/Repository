#include <iostream>

int main(){
    std::string input;
    std::string tree = "[ ";

    std::cin >> input;

    for(char t : input){
        if(t == 'x'){
            continue;
        } else {
            tree = tree + t + " ";
        }
    }

    tree = tree + "]";
    std::cout << tree;
}
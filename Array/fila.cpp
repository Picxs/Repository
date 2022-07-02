#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    int size = 10;

    std::vector<int>fila;

    for(int i = 0; i < size; i++){
        fila.push_back(i);
    }

    int left = 5;

    std::vector<int>sairam;

    for(int i = 0; i < left; i++){
        sairam.push_back(i);
    }

    for(int i = 0; i < left; i++){
        auto it = find(fila.begin(), fila.end(), sairam[i]);
        fila.erase(it);
    }

    for(int value : fila){
       std::cout << value << " ";
    }
    
}
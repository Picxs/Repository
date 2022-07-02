#include <iostream>
#include <vector>

int main() {
    int size = 10;
    int qtd = 12;

    if(qtd > size){
        qtd = qtd % size;
    }

    std::vector<int>vet;
    std::vector<int>rot;



    for(int i = 0; i < size; i++){
        vet.push_back(i);
    }

    for(int i = size - 1; qtd > 0; i--){
        rot.push_back(vet[i]);
        vet.pop_back();
        qtd--;
    }

    for(int i = 0; i < (int)rot.size(); i++){
        auto it = vet.begin();
        vet.insert(it, rot[i]);
    }

    for(int value : vet){
        std::cout << value << " ";
    }
}
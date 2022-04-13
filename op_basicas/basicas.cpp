#include <iostream>
#include <list>


void show(std::list<int> vet){
    std::cout << vet.front();
    vet.erase(vet.begin());
    show(vet);
}

void rshow(std::list<int> vet){
    std::cout << vet.back();
    vet.pop_back();
    rshow(vet);
    
}

void vet_soma(std::list<int> vet, int soma){
    
    soma = soma + vet.front();
    vet.erase(vet.begin());
    if((int)vet.size() == 0){
        std::cout << soma;
    }
    vet_soma(vet, soma);
}
void vet_mult(std::list<int> vet, int mult){
    if(mult == 0) {
        mult++;
    }
    
    mult = mult * vet.front();
    vet.erase(vet.begin());
    if((int)vet.size() == 0){
        std::cout << mult;
    }
    vet_mult(vet, mult);
}


void vet_menor(std::list<int> vet, int menor) {


}


int main(){

    int size;
    std::cout << "Escolha o tamanho: " << std::endl;
    std::cin >> size;

    std::list<int> vet;

    for(int i = 0; i <= size; i++){
        vet.push_back(i);
    }
    int mul{};

    vet_mult(vet, mul);

  


    
}

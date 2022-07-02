#include <iostream>
#include <vector>
#include <fstream>


std::vector<int> comparar(std::vector<std::string> busca, std::vector<std::string> consulta){
    int contador{ };
    std::vector<int> vet_contador{ };

    for(int i = 0; i < (int)busca.size(); i++){
        for(int j = 0; j < (int)consulta.size(); j++){
            if(consulta[j] == busca[i]){
                contador++;
            }
        }
        vet_contador.push_back(contador);
        contador = 0;
    }
    return vet_contador;
}

int main(){
    std::vector<std::string> consulta;
    std::vector<std::string> busca;

    int sizeC{ };
    int sizeB{ };

    std::ifstream input("input.txt");

    input >> sizeC;

     for(int i = 0; i < sizeC; i++){
        std::string line;
        input >> line;
        consulta.push_back(line);
    }

    input >> sizeB;

   
    for(int i = 0; i < sizeB; i ++){
        std::string line;
        input >> line;
        busca.push_back(line);
    }

    std::vector<int> quantos = comparar(busca, consulta);

    for(int value : quantos){
        std::cout << value << " ";
    }

}
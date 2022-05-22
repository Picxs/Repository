#include <iostream>
#include <fstream>
#include <vector>

bool posso_inserir(std::string& line, int index, int value, int prox){
    for(int i = index + 1; i < index + 1 + prox; i++)
        if(i < (int)line.size() && line[i] == value + '0')
            return false;

    for(int i = index - prox; i < index; i++)
        if(i >= 0 && line[i] == value + '0')
            return false;
    
    return true;
}

bool preencher(std::string& line, int i, int lim, int prox){
    if((int)line.size() == i){
        std::cout << line << "<---\n";
        return true;
    }
        
    if(line[i] != '.')
        return preencher(line, i + 1, lim, prox);


    for(int value = 0; value <= lim; value++) {
        if(posso_inserir(line, i, value, prox)){
            line[i] = value + '0';
            std::cout << line << std::endl;
            if(preencher(line, i + 1, lim, prox))
                return true;
        }
    }

    line[i] = '.';
    std::cout << line << std::endl;
    return false;
}

int main(){
    std::ifstream input("input.txt");
    std::string line;
    int prox;
    int lim = 1;

    input >> line >> prox;

    preencher(line, 0, lim, prox);
}
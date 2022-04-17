#include <iostream>
#include <fstream>
#include <vector>

void show(std::vector<std::string> map){
    for(auto line : map){
        std::cout << line << std::endl;
    }
}


void andar(std::vector<std::string>& labirinto, int nl, int nc){

    int nlmax = labirinto.size();
    int ncmax = labirinto[0].size();

    if(nl < 0 || nl >= nlmax || nc < 0 || nc >= ncmax){
        return;
    }
    if(labirinto[nl][nc] != '_'){
        return;
    }

    labirinto[nl][nc] = '.';
    show(labirinto);
    getchar();

    andar(labirinto, nl, nc - 1);
    andar(labirinto, nl - 1, nc );
    andar(labirinto, nl, nc + 1);
    andar(labirinto, nl + 1, nc);

}

int main(){
    std::ifstream input("input.txt");

    int nl{ }, nc{ }, li{ }, ci{ };

    input >> nl >> nc;
    std::vector<std::string> labirinto;

    for(int i = 0; i < nl; i++){
        std::string line;
        input >> line;
        labirinto.push_back(line);
    }

    show(labirinto);
    std::cin >> li >> ci;
    std::cin.ignore();

    andar(labirinto, li, ci);

}
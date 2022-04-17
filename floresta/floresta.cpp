#include <iostream>
#include <vector>
#include <ctime>
#include <random>


int random(){
    return (rand() % 10 + 1);
}

int menor_random(int num){
    return (rand() % num);
}

void show(std::vector<std::string> map){
    for(auto line : map){
        std::cout << line << std::endl;
    }
}

void queimar(std::vector<std::string>& floresta, int nl, int nc){

    int nlmax = floresta.size();
    int ncmax = floresta[0].size();

    if(nl < 0 || nl >= nlmax || nc < 0 || nc >= ncmax){
        return;
    }
    if(floresta[nl][nc] != '#'){
        return;
    }

    floresta[nl][nc] = 'x';
    show(floresta);
    getchar();

    queimar(floresta, nl, nc - 1);
    queimar(floresta, nl - 1, nc );
    queimar(floresta, nl, nc + 1);
    queimar(floresta, nl + 1, nc);

}


int main(){
    srand(time(NULL));

    int nl = random();
    int nc = random();

    if(nc <= 1 || nl <= 1){
        nl++;
        nc++;
    }

    std::vector<std::string> floresta(nl, std::string(nc, '#'));

    for(int i = menor_random((nc * nl)); i > 0; i--){
        int randl = menor_random(nl);
        int randc = menor_random(nc);

        if(floresta[randl][randc] == '#'){
            floresta[randl][randc] = 'o';
        }
    }

    show(floresta);

    int li{}, ci{};
    
    std::cin >> li >> ci;
    std::cin.ignore();

    queimar(floresta, li, ci);

}
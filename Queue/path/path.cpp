#include <iostream>
#include <vector>
#include <fstream>
#include <queue>


struct Pos{
    int l;
    int c;
    Pos(int l, int c){
        this->c = c;
        this->l = l;
    }
};

std::vector<Pos> findneib(Pos atual){
    auto [l,c] = atual;
    return {{l - 1, c}, {l + 1, c}, {l, c - 1}, {l, c + 1}};
}

void show(std::vector<std::string> vet){
    for(std::string line : vet){
        std::cout << line << std::endl;
    }
}


void voltar(std::vector<std::vector<int>> &distancia, std::vector<std::string> &mat, Pos fim){
    Pos atual = fim;
    bool find = false;

    while(!find){
        for(auto vizinho : findneib(atual)){
            if(vizinho.l == (int)mat.size() || vizinho.l < 0 || vizinho.c == (int)mat[0].size() || vizinho.c < 0){
                continue;
            }

            if(distancia[vizinho.l][vizinho.c] == distancia[atual.l][atual.c] - 1){
                mat[atual.l][atual.c] = '.';
                atual = vizinho;
            }
            if(mat[atual.l][atual.c] == 'I'){
                mat[atual.l][atual.c] = '.';
                find = true;
            }
        }
    }
}
void saida(std::vector<std::string> &mat, Pos inicio, Pos fim){

    std::vector<std::vector<int>> dis(mat.size(), std::vector<int>(mat[0].size(), -1));
    std::queue<Pos> queue;
    queue.push(inicio);
    dis[inicio.l][inicio.c] = 0;

    while(queue.size() != 0){
        Pos atual = queue.front();
        for(auto vizinho : findneib(atual)){
            if(vizinho.l == (int)mat.size() || vizinho.l < 0 || vizinho.c == (int)mat[0].size() || vizinho.c < 0){
                continue;
            }
            if(mat[vizinho.l][vizinho.c] == 'F' || (mat[vizinho.l][vizinho.c] == ' ' && dis[vizinho.l][vizinho.c] == -1)){
                queue.push(vizinho);
                dis[vizinho.l][vizinho.c] = dis[atual.l][atual.c] + 1;
            }
            if(mat[vizinho.l][vizinho.c] == 'F'){
                voltar(dis, mat, fim);
                return;
            }   
        }   
        queue.pop();
    }
}

int main(){
 int nl{};
 int nc{};

 std::cin >> nl;
 std::cin >> nc;

 std::cin.ignore();

 std::vector<std::string> matriz(nl);

 for(int i = 0; i < nl; i++){
    getline(std::cin, matriz[i]);

 }
 Pos inicio(0,0);
 Pos fim(0,0);

 for(int i = 0; i < nl; i++){
    for(int j = 0; j < nc; j++){
        if(matriz[i][j] == 'I'){
            inicio = Pos{i,j};
        }
        if(matriz[i][j] == 'F'){
            fim = Pos{i,j};
        }
    }
 }
 saida(matriz, inicio, fim);
 show(matriz);
}


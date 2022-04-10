#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

vector<int> clonar(const vector<int> &vet) 
{
    vector<int> copia{};
    for(int i = 0; i < (int)vet.size(); i++) { 
        copia.push_back(vet[i]);
    }
    return copia;
}

vector<int> pegar_homens(const vector<int> &vet) 
{
    vector<int> homens{};
    for(int i = 0; i < (int)vet.size(); i++) {
        if(vet[i] > 0) {
            homens.push_back(vet[i]);
        }
    }
    return homens;
}

vector<int> pegar_calmos(const vector<int> &vet) 
{
    vector<int> calmos{};
    for(int i = 0; i < (int)vet.size(); i++) {
        if(vet[i] < 10 && vet[i] > -10) {
            calmos.push_back(vet[i]);
        }
    }
    return calmos;
}


vector<int> pegar_mulheres_calmas(const vector<int> &vet) 
{
    vector<int> mulheres{};
    for(int i = 0; i < (int)vet.size(); i++) {
        if (vet[i] > -10 && vet[i] < 0) {
            mulheres.push_back(vet[i]);
        }
    }
    return mulheres;
}

// Professor, não fiz o inverter_com_copia, não consegui usar o vet.rbegin nem o vet.rend, até pesquisei mas não entendi como usa.

void inverter_inplace(vector<int> &vet) 
{
    int j{(int)vet.size()};

    for(int i = 0; i < ((int)vet.size() / 2); i++) {
        swap(vet[i], vet[j]);
        j--;
    }

}
int sortear(const vector<int> &vet) 
{
    int sorteado{};
    srand(time(NULL));

    sorteado = rand() % (int)vet.size();

    return vet[sorteado];
}

void embaralhar(vector<int> &vet) 
{
    srand(time(NULL));
    

    for(int i = 0; i < (int)vet.size(); i++) {
        int aleatorio = rand() % vet.size();
        swap(vet[i], aleatorio);
    }
}

void ordenar(vector<int> &vet) 
{
    for(int i = 0; i < (int)vet.size(); i++) {
        for(int i = 0; i < (int)vet.size(); i++) {
            if(vet[i+1] > vet[i]) {
                swap(vet[i+1], vet[i]);
            }
        }
    }
}

vector<int> exclusivos(const vector<int> &vet) 
{
    vector<int> exclusivos{};

    for(int i = 0; i < (int)vet.size(); i++) {
        if(find(exclusivos.begin(), exclusivos.end(), vet[i]) == exclusivos.end()) {
            exclusivos.push_back(vet[i]);
        } 
    }
    return exclusivos;
}

vector<int> diferentes(const vector<int>& vet) 
{
    vector<int> diferente{};

    for(int i = 0; i < (int)vet.size(); i++) {
        if(find(diferente.begin(), diferente.end(), abs(vet[i])) == diferente.end()) {
            diferente.push_back(abs(vet[i]));
        }
    }
    return diferente;
}

vector<int> abandonados(const vector<int> &vet) 
{
    vector<int> abandonados{};
    vector<int> escolhidos{};

    for(int i = 0; i < (int)vet.size(); i++) {
        if(find(escolhidos.begin(), escolhidos.end(), vet[i]) == escolhidos.end()) {
            escolhidos.push_back(vet[i]);
        } else {
            abandonados.push_back(vet[i]);
        }
    }
   return abandonados;
}


int main() {


    vector<int> vet{-11, -2, -1, -1, 4, 5, 6};

}
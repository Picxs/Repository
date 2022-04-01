#include <vector>
#include <iostream>

using namespace std;

int prox_vivo(vector<bool> fila, int size, int start) {
    for(int i = start + 1; i < size; i++) {
        if(fila[i] == true) {
            return i;
            if(start == size -1) {
                start = start % (size -1);
         }
        }
         
    }
}



void printar_fila(vector<bool> fila, int size, int espada) {

    string printar;

    for(int i = 0; i < size; i++) {
        if(fila[i] == true){
            if(i == espada){
            cout << to_string(i) + ">";
        } else {
            cout << i;
        }
        }
       
    }
        
}


int main() {
   int size{};
   cin >> size;

 vector<bool> fila;
   for(int i = 0; i < size; i++) {
       fila.push_back(true);
   }

   int espada{};
   cin >> espada;
   espada = espada - 1;

   int tamanho = size - 1;
   printar_fila(fila, size, espada);
   while(tamanho--) {

        int matar {prox_vivo(fila, size, espada)};
        fila[matar] = false;
        espada = prox_vivo(fila, size, matar);
        printar_fila(fila, size, espada);
        

   }
}
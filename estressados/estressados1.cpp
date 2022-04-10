#include <iostream>

#define size 6
using namespace std;

int existe(int vet[])
{
    int i;
    int valor;

    printf("Qual o valor: ");
    scanf("%i", &valor);

    for(i = 0; i < size; i++) {
        if(valor == vet[i]) {
            return 1;
        }
    }
    return 0;
}

int contador(int vet[])
{
    int i;
    int valor;
    int contador = 0;

    printf("Qual o valor: ");
    scanf("%i", &valor);

    for(i = 0; i < size; i++) {
        if(valor == vet[i]) {
            contador++;
        }
    }
    return contador;
}

int local_da_fila(int vet[])
{
    int i;
    int valor;

    printf("Qual o valor: ");
    scanf("%i", &valor);

    for(i = 0; i < size; i++) {
        if(valor == vet[i]) {
            return i;
        }
    }
    return -1;
}

int proximo(int vet[])
{
    int i;
    int valor;

    printf("Qual o inicio: ");
    scanf("%i", &i );

    printf("Qual o valor: ");
    scanf("%i", &valor);

    for(i = i; i < size; i++) {
        if(valor == vet[i]) {
            return i;
        }
    }
    return -1;
}

int menor(int vet[])
{  
    int i;
    int menor = 100;

    for(i = 0; i < size; i++) {
        if (menor > vet[i]) {
            menor = vet[i];
        }
    }
    return menor;
}

int maior(int vet[])
{  
    int i;
    int maior = 0;

    for(i = 0; i < size; i++) {
        if (maior < vet[i]) {
            maior = vet[i];
        }
    }
    return maior;
}

int pos_menor(int vet[]) 
{

    int i;
    int menor = 100;
    int pos;

    for (i = 0; i < size; i++) {
        if (vet[i] <= menor ) {
            menor = vet[i];
            pos = i;
        }

    }
    return pos;
}

int pos_maior(int vet[])
{  
    int i;
    int maior = 0;
    int pos;

    for(i = 0; i < size; i++) {
        if (maior < vet[i]) {
            maior = vet[i];
            pos = i;
        }
    }
    return pos;
}

int pos_menor_apartir(int vet[]) 
{

    int i;
    int menor = 100;
    int pos;

    printf("Qual o inicio: ");
    scanf("%i", &i);

    for (i = i; i < size; i++) {
        if (vet[i] < menor ) {
            menor = vet[i];
            pos = i;
        }

    }
    return pos;
}

int homem_mais_calmo(int vet[])
{
    int i;
    int menor_calmo = 100;
    int pos_calmo;

    for(i = 0; i < size; i++ ) {
        if(vet[i] > 0) {
            if(vet[i] < menor_calmo) {
                menor_calmo = vet[i];
                pos_calmo = i;
            }
        }
    }
    return pos_calmo;
}

float stress_medio(int vet[]) 
{
    int i;
    float soma;
    

    for(i = 0; i < size; i++) {
        if(vet[i] < 0) {
            soma = soma + (vet[i] * -1);
        } else {
            soma = soma + vet[i];
        }
    }
    return (soma/size);
}

string mais_homem_mulher(int vet[]) 
{
    int i;
    int homem = 0;
    int mulher = 0;

    for(i = 0; i < size; i++) {
        if(vet[i] > 0) {
            homem += 1;
        } else {
            mulher += 1;
        }
    }

    if(homem > mulher){
        return ("homens");
    } else if (mulher > homem) {
        return ("mulheres");
    } else {
        return ("empate");
    }
}

string metade_mais_estressada(int vet[])
{
    int i;
    int primeiro = 0;
    int segundo = 0;

    for (i = 0; i < (size/2); i++) {
        if (vet[i] < 0) {
            primeiro = primeiro + (vet[i] * -1);
        } else {
            primeiro = primeiro + vet[i];
        }
    }
    for (i = (size/2); i < size; i++) {
        if (vet[i] < 0) {
            segundo = segundo + (vet[i] * -1);
        } else {
            segundo = segundo + vet[i];
        }
    }

    if (primeiro > segundo) {
        return ("primeiro");
    } else if (primeiro < segundo) {
        return ("segundo");
    } else {
        return ("empate");
    }

}

string quem_eh_mais_estressado(int vet[]) 
{
    int i;
    int homens = 0;
    int mulheres = 0;
    int stress_homens = 0;
    int stress_mulheres = 0;

    for (i = 0; i < size; i++) 
    { 
        if(vet[i] > 0) {
            stress_homens = stress_homens + vet[i];
            homens ++;
        } else {
            stress_mulheres = stress_mulheres + (vet[i] * -1);
            mulheres++;
        }
    }

    if (stress_homens/homens > stress_mulheres/mulheres) {
        return ("os homens sao mais estressados");
    } else if (stress_homens/homens < stress_mulheres/mulheres) {
        return ("as mulheres sao mais estressadas");
    } else {
        return ("todo mundo eh estressado igualmente");
    }
}


int main()
{

//    int vet[size] = {2, 1, 2, 3, 4};
    int veti[size] = {99, 2, 13, 12, -21, 12};

//int acho;

//acho = existe(vet);

  //  if(acho == 1){
  //      printf("Existe\n");
 //   } else {
  //      printf("N existe\n");
  //  }

  //  int quantos;
  //  quantos = contador(vet);
   // printf("%i\n", quantos);

  //  int onde;

  //  onde = local_da_fila(vet);
   // printf("%i\n", onde);


   // int procurar_proximo;
  //  procurar_proximo = proximo(vet);
  // printf("%i\n", procurar_proximo);

  //  int menozinho;
  //  menozinho = menor(vet);
  //  printf("O menozinho eh %i\n", menozinho);

   // int maiozinho;
   // maiozinho = maior(vet);
   // printf("O maiozinho eh %i\n", maiozinho);
    
   // int posMenor;
  //  posMenor = pos_menor(vet);
  //  printf("a pos do menor eh %i\n", posMenor);

  //  int posMaior;
  //  posMaior = pos_maior(vet);
  //  printf("a pos do maior eh %i\n", posMaior);

  //  int posMenorAp;
  //  posMenorAp = pos_menor_apartir(vet);
  //  printf("a pos do menor apartir do valor eh %i\n", posMenorAp);

  //  int homimaiscalmo;
   // homimaiscalmo = homem_mais_calmo(veti);
  //  printf("a pos do homi mar calmo eh %i\n", homimaiscalmo);

   // float estresseMedio;
  // estresseMedio = stress_medio(veti);
   // printf("o stress medio eh %.1f\n", estresseMedio);

  // cout << mais_homem_mulher(veti);
 
   // cout << metade_mais_estressada(veti);

   //cout << quem_eh_mais_estressado(veti);

}
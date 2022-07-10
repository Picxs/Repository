#include <iostream>
#include <list>



std::list<char>::iterator enter(std::list<char>& texto, std::list<char>::iterator cursor){
    texto.insert(cursor, '\n');
    return cursor;
}

std::list<char>::iterator backspace(std::list<char>& texto, std::list<char>::iterator cursor){
    if(cursor == texto.begin()){
        return texto.begin();
    }
    return texto.erase(--cursor);
}

std::list<char>::iterator delet(std::list<char>& texto, std::list<char>::iterator cursor){
    if(cursor == texto.end()){
        return texto.end();
    }
    return texto.erase(cursor);
}

std::list<char>::iterator add(std::list<char>& texto, std::list<char>::iterator cursor, char x){
    texto.insert(cursor, x);
    return cursor;
}

std::list<char>::iterator direita(std::list<char>& texto, std::list<char>::iterator cursor){
    if(cursor == texto.end()){
        return cursor;
    }
    return ++cursor;
}

std::list<char>::iterator esquerda(std::list<char>& texto, std::list<char>::iterator cursor){
    if(cursor == texto.begin()){
        return cursor;
    }
    return --cursor;
}

void show(std::list<char> texto){
    for(char letra : texto){
        std::cout << letra;
    }
    std::cout << std::endl;
}



int main(){
    std::list<char> texto{};
    std::string entrada{};
    std::list<char>::iterator cursor = texto.begin();

    std::cin >> entrada;

    for(char letra : entrada){
        if(letra == 'R'){
            cursor = enter(texto, cursor);
        } else if(letra == 'B'){
            cursor = backspace(texto, cursor);
        } else if(letra == 'D'){
            cursor = delet(texto, cursor);
        } else if(letra == '>'){
            cursor = direita(texto, cursor);
        } else if(letra == '<'){
            cursor = esquerda(texto, cursor);
        } else {
            cursor = add(texto, cursor, letra);
        }

    }
    texto.insert(cursor, '|');
    show(texto);
}
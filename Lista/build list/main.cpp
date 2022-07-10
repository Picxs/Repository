#include "list.hpp"
#include <iostream>



std::ostream& operator<<(std::ostream& os, List& lista){
    os << "[ ";
    Node * node = lista.head;

    while(node != nullptr){
        os << node->value << " ";
        node = node->next;
    }
    os << "]";
    return os;
}

int main(){
    List lista;
    lista.push_front(10);
    lista.push_back(9);
    std::cout << lista;
}
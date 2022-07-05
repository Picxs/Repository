#include <iostream>
#include <sstream>
#include "banco.hpp"

int main(){
    Banco bb(3);

    while(true){
        std::string line, cmd;
        std::getline(std::cin, line);

        std::cout << "$" << line << "\n";
        std::stringstream ss(line);
        ss >> cmd;

        if(cmd == "end"){
            break;
        }
        if(cmd == "show"){
            bb.show();
        } else if (cmd == "in"){
            std::string name;
            int doc, pac;
            ss >> name >> doc >> pac;
            bb.insert(new Cliente(name, doc, pac));
        } else if(cmd == "init"){
            int size;
            ss >> size;
            bb = Banco(size);
        } else if(cmd == "tic"){
                bb.tic();
        } else if(cmd == "fim"){
            while(!bb.empty()){
                bb.tic();
                std::cout << "recebidos: " << bb.get_recebidos() << std::endl;
                std::cout << "perdidos: " << bb.get_perdidos() << std::endl;
                std::cout << "tics: " << bb.get_tics() << std::endl; 
            }

        } else {
            std::cout << "erro";
        }
    }

}
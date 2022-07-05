#include <iostream>
#include <vector>
#include <list>
#include "Cliente.hpp"

class Banco{
    std::vector<Cliente*> caixas;
    std::list<Cliente*> entrada;
    std::list<Cliente*> saida;
    int recebido{0};
    int perdido{0};
    int tics{0};

    public:

    

    Banco(int num_caixas){
        std::vector<Cliente*> caixas (num_caixas, nullptr);
        this->caixas = caixas;
    }

    int get_recebidos(){
        return this->recebido;
    }
    int get_perdidos(){
        return this->perdido;
    }
    int get_tics(){
        return this->tics;
    }
    void insert(Cliente * cliente){
        entrada.push_back(cliente);
    }

    bool empty(){
        int ax{0};

        for(auto cliente : caixas){
            if(cliente != nullptr){
                ax++;
            }
        }

        if(entrada.empty() && saida.empty() && ax == 0){
            return true;
        }
        return false;
    }

    void tic(){
        while(!saida.empty()){
            delete saida.front();
            saida.pop_front();
        }

        for(int i = 0; i < (int)caixas.size(); i++){
            if(caixas[i] != nullptr){
                if(caixas[i]->get_doc() != 0){
                    caixas[i]->diminuir_doc();
                    this->recebido++;
                } else {
                    saida.push_back(caixas[i]);
                    caixas[i] = nullptr;
                }
            } else {
                if(!entrada.empty()){
                    this->caixas[i] = entrada.front();
                    entrada.pop_front();
                }
            }
        }

        for(auto it = entrada.begin(); it != entrada.end();){
            if((*it)->get_pac() != 0){
                (*it)->diminuir_pac();
                it++;
            } else {
                saida.push_back(*it);
                this->perdido += (*it)->get_doc();
                it = entrada.erase(it);
            }
        }
        this->tics++;
    }

    void show(){
        for(auto cliente : caixas){
            std::cout << "[" << (cliente == nullptr ? "" : cliente->str()) << "]";
        }
        std::cout << "\nin :{";
        for(auto cliente : entrada){
            std::cout << cliente->str() << " ";
        }
        std::cout << "}\nout:{ ";
        for(auto cliente : saida){
            std::cout << cliente->str() << " ";
        } 
        std::cout << "}\n";
    }

};
#include <iostream>

class Cliente{
    std::string nome = "";
    int doc{0};
    int pac{0};

    public:
    
    Cliente(std::string nome, int ac, int pac){
        this->nome = nome;
        this->doc = ac;
        this->pac = pac;
    } 

    void diminuir_doc(){
        this->doc--;
    }
    void diminuir_pac(){
        this->pac--;
    }
    int get_pac(){
        return this->pac;
    }
    int get_doc(){
        return this->doc;
    }
    std::string str(){
        return nome + ":" + std::to_string(doc) + ":" + std::to_string(pac);
    }

};
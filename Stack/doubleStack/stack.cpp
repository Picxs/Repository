#include <iostream>
#include <stack>

int main(){
    std::stack<int> deposito;
    std::stack<int> pratileira;

    int queries;
    std::cin >> queries;
    

    for(int i = 0; i < queries; i++){
        int cmd{};
        std::cin >> cmd;

        switch(cmd){
            case 1:
            int valor;
            std::cin >> valor;
            deposito.push(valor);
            break;
            case 2:
            pratileira.pop();
            break;
            case 3:
            std::cout << pratileira.top() << std::endl;
            break;
            case 4:
            std::cout << deposito.top() << std::endl;
            break;
            default:
            std::cout << "ERRO : Comando Desconhecido" << std::endl;
        }
        if(pratileira.empty()){
            while(!deposito.empty()){
                pratileira.push(deposito.top());
                deposito.pop();
            }
        }
    }
}
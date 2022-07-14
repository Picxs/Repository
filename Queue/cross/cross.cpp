#include <iostream>
#include <queue>
#include <fstream>

int main(){
    std::ifstream input("input.txt");
    std::queue<char> times({'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'});
    
    while(times.size() != 1){
        std::string vencedor;

        vencedor.push_back(times.front());
        times.pop();
        vencedor.push_back(times.front());
        times.pop();

        int time1, time2;

        input >> time1 >> time2;

        if(time1 > time2){
            times.push(vencedor[0]);
        } else {
            times.push(vencedor[1]);
        }

    }
    std::cout << times.back() << std::endl;
}
#include <iostream>
#include <algorithm>
#include <vector>

bool can_put(std::vector<std::string> mat, std::vector<std::pair<int, int>> neib, int numl, int numc){
    
    int ncmax = mat[0].size();
    int nlmax = mat.size();
    int qnt = 0;

    if(mat[nl][nc] == ' '){
        return false;
    }

    for(auto viz : neib){
        if(viz.first < 0 || viz.first >= nlmax || viz.second < 0 || viz.second >= ncmax){
            continue;
        }
        if(mat[viz.first][viz.second] == '#'){
            qnt += 1;
        }
    }
    if(qnt >= 3){
        return true;
    }
    return false;
}

void create(std::vector<std::string>& mat, int numl, int numc){

    int ncmax = mat[0].size();
    int nlmax = mat.size();

    if(numl < 0 || numl >= nlmax || numc < 0 || numc >= ncmax){
        return;
    }

    std::vector<std:pair<int, int>> neib;

    neib.push_back({numl, numc - 1});
    neib.push_back({numl, numc + 1});
    neib.push_back({numl - 1, numc});
    neib.push_back({numl + 1, numc});

    // travei aq :/
}

void show(std::vector<std::string> mat){
    for(auto line : mat){
        std::cout << line << std::endl;
    }
}

int main(){
    
}




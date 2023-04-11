#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// Funcao para converter de decimal para binario
std::vector<bool> toBinary(int decimal, int size){
    std::vector<bool> binary;

    if(decimal == 0){
        binary.push_back(0);
    }

    else{
        while(decimal > 0){
            binary.push_back(decimal%2);
            decimal = decimal / 2;
        }
    }
    while(binary.size() != size)
        binary.push_back(0);

    std::reverse(binary.begin(), binary.end());

    return binary;
}

// Funcao para calcular as combinacoes
int findSum(std::vector<int>& v, int target){
    for(int i = 0; i < (int)pow(2, v.size()); i++){
        std::vector<bool> b = toBinary(i, v.size());
        int soma = 0;
        for(int j = 0; j < v.size(); j++){
            if(b[j] == 1){
                soma += v[j];
            }
        }
        if(soma == target)
            return 1;
    }

    return 0;
}

int main(){    
    vector<int> v1;

    int i, x;
    cin >> i;

    while(i != -1){
        v1.push_back(i);
        cin >> i;
    }

    cin >> x;

    if(findSum(v1, x))
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;

    return 0;
}
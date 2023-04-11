#include <iostream>
#include <vector>

using namespace std;

int findSum(vector<int>& v, int x){
    int soma = 0;
    int i = 0;

    for(int i = 0; i < v.size() -1; i++){
        soma += v[i];

        if(soma == x)
            return 1;
        else if(soma > x)
            soma -= v[i];
    }

    for(int i = 0; i < v.size() -1; i++){
        soma += v[i];
        for(j = 1; j < v.size(); j++){
            soma += v[j];
        }        
    }


    for(i = 0; i < v.size(); i++){
        soma += v[i];
        if(soma == x)
            return 1;
        else if(soma > x)
            break;
    }
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
            

    for(i = 0; i < v1.size(); i++)
        cout << v1[i] << endl;


    return 0;
}
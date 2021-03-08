#include <iostream>
#include <set>

using namespace std;

#define DISTANCE 5

/*
 Contenedor asociativo
*/
struct ValorAbsMenos {
    bool operator() (const int& v1, const int& v2) const {
        return (abs(v1-v2) < DISTANCE);
    }
};

void recorrer(set<int, ValorAbsMenos> valores) {
    for(auto v: valores) {
        cout << v << " ";
    }
    /* 
    for(set<int, ValorAbsMenos>::iterator it = valores.begin(); it!=valores.end(); it++) {
        cout << *it << " ";
    }*/
    cout << endl;
}

int main() {
    set<int, ValorAbsMenos> valores;
    valores.insert(5);
    valores.insert(9);
    valores.insert(3);
    valores.insert(7);
    
    recorrer(valores);
    return 0;
}


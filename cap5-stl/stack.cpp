#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
 El stack es un adaptador de secuencia de tipo LIFO
*/

int main() {
    vector<int> fichas;
    stack<int> pila;

    // rellenar el vector
    cout << "fichas" << endl;
    for(int i=0; i<10; i++) {
        fichas.push_back(i);
        cout << i << " ";
    }
    cout << endl;

    // apilar elementos para invertir
    for(int n: fichas) pila.push(n); 
    /*
    vector<int>::iterator it;
    for(it = fichas.begin(); it!=fichas.end(); ++it) {
        pila.push(*it);
    }*/

    fichas.clear();

    cout << "pila" << endl;
    while(!pila.empty()) {
        cout << pila.top() << " ";
        fichas.push_back(pila.top());
        pila.pop();
    }
    cout << endl;
    return 0;
}

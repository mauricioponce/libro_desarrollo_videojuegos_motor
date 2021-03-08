#include <iostream>
#include <queue>
#include <vector>
#include "util.cpp"
using namespace std;

/*
 El cola es un adaptador de secuencia de tipo FIFO
*/

void printVector() {

}

int main() {
    vector<int> fichas;
    vector<int>::iterator it;
    queue<int> cola;

    // rellenar el vector
    for(int i=0; i<10; i++) {
        fichas.push_back(i);
    }
    cout << "fichas" << endl;
    print_vector(fichas);

    // apilar elementos para invertir
    for(it = fichas.begin(); it!=fichas.end(); ++it) {
        cola.push(*it);
    }

    fichas.clear();

    while(!cola.empty()) {
        fichas.push_back(cola.front());
        cola.pop();
    }

    cout << "fichas invertidas" << endl;
    print_vector(fichas);
    
    return 0;
}

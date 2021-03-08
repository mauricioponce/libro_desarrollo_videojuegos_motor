#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, string> jugadores;
    pair<map<int, string>::iterator, bool> ret;

    // agregar jugadores
    jugadores.insert(pair<int, string>(1, "Luis"));
    jugadores.insert(pair<int, string>(2, "Sergio"));

    // comprobando elementos insertados
    ret = jugadores.insert(pair<int, string>(2, "David"));

    if(ret.second == false) {
        cout << "el elemento 2 ya existe con valor " << ret.first->second << endl;
    }

    // inserción con []
    jugadores[3] = "Alfredo";

    const string& j_aux = jugadores[4];

    return 0;
}

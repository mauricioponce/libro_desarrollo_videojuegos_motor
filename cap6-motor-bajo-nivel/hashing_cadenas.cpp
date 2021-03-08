#include <iostream>
#include <string>
#include <boost/functional/hash.hpp>
using namespace std;

// Si se pasa una referencia al string, se hace uso del constructor copia en desmedro del rendimiento.
// Si se pasa el puntero se logra mejor rendimiento
size_t internalString(string& value) {
    return boost::hash_value(&value);
};


static size_t sid_hola = internalString("hola");
static size_t sid_mundo = internalString("mundo");


int main() {
    cout << "sid_hola " << sid_hola << endl;
    cout << "sid_mundo " << sid_mundo << endl;

    // Las comparaciones de enteros son mas baratas que las de strings.

    return 0;
}

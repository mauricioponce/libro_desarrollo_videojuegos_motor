#include <iostream>
#include <vector>

using namespace std;

/*
TODO
[ ] test unitarios
[ ] refactorización
*/

int main() {
    vector<int> v;

    v.push_back(7);
    v.push_back(3);
    v.push_back(6);

/*
    vector<int>::iterator it;

    for(it = v.begin(); it != v.end(); ++it) {
        cout << *it << endl;
    }
*/
    for(int n: v) cout << n << endl;

    // ----------------------
    cout << "-------------------------" << endl;
    vector<int> v1;
    v1.reserve(4);
    cout << "capacidad inicial " << v1.capacity() << endl;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    cout << "capacidad actual " << v1.capacity() << endl;

    v1.push_back(5);
    cout << "capacidad reasignada " << v1.capacity() << endl;

    return 0;
}

#include <iostream>
using namespace std;

class A {
private:
    int _value;
public:
    A(int value) : _value(value) {
        cout << "constructor" << endl;
    }

    ~A() {
        cout << "destructor" << endl;
    }

    int getValue() const { return _value; }
};

// passing a reference to pointer 
void showValue(A &a) {
    cout << a.getValue() << endl;
}

int main() {
    A a(7);
    showValue(a);
    return 0;
}


class Firearm {
public:
    virtual float noise() const = 0;
    virtual int bullets() const = 0;
};

class Rifle: public Firearm {
public:
    float noise () const { return 150.0; }
    int bullets () const { return 5; }
};

/* Decorators */
class FirearmDecorator: public Firearm {
protected:
    Firearm* _gun;
public:
    FirearmDecorator(Firearm* gun): _gun(gun) { };
    virtual float noise () const { return _gun-> noise(); }
    virtual int bullets () const { return _gun-> bullets(); }
};

class Silencer: public FirearmDecorator {
public:
    Silencer(Firearm* gun): FirearmDecorator(gun) { };
    float noise () const { return _gun->noise() - 55; }
    int bullets () const { return _gun->bullets() + 5; }
};

class Magazine: public FirearmDecorator {
public:
    Magazine(Firearm* gun): FirearmDecorator(gun) { };
    float noise () const { return _gun->noise(); }
    int bullets () const { return _gun->bullets() + 5; }
};

#include <iostream>
using namespace std;
/* Using decorators */
int main() {
    Firearm* gun = new Rifle();
    cout << "Rifle Noise: " << gun->noise() << endl;
    cout << "Rifle bullets: " << gun->bullets() << endl;

    //get a silencer
    gun = new Silencer(gun);
    cout << "Silencer Noise: " << gun->noise() << endl;
    cout << "Silencer bullets: " << gun->bullets() << endl;

    //gets a new magazine
    gun = new Magazine(gun);
    cout << "Magazine Noise: " << gun->noise() << endl;
    cout << "Magazine bullets: " << gun->bullets() << endl;

    return 0;
}

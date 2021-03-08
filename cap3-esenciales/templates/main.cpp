#include <iostream>

using namespace std;

template<class T> class Triangle {
public:
    Triangle(const T &v1, const T &v2, const T &v3): _v1(v1), _v2(v2), _v3(v3) { }
    ~Triangle() { }
    T getV1() const { return _v1; }
    T getV2() const { return _v2; }
    T getV3() const { return _v3; }
private:
    T _v1, _v2, _v3;
};

class Vec2 {
public:
    Vec2(int x, int y): _x(x), _y(y) { }
    ~Vec2() { }
    int getX() const { return _x; }
    int getY() const { return _y; }
private:
    int _x, _y;
};

int main() {
    Vec2 p1(2,7), p2(3,4), p3(7,10);
    Triangle<Vec2> t(p1, p2, p3);

    cout << "V1: [" << t.getV1().getX() << "," << t.getV1().getY() << "]" << endl;
    return 0;
}

#include <iostream>
#include <list>
#include <stdlib.h>

using namespace std;

class Class {
public:
    Class(int id, int students_num): _id(id), _students_num(students_num) { }
    int getId() const { return _id; }
    int getStudentsNum() const { return _students_num; }

    bool operator< (const Class &c) const {
        return _students_num < c.getStudentsNum();
    }

private:
    int _id;
    int _students_num;
};


ostream& operator<<(ostream& os, const Class& item) {
    return os << item.getId() << ":"  << item.getStudentsNum() << " ";
}

void show_classrooms(list<Class> &li) {
    for(Class c: li){
        cout << c;
    }
    cout << endl;
}

int main() {
    list<Class> classes;
    srand(time(NULL));
    for(int i=0; i < 10; i++) {
        classes.push_back(Class(i,int(rand() % 30 + 10)));
    }

    cout << "===== Unsorted =====" << endl;
    show_classrooms(classes);
    classes.sort();
    cout << "===== Sorted =====" << endl;
    show_classrooms(classes);
    return 0;
}

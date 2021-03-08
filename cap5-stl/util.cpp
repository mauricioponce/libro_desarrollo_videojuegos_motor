#include <iostream>

template<typename T>
void print_queue(T q) { // NB: pass by value so the print uses a copy
    while(!q.empty()) {
        std::cout << q.top() << ' ';
        q.pop();
    }
    std::cout << std::endl;
};


template<typename T>
void print_vector(T v) {
    std::cout << "v={";
    for(int n: v) {
        std::cout << n << ' ';
    }
    std::cout << "}" << std::endl;
}

#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include "util.cpp"

using namespace std;

int main() {
    priority_queue<int> pq1;

    // "normal" queue
    const auto data = {1,8,5,6,3,4,0,9,7,2}; 

    for(int n:data) {
        pq1.push(n);
    }
    print_queue(pq1);

    // priority queue
    priority_queue<int, vector<int>, greater<int>> pq2(data.begin(), data.end());
     
    print_queue(pq2);

    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
 
    for(int n : data)
        q3.push(n);
 
    print_queue(q3);
    
    return 0;
}

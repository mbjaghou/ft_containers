#include "stack.hpp"
#include <iostream>

int main() {
    ft::stack<int> pstack;
    pstack.push(21);
    pstack.push(22);
    pstack.push(24);
    pstack.push(25);
       
    pstack.pop();
    pstack.pop();
   
    while (!pstack.empty()) {
        std::cout << pstack.top() <<" ";
        pstack.pop();
    }
}
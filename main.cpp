#include "stack.hpp"
#include "vector.hpp"
#include <iostream>

int main() {
    // ft::stack<int> pstack;
    // pstack.push(21);
    // pstack.push(22);
    // pstack.push(24);
    // pstack.push(25);
       
    // pstack.pop();
    // pstack.pop();
   
    // while (!pstack.empty()) {
    //     std::cout << pstack.top() <<" ";
    //     pstack.pop();
    // }

    ft::vector<int> vect(2, 10);
    for (size_t i = 0; i < vect.size(); ++i) {
        std::cout << vect[i] << ' ';
    }
    std::cout <<'\n';

    ft::vector<int> vect2(vect.begin(), vect.end());
   for (size_t i = 0; i < vect2.size(); ++i) {
        std::cout << vect2[i] << ' ';
    }
    std::cout <<'\n';
    std::cout << "test only\n";
    vect2.push_back(5);
    vect2.push_back(-5);
     vect2.push_back(-5);
    std::cout << vect2.capacity() << std::endl;
    for (size_t i = 0; i < vect2.size(); ++i) {
        std::cout << vect2[i] << ' ';
    }
    std::cout <<'\n';

    std::cout <<"test push_back\n";
    ft::vector<int> vect3;
    std::cout << vect3.capacity() << std::endl;
    vect3.push_back(1);
    vect3.push_back(1);
    vect3.push_back(1);
    vect3.push_back(1);
    vect3.push_back(1);
    for (size_t i = 0; i < vect3.size(); ++i)
        std::cout << vect3[i] << std::endl;
    std::cout << vect3.capacity() << std::endl;
    std::cout <<"test resize\n\n\n\n";
    ft::vector<int> ob;

    ob.push_back(1);
    ob.push_back(1);
    ob.push_back(1);
    ob.push_back(1);
    ob.push_back(1);

    for (size_t i = 0; i < ob.size(); i++)
    {
        std::cout << ob[i] << "\n\n";
    }
    ob.resize(8);
    std::cout << "after resize" << "\n\n";
    for (size_t i = 0; i < ob.size(); i++)
    {
        std::cout << ob[i] << "\n";
    }

    std::cout << "test assign\n";

    ft::vector<int> obj2(10, 24);

    obj2.assign(1, 8);
    for(size_t i = 0; i < obj2.size(); ++i)
        std::cout << obj2[i] << " " << std::endl;

    std::cout << "test insert\n";

    ft::vector<int> obj1(10, 24);

    obj1.insert(obj1.begin() + 2, 100, 8);
    for(size_t i = 0; i < obj1.size(); ++i)
        std::cout << obj1[i] << " " << std::endl;


}
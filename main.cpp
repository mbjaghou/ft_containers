#include "stack.hpp"
#include "vector.hpp"
#include <iostream>

// class test {
// private:
//     int* i;
// public:
//     test() {
//         i = new int;
//     }
//     test(int* j) {
//         i = new int;
//         *i = *j;
//     }
//     ~test() {
//         if (i)
//             delete i;
//     }
//     int* operator+(int n) {
//         return i + n;
//     }
//     test& operator=(test& m) {
//         if (i)
//             free (i);
//         i = new int;
//         *i = *m.i;
//         return *this;
//     }
// };

void print()
{
    std::cout << "test erase\n";
    // ft::vector<test> oo;

    // int val = 10;
    // int val2 = 20;
    // int *ptr = &val;
    // int *ptr2 = &val2;
    // int val3 = 30;
    // int *ptr3 = &val3;

    // test    tst1(ptr);
    // test    tst2(ptr2);
    // test    tst3(ptr3);

    // oo.push_back(tst1);
    // oo.push_back(tst2);
    // oo.push_back(tst3);

    // oo.erase(oo.begin());

    ft::vector<ft::vector<int> > oo;

    ft::vector<int> i(2, 2);
    ft::vector<int> j(3, 3);
    ft::vector<int> k(4, 4);
    oo.push_back(i);
    oo.push_back(j);
    oo.push_back(k);

    oo.erase(oo.begin() + 2, oo.end());
    // for (size_t i = 0; i < oo.size(); ++i)
        // std::cout << oo[i] << " test\n";
}
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

//     ft::vector<int> vect(2, 10);
//     for (size_t i = 0; i < vect.size(); ++i) {
//         std::cout << vect[i] << ' ';
//     }
//     std::cout <<'\n';

//     ft::vector<int> vect2(vect.begin(), vect.end());
//    for (size_t i = 0; i < vect2.size(); ++i) {
//         std::cout << vect2[i] << ' ';
//     }
//     std::cout <<'\n';
//     std::cout << "test only\n";
//     vect2.push_back(5);
//     vect2.push_back(-5);
//      vect2.push_back(-5);
//     std::cout << vect2.capacity() << std::endl;
//     for (size_t i = 0; i < vect2.size(); ++i) {
//         std::cout << vect2[i] << ' ';
//     }
//     std::cout <<'\n';

//     std::cout <<"test push_back\n";
//     ft::vector<int> vect3;
//     std::cout << vect3.capacity() << std::endl;
//     vect3.push_back(1);
//     vect3.push_back(1);
//     vect3.push_back(1);
//     vect3.push_back(1);
//     vect3.push_back(1);
//     for (size_t i = 0; i < vect3.size(); ++i)
//         std::cout << vect3[i] << std::endl;
//     std::cout << vect3.capacity() << std::endl;
//     std::cout <<"test resize\n\n\n\n";
//     ft::vector<int> ob;

//     ob.push_back(1);
//     ob.push_back(1);
//     ob.push_back(1);
//     ob.push_back(1);
//     ob.push_back(1);

//     for (size_t i = 0; i < ob.size(); i++)
//     {
//         std::cout << ob[i] << "\n\n";
//     }
//     ob.resize(8);
//     std::cout << "after resize" << "\n\n";
//     for (size_t i = 0; i < ob.size(); i++)
//     {
//         std::cout << ob[i] << "\n";
//     }

//     std::cout << "test assign\n";

//     ft::vector<int> obj2(10, 24);

//     obj2.assign(1, 8);
//     for(size_t i = 0; i < obj2.size(); ++i)
//         std::cout << obj2[i] << " " << std::endl;

//     std::cout << "test insert\n";

//     ft::vector<int> obj1;
//     ft::vector<int> obj8(15, 5);

//     obj1.insert(obj1.begin(), obj8.begin() , obj8.end());
//     for(size_t i = 0; i < obj1.size(); ++i)
//         std::cout << obj1[i] << " " << std::endl;
    // print();
}
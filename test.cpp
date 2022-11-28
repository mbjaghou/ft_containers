#include <iostream>
#include "is_integral.hpp"
#include <vector>

using namespace std;


// general template
template <class T>
bool Eq(T lhs, T rhs,typename ft::enable_if<ft::is_integral<T>::value >::type* = 0)
{
    std::cout << "first 1\n";
    return (lhs == rhs);
}

//handel the overoding betwine template that take the same paramter is call sfinae
// enable if hanedl , sfinae is maen substitution failure is not an error 
template <class T>
bool Eq(T LJ, T lQ ,typename ft::enable_if<!ft::is_integral<T>::value >::type* = 0)
{
    std::cout << "first 2\n";
    return (true);
}
// tmplate specialization

// template <>
// bool Eq<int>(int n, int b)
// {
//     cout << "spisifiq int\n";
//     return (n == b);
// }
int main()
{
    std::vector<std::string> obj(5, "mouhamed");
    if (Eq(obj.begin(), obj.end()))
        return (true);
    if (Eq(obj.begin(), obj.end()))
        return (true);
    return (false);
}
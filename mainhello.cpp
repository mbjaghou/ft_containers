#include <iostream>





template <class T>
class hello5
{
    public:

        hello5(T O, T c)
        {
            std::cout << "hello1\n";
        }

        template <class To>
        hello5(T Ou, T cu)
        {
            std::cout << "hello2\n";
        }
};
// template <class T>

// T hello(T Ob, T cb)
// {
//     std::cout << "hello3\n";
// }


int main ()
{
    hello5<int> s(5, 5);
}
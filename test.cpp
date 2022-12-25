#include "map.hpp"

int main()
{
    ft::map<int, int> map1;

    map1[188] = 455;
    map1[19] = 455;
    map1[23] = 451;
    map1[24] = 451;
    map1[25] = 451;
    map1[26] = 451;

    // map1.insert(map1.begin(), ft::pair<int, int>(1, 2));
    ft::map<int, int>::iterator it;
    it = map1.begin();

    // std::cout << it->first << std::endl;
    for(; it != map1.end(); ++it)
        std::cout << it->first << std::endl;

    // std::cout << map1.max_size() << std::endl;

}
#include "map.hpp"

int main()
{
    ft::map<int, int> map1;

    map1[188] = 455;
    map1[19] = 80;
    map1[23] = 90;
    map1[24] = 100;
    map1[25] = 200;
    map1[26] = 300;

    map1.insert(ft::pair<int, bool>(90, 1));
    ft::map<int, int>::iterator it;

    it = map1.begin();

    // std::cout << it->first << std::endl;
    for(; it != map1.end(); ++it)
        std::cout << it->first << " " <<  it->second << std::endl;


    // ft::map<int, int> map2;

    // map2[1] = 45;
    // map2[2] = 45;
    // map2[3] = 45;
    // map2[4] = 45;
    // map2[5] = 45;

    // // if (map1 < map2)
    // //     std::cout << "true" << std::endl;
    // // else
    // //     std::cout << "false" << std::endl;
    // swap(map2, map1);
    // ft::map<int, int>::iterator it2;
    // it2 = map2.begin();
    // // map2.erase(it2);
    // std::cout << "----------------" << std::endl;
    // for(; it2 != map2.end(); ++it2)
    //     std::cout << it2->first << " " <<  it2->second << std::endl;

    // std::cout << "----------------" << std::endl;

    // std::cout << map1.at(1) << std::endl;

    // std::cout << map1.max_size() << std::endl;

}
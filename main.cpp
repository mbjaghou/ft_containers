/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:22:24 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/12/29 20:15:15 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include "vector.hpp"
#include <iostream>
#include "map.hpp"

using namespace std;
void ft_vector()
{
    cout << "\033[32m---------------->constructs the vector---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(5, 10);

        ft::vector<int>::iterator it;
        for (it = obj.begin(); it != obj.end(); ++it)
            cout << *it << " ";
        cout << endl;

        ft::vector<int> obj1(obj.begin() + 2, obj.end());
        ft::vector<int>::iterator it1;
        for (it1 = obj1.begin(); it1 != obj1.end(); ++it1)
            cout << *it1 << " ";
        cout << endl;
    }
    cout << "\033[32m---------------->Copy assignment operator---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(5, 10);
        ft::vector<int> obj1(5, 5);

        obj = obj1;
        ft::vector<int>::iterator it;
        for (it = obj.begin(); it != obj.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << "\033[32m---------------->assign---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(5, 10);
        ft::vector<int> obj1(5, 5);

        obj.assign(10, 15);
        ft::vector<int>::iterator it;
        for (it = obj.begin(); it != obj.end(); ++it)
            cout << *it << " ";
        cout << endl;

        obj1.assign(obj.begin() + 5, obj.end());
        ft::vector<int>::iterator it1;
        for (it1 = obj1.begin(); it1 != obj1.end(); ++it1)
            cout << *it1 << " ";
        cout << endl;
    }
    cout << "\033[32m---------------->at---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(5, 10);

        obj.push_back(1);
        const int &i = obj.at(5);
        cout << i << endl;
    }
    cout << "\033[32m---------------->operator[]---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(15);

        for (size_t i = 0; i < obj.size(); ++i)
            obj[i] = i + 1;
        for (size_t i = 0; i < obj.size(); ++i)
            cout << obj[i] << " ";
        cout << endl;
    }
    cout << "\033[32m---------------->front---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(1, 150);

        cout << obj.front() << endl;
    }
    cout << "\033[32m---------------->back---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(1, 150);

        obj.push_back(90);

        cout << obj.back() << endl;
    }
    cout << "\033[32m---------------->data---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(10, 20);

        int *p = obj.data();

        for (size_t i = 0; i < obj.size(); ++i)
            cout << p[i] << " ";
        cout << endl;
    }
    cout << "\033[32m---------------->Iterators begin---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(10, 80);

        ft::vector<int>::iterator it = obj.begin();

        cout << *it << endl;
    }
    cout << "\033[32m---------------->Iterators end---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(10, 80);

        obj.push_back(10);

        ft::vector<int>::iterator it = obj.end() - 1;

        cout << *it << endl;
    }
    cout << "\033[32m---------------->reverse_iterator rbegin, rend---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(10, 15);

        for (size_t i = 0; i < obj.size(); ++i)
            obj[i] = i + 1;
        ft::vector<int>::reverse_iterator it = obj.rbegin();
    
        for (; it != obj.rend(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << "\033[32m---------------->empty---------------->\033[0m" << endl;
    {
        ft::vector<int> obj;

        if (obj.empty())
            cout << "is empty" << endl;
        else
            cout << "is not" << endl;
    }
    cout << "\033[32m---------------->size---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(10, 10);

        size_t i = obj.size();

        cout << i << endl;
    }
    cout << "\033[32m---------------->max_size---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(10, 10);

        size_t i = obj.max_size();

        cout << i << endl;
    }
    cout << "\033[32m---------------->capacity---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(10, 10);

        obj.push_back(5);
        size_t i = obj.capacity();

        cout << i << endl;
    }
    cout << "\033[32m---------------->reserve---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(10, 10);

        ft::vector<int>::iterator it;
        for (it = obj.begin(); it != obj.end(); ++it)
            cout << *it << " ";
        cout << endl;
        cout << "capacity: " << obj.capacity() << endl;
        obj.reserve(15);
        cout << "capacity: " << obj.capacity() << endl;
    }
    cout << "\033[32m---------------->clear---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(10, 10);

        obj.push_back(1);

        cout << obj.size() << endl;
        obj.clear();
        cout << obj.size() << endl;
    }
    cout << "\033[32m---------------->insert---------------->\033[0m" << endl;
    {
        ft::vector<int> obj;
        obj.push_back(1);
        obj.push_back(2);
        obj.push_back(3);
        obj.push_back(4);
        obj.push_back(5);

        obj.insert(obj.begin() + 2, 80);
        ft::vector<int>::iterator it;
        for (it = obj.begin(); it != obj.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << "\033[32m---------------->insert2---------------->\033[0m" << endl;
    {
        ft::vector<int> obj;
        obj.push_back(1);
        obj.push_back(2);
        obj.push_back(3);
        obj.push_back(4);
        obj.push_back(5);

        obj.insert(obj.begin() + 2, 5, 80);
        ft::vector<int>::iterator it;
        for (it = obj.begin(); it != obj.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << "\033[32m---------------->insert3---------------->\033[0m" << endl;
    {
        ft::vector<int> obj;
        ft::vector<int> obj1(5, 100);
        obj.push_back(1);
        obj.push_back(2);
        obj.push_back(3);
        obj.push_back(4);
        obj.push_back(5);

        obj.insert(obj.begin() + 2, obj1.begin(), obj1.end());
        ft::vector<int>::iterator it;
        for (it = obj.begin(); it != obj.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << "\033[32m---------------->erase---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(10, 100);

        obj.push_back(1);
        obj.push_back(2);
        obj.push_back(3);

        obj.erase(obj.begin() + 11);
        ft::vector<int>::iterator it;
        for (it = obj.begin(); it != obj.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << "\033[32m---------------->erase1---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(10, 100);

        obj.push_back(1);
        obj.push_back(2);
        obj.push_back(3);

        obj.erase(obj.begin() + 5 , obj.end());
        ft::vector<int>::iterator it;
        for (it = obj.begin(); it != obj.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << "\033[32m---------------->push_back---------------->\033[0m" << endl;
    {
        ft::vector<int> obj;
        obj.push_back(1);
        obj.push_back(2);
        obj.push_back(3);
        obj.push_back(4);
        obj.push_back(5);
        obj.push_back(6);
        obj.push_back(7);
        obj.push_back(8);
        ft::vector<int>::iterator it;
        for (it = obj.begin(); it != obj.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << "\033[32m---------------->pop_back---------------->\033[0m" << endl;
    {
        ft::vector<int> obj;
        obj.push_back(1);
        obj.push_back(2);
        obj.push_back(3);
        obj.push_back(4);
        obj.push_back(5);
        obj.push_back(6);
        obj.pop_back();
        obj.push_back(7);
        obj.pop_back();
        obj.push_back(8);
        obj.pop_back();
        ft::vector<int>::iterator it;
        for (it = obj.begin(); it != obj.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << "\033[32m---------------->resize---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(30, 10);

        cout << "size : " <<  obj.size() << endl;
        obj.resize(10);
        cout << "resize : " << obj.size() << endl;

        ft::vector<int> obj1(5, 10);

        cout << "size : " <<  obj1.size() << endl;
        obj1.resize(10, 20);
        cout << "resize : " << obj1.size() << endl;
        ft::vector<int>::iterator it;
        for (it = obj1.begin(); it != obj1.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << "\033[32m---------------->swap---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(10, 100);
        ft::vector<int> obj1(10, 200);

        obj.swap(obj1);
        ft::vector<int>::iterator it;
        for (it = obj.begin(); it != obj.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << "\033[32m---------------->operator==,!=,<,<=,>,>=;---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(5, 10);
        ft::vector<int> obj1(obj);
        ft::vector<int> obj2(10, 15);

        if (obj == obj1)
            cout << "operator == " << endl;
        if (obj != obj2)
            cout << "operator != " << endl;
        if (obj < obj2)
            cout << "operator < " << endl;
        if (obj2 > obj)
            cout << "operator > " << endl;
        if (obj >= obj1)
            cout << "operator >= " << endl;
        if (obj <= obj1)
            cout << "operator <= " << endl;
    }
    cout << "\033[32m---------------->::swap---------------->\033[0m" << endl;
    {
        ft::vector<int> obj(10, 50);
        ft::vector<int> obj1(10, 150);

        swap(obj, obj1);
        
        ft::vector<int>::iterator it;
        for(it = obj.begin(); it != obj.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
}

void ft_stack()
{
    ft::stack<int> stack;
    stack.push(21);
    stack.push(22);
    stack.push(24);
    stack.push(25);
   
    while (!stack.empty()) {
        cout << stack.top() <<" ";
        stack.pop() ;
    }
    cout << endl;
    cout << "size now = "<< stack.size() << endl;
}

void ft_map()
{
    cout << "constructing map" << endl;
    {
        ft::map<char, int> map;

        map['a'] = 1;
        map['b'] = 2;
        map['c'] = 3;
        ft::map<char, int> map1(map.begin(), map.end());

        ft::map<char, int> map2;

        map2 = map1;

        ft::map<char, int>::iterator it = map2.begin();

        for(; it != map2.end(); it++)
        {
            cout << it->first << " " << it->second << endl;
        }
    }
    cout << "iterator begin , end" << endl;
    {
        ft::map<int, int> map;

        map[10] = 100;
        map[11] = 200;
        map[5] = 78;

        ft::map<int, int>::iterator be = map.begin();

        cout << "iteartor begin -> " << be->first << " " << be->second << endl;

        for(; be != map.end(); be++)
            cout << be->first << " " << be->second << endl;
    }
    cout << "iterator rbegin , rend" << endl;
    {
        ft::map<int, int> map;

        map[10] = 10;
        map[20] = 10;
        map[30] = 10;
        map[40] = 10;

        ft::map<int, int>::reverse_iterator it = map.rbegin();
        for (; it != map.rend(); it++)
            cout << it->first << " " << it->second << endl;
    }
    cout << "capacity empty, size, max size" << endl;
    {
        ft::map<int, int> map;

        map[10] = 10;
        map[20] = 10;
        map[30] = 10;
        map[40] = 10;

        cout << "size map = " << map.size() << endl;
        cout << "max size = " << map.max_size() << endl;

        if (map.empty())
            cout << "is empty" << endl;
        else
            cout << "is not" << endl;
    }
    cout << "Element access: operator[], at" << endl;
    {
            ft::map<const char,int> mymap;

            mymap.insert(ft::make_pair<const char, int>('a', 1));
            mymap['b'] = 2;
            mymap['c'] = 3;

            cout << "mymap['a'] is " << mymap['a'] << '\n';
            cout << "mymap['b'] is " << mymap['b'] << '\n';
            cout << "mymap['c'] is " << mymap['c'] << '\n';
            cout << "mymap now contains " << mymap.size() << " elements.\n";


            ft::map<char, int> map(mymap.begin(), mymap.end());

            cout << "at   a=> " << map.at('a') << endl;
            cout << "at   b=> " << map.at('b') << endl;
            cout << "at   c=> " << map.at('c') << endl;
    }
    cout << "Modifiers insert" << endl;
    {
        ft::map<int, int> map;
        ft::map<int, int> map1;

        map1[60] = 60;
        map1[70] = 70;
        map1[80] = 80;
        map1[90] = 90;

        map[1] = 122;
        map[2] = 20;
        map[3] = 30;
        map[4] = 40;
        ft::pair<ft::map<int, int>::iterator, bool> pair;

        pair = map.insert(ft::pair<int, int>(5, 18));
        if (pair.second)
            cout << "true\n";
        else
            cout << "false\n";

        map.insert(map1.begin(), map1.end());

        map.insert(map.begin(), ft::pair<int, int>(100, 1000));
        ft::map<int, int>::iterator it2 = map.begin();
        for(; it2 != map.end(); ++it2) 
          cout << it2->first << "      "  << it2->second << endl;

    }
    cout << "Modifiers erase" << endl;
    {
        ft::map<int, int> map;

        map[10] = 10;
        map[20] = 20;
        map[30] = 30;
        map[40] = 40;
        map[50] = 50;

        ft::map<int, int>::iterator it = map.begin();

        for (;it != map.end(); ++it)
            cout << it->first << "    " << it->second << endl;

        map.erase(map.begin());
        cout << "after erase white give hime the position" << endl;
        ft::map<int, int>::iterator it1 = map.begin();
        for (;it1 != map.end(); ++it1)
            cout << it1->first << "    " << it1->second << endl;


        map.erase(20);
        cout << "after erase white give hime the key_type" << endl;
        ft::map<int, int>::iterator it2 = map.begin();
        for (;it2 != map.end(); ++it2)
            cout << it2->first << "    " << it2->second << endl;

        cout << "after erase white give hime the first and last" << endl;
        map.erase(map.begin(), map.end());
        ft::map<int, int>::iterator it3 = map.begin();
        for (;it3 != map.end(); ++it3)
            cout << it3->first << "    " << it3->second << endl;
        cout << "is clean" << endl;
    }
    cout << "Modifiers clear" << endl;
    {
        ft::map<char, char> map;

        map['a'] = 'b';
        map['b'] = 'c';
        map['j'] = 'o';

        ft::map<char, char>::iterator it = map.begin();
        for (;it != map.end(); ++it)
            cout << it->first << "    " << it->second << endl;
        map.clear();
        ft::map<char, char>::iterator it2 = map.begin();
        for (;it2 != map.end(); ++it2)
            cout << it2->first << "    " << it2->second << endl;
        cout << "after clear" << endl;
    }
    cout << "Modifiers swap" << endl;
    {
        ft::map<int, int> map;

        map[10] = 10;
        map[20] = 20;
        map[30] = 30;
        map[40] = 40;
        map[50] = 50;

        ft::map<int, int> map1;
        map1[60] = 60;
        map1[70] = 70;
        map1[80] = 80;
        map1[90] = 90;
        map1[100] = 100;
        
        map1.swap(map);

        ft::map<int, int>::iterator it2 = map.begin();
        
        for (; it2 != map.end(); ++it2)
            cout << it2->first << "     " << it2->second << endl;

        ft::map<int, int>::iterator it = map1.begin();
        
        for (; it != map1.end(); ++it)
            cout << it->first << "     " << it->second << endl;
    }
    cout << "Lookup count" << endl;
    {
        ft::map<char, int> mymap;
        char c;
        mymap ['a']=101;
        mymap ['c']=202;
        mymap ['f']=303;

        for (c='a'; c<'h'; c++)
        {
            cout << c;
            if (mymap.count(c)>0)
            cout << " is an element of mymap.\n";
            else 
            cout << " is not an element of mymap.\n";
        }
    }
    cout << "lookup find" << endl;
    {
        ft::map<int, int> map;
        map[10] = 10;
        map[20] = 20;
        map[30] = 30;
        map[40] = 40;
        map[50] = 50;

        for (ft::map<int, int>::iterator itr = map.find(20); itr != map.end(); itr++) {
                cout << itr->first << '\t' << itr->second << '\n';
    }
    }
    cout << "lookup equal_range" << endl;
    {
        ft::map<int, int> map;
        map[10] = 10;
        map[20] = 20;
        map[30] = 30;
        map[40] = 40;
        map[50] = 50;

        ft::pair<ft::map<int, int>::iterator , ft::map<int, int>::iterator> pair;

        pair = map.equal_range(10);
        cout << pair.first->first << "   "  << pair.first->second << "   " 
        << pair.second->first << "   " << pair.second->second <<  endl;
    }
    cout << "lookup lower_bound" << endl;
    {
        ft::map<int, int> map;
        map[10] = 10;
        map[20] = 20;
        map[30] = 30;
        map[40] = 40;
        map[50] = 50;

        ft::map<int, int>::iterator it = map.lower_bound(20);
        cout << it->first  << "    " << it->second << endl;

    }
    cout << "lookup upper_bound" << endl;
    {
        ft::map<int, int> map;
        map[10] = 10;
        map[20] = 20;
        map[30] = 30;
        map[40] = 40;
        map[50] = 50;

        ft::map<int, int>::iterator it = map.upper_bound(40);
        cout << it->first  << "    " << it->second << endl;
    }
    cout << "Observers key_comp" << endl;
    {
        ft::map<char, int> map;
        ft::map<char, int>::key_compare comp = map.key_comp();

        map['a'] = 10;
        map['b'] = 20;
        map['c'] = 30;
        map['d'] = 40;
    
        cout << "Map has the elements\n";
    
        char l = map.rbegin()->first;
        ft::map<char, int>::iterator it = map.begin();
        do {
    
            cout << it->first << " => " << it->second << '\n';
        } while (comp((*it++).first, l));
    
    }   
    cout << "Observers value_comp" << endl;
    {
        ft::map<char,int> mymap;

        mymap['x']=1001;
        mymap['y']=2002;
        mymap['z']=3003;

        cout << "mymap contains:\n";

        ft::pair<char,int> highest = *mymap.rbegin();

        ft::map<char,int>::iterator it = mymap.begin();
        do {
            std::cout << it->first << " => " << it->second << '\n';
        } while ( mymap.value_comp()(*it++, highest) );
    }
    cout << "Non-member functions operator" << endl;
    {
        ft::map<int, int> map;
        map[10] = 10;
        map[20] = 20;
        map[30] = 30;
        map[40] = 40;
        map[50] = 50;
        ft::map<int, int> map1(map);
        ft::map<int, int> map2;
        map2[60] = 10;
        map2[70] = 20;
        map2[80] = 30;
        map2[90] = 40;
        map2[100] = 50;
        if (map == map1)
            cout << "operator == " << endl;
        if (map != map2)
            cout << "operator != " << endl;
        if (map < map2)
            cout << "operator < " << endl;
        if (map2 > map)
            cout << "operator > " << endl;
        if (map >= map1)
            cout << "operator >= " << endl;
        if (map <= map1)
            cout << "operator <= " << endl;
    }
    cout << "Non-member functions swap" << endl;
    {
        ft::map<int, int> map;

        map[10] = 10;
        map[20] = 20;
        map[30] = 30;
        map[40] = 40;
        map[50] = 50;

        ft::map<int, int> map1;
        map1[60] = 60;
        map1[70] = 70;
        map1[80] = 80;
        map1[90] = 90;
        map1[100] = 100;
        
        swap(map1, map);

        ft::map<int, int>::iterator it2 = map.begin();
        
        for (; it2 != map.end(); ++it2)
            cout << it2->first << "     " << it2->second << endl;

        ft::map<int, int>::iterator it = map1.begin();
        
        for (; it != map1.end(); ++it)
            cout << it->first << "     " << it->second << endl;
    }
}

int main()
{
    cout << "\033[41mvector testing\033[0m" << endl;
    ft_vector();
    cout << "\033[41mstack testing\033[0m" << endl;
    ft_stack();
    std::cout << "\033[41mtesting map\033[0m" << std::endl;
    ft_map();

}
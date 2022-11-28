/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:22:24 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/11/28 11:07:43 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include "vector.hpp"
#include <iostream>

using namespace std;
void vectortest()
{
    cout << "constructs the vector" << endl;
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
    cout << "Copy assignment operator" << endl;
    {
        ft::vector<int> obj(5, 10);
        ft::vector<int> obj1(5, 5);

        obj = obj1;
        ft::vector<int>::iterator it;
        for (it = obj.begin(); it != obj.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << "assign" << endl;
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
    cout << "at" << endl;
    {
        ft::vector<int> obj(5, 10);

        obj.push_back(1);
        const int &i = obj.at(5);
        cout << i << endl;
    }
    cout << "operator[]" << endl;
    {
        ft::vector<int> obj(15);

        for (size_t i = 0; i < obj.size(); ++i)
            obj[i] = i + 1;
        for (size_t i = 0; i < obj.size(); ++i)
            cout << obj[i] << " ";
        cout << endl;
    }
    cout << "front" << endl;
    {
        ft::vector<int> obj(1, 150);
        
        cout << obj.front() << endl;
    }
    cout << "back" << endl;
    {
        ft::vector<int> obj(1, 150);

        obj.push_back(90);
        
        cout << obj.back() << endl;
    }
    cout << "data" << endl;
    {
        ft::vector<int> obj(10, 20);
        
        int * p = obj.data();
        
        for (size_t i = 0; i < obj.size(); ++i)
            cout << p[i] << " ";
        cout << endl;
    }
    cout << "Iterators begin" << endl;
    {
        ft::vector<int> obj(10, 80);
        
         ft::vector<int>::iterator it = obj.begin();

         cout << *it << endl;
    }
    cout << "Iterators end" << endl;
    {
        ft::vector<int> obj(10, 80);

        obj.push_back(10);
        
         ft::vector<int>::iterator it = obj.end() - 1;

         cout << *it << endl;
    }
    cout << "reverse_iterator rbegin, rend" << endl;
    {
        ft::vector<int> obj(10 ,15);

        for (size_t i = 0; i < obj.size(); ++i)
            obj[i] = i + 1;
        
        for (ft::vector<int>::reverse_iterator it = obj.rbegin(); it != obj.rend(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << "empty" << endl;
    {
        ft::vector<int> obj;

        if (obj.empty())
           cout << "is empty" << endl;
        else
            cout << "is not" << endl;
    }
    cout << "size" << endl;
    {
        ft::vector<int> obj(10, 10);
        
        size_t i = obj.size();

        cout << i << endl;
    }
    cout << "max_size" << endl;
    {
        ft::vector<int> obj(10, 10);
        
        size_t i = obj.max_size();

        cout << i << endl;
    }
    cout << "capacity" << endl;
    {
        ft::vector<int> obj(10, 10);
        
        obj.push_back(5);
        size_t i = obj.capacity();

        cout << i << endl;
    }
    cout << "reserve" << endl;
    {
        ft::vector<int> obj(10, 10);

        ft::vector<int>::iterator it;
        for (it = obj.begin(); it != obj.end(); ++it)
            cout << *it << " ";
        cout << endl;
        cout << "capacity: " <<  obj.capacity() << endl;
        obj.reserve(15);
        cout << "capacity: " << obj.capacity() << endl;
    }
}
int main()
{
    cout << "vector testing" << std::endl;
    vectortest();
}
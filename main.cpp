/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:22:24 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/11/30 12:09:51 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include "vector.hpp"
#include <iostream>

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

        for (ft::vector<int>::reverse_iterator it = obj.rbegin(); it != obj.rend(); ++it)
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
       
    stack.pop();
    stack.pop();
   
    while (!stack.empty()) {
        cout << stack.top() <<" ";
        stack.pop();
    }
}
#include "pair.hpp"

int main()
{
    ft::pair<char, int> pr = ft::make_pair<char, int>('c', 6);
ft::pair<char, int> pr1(pr);
    std::cout << pr1.first << ' ' << pr1.second << '\n';
    
//     cout << "\033[41mvector testing\033[0m" << endl;
//     ft_vector();
//     cout << "\033[41mstack testing\033[0m" << endl;
//     ft_stack();
}
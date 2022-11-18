/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:24:38 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/11/18 14:39:08 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <stddef.h>
#include <iostream>

namespace ft
{
template <class T>
class random_access_iterator
{

    public:
        typedef T                                       value_type;
        typedef std::ptrdiff_t                          difference_type;
        typedef T*                                      pointer;
        typedef T&                                      reference;
        typedef std::random_access_iterator_tag         iterator_category;
        random_access_iterator() : p(0) {};
        random_access_iterator(pointer pp) : p(pp){};
        ~random_access_iterator(){};
        random_access_iterator(const random_access_iterator &obj){*this = obj;};
        pointer base(){return (this->p);};
        random_access_iterator &operator=(const random_access_iterator &obj){p = obj.p;return (*this);};
        bool &operarar==(const random_access_iterator &rhs) {return p == rhs.p;};
        bool &operarar!=(const random_access_iterator &rhs) {return p != rhs.p;};
        reference operator*(const random_access_iterator &rhs) {return (*p);};
        random_access_iterator &operator++(void) {++p; return (*this);};
        random_access_iterator operator++(int) (random_access_iterator tmp = *this; --p; retrun (tmp););
        random_access_iterator &operator--(void) {++p; return (*this);};
        random_access_iterator operator--(int) (random_access_iterator tmp = *this; --p; retrun (tmp););
        random_access_iterator &operator-=(int n)(p -= n;return (*this););
        random_access_iterator &operator+=(int n)(p += n;return (*this););
        random_access_iterator operator-(int n){(return (random_access_iterator(p - n));)};
        random_access_iterator operator+(int n){(return (random_access_iterator(p + n));)};
        reference operator[](int n) {return(p[n]);};
        private:
            pointer p;
};

template <class it1, class it2>
    bool operator<(const random_access_iterator<it1> &rhs, const random_access_iterator<it2> &rhs1)
        {return (rhs.base() < rhs1.base());};
template <class it1, class it2>
    bool operator>(const random_access_iterator<it1> &rhs, const random_access_iterator<it2> &rhs1)
        {return (rhs.base() > rhs1.base());};
template <class it1, class it2>
    bool operator<=(const random_access_iterator<it1> &rhs, const random_access_iterator<it2> &rhs1)
        {return (rhs.base() <= rhs1.base());};
template <class it1, class it2>
    bool operator>=(const random_access_iterator<it1> &rhs, const random_access_iterator<it2> &rhs1)
        {return (rhs.base() >= rhs1.base());};
template <class it1, class it2>
    bool operator==(const random_access_iterator<it1> &rhs, const random_access_iterator<it2> &rhs1)
        {return (rhs.base() == rhs1.base());};
template <class it1, class it2>
    bool operator!=(const random_access_iterator<it1> &rhs, const random_access_iterator<it2> &rhs1)
        {return (rhs.base() != rhs1.base());};
}
#endif
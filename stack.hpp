/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:18:44 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/12/30 17:07:22 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "vector.hpp"
#include <deque>
#include <list>
namespace ft
{
template<class T, class Container = ft::vector<T> > 
class stack
{
    public:
        typedef Container                               container_type;
        typedef typename    Container::value_type       value_type;
        typedef typename    Container::size_type        size_type;
        typedef typename    Container::reference        reference;
        typedef typename    Container::const_reference  const_reference;

        stack( const stack& other ){*this = other;}
        explicit stack( const Container& cont = Container() ) : c(cont){}
        stack &operator=(const stack &obj) {this->c = obj.c; return (*this);}
        ~stack(){}
        reference top(){return (c.back());}
        const_reference top() const{return (c.back());}
        bool empty() const{return (c.empty());}
        size_type size() const{return (c.size());}
        void push( const value_type& value )
        {
            c.push_back(value);
        }
        void pop(){c.pop_back();}
        
        template <class U, class C> friend bool operator== (const stack<U,C>& lhs, const stack<U,C>& rhs) {
			return (lhs.c == rhs.c);
		}
		template <class U, class C> friend bool operator!= (const stack<U,C>& lhs, const stack<U,C>& rhs) {
			return (lhs.c != rhs.c);
		}
		template <class U, class C> friend bool operator< (const stack<U,C>& lhs, const stack<U,C>& rhs) {
			return (lhs.c < rhs.c);
		}
		template <class U, class C> friend bool operator<= (const stack<U,C>& lhs, const stack<U,C>& rhs) {
			return (lhs.c <= rhs.c);
		}
		template <class U, class C> friend bool operator> (const stack<U,C>& lhs, const stack<U,C>& rhs) {
			return (lhs.c > rhs.c);
		}
		template <class U, class C> friend bool operator>= (const stack<U,C>& lhs, const stack<U,C>& rhs) {
			return (lhs.c >= rhs.c);
		}
    protected:
        container_type c;
};
}
#endif
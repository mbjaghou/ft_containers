/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:53:15 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/11/20 11:32:46 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <stddef.h>
#include "iterator.hpp"


template <class T, class Allocator = std::allocator<T> > 
class vector
{
    public:
        typedef T                                                   value_type;
        typedef Allocator                                           allocator_type;
        typedef std::size_t                                         size_type;
        typedef std::ptrdiff_t                                      difference_type;
        typedef value_type&                                         reference;
        typedef const value_type&                                   const_reference;
        typedef typename Allocator::pointer                         pointer;
        typedef typename Allocator::const_pointer                   const_pointer;
        typedef ft::random_access_iterator<value_type>              iterator;
        typedef ft::random_access_iterator<const value_type>        const_iterator;
        typedef ft::reverse_iterator<value_type>                    reverse_iterator;
        typedef ft::reverse_iterator<const value_type>              const_reverse_iterator;
        /*--------Member functions-----*/
        explicit vector (const allocator_type& alloc = allocator_type()){}
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){}
        template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){}
        vector (const vector& x){}
        ~vector(){}
        vector& operator=( const vector& other ){}
        allocator_type get_allocator() const{return (this->_alloc);}
        /*--------Iterators-----*/
        iterator begin(){return (iterator(p));}
        const_iterator begin() const{return const_iterator(p);}
        iterator end(){return (iterator(p + _size));}
        const_iterator end() const{return (const_iterator(p + _size));}
        reverse_iterator rbegin(){return (reverse_iterator(p + _size));}
        const_reverse_iterator rbegin() const{return (const_reverse_iterator(p + _size));}
        reverse_iterator rend(){return reverse_iterator(p);}
        const_reverse_iterator rend() const{return (const_reverse_iterator(p));}
        /*--------Capacity-----*/
        bool empty() const{
            if(this->_size == 0)
                return (1);
            return (0);
        }
        size_type size() const{return (this->_size);}
        size_type max_size() const{}
        void reserve( size_type new_cap ){}
        size_type capacity() const{return (this->_capacity);};
  
    private:
        size_type           _size;
        size_type           _capacity;
        pointer             p;
        allocator_type      _alloc;
};
#endif
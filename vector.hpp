/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:53:15 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/11/20 13:50:56 by mbjaghou         ###   ########.fr       */
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
        size_type max_size() const{return (_alloc.max_size());}
        size_type capacity() const{return (this->_capacity);};
        void reserve( size_type new_cap )
        {
            if (new_cap > max_size())
                std::length_error("no spase left");
            else if (new_cap > _capacity)
            {
                pointer tmp_p = _alloc.allocate(new_cap);
                if (!tmp_p)
                    std::bad_alloc("Bad allocation");
            }
            for (size_type i = 0; i < _size; i++)
                _alloc.construct(tmp_p + i, p[i]);
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(this->p + i);
            _alloc.dellocator(this->p , this->_capacity);
            this->p = tmp_p;
            this->_capacity = new_cap;
        }
  
    private:
        size_type           _size;
        size_type           _capacity;
        pointer             p;
        allocator_type      _alloc;
};
#endif
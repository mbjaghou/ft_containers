/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:53:15 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/11/21 16:53:57 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <stddef.h>
#include "iterator.hpp"
#include "is_integral.hpp"

namespace ft{
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
        explicit vector (const allocator_type& alloc = allocator_type()) : p(NULL), _capacity(0), _size(0), _alloc(0){}
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
        {
            _size = n;
            _capacity = n;
            _alloc = alloc;
            p = _alloc.allocate(n);
            for (size_type i = 0; i < n; ++i)
                _alloc.construct(p + i, val);
        }
        template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
            {

                _size = std::distance(first, last);
                _capacity = _size;
                _alloc = alloc;
                p = _alloc.allocate(_size);
                size_type i = 0;
                while(first != last)
                {
                    _alloc.construct(p + i, *first);
                    ++first;
                    ++i;
                }
            }
        ~vector()
        {
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(p + i);
            if (_capacity != 0)
                _alloc.deallocate(p, _capacity);
        }
        vector (const vector& x){
            *this = x;
        }
        vector& operator=( const vector& other )
        {
            p = other.p;
            _capacity = other._capacity;
            _size = other._size;
            _alloc = other._alloc;
            return (*this);
        }
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
                throw std::length_error("no spase left");
            else if (new_cap > _capacity)
            {
                pointer tmp_p = _alloc.allocate(new_cap);
                if (!tmp_p)
                    throw std::bad_alloc();
                for (size_type i = 0; i < _size; i++)
                    _alloc.construct(tmp_p + i, p[i]);
                for (size_type i = 0; i < _size; i++)
                    _alloc.destroy(this->p + i);
                _alloc.dellocator(this->p , this->_capacity);
                this->p = tmp_p;
                this->_capacity = new_cap;
            }
        }
        /*--------Modifiers-----*/
        void clear()
        {
            for (size_type  i = 0; i < _size; ++i)
                _alloc.destroy(p + i);
        }
        template <class InputIterator>
            void assign (InputIterator first, InputIterator last , 
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
            {
                size_type n = std::distance(first, last);
                if (n > _capacity)
                    _capacity = _capacity * 2;
                for (size_type  i = 0; i < _size; ++i)
                    _alloc.destroy(p + i);
                size_type i = 0;
                while(first != last)
                {
                    _alloc.construct(p + i, *first);
                    i++;
                    first++;
                }
                _size = n;
            }
        void assign (size_type n, const value_type& val)
        {
            if (n > _capacity)
                _capacity = _capacity * 2;
            for (size_type  i = 0; i < _size; ++i)
                _alloc.destroy(p + i);
            size_type i = 0;
            while(i < n)
            {
                _alloc.construct(p + i, val);
                i++;
            }
            _size = n;
        }
        iterator insert (iterator position, const value_type& val)
        {
            
        }
        void insert (iterator position, size_type n, const value_type& val)
        {
            
        }
        template <class InputIterator>    
            void insert (iterator position, InputIterator first, InputIterator last)
            {
                
            }
        iterator erase( iterator pos )
        {
            
        }
        iterator erase( iterator first, iterator last )
        {
            
        }
        void push_back( const T& value )
        {
            
        }
        void pop_back()
        {
            
        }
        void resize( size_type count, T value = T() )
        {
            
        }
        void swap( vector& other )
        {
            
        }
        /*--------Element access-----*/
        reference at( size_type pos )
        {
            if (!(pos < size()))
               throw std::out_of_range("out of range");
            return (p[pos]);
        }
        const_reference at( size_type pos ) const
        {
            if (!(pos < size()))
                throw std::out_of_range("out of range");
            return (p[pos]);
        }
        reference operator[]( size_type pos ){return (p[pos]);}
        const_reference operator[]( size_type pos ) const{return (p[pos]);}
        reference front(){return (this->at(0));}
        const_reference front() const{return (this->at(0));}
        reference back(){return (this->at(_size - 1));}
        const_reference back() const{return (this->at(_size - 1));}
        T* data(){return (p);}
        const T* data() const{return (p);}
    private:
        size_type           _size;
        size_type           _capacity;
        pointer             p;
        allocator_type      _alloc;
};
}
#endif
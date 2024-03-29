/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:53:15 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/12/30 19:13:31 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <stddef.h>
#include "iterator.hpp"
#include "is_integral.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"
#include "distance.hpp"


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
        typedef ft::reverse_iterator<iterator>                    reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>              const_reverse_iterator;
        /*--------Member functions-----*/
        explicit vector (const allocator_type& alloc = allocator_type())
        {
            p = NULL;
            this->_capacity = 0;
            this->_alloc = alloc;
            this->_size = 0;
        }
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
                _size = ft::distance(first, last);
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
            if (_capacity)
                _alloc.deallocate(p, _capacity);
        }
        vector (const vector& x){
            _capacity = 0;
            _size = 0;
            *this = x;
        }
        vector& operator=( const vector& other )
        {
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(p + i);
            if(_capacity)
                _alloc.deallocate(p, _capacity);
            _capacity = other._capacity;
            _size = other._size;
            _alloc = other._alloc;
            if (_capacity)
                p = _alloc.allocate(_capacity);
            for (size_type i = 0; i < _size; ++i)
                _alloc.construct(p + i, other.p[i]);
            return (*this);
        }
        allocator_type get_allocator() const{return (this->_alloc);}
        /*--------Iterators-----*/
        iterator begin(){return (iterator(p));}
        const_iterator begin() const{return const_iterator(p);}
        iterator end(){return (iterator(p + _size));}
        const_iterator end() const{return (const_iterator(p + _size));}
        reverse_iterator rbegin(){return (reverse_iterator(end()));}
        const_reverse_iterator rbegin() const{return (const_reverse_iterator(end()));}
        reverse_iterator rend(){return reverse_iterator(begin());}
        const_reverse_iterator rend() const{return (const_reverse_iterator(begin()));}
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
                if (_capacity)
                    _alloc.deallocate(this->p , this->_capacity);
                this->p = tmp_p;
                this->_capacity = new_cap;
            }
        }
        /*--------Modifiers-----*/
        void clear()
        {
            for (size_type  i = 0; i < _size; ++i)
                _alloc.destroy(p + i);
            _size = 0;
        }
        template <class InputIterator>
            void assign (InputIterator first, InputIterator last , 
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
            {
                size_type n = ft::distance(first, last);
                for (size_type  i = 0; i < _size; ++i)
                    _alloc.destroy(p + i);
                reserve(n);
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
            reserve(n);
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
            if (_size + 1 > _capacity) {
                _capacity = _capacity * 2;
                reserve(_capacity);
            }
            size_t o = ft::distance(position, end());
            vector<value_type> tmp;
            tmp.assign(position, end());
            for (size_t i = o; i < _size; ++i)
                _alloc.destroy(p + i);
            _size -= o;
            push_back(val);
            for(size_t i = o; i < tmp.size(); ++i, ++_size)
                _alloc.construct(p + _size, tmp[i]);
            return (position);
        }
        void insert (iterator position, size_type n, const value_type& val)
        {
            difference_type o = ft::distance(position, end());
            vector<value_type> tmp;
            tmp.assign(position, end());
	        if (n + _size > _capacity)
		        reserve(n + _size);
            for (size_t i = 0; i < _size; ++i)
                _alloc.destroy(p + i);
            _size -= o;
            for (size_t i = 0; i < n; ++i)
                push_back(val);
            for(size_t i = 0; i < tmp.size(); ++i, ++_size)
                _alloc.construct(p + _size, tmp[i]);
        }
        template <class InputIterator>    
            void insert (iterator position, InputIterator first, InputIterator last, 
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
            {
                size_type d = ft::distance(first, last);
                size_type o = ft::distance(begin(), position);
                vector<value_type> tmp;
                tmp.assign(position, end());
                if (d + _size > _capacity)
                    reserve(d + _size);
                for (size_type i = o; i < _size; ++i)
                    _alloc.destroy(p + i);
                _size = o;
                while(first != last)
                {
                    _alloc.construct(p + _size, *first);
                    ++_size;
                     ++first;
                }
                for(size_t i = 0; i < tmp.size(); ++i, ++_size)
                    _alloc.construct(p + _size, tmp[i]);                
            }
        iterator erase( iterator pos )
        {
            iterator tmpos = pos;
            while (tmpos != end())
            {
                *tmpos = *(tmpos + 1);
                tmpos++;
            }
            _size--;
            return (pos);
        }
        iterator erase( iterator first, iterator last )
        {
            while (first != last)
            {
                erase(first);
                last--;
            }
            return (first);
        }
        void resize( size_type count, T value = T() )
        {
            if (count > max_size())
				throw std::length_error("Length Error");
			else if (count < _size)
			{
				for (size_type i = count; i < _size; i++)
					_alloc.destroy(p + i);
				_size = count;
			} 
			else 
			{
				if (count > _capacity)
					reserve(count);
				for (size_type i = _size; i < count; i++)
					_alloc.construct(p + i, value);
				_size = count;
			}
        }
        void push_back( const T& value )
        {
            if (!_capacity)
                reserve(1);
            else if (_size + 1 > _capacity)
                reserve(_capacity * 2);
            _alloc.construct(p + _size, value);
            _size++;
        }
        void pop_back()
        {
            _alloc.destroy(p + _size);
            _size--;
        }
        void swap( vector& other )
        {
            size_type tmps = _size;
            _size = other._size;
            other._size = tmps;

            size_type tmpc = _capacity;
            _capacity = other._capacity;
            other._capacity = tmpc;

            pointer tmpp = p;
            p = other.p;
            other.p = tmpp;
        }
        /*--------Element access-----*/
        reference at( size_type pos )
        {
            if (pos >= size())
               throw std::out_of_range("out of range");
            return (p[pos]);
        }
        const_reference at( size_type pos ) const
        {
            if (pos >= size())
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

template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}
template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return !(lhs == rhs);
}
template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return !(rhs < lhs);
}
template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return (rhs < lhs);
}
template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return !(lhs < rhs);
}
template <class T, class Alloc>  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
    x.swap(y);
}
}
#endif

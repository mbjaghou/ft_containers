/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:51:23 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/12/25 11:44:47 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "iterator.hpp"
#include <map>
#include "avl_tree.hpp"
#include "pair.hpp"

namespace ft
{
template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
class map
{
    public:
        typedef Key                                                                    key_type;
        typedef T                                                                      mapped_type;
        typedef ft::pair<const key_type,mapped_type>                                   value_type;
        typedef Compare                                                                key_compare;
        typedef typename std::map::value_comp                                          value_compare;
        typedef Allocator                                                              allocator_type;
        typedef typename allocator_type::reference	                                   reference;
        typedef typename allocator_type::const_reference	                           const_reference;
        typedef typename allocator_type::pointer                                       pointer;
        typedef typename allocator_type::const_pointer                                 const_pointer;
        typedef ft::bidirectional_iterator<mapped_type, Compare, Allocator>            iterator;
        typedef ft::bidirectional_iterator<const mapped_type, Compare, Allocator>      const_iterator;
        typedef ft::reverse_iterator<iterator>                                         reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                                   const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type                difference_type;
        typedef size_t                                                        size_type;

    protected:
        allocator_type _alloc;
        size_type      _size;
        key_compare    _comp;
        avl<ft::pair<key_type, mapped_type>, Compare, Allocator> *tree;
        /*Member functions*/
        map(): _alloc(NULL), _size(0), _value(NULL){}
        ~map(){}
        explicit map( const Compare& comp, const Allocator& alloc = Allocator() )
        {
            _alloc = alloc;
            _size = 0;
        }
        template< class InputIt >
            map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
            {
                _alloc = alloc;
                _size = ft::distance(first, last);
                while (first != last)
                {
                    tree->insert(*first);
                    first++;
                }
            }
        map( const map& other )
        {
            *this = other;
        }
        map& operator=( const map& other )
        {
            _alloc = other._alloc;
            _value = other._value;
            _size = other._size;
            return (*this);
        }
        allocator_type get_allocator() const
        {
            return (_alloc);
        }
        /*Element access*/
        T& at( const Key& key )
        {        
        }
        const T& at( const Key& key ) const{}
        T& operator[]( const Key& key )
        {
            
        }
        /*Iterators*/
        iterator begin(){}
        const_iterator begin() const{}
        iterator end(){}
        const_iterator end() const{}
        reverse_iterator rbegin(){}
        const_reverse_iterator rbegin() const{}
        reverse_iterator rend(){}
        const_reverse_iterator rend() const{}
        /*Capacity*/
        bool empty() const{}
        size_type size() const {return(_size);}
        size_type max_size() const{return (_alloc.max_size());}
        /*Modifiers*/
        void clear(){}
        ft::pair<iterator, bool> insert( const value_type& value ){}
        iterator insert( iterator pos, const value_type& value ){}
        template< class InputIt >
            void insert( InputIt first, InputIt last ){}
        iterator erase( iterator pos ){}
        iterator erase( iterator first, iterator last ){}
        size_type erase( const Key& key ){}
        void swap( map& other ){}
        /*Lookup*/
        size_type count( const Key& key ) const{}
        iterator find( const Key& key ){}
        const_iterator find( const Key& key ) const{}
        ft::pair<iterator,iterator> equal_range( const Key& key ){}
        ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const{}
        iterator lower_bound( const Key& key ){}
        const_iterator lower_bound( const Key& key ) const{}
        iterator upper_bound( const Key& key ){}
        const_iterator upper_bound( const Key& key ) const{}
        /*Observers*/
        key_compare key_comp() const{}
        ft::map::value_compare value_comp() const{}
        
};
template< class Key, class T, class Compare, class Alloc >
bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
                 {}
template< class Key, class T, class Compare, class Alloc >
bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs ){}
template< class Key, class T, class Compare, class Alloc >
bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
                const ft::map<Key,T,Compare,Alloc>& rhs ){}
template< class Key, class T, class Compare, class Alloc >
bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs ){}
template< class Key, class T, class Compare, class Alloc >
bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
                const ft::map<Key,T,Compare,Alloc>& rhs ){}
template< class Key, class T, class Compare, class Alloc >
bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs ){}
template< class Key, class T, class Compare, class Alloc >
void swap( ft::map<Key,T,Compare,Alloc>& lhs,
           ft::map<Key,T,Compare,Alloc>& rhs ){}
}
#endif
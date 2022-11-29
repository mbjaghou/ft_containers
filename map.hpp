/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:51:23 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/11/29 10:27:35 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "iterator.hpp"
#include <map>

namespace ft
{
template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
class map
{
    public:
        typedef key                                                         key_type;
        typedef T                                                           mapped_type;
        typedef std::pair<const key_type,mapped_type>                       value_type;
        typedef Compare                                                     key_compare;
        typedef typename std::map::value_comp                               value_compare;
        typedef Allocator                                                   allocator_type;
        typedef typename allocator_type::reference	                        reference;
        typedef typename allocator_type::const_reference	                const_reference;
        typedef typename allocator_type::pointer                            pointer;
        typedef typename allocator_type::const_pointer                      const_pointer;

        
        typedef ft::reverse_iterator<iterator>                              reverse_iterator;
        typedef ft::reverse_iterator<const_reverse_iterator>                const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type     difference_type;
        typedef difference_type                                             size_type;

        /*Member functions*/
        map(){}
        explicit map( const Compare& comp, const Allocator& alloc = Allocator() ){}
        template< class InputIt >
            map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ){}
        map( const map& other ){}
        ~map(){}
        map& operator=( const map& other ){}
        allocator_type get_allocator() const{}
        /*Element access*/
        T& at( const Key& key ){}
        const T& at( const Key& key ) const{}
        T& operator[]( const Key& key ){}
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
        size_type size() const{}
        size_type max_size() const{}
        /*Modifiers*/
        void clear(){}
        std::pair<iterator, bool> insert( const value_type& value ){}
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
        std::pair<iterator,iterator> equal_range( const Key& key ){}
        std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const{}
        iterator lower_bound( const Key& key ){}
        const_iterator lower_bound( const Key& key ) const{}
        iterator upper_bound( const Key& key ){}
        const_iterator upper_bound( const Key& key ) const{}
        /*Observers*/
        key_compare key_comp() const{}
        std::map::value_compare value_comp() const{}
    protected:
        
};
template< class Key, class T, class Compare, class Alloc >
bool operator==( const std::map<Key,T,Compare,Alloc>& lhs,
                 const std::map<Key,T,Compare,Alloc>& rhs ){}
template< class Key, class T, class Compare, class Alloc >
bool operator!=( const std::map<Key,T,Compare,Alloc>& lhs,
                 const std::map<Key,T,Compare,Alloc>& rhs ){}
template< class Key, class T, class Compare, class Alloc >
bool operator<( const std::map<Key,T,Compare,Alloc>& lhs,
                const std::map<Key,T,Compare,Alloc>& rhs ){}
template< class Key, class T, class Compare, class Alloc >
bool operator<=( const std::map<Key,T,Compare,Alloc>& lhs,
                 const std::map<Key,T,Compare,Alloc>& rhs ){}
template< class Key, class T, class Compare, class Alloc >
bool operator>( const std::map<Key,T,Compare,Alloc>& lhs,
                const std::map<Key,T,Compare,Alloc>& rhs ){}
template< class Key, class T, class Compare, class Alloc >
bool operator>=( const std::map<Key,T,Compare,Alloc>& lhs,
                 const std::map<Key,T,Compare,Alloc>& rhs ){}
template< class Key, class T, class Compare, class Alloc >
void swap( std::map<Key,T,Compare,Alloc>& lhs,
           std::map<Key,T,Compare,Alloc>& rhs ){}
}
#endif
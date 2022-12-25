/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:51:23 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/12/25 21:08:10 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "iterator.hpp"
#include <map>
#include "avl_tree.hpp"
#include "pair.hpp"
#include "distance.hpp"

namespace ft
{
template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
class map
{
    public:
        typedef Key                                                                    key_type;
        typedef T                                                                      mapped_type;
        typedef ft::pair<const key_type,mapped_type>                                   value_type;
        typedef Compare                                                                key_compare;
        // typedef typename std::map::value_comp                                          value_compare;
        typedef Allocator                                                              allocator_type;
        typedef typename allocator_type::reference	                                   reference;
        typedef typename allocator_type::const_reference	                           const_reference;
        typedef typename allocator_type::pointer                                       pointer;
        typedef typename allocator_type::const_pointer                                 const_pointer;
        typedef ft::bidirectional_iterator<value_type, Compare, Allocator>            iterator;
        typedef ft::bidirectional_iterator<const value_type, Compare, Allocator>      const_iterator;
        typedef ft::reverse_iterator<iterator>                                         reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                                   const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type                difference_type;
        typedef size_t                                                                 size_type;

        /*Member functions*/
        map(): _size(0){}
        ~map(){}
        explicit map( const Compare& comp, const Allocator& alloc = Allocator() )
        {
            _alloc = alloc;
            _comp = comp;
            _size = 0;
        }
        template< class InputIt >
            map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
            {
                _alloc = alloc;
                _size = ft::distance(first, last);
                _comp = comp;
                while (first != last)
                {
                    tree.insert(*first);
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
                value_type	o = ft::make_pair<const key_type, mapped_type>(key, mapped_type());
				avlnode<value_type, Allocator>* node = tree.search(tree.root, o);
				if (!node) {
     
					node = tree.insert(o);
					_size++;
					return (tree.search(tree.root, o))->element->second;
				}
				return node->element->second;
        }
        /*Iterators*/
        iterator begin()
        {
            return iterator(tree.minValueNode(tree.root) ? tree.minValueNode(tree.root)->element : NULL, &tree);
        }
        const_iterator begin() const
        {
            return const_iterator(tree.minValueNode(tree.root) ? tree.minValueNode(tree.root)->element : NULL, &tree);
        }
        iterator end()
        {
            return iterator(NULL, &tree);
        }
        const_iterator end() const
        {
            return const_iterator(NULL, &tree);
        }
        reverse_iterator rbegin(){return reverse_iterator(end());}
        const_reverse_iterator rbegin() const{return const_reverse_iterator(end());}
        reverse_iterator rend(){ return reverse_iterator(begin());}
        const_reverse_iterator rend() const{ return const_reverse_iterator(begin());}
        /*Capacity*/
        bool empty() const
        {
            if (_size == 0)
                return (true);
            return (false);
        }
        size_type size() const {return(_size);}
        size_type max_size() const{return (_alloc.max_size());}
        /*Modifiers*/
        void clear(){}
        ft::pair<iterator, bool> insert( const value_type& value )
        {
            avlnode<value_type, Allocator>* node = tree.search(tree.root, value);
            if (!node) {
                node = tree.insert(value);
                _size++;
                return (ft::make_pair(iterator(node->element, &tree), true));
            }
            return (ft::make_pair(iterator(node->element, &tree), false));
        }
        iterator insert( iterator pos, const value_type& value )
        {
            avlnode<value_type, Allocator>* node = tree.search(tree.root, value);
            if (!node) {
                node = tree.insert(value);
                _size++;
                return (iterator(node->element, &tree));
            }
            return (iterator(node->element, &tree));
        }
        template< class InputIt >
            void insert( InputIt first, InputIt last )
            {
                while (first != last)
                {
                    tree.insert(*first);
                    first++;
                }
            }
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
        // ft::map::value_compare value_comp() const{}
    protected:
        allocator_type _alloc;
        size_type      _size;
        key_compare    _comp;
        avl<ft::pair<const key_type, mapped_type>, Compare, Allocator> tree;
        
};
template< class Key, class T, class Compare, class Alloc >
bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
                 {}
template< class Key, class T, class Compare, class Alloc >
bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
                 {}
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
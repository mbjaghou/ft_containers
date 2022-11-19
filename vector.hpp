/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:53:15 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/11/19 14:31:42 by mbjaghou         ###   ########.fr       */
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
        typedef Allocator::pointer                                  pointer;
        typedef Allocator::const_pointer                            const_pointer;
        typedef ft::random_access_iterator<value_type>              iterator;
        typedef ft::random_access_iterator<const value_type>        const_iterator;
        typedef ft::reverse_iterator<value_type>                    reverse_iterator;
        typedef ft::reverse_iterator<const value_type>              const_reverse_iterator;
        /*--------Member functions-----*/
        vector(){}
        explicit vector( const Allocator& alloc ){}
        explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()){}
        template< class InputIt >
        vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() ){}
        vector( const vector& other );
        ~vector(){}
        vector& operator=( const vector& other ){}
        void assign( size_type count, const T& value ){}
        template< class InputIt >
        void assign( InputIt first, InputIt last ){}
        allocator_type get_allocator() const{}
  
    private:
        size_t size;
        size_t capacity;
};
#endif
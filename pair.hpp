/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:57:32 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/12/02 13:06:47 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP


#include <iostream>

namespace ft
{
template <class T1, class T2> 
struct pair
{
    public:
        pair(): first(0), second(0){}
        pair( const T1& x, const T2& y ): first(x), second(y){}
        template< class U1, class U2 >
            pair( const pair<U1, U2>& p )
            {
                this->first = p.first;
                this->second = p.second;
            }
        pair( const pair& p ){ *this = p;}
        pair& operator=( const pair& other )
        {
            first = other.first;
            second = other.second;
            return (*this);
        }
        template< class Tt1, class Tt2 >
            friend bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
            {
                return (lhs.first == rhs.first && lhs.second == rhs.second);
            }
        template< class Tt1, class Tt2 >
            friend bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
            {
                return !(lhs == rhs);
            }
        template< class Tt1, class Tt2 >
            friend bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
            {
                if (lhs.first < rhs.first)
                    return (true);
                else if (rhs.first < lhs.first)
                    return (false);
                else if (lhs.second < rhs.second)
                    return (true);
                else
                    return (false);
            }
        template< class Tt1, class Tt2 >
            friend bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
            {
                return !(rhs < lhs);
            }
        template< class Tt1, class Tt2 >
            friend bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
            {
                return (rhs < lhs);
            }
        template< class Tt1, class Tt2 >
            friend bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
            {
                return !(lhs < rhs);
            }
        
        T1 first;
        T2 second;
};
template< class T1, class T2 >
    ft::pair<T1, T2> make_pair( T1 t, T2 u )
    {
        return pair<T1, T2>(t, u);
    }
}
#endif
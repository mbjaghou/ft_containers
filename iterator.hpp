/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:24:38 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/12/30 19:25:56 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <stddef.h>
#include <iostream>
#include "avl_tree.hpp"

/*------------------random_access_iterator------------------*/
namespace ft
{
template <class T>
class random_access_iterator
{

    public:
        typedef T                                       value_type;
        typedef std::ptrdiff_t                          difference_type;
        typedef T*                                      pointer;
        typedef T&                                      reference;
        typedef std::random_access_iterator_tag         iterator_category;
        random_access_iterator() : p(0) {}
        random_access_iterator(pointer pp) : p(pp){}
        ~random_access_iterator(){}
        random_access_iterator(const random_access_iterator &obj){*this = obj;}
        pointer base() const {return (this->p);}
        random_access_iterator &operator=(const random_access_iterator &obj){p = obj.p;return (*this);}
        reference operator*() {return (*p);}
        pointer operator->(void) {return &(operator*());}
        random_access_iterator &operator++(void) {++p; return (*this);}
        random_access_iterator operator++(int) {random_access_iterator tmp = *this; ++p; return (tmp);}
        random_access_iterator &operator--(void){ --p; return (*this);};
        random_access_iterator operator--(int) {random_access_iterator tmp = *this; --p; return (tmp);}
        random_access_iterator &operator-=(int n){p -= n;return (*this);}
        random_access_iterator &operator+=(int n){p += n;return (*this);}
        random_access_iterator operator-(int n){return (random_access_iterator(p - n));}
        random_access_iterator operator+(int n){return (random_access_iterator(p + n));}
        reference operator[](int n) {return(p[n]);}
        	operator random_access_iterator<const T> () const {
				return (random_access_iterator<const T>(p));
			}
        private:
            pointer p;
};
template <class Iter1, class Iter2> typename random_access_iterator<Iter1>::difference_type operator-( const random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2> &rhs) {
	return (lhs.base() - rhs.base());
}
	template <class Iter1, class Iter2> typename random_access_iterator<Iter1>::difference_type operator+( const random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2> &rhs) {
	return (lhs.base() + rhs.base());
}
template <class it1, class it2>
    bool operator<(const random_access_iterator<it1> &rhs, const random_access_iterator<it2> &rhs1)
        {return (rhs.base() < rhs1.base());}
template <class it1, class it2>
    bool operator>(const random_access_iterator<it1> &rhs, const random_access_iterator<it2> &rhs1)
        {return (rhs.base() > rhs1.base());}
template <class it1, class it2>
    bool operator<=(const random_access_iterator<it1> &rhs, const random_access_iterator<it2> &rhs1)
        {return (rhs.base() <= rhs1.base());}
template <class it1, class it2>
    bool operator>=(const random_access_iterator<it1> &rhs, const random_access_iterator<it2> &rhs1)
        {return (rhs.base() >= rhs1.base());}
template <class it1, class it2>
    bool operator==(const random_access_iterator<it1> &rhs, const random_access_iterator<it2> &rhs1)
        {return (rhs.base() == rhs1.base());}
template <class it1, class it2>
    bool operator!=(const random_access_iterator<it1> &rhs, const random_access_iterator<it2> &rhs1)
        {return (rhs.base() != rhs1.base());}

/*------------------iterator_traits------------------*/
template <class Iterator> class iterator_traits {
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};
template <class T> class iterator_traits<T *> {
		public:
			typedef std::ptrdiff_t					diffrence_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::random_access_iterator_tag	iterator_category;
	};
template <class T> class iterator_traits<const T *> {
		public:
			typedef std::ptrdiff_t					diffrence_type;
			typedef T								value_type;
			typedef const T*						pointer;
			typedef const T&						reference;
			typedef std::random_access_iterator_tag	iterator_category;
            
	};
/*------------------reverse_iterator------------------*/
template <class Iterator> class reverse_iterator
{
     public:
        typedef Iterator                                                    iterator_type;
        typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
        typedef typename ft::iterator_traits<Iterator>::value_type	        value_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type	    difference_type;
        typedef typename ft::iterator_traits<Iterator>::pointer	            pointer;
        typedef typename ft::iterator_traits<Iterator>::reference	        reference;
        reverse_iterator(){};
        explicit reverse_iterator( iterator_type x )
        {
            this->t = x;
        }
        template< class U >
        reverse_iterator( const reverse_iterator<U>& other ){*this = other;}
        template< class U >
        reverse_iterator& operator=( const reverse_iterator<U>& other )
        {
            
            this->t = other.base();
            return (*this);
        }
        iterator_type base() const {return t;}
        reference operator*() const{Iterator tmp = t; return *--tmp;}
        pointer operator->() const {return &(operator*());}
        reference operator[]( difference_type n ) const{return (base()[-n-1]);}
        reverse_iterator& operator+=( difference_type n ){t += n; return (*this);}
        reverse_iterator& operator-=( difference_type n ){t -= n; return (*this);}
        reverse_iterator operator-( difference_type n ) const{return (reverse_iterator(t - n));}
        reverse_iterator operator+( difference_type n ) const{return (reverse_iterator(t + n));}
        reverse_iterator& operator++(){--t; return (*this);}
        reverse_iterator& operator--(){++t; return (*this);}
        reverse_iterator operator++( int ){reverse_iterator tmp = *this; --t; return (tmp);}
        reverse_iterator operator--( int ){reverse_iterator tmp = *this; ++t; return (tmp);}
        protected:
            iterator_type t;
    
};
template< class Iterator1, class Iterator2 >
bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs ){return (lhs.base() == rhs.base());}
template< class Iterator1, class Iterator2 >
bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs ){return (lhs.base() != rhs.base());}
template< class Iterator1, class Iterator2 >
bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs ){return (lhs.base() < rhs.base());}
template< class Iterator1, class Iterator2 >
bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs ){return (lhs.base() <= rhs.base());}
template< class Iterator1, class Iterator2 >
bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs ){return (lhs.base() > rhs.base());}
template< class Iterator1, class Iterator2 >
bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs ){return (lhs.base() >= rhs.base());}
template< class Iter >
reverse_iterator<Iter>
    operator+( typename reverse_iterator<Iter>::difference_type n,
               const reverse_iterator<Iter>& it ){return (reverse_iterator<Iter>(it.base() - n));}
template< class Iterator1, class Iterator2 >
typename reverse_iterator<Iterator1>::difference_type
    operator-( const reverse_iterator<Iterator1>& lhs,
               const reverse_iterator<Iterator2>& rhs ){return(rhs.base() - lhs.base());}
/*------------------bidirectional_iterator------------------*/
template <class T, class cop, class AL>
class bidirectional_iterator
{
    public:
        typedef T                                       value_type;
        typedef std::ptrdiff_t                          difference_type;
        typedef T*                                      pointer;
        typedef T&                                      reference;
        typedef std::bidirectional_iterator_tag         iterator_category;
        bidirectional_iterator(/* args */): p(NULL), tree(NULL){}
        bidirectional_iterator(pointer p, const avl<T, cop, AL> *tree = NULL) : p(p), tree(tree){}
        ~bidirectional_iterator(){}
        bidirectional_iterator(const bidirectional_iterator &obj): p(obj.p), tree(obj.tree){}
        bidirectional_iterator &operator=(const bidirectional_iterator &obj)
        {
            p = obj.p; tree = obj.tree; return *this;
        }
        reference operator*() {return (*p);}
        pointer operator->(void) {return &(operator*());}
        bidirectional_iterator& operator++ ()
        {
            avlnode<T, AL> *node = tree->search(tree->root, *p);
            if (node)
            {
                avlnode<T, AL> *successor = tree->successor(*p);
                if (successor)
                {
                    p = successor->element;
                }
                else
                    p = NULL;
            }
            return (*this);
        }
        bidirectional_iterator operator++ (int)
        {
            bidirectional_iterator tmp = *this;
            ++(*this);
            return (tmp);
        }
        bidirectional_iterator& operator-- ()
        {
            
            if (!p) {
				if (tree->root->right)
					p = tree->maxValueNode(tree->root->right)->element;
				else
					p = tree->root->element;
				return *this;
			}
            avlnode<T, AL> *node = tree->search(tree->root, *p);
            if (node)
            {
                avlnode<T, AL> *predecessor = tree->predecessor(*p);
                if (predecessor)
                {
                    p = predecessor->element;
                }
                else
                    p = NULL;
            }
            return (*this);
        }
        bidirectional_iterator operator-- (int)
        {
            bidirectional_iterator tmp = *this;
            --(*this);
            return (tmp);
        }
        bool operator!=( const bidirectional_iterator & rhs)
        {return (p != rhs.p);}
        bool operator==( const bidirectional_iterator & rhs)
        {return (p != rhs.p);}


        
        operator bidirectional_iterator<const T, cop, AL> () const {
			return bidirectional_iterator<const T, cop, AL>(p, reinterpret_cast<const avl<const value_type, cop, AL>*>(tree));}
    private:
        pointer p;
        const avl<value_type, cop, AL> *tree;
};
}

#endif
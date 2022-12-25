#ifndef DISTANCE_HPP
#define DISTANCE_HPP
#include "iterator.hpp"

namespace ft {
 
template <class input_itt>
	typename iterator_traits<input_itt>::difference_type
		distance(input_itt first, input_itt last){
			typename ft::iterator_traits<input_itt>::difference_type res = 0;
			while (first != last){
				first++;
				res++;
			}
			return res;
		}

}

#endif
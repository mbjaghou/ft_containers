/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:31:11 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/12/18 17:37:50 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <iostream>

namespace ft
{
   template <class T, class A = std::allocator<T> >
    class avlnode
    {
        public:
            T*       _key;
            avlnode *left;
            avlnode *right;
            avlnode *parent;
            int _height;
            A alloc;

            avlnode()
            {
                _key = 0;
                left = NULL;
                right = NULL;
                parent = NULL;
                _height = 0;
            }
            ~avlnode()
            {}
            avlnode(T value) {
				left = NULL;
				right = NULL;
				parent = NULL;
				_key = alloc.allocate(1);
				alloc.construct(_key, value);
				_height = 1;
			}
            avlnode(const avlnode &obj){ *this = obj;}
            avlnode &operator=(const avlnode &obj)
            {
                _key = alloc.allocate(1);
                alloc.construct(_key, obj._key);
                left = obj.left;
                right = obj.right;
                parent = obj.parent;
                _height = obj._height;
                return (*this);
            }
    };
    template <class T, class cop = std::less<T> , class AL = std::allocator<T> >
        class avl
        {
            private:
                avlnode<T, AL> *root;
                cop         _comp;
                AL          alloc;
            public:
                avl(): root(NULL){};
                ~avl(){};
                avl(const avl &obj)
                {
                    *this = obj;
                }
                avl &operator=(const avl &obj)
                {
                    root = obj.root;
                    _comp = obj._comp;
                    return (*this);
                }
                
                T max(T a, T b){
                    return (a < b) ? a : b;
                }
                int height(avlnode<T, AL> *n)
                {
                    if (n == 0)
                        return (0);
                    return (n->_height);
                }
                avlnode<T, AL> * newNode(T* key)
                {
                    avlnode<T, AL> *node;
                    node->_key = alloc.allocate(1);
                    alloc.construct(node->_key, key);
                    node->left = NULL;
                    node->right = NULL;
                    node->parent = NULL;
                    node->_height = 1;
                    return (node);
                }
                avlnode<T, AL> *rightRotate(avlnode<T, AL> *y)
                {
                    avlnode<T, AL> *x = y->left;
                    avlnode<T, AL> *tmp = x->right;
                    if (x->right)
                        x->right->parent = y;
                    x->right = y;
                    y->left = tmp;
                    x->parent = y->parent;
                    y->parent = x;
                    y->_height = max(height(y->left), height(y->right)) + 1;
                    x->_height = max(height(x->left), height(x->right)) + 1;

                    return (x);
                }
                avlnode<T, AL> *leftRotate(avlnode<T, AL> *y)
                {
                    avlnode<T, AL> *x = y->right;
                    avlnode<T, AL> *tmp = x->left;
                    if (x->left)
                        x->left->parent = y;
                    x->left = y;
                    y->right = tmp;
                    x->parent = y->parent;
                    y->parent = x;
                    y->_height = max(height(y->left), height(y->right)) + 1;
                    x->_height = max(height(x->left), height(x->right)) + 1;
                    return (x);
                }
                int getBalance(avlnode<T, AL> *n)
                {
                    if (n == 0)
                        return (0);
                    return (height(n->left) - height(n->right));
                }
                // void preOrder(avlnode<T, AL> *root)
                // {
                //     if (root != NULL)
                //     {
                //         std::cout << root->key << " ";
                //         preOrder(root->left);
                //         preOrder(root->right);
                //     }
                // }
                avlnode<T, AL> *search(avlnode<T, AL> *node, const T &key) const
			    {
			    	if (!node )
			    		return (node);
			    	if (node->key && node->key->first == key.first)
			    		return (node);
			    	if (_comp(key.first, node->key->first))
			    		return (search(node->left, key));
			    	else if (_comp(node->key->first, key.first))
			    		return (search(node->right, key));
			    	return (node);
			    }
                avlnode<T, AL> *insert(avlnode<T, AL>* node, T key)
                {
                    if (node == NULL)
                        return(newNode(key));
                    if (key < node->key)
                        node->left = insert(node->left, key);
                    else if (key > node->key)
                        node->right = insert(node->right, key);
                    else
                        return node;
                    node->_height = 1 + max(height(node->left),
                        height(node->right));

                    int balance = getBalance(node);

                    // Left Left Case  
                    if (balance > 1 && key < node->left->key)
                        return rightRotate(node);

                    // Right Right Case  
                    if (balance < -1 && key > node->right->key)
                        return leftRotate(node);

                    // Left Right Case  
                    if (balance > 1 && key > node->left->key)
                    {
                        node->left = leftRotate(node->left);
                        return rightRotate(node);
                    }

                    // Right Left Case  
                    if (balance < -1 && key < node->right->key)
                    {
                        node->right = rightRotate(node->right);
                        return leftRotate(node);
                    }
                    return node;
                }
        };
}


#endif
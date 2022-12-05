/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:31:11 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/12/05 12:58:45 by mbjaghou         ###   ########.fr       */
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
            T _key;
            avlnode *left;
            avlnode *right;
            avlnode *parent;
            T _height;
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
            avlnode(const avlnode &obj){ *this = obj;}
            avlnode &operator=(const avlnode &obj)
            {
                _key = obj._key;
                left = obj.left;
                right = obj.right;
                parent = obj.parent;
                _height = obj._height;
                return (*this);
            }
    };
    template <class T, class AL = std::allocator<T> >
        class avl
        {
            avl();
            ~avl();
            avl(const avl &obj){}
            avl &operator=(const avl &obj){}
            
            T max(T a, T b){
                return (a < b) ? a : b;
            }
            T height(avlnode<T, AL> *n)
            {
                if (n == 0)
                    return (0);
                return (n->_height);
            }
            avlnode<T, AL> * newNode(T key)
            {
                avlnode<T, AL> *node = node.allocate(1);
                node->_key = key;
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
                
                x->right = y;
                y->left = tmp;

                y->_height = max(height(y->left), height(y->right)) + 1;
                x->_height = max(height(x->left), height(x->right)) + 1;

                return (x);
            }
            avlnode<T, AL> *leftRotate(avlnode<T, AL> *y)
            {
                avlnode<T, AL> *x = y->right;
                avlnode<T, AL> *tmp = x->left;
                
                x->left = y;
                y->right = tmp;

                y->_height = max(height(y->left), height(y->right)) + 1;
                x->_height = max(height(x->left), height(x->right)) + 1;

                return (x);
            }
            T getBalance(avlnode<T, AL> *n)
            {
                if (n == 0)
                    return (0);
                return (height(n->left) - height(n->right));
            }
            void preOrder(avlnode<T, AL> *root)
            {
                if (root != NULL)
                {
                    std::cout << root->key << " ";
                    preOrder(root->left);
                    preOrder(root->right);
                }
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
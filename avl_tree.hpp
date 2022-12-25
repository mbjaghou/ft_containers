/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:31:11 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/12/24 14:24:27 by mbjaghou         ###   ########.fr       */
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
            T*       _key;//element
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
                cop         _comp;
                AL          alloc;
                typename AL::template rebind<T>::other _Alloc_type;
            public:
                avlnode<T, AL> *root;
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
                // void preOrder(avlnode<T, AL> *root)
                // {
                //     if (root != NULL)
                //     {
                //         std::cout << root->_key << " ";
                //         preOrder(root->left);
                //         preOrder(root->right);
                //     }
                // }
                avlnode<T, AL> *insert(const T &key)
                {
                    root = insert(root, key);
                    return (root);
                }
                bool _delete(const T &key)
                {
                    if (search(root, key))
                    {
                        root = _delete(root, key);
                        return true;
                    }
                    else
                        return false; 
                }
                avlnode<T, AL> *search(avlnode<T, AL> *node, const T &key) const
			    {
			    	if (!node )
			    		return (node);
			    	if (node->_key && node->_key->first == key.first)
			    		return (node);
			    	if (_comp(key.first, node->_key->first))
			    		return (search(node->left, key));
			    	else if (_comp(node->_key->first, key.first))
			    		return (search(node->right, key));
			    	return (node);
			    }
                avlnode<T, AL> *minValueNode(avlnode<T, AL> *node) const
			    {
				    if (!node)
				    	return (NULL);
				    avlnode<T, AL> *min = node;
				    while (min->left)
				    	min = min->left;
				    return (min);
			    }
			    avlnode<T, AL> *maxValueNode(avlnode<T, AL> *node) const
			    {
			    	if (!node)
			    		return (NULL);
			    	avlnode<T, AL> *max = node;
			    	while (max->right)
			    		max = max->right;
			    	return (max);
			    }
                int getBalance(avlnode<T, AL> *n)
                {
                    if (n == 0)
                        return (0);
                    return (height(n->left) - height(n->right));
                }
                avlnode<T, AL> balance_for_insert(avlnode<T, AL> *node, T key)
                {
                    int balance = getBalance(node);
                    
                    // Left Left Case  
                    if (balance > 1 && _comp(key->first , node->left->_key->first))
                        return rightRotate(node);
                    // Right Right Case  
                    if (balance < -1 && _comp(node->right->_key->first , key->first))
                        return leftRotate(node);
                    // Left Right Case  
                    if (balance > 1 && _comp(node->left->_key->first, key->first))
                    {
                        node->left = leftRotate(node->left);
                        return rightRotate(node);
                    }
                    // Right Left Case  
                    if (balance < -1 && _comp(key->first , node->right->_key->first))
                    {
                        node->right = rightRotate(node->right);
                        return leftRotate(node);
                    }
                    return node;
                    
                }
                avlnode<T, AL> balance_for_delete(avlnode<T, AL> *node)
                {
                    int balance = getBalance(node);
                    
                    // Left Left Case  
                    if (balance > 1 && getBalance(root->left) >= 0)
                        return rightRotate(node);
                    // Right Right Case  
                    if (balance < -1 && getBalance(root->right) <= 0)
                        return leftRotate(node);
                    // Left Right Case  
                    if (balance > 1 && getBalance(root->left) < 0)
                    {
                        node->left = leftRotate(node->left);
                        return rightRotate(node);
                    }
                    // Right Left Case  
                    if (balance < -1 && getBalance(root->right) > 0)
                    {
                        node->right = rightRotate(node->right);
                        return leftRotate(node);
                    }
                    return node;
                    
                }
                avlnode<T, AL> * newNode(T* key)
                {
                    avlnode<T, AL> *node = _Alloc_type.allocate(1);
                    _Alloc_type.construct(node, key);
                    return (node);
                }
                avlnode<T, AL> *insert(avlnode<T, AL>* node, T &key)
                {
                    if (node == NULL)
                        return(newNode(key));
                    if (_comp(key->first ,node->_key->first ))
                    {
                        node->left = insert(node->left, key);
                        node->left->parent = node;
                    }
                    else if (_comp(node->_key->first , key->first))
                    {
                        node->right = insert(node->right, key);
                        node->right->parent = node;
                    }
                    else
                        return node;
                    node->_height = 1 + max(height(node->left),
                        height(node->right));
                    return balance_for_insert(node, key);
                }
                avlnode<T, AL>* _delete(avlnode<T, AL>* node, const T& key) {
		        	if (node == NULL)
		        		return NULL;
		        	if (_comp(key.first ,node->_key->first))
		        		node->left = _delete(node->left, key);
		        	else if(_comp(node->_key->first, key.first))
		        		node->right = _delete(node->right, key);
		        	else {
                        // node with only one child or no child 
		        		if(node->left == NULL || node->right == NULL) {
		        			avlnode<T, AL> *temp = node->left ? node->left : node->right;
		        			if (temp == NULL) {
		        				temp = node;
		        				node = NULL;
		        			}
		        			else {
                                // One child case Copy the contents of the non-empty child 
		        				avlnode<T, AL> *newparent = node->parent;
		        				*node = *temp;
		        				node->parent = newparent;
		        			}
		        			alloc.destroy(temp->_key);
		        			alloc.deallocate(temp->_key , 1);
		        			_Alloc_type.destroy(temp);
		        			_Alloc_type.deallocate(temp, 1);
		        		}
		        		else {
                            // node with two children: Get the inorder 
                            // successor (smallest in the right subtree) 
		        			avlnode<T, AL> *tmp = minValueNode(node->right);
		        			alloc.construct(node->_key, *tmp->_key);
		        			node->right = _delete(node->right, *tmp->_key);
		        		}
		        	}
		        	if (node == NULL)
		        		return NULL;
		        	node->height = 1 + max(getHeight(node->left), getHeight(node->right));
		        	return balance_for_delete(node);
		        }
                avlnode<T, AL>* successor(const T& key) const 
                {
                    avlnode<T, AL>*	node = search(root, key);
                    if (node == NULL)
                        return NULL;
                    if (node->right)
                        return minNode(node->right);
                    avlnode<T, AL>*	successor = node->parent;
                    while (successor && successor->left != node) {
                        node = successor;
                        successor = node->parent;
                    }
                    return successor;
                }
                avlnode<T, AL>* predecessor(const T& key) const {
                    avlnode<T, AL>*	node = search(root, key);
                    if (node == NULL)
                        return NULL;
                    if (node->left)
                        return maxNode(node->left);
                    avlnode<T, AL>*	predecessor = node->parent;
                    while (predecessor && predecessor->right != node) {
                        predecessor = predecessor;
                        predecessor = node->parent;
                    }
                    return predecessor;
                }
        };
}
#endif
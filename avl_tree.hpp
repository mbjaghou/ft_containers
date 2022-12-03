/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:31:11 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/12/03 13:48:18 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <iostream>

namespace ft
{
    template <typename T>
    class Node
    {
        public:
            T key;
            Node *left;
            Node *right;
            int _height;
        int height(Node *N)
        {
            if (N == NULL)
                return 0;
            return N->_height;
        }
        T max(T a, T b)
        {
            return (a > b)? a : b;
        }
        Node* newNode(T key)
        {
            Node* node = new Node();
            node->key = key;
            node->left = NULL;
            node->right = NULL;
            node->_height = 1;
            return(node);
        }
        Node *rightRotate(Node *y)
        {
            Node *x = y->left;
            Node *T2 = x->right;

            x->right = y;
            y->left = T2;
            y->_height = max(height(y->left),
                            height(y->right)) + 1;
            x->_height = max(height(x->left),
                            height(x->right)) + 1;
            return x;
        }
        Node *leftRotate(Node *x)
        {
            Node *y = x->right;
            Node *T2 = y->left;

            y->left = x;
            x->right = T2;
            x->_height = max(height(x->left),   
                            height(x->right)) + 1;
            y->_height = max(height(y->left),
                            height(y->right)) + 1;
            return y;
        }
        T getBalance(Node *N)
        {
            if (N == NULL)
                return 0;
            return height(N->left) - height(N->right);
        }
        Node* insert(Node* node, int key)
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
            if (balance > 1 && key < node->left->key)
                return rightRotate(node);
            if (balance < -1 && key > node->right->key)
                return leftRotate(node);
            if (balance > 1 && key > node->left->key)
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
            if (balance < -1 && key < node->right->key)
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
            return node;
        }
        Node* deleteNode(Node* root, int key) 
        {
            if (root == NULL) 
                return root; 
            if ( key < root->key ) 
                root->left = deleteNode(root->left, key);
            else if( key > root->key ) 
                root->right = deleteNode(root->right, key); 
            else
            {
                if( (root->left == NULL) ||
                    (root->right == NULL) ) 
                { 
                    Node *temp = root->left ? 
                                root->left : 
                                root->right; 
                    if (temp == NULL) 
                    { 
                        temp = root; 
                        root = NULL; 
                    } 
                    else
                        *root = *temp;
                    delete(temp); 
                } 
                else
                {
                    Node* temp = minValueNode(root->right); 
                    root->key = temp->key; 
                    root->right = deleteNode(root->right, 
                                            temp->key); 
                } 
            }
            if (root == NULL) 
                return root; 
            root->_height = 1 + max(height(root->left), 
                                height(root->right)); 
            int balance = getBalance(root); 
            if (balance > 1 && 
                getBalance(root->left) >= 0) 
                return rightRotate(root); 
            if (balance > 1 && 
                getBalance(root->left) < 0) 
            { 
                root->left = leftRotate(root->left); 
                return rightRotate(root); 
            } 
            if (balance < -1 && 
                getBalance(root->right) <= 0) 
                return leftRotate(root); 
            if (balance < -1 && 
                getBalance(root->right) > 0) 
            { 
                root->right = rightRotate(root->right); 
                return leftRotate(root); 
            } 
            return root; 
        } 
        Node * minValueNode(Node* node) 
        { 
            Node* current = node; 
            while (current->left != NULL) 
                current = current->left; 
        
            return current; 
        } 
        void preOrder(Node *root)
        {
            if(root != NULL)
            {
                std::cout << root->key << " ";
                preOrder(root->left);
                preOrder(root->right);
            }
        }
                    
    };
}


#endif
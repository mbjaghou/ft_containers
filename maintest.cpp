#include "avl_tree.hpp"

int main()
{
    ft::avlnode<int> *root = NULL;
     
    /* Constructing tree given in
    the above figure */
    root = insert(root, 5);
    root = insert(root, 9);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
     
    /* The constructed AVL Tree would be
                30
            / \
            20 40
            / \ \
        10 25 50
    */
    std::cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    root->preOrder(root);

    // root = root->deleteNode(root, 10);
    //     std::cout << "\nPreorder traversal after"
    //      << " deletion of 10 \n"; 
    root->preOrder(root); 
    return 0;
}
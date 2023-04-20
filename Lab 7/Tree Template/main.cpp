#include <iostream>
#include "Tree.h"

// Comparison function used by find()
bool compare_find(const int& a, const int& b) {
    return a == b;
}

// Comparison function for sorting nodes by value
bool compare_sort(const int& a, const int& b) {
    return a > b;
}

int main()
{
    using TreeNode = typename Tree<int>::Node;

    // Create a new tree with an integer root node
    Tree<int> my_tree;
    TreeNode* root = my_tree.add_node(10);

    // Add some child nodes

    TreeNode* child1 = my_tree.add_node(5, root);
    TreeNode* child2 = my_tree.add_node(15, root);
    TreeNode* child3 = my_tree.add_node(7, child1);
    TreeNode* child4 = my_tree.add_node(12, child2);

    // Get a node by parent reference
    TreeNode& node = my_tree.get_node(root);

    // Print the value of the node
    std::cout << "Value of node: " << node.value << std::endl;

    // Delete a node and its children
    my_tree.delete_node(child1);

    // Find a node based on its value
    TreeNode* found_node = my_tree.find(compare_find, 7);

    if (found_node != nullptr) {
        std::cout << "Found node with value: " << found_node->value << std::endl;
    }
    else {
        std::cout << "Node not found" << std::endl;
    }

    // Insert a new node at a specific index
    my_tree.insert(8, root, 2);

    // Sort the children of a node by value
    my_tree.sort(root, compare_sort);

    // Count the number of children of a node
    int num_children = my_tree.count(root);
    std::cout << "Number of children: " << num_children << std::endl;

    my_tree.print_tree(root);

    return 0;
}
#pragma once

template <typename T>
class Tree {

public:

    struct Node {
        T value;
        Node* parent;
        Node* first_child;
        Node* next_sibling;

        Node(T value, Node* parent = nullptr)
            : value(value), parent(parent), first_child(nullptr), next_sibling(nullptr) {}
    };

    Tree() : m_root(nullptr) {}
    ~Tree() { delete_node(m_root); }

    Node* add_node(const T& value, Node* parent = nullptr) {
        Node* node = new Node(value, parent);

        if (parent == nullptr) {
            m_root = node;
        }
        else if (parent->first_child == nullptr) {
            parent->first_child = node;
        }
        else {
            Node* child = parent->first_child;
            while (child->next_sibling != nullptr) {
                child = child->next_sibling;
            }
            child->next_sibling = node;
        }

        return node;
    }


    Node& get_node(Node* parent = nullptr) const {

        if (parent == nullptr) {
            return *m_root;
        }
        else {
            return *(parent->first_child);
        }
    }

    // (deletes a node and all its children)
    void delete_node(Node* node){

        if (node == nullptr) {
            return;
        }

        // Recursively delete all child nodes
        while (node->first_child != nullptr) {
            delete_node(node->first_child);
        }

        // Remove node from its parent's children list
        if (node->parent == nullptr) {
            m_root = nullptr;
        }
        else if (node->parent->first_child == node) {
            node->parent->first_child = node->next_sibling;
        }
        else {
            Node* child = node->parent->first_child;
            while (child->next_sibling != node) {
                child = child->next_sibling;
            }
            child->next_sibling = node->next_sibling;
        }

        // Delete the node
        delete node;
    }

    
    Node* find(bool (*cmp)(const T&, const T&), const T& value) const {
        return find_helper(m_root, cmp, value);
    }


    void insert(const T& value, Node* parent, int index) {
        if (parent == nullptr) {
            return;
        }

        // Create the new node
        Node* node = new Node(value, parent);

        // Insert the new node at the given index
        if (index == 0 || parent->first_child == nullptr) {
            node->next_sibling = parent->first_child;
            parent->first_child = node;
        }
        else {
            Node* child = parent->first_child;
            int i = 1;
            while (child->next_sibling != nullptr && i < index) {
                child = child->next_sibling;
                i++;
            }
            node->next_sibling = child->next_sibling;
            child->next_sibling = node;
        }
    }

    void sort(Node* parent, bool (*compare)(const T&, const T&) = nullptr) {

        if (!parent) {
            return;
        }

        Node* current = parent->first_child;

        // Traverse the list of children and sort using the provided compare function or operator<
        while (current != nullptr) {
            Node* next = current->next_sibling;
            while (next != nullptr) {
                if (compare ? compare(current->value, next->value) : (current->value < next->value)) {
                    T temp = current->value;
                    current->value = next->value;
                    next->value = temp;
                }
                next = next->next_sibling;
            }
            current = current->next_sibling;
        }
    }

    
    int count(Node* parent = nullptr) const {

        int nr = 0;

        // If parent is null, start from root
        if (parent == nullptr) {
            parent = m_root;
        }

        // Traverse the children of parent node and increment count for each child
        for (Node* child = parent->first_child; child != nullptr; child = child->next_sibling) {
            nr += 1 + count(child);
        }

        return nr;
    }

    // auxiliar function to check if some methods work properly
    void print_tree(Node* root, int indent = 0) const {
        if (root == nullptr) {
            return;
        }

        // Print the node value indented by the given amount
        for (int i = 0; i < indent; i++) {
            std::cout << "  ";
        }
        std::cout << "- " << root->value << std::endl;

        // Recursively print the children of the node
        for (Node* child = root->first_child; child != nullptr; child = child->next_sibling) {
            print_tree(child, indent + 1);
        }
    }



private:

    Node* m_root;

    Node* find_helper(Node* node, bool (*cmp)(const T&, const T&), const T& value) const {

        if (node == nullptr) {
            return nullptr;
        }

        if (cmp(node->value, value)) {
            return node;
        }

        Node* found = nullptr;
        Node* child = node->first_child;
        while (child != nullptr && found == nullptr) {
            found = find_helper(child, cmp, value);
            child = child->next_sibling;
        }

        return found;
    }
};
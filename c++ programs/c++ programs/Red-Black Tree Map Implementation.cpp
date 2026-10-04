#include <iostream>
#include <stdexcept>
#include <string>

enum Color { RED, BLACK };

template <typename K, typename V>
class Map {
private:
    struct Node {
        K key;
        V value;
        Color color;
        Node* left;
        Node* right;
        Node* parent;

        Node(K k, V v) 
            : key(k), value(v), color(RED), left(NULL), right(NULL), parent(NULL) {}
    };

    Node* root;
    size_t treeSize;

    // Helper: Left Rotate
    void rotateLeft(Node*& ptr) {
        Node* rightChild = ptr->right;
        ptr->right = rightChild->left;

        if (ptr->right != NULL)
            ptr->right->parent = ptr;

        rightChild->parent = ptr->parent;

        if (ptr->parent == NULL)
            root = rightChild;
        else if (ptr == ptr->parent->left)
            ptr->parent->left = rightChild;
        else
            ptr->parent->right = rightChild;

        rightChild->left = ptr;
        ptr->parent = rightChild;
    }

    // Helper: Right Rotate
    void rotateRight(Node*& ptr) {
        Node* leftChild = ptr->left;
        ptr->left = leftChild->right;

        if (ptr->left != NULL)
            ptr->left->parent = ptr;

        leftChild->parent = ptr->parent;

        if (ptr->parent == NULL)
            root = leftChild;
        else if (ptr == ptr->parent->right)
            ptr->parent->right = leftChild;
        else
            ptr->parent->left = leftChild;

        leftChild->right = ptr;
        ptr->parent = leftChild;
    }

    // Balance tree after insertion
    void fixViolation(Node*& ptr) {
        Node* parentNode = NULL;
        Node* grandParentNode = NULL;

        while ((ptr != root) && (ptr->color != BLACK) && (ptr->parent->color == RED)) {
            parentNode = ptr->parent;
            grandParentNode = ptr->parent->parent;

            // Case A: Parent is left child of Grandparent
            if (parentNode == grandParentNode->left) {
                Node* uncleNode = grandParentNode->right;

                // Case 1: Uncle is RED -> Recolor
                if (uncleNode != NULL && uncleNode->color == RED) {
                    grandParentNode->color = RED;
                    parentNode->color = BLACK;
                    uncleNode->color = BLACK;
                    ptr = grandParentNode;
                } else {
                    // Case 2: ptr is right child -> Left Rotate
                    if (ptr == parentNode->right) {
                        rotateLeft(parentNode);
                        ptr = parentNode;
                        parentNode = ptr->parent;
                    }
                    // Case 3: ptr is left child -> Right Rotate
                    rotateRight(grandParentNode);
                    std::swap(parentNode->color, grandParentNode->color);
                    ptr = parentNode;
                }
            } 
            // Case B: Parent is right child of Grandparent
            else {
                Node* uncleNode = grandParentNode->left;

                // Case 1: Uncle is RED -> Recolor
                if (uncleNode != NULL && uncleNode->color == RED) {
                    grandParentNode->color = RED;
                    parentNode->color = BLACK;
                    uncleNode->color = BLACK;
                    ptr = grandParentNode;
                } else {
                    // Case 2: ptr is left child -> Right Rotate
                    if (ptr == parentNode->left) {
                        rotateRight(parentNode);
                        ptr = parentNode;
                        parentNode = ptr->parent;
                    }
                    // Case 3: ptr is right child -> Left Rotate
                    rotateLeft(grandParentNode);
                    std::swap(parentNode->color, grandParentNode->color);
                    ptr = parentNode;
                }
            }
        }
        root->color = BLACK;
    }

    // Binary Search Tree Insertion Helper
    Node* insertBST(Node* rootNode, Node* ptr) {
        if (rootNode == NULL) return ptr;

        if (ptr->key < rootNode->key) {
            rootNode->left = insertBST(rootNode->left, ptr);
            rootNode->left->parent = rootNode;
        } else if (ptr->key > rootNode->key) {
            rootNode->right = insertBST(rootNode->right, ptr);
            rootNode->right->parent = rootNode;
        } else {
            // Key already exists; update value
            rootNode->value = ptr->value;
            delete ptr;
            return rootNode;
        }

        return rootNode;
    }

    // Helper: Find node by key
    Node* findNode(Node* node, const K& key) const {
        if (node == NULL || node->key == key)
            return node;

        if (key < node->key)
            return findNode(node->left, key);

        return findNode(node->right, key);
    }

    // Helper: In-order traversal print
    void inOrderPrint(Node* node) const {
        if (node == NULL) return;

        inOrderPrint(node->left);
        std::cout << "[" << node->key << " : " << node->value << "] ";
        inOrderPrint(node->right);
    }

    // Helper: Clear tree memory
    void destroyTree(Node* node) {
        if (node == NULL) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    Map() : root(NULL), treeSize(0) {}

    ~Map() {
        destroyTree(root);
    }

    // Insert or Update key-value pair - O(log N)
    void insert(const K& key, const V& value) {
        Node* existing = findNode(root, key);
        if (existing != NULL) {
            existing->value = value;
            return;
        }

        Node* newNode = new Node(key, value);
        root = insertBST(root, newNode);
        fixViolation(newNode);
        treeSize++;
    }

    // Access via subscript operator [] - O(log N)
    V& operator[](const K& key) {
        Node* node = findNode(root, key);
        if (node == NULL) {
            insert(key, V());
            node = findNode(root, key);
        }
        return node->value;
    }

    // Check if key exists - O(log N)
    bool contains(const K& key) const {
        return findNode(root, key) != NULL;
    }

    // Search value by key - O(log N)
    V& at(const K& key) {
        Node* node = findNode(root, key);
        if (node == NULL) throw std::out_of_range("Key not found");
        return node->value;
    }

    size_t getSize() const { return treeSize; }
    bool empty() const { return treeSize == 0; }

    // Print contents in sorted order of keys - O(N)
    void print() const {
        if (empty()) {
            std::cout << "{ Empty Map }\n";
            return;
        }
        std::cout << "{ ";
        inOrderPrint(root);
        std::cout << "}\n";
    }
};

// ==========================================
// MAIN ENTRY POINT
// ==========================================
int main() {
    Map<std::string, int> ageMap;

    std::cout << "--- Map Operations ---\n";

    // Insertion
    ageMap.insert("Alice", 25);
    ageMap.insert("Bob", 30);
    ageMap.insert("Charlie", 22);

    // Operator [] Insertion/Access
    ageMap["David"] = 28;

    std::cout << "Map Contents (Sorted by Key):\n";
    ageMap.print();

    // Value Lookup
    std::cout << "\nBob's Age: " << ageMap.at("Bob") << "\n";

    // Value Update
    ageMap["Alice"] = 26;
    std::cout << "Updated Alice's Age: " << ageMap["Alice"] << "\n";

    // Key Existence
    std::cout << "Contains 'Charlie': " << (ageMap.contains("Charlie") ? "Yes" : "No") << "\n";
    std::cout << "Contains 'Eve': " << (ageMap.contains("Eve") ? "Yes" : "No") << "\n";

    std::cout << "Map Size: " << ageMap.getSize() << "\n";

    return 0;
}

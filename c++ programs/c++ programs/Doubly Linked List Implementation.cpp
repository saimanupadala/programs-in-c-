#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& val) : data(val), prev(NULL), next(NULL) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    LinkedList() : head(NULL), tail(NULL), size(0) {}

    ~LinkedList() {
        clear();
    }

    // Push front - O(1)
    void push_front(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Push back - O(1)
    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // Pop front - O(1)
    void pop_front() {
        if (!head) throw std::underflow_error("List is empty");
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        else tail = NULL;
        delete temp;
        size--;
    }

    // Pop back - O(1)
    void pop_back() {
        if (!tail) throw std::underflow_error("List is empty");
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = NULL;
        else head = NULL;
        delete temp;
        size--;
    }

    // Clear all nodes - O(N)
    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = tail = NULL;
        size = 0;
    }

    // Display elements - O(N)
    void print() const {
        Node* curr = head;
        while (curr) {
            std::cout << curr->data << " <-> ";
            curr = curr->next;
        }
        std::cout << "NULL\n";
    }

    size_t getSize() const { return size; }
    bool empty() const { return size == 0; }
};

int main() {
    LinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_front(5);

    std::cout << "List contents: ";
    list.print();

    std::cout << "List size: " << list.getSize() << std::endl;

    return 0;
}

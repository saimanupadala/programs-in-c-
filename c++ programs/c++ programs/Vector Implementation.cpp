#include <iostream>
#include <stdexcept>

// ==========================================
// 1. DYNAMIC VECTOR IMPLEMENTATION
// ==========================================
template <typename T>
class Vector {
private:
    T* data;
    size_t capacity;
    size_t size;

    void reallocate(size_t newCapacity) {
        T* newBuffer = new T[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newBuffer[i] = data[i];
        }
        delete[] data;
        data = newBuffer;
        capacity = newCapacity;
    }

public:
    Vector() : data(NULL), capacity(0), size(0) {}

    ~Vector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            size_t newCapacity = capacity == 0 ? 2 : capacity * 2;
            reallocate(newCapacity);
        }
        data[size++] = value;
    }

    void pop_back() {
        if (size == 0) throw std::underflow_error("Vector is empty");
        size--;
    }

    T& at(size_t index) {
        if (index >= size) throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    T& operator[](size_t index) {
        return data[index];
    }

    void insert(size_t index, const T& value) {
        if (index > size) throw std::out_of_range("Index out of bounds");
        if (size == capacity) {
            reallocate(capacity == 0 ? 2 : capacity * 2);
        }
        for (size_t i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    void erase(size_t index) {
        if (index >= size) throw std::out_of_range("Index out of bounds");
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;
    }

    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
    bool empty() const { return size == 0; }
};

// ==========================================
// 2. DOUBLY LINKED LIST IMPLEMENTATION
// ==========================================
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

    void pop_front() {
        if (!head) throw std::underflow_error("List is empty");
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        else tail = NULL;
        delete temp;
        size--;
    }

    void pop_back() {
        if (!tail) throw std::underflow_error("List is empty");
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = NULL;
        else head = NULL;
        delete temp;
        size--;
    }

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

// ==========================================
// 3. MAIN FUNCTION (ENTRY POINT)
// ==========================================
int main() {
    // --- Vector Operations ---
    std::cout << "--- Vector Test ---\n";
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "Vector Elements: ";
    for (size_t i = 0; i < vec.getSize(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\nVector Size: " << vec.getSize() << "\n\n";

    // --- Linked List Operations ---
    std::cout << "--- Linked List Test ---\n";
    LinkedList<int> list;
    list.push_back(100);
    list.push_back(200);
    list.push_front(50);

    std::cout << "LinkedList Elements: ";
    list.print();
    std::cout << "List Size: " << list.getSize() << "\n";

    return 0;
}

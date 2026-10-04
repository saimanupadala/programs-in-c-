#include <iostream>
#include <stdexcept>

template <typename T>
class Deque {
private:
    T* data;
    size_t capacity;
    size_t size;
    int frontIndex;
    int backIndex;

    // Resizes the internal array when capacity is reached - O(N)
    void reallocate(size_t newCapacity) {
        T* newBuffer = new T[newCapacity];
        
        for (size_t i = 0; i < size; ++i) {
            newBuffer[i] = data[(frontIndex + i) % capacity];
        }

        delete[] data;
        data = newBuffer;
        capacity = newCapacity;
        frontIndex = 0;
        backIndex = (size == 0) ? -1 : static_cast<int>(size - 1);
    }

public:
    Deque() : data(NULL), capacity(0), size(0), frontIndex(-1), backIndex(-1) {}

    ~Deque() {
        delete[] data;
    }

    // Push element to the front - O(1) amortized
    void push_front(const T& value) {
        if (size == capacity) {
            reallocate(capacity == 0 ? 2 : capacity * 2);
        }

        if (empty()) {
            frontIndex = 0;
            backIndex = 0;
        } else {
            frontIndex = (frontIndex - 1 + static_cast<int>(capacity)) % static_cast<int>(capacity);
        }

        data[frontIndex] = value;
        size++;
    }

    // Push element to the back - O(1) amortized
    void push_back(const T& value) {
        if (size == capacity) {
            reallocate(capacity == 0 ? 2 : capacity * 2);
        }

        if (empty()) {
            frontIndex = 0;
            backIndex = 0;
        } else {
            backIndex = (backIndex + 1) % static_cast<int>(capacity);
        }

        data[backIndex] = value;
        size++;
    }

    // Remove element from the front - O(1)
    void pop_front() {
        if (empty()) throw std::underflow_error("Deque is empty");

        if (size == 1) {
            frontIndex = -1;
            backIndex = -1;
        } else {
            frontIndex = (frontIndex + 1) % static_cast<int>(capacity);
        }
        size--;
    }

    // Remove element from the back - O(1)
    void pop_back() {
        if (empty()) throw std::underflow_error("Deque is empty");

        if (size == 1) {
            frontIndex = -1;
            backIndex = -1;
        } else {
            backIndex = (backIndex - 1 + static_cast<int>(capacity)) % static_cast<int>(capacity);
        }
        size--;
    }

    // Access first element - O(1)
    T& front() {
        if (empty()) throw std::underflow_error("Deque is empty");
        return data[frontIndex];
    }

    // Access last element - O(1)
    T& back() {
        if (empty()) throw std::underflow_error("Deque is empty");
        return data[backIndex];
    }

    // Direct index access - O(1)
    T& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of bounds");
        return data[(frontIndex + index) % capacity];
    }

    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
    bool empty() const { return size == 0; }

    // Display elements from front to back - O(N)
    void print() const {
        if (empty()) {
            std::cout << "[ Empty Deque ]\n";
            return;
        }
        std::cout << "Front -> ";
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[(frontIndex + i) % capacity] << " ";
        }
        std::cout << "<- Back\n";
    }
};

// ==========================================
// MAIN ENTRY POINT
// ==========================================
int main() {
    Deque<int> dq;

    std::cout << "--- Deque Operations ---\n";
    
    dq.push_back(20);
    dq.push_back(30);
    dq.push_front(10);
    dq.push_front(5);

    std::cout << "Deque elements: ";
    dq.print(); // Output: Front -> 5 10 20 30 <- Back

    std::cout << "Front element: " << dq.front() << "\n";
    std::cout << "Back element: " << dq.back() << "\n";

    dq.pop_front();
    std::cout << "After pop_front: ";
    dq.print(); // Output: Front -> 10 20 30 <- Back

    dq.pop_back();
    std::cout << "After pop_back: ";
    dq.print(); // Output: Front -> 10 20 <- Back

    std::cout << "Element at index 1: " << dq[1] << "\n";

    return 0;
}

// stack.cpp
#include <vector>
#include <cstddef>  // for size_t

// Template definition for the stack
template <typename T>
class Stack {
public:
    Stack();

    size_t size() const;

    bool peek(T& elem) const;

    bool pop(T& elem);

    void push(const T& elem);

private:
    std::vector<T> elements;
};

// Constructor: initialize empty stack
template <typename T>
Stack<T>::Stack() {
    // elements is default-initialized
}

// Returns the number of elements in the stack
template <typename T>
size_t Stack<T>::size() const {
    return elements.size();
}

// Adds an element to the top of the stack
template <typename T>
void Stack<T>::push(const T& elem) {
    elements.push_back(elem);
}

// Removes the top element and assigns it to elem
// Returns true if successful, false if stack was empty
template <typename T>
bool Stack<T>::pop(T& elem) {
    if (elements.empty()) {
        return false;
    }
    elem = elements.back(); // copy the last element
    elements.pop_back();    // remove it from the vector
    return true;
}

// Assigns elem with the top element without removing it
// Returns true if successful, false if stack was empty
template <typename T>
bool Stack<T>::peek(T& elem) const {
    if (elements.empty()) {
        return false;
    }
    elem = elements.back();
    return true;
}


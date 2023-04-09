// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
private:
    T* array;
    int top;

public:
    TStack() : top(-1) {
        array = new T[size];
    }
    bool isEmpty() const {
        return top == -1;
    }
    bool isFull() const {
        return top == size - 1;
    }
    void push(T num) {
        if (isFull()) {
            throw std::string("full!");
        }
        else {
            array[++top] = num;
        }
    }
    const T& get() {
        if (isEmpty()) {
            throw std::string("empty!");
        }
        else {
            return array[top];
        }
    }
    const T& pop() {
        if (isEmpty()) {
            throw std::string("empty!");
        }
        else {
            return array[top--];
        }
    }
};
#endif  // INCLUDE_TSTACK_H_

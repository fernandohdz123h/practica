//Fernando Hernandez Hernandez
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <sstream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insertion(T value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    int search(T value) {
        Node* current = head;
        int position = 0;
        while (current != nullptr) {
            if (current->data == value) {
                return position;
            }
            current = current->next;
            position++;
        }
        return -1;
    }

    void update(int position, T newValue) {
        Node* current = head;
        int currentIndex = 0;
        while (current != nullptr && currentIndex < position) {
            current = current->next;
            currentIndex++;
        }
        if (current != nullptr) {
            current->data = newValue;
        }
    }

    T deleteAt(int position) {
        if (head == nullptr) {
            throw std::out_of_range("Empty list");
        }

        Node* current = head;
        if (position == 0) {
            T data = head->data;
            head = head->next;
            delete current;
            return data;
        }

        Node* prev = nullptr;
        int currentIndex = 0;
        while (current != nullptr && currentIndex < position) {
            prev = current;
            current = current->next;
            currentIndex++;
        }

        if (current == nullptr) {
            throw std::out_of_range("Position out of range");
        }

        prev->next = current->next;
        T data = current->data;
        delete current;
        return data;
    }

    std::string toString() {
        std::stringstream ss;
        Node* current = head;
        while (current != nullptr) {
            ss << current->data;
            if (current->next != nullptr) {
                ss << " ";
            }
            current = current->next;
        }
        return ss.str();
    }
};

#endif // LINKEDLIST_H

#pragma once

#include <iostream>
#include <exception>

template<class T>
class CustomList{
private:
    struct Node {
        T data;
        Node* next;

        Node(T value) {
            std::cout << "\nINFO::CustomList::Node::Constructor(T)\n";

            this->data = value;
            this->next = nullptr;
        }

        ~Node() {
            std::cout << "\nINFO::CustomList::Node::Destructor()\n";

            if (this->next != nullptr) delete this->next;
        }
    };
    Node* head;
    unsigned int _length;
    
    CustomList(const CustomList& list) = delete;
    void operator=(const CustomList&) = delete;
public:
    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* element) {
            std::cout << "\nINFO::CustomList::Iterator::Constructor(Node*)\n";

            this->current = element;
        }

        Iterator(const Iterator& iter) {
            std::cout << "\nINFO::CustomList::Iterator::Constructor(const Iterator&)\n";

            this->current = iter.current;
        }

        Iterator& operator++() {
            std::cout << "\nINFO::CustomList::Iterator::operator{++this}\n";

            if (this->current == nullptr) throw std::exception("No more elements in the list");
            this->current = this->current->next;
            return *this;
        }

        Iterator operator++(int) {
            std::cout << "\nINFO::CustomList::Iterator::operator{this++}\n";

            if (this->current == nullptr) throw std::exception("No more elements in the list");
            this->current = this->current->next;
            return *this;
        }

        T operator*() {
            std::cout << "\nINFO::CustomList::Iterator::operator*\n";

            return this->current->data;
        }

        T* operator->() {
            std::cout << "\nINFO::CustomList::Iterator::operator->\n";

            return &(this->current->data);
        }

        bool operator==(Iterator iter) {
            std::cout << "\nINFO::CustomList::Iterator::operator{==Iterator}\n";

            return this->current == iter.current;
        }

        bool operator!=(Iterator iter) {
            std::cout << "\nINFO::CustomList::Iterator::operator{!=Iterator}\n";

            return this->current != iter.current;
        }
    };

    CustomList() {
        std::cout << "\nINFO::CustomList::Constructor()\n";

        this->head = nullptr;
        this->_length = 0;
    }

    ~CustomList() {
        std::cout << "\nINFO::CustomList::Destructor()\n";

        if (this->head != nullptr) delete this->head;
    }
    
    void push(T data) {
        std::cout << "\nINFO::CustomList::push(T data)\n";

        Node* curr;
        try
        {
            curr = new Node(data);
        }
        catch (const std::exception& e)
        {
            /* TODO: response to memory overflow */
            std::cerr << "\nERROR::" << e.what() << '\n';
            return;
        }
        curr->next = this->head;
        this->head = curr;
        this->_length++;
    }

    void push_back(T data) {
        std::cout << "\nINFO::CustomList::push_back(T data)\n";

        if (this->head == nullptr)
        {
            this->push(data);
            return;
        }
        Node* curr = this->head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        try
        {
            curr->next = new Node(data);
        }
        catch (const std::exception& e)
        {
            /* TODO: response to memory overflow */
            std::cerr << "\nERROR::" << e.what() << '\n';
            return;
        }
        this->_length++;
    }
    
    T pop() {
        std::cout << "\nINFO::CustomList::pop()\n";

        if (this->head == nullptr) throw std::exception("List is empty");
        T data = this->head->data;
        Node* curr = this->head;
        this->head = curr->next;
        curr->next = nullptr;
        delete curr;
        this->_length--;
        return data;
    }

    T pop_back() {
        std::cout << "\nINFO::CustomList::pop_back()\n";

        if (this->head == nullptr) throw std::exception("List is empty");
        if (this->head->next == nullptr) {
            T data = this->head->data;
            delete this->head;
            this->head = nullptr;
            return data;
        }

        Node* curr = this->head;
        while (curr->next->next != nullptr) {
            curr = curr->next;
        }
        T data = curr->next->data;
        delete curr->next;
        curr->next = nullptr;
        this->_length--;
        return data;
    }

    unsigned int length() {
        std::cout << "\nINFO::CustomList::length()\n";

        return this->_length;
    }

    Iterator begin() const {
        std::cout << "\nINFO::CustomList::begin()const\n";

        return Iterator(this->head);
    }

    Iterator getIterator(const unsigned int position) const {
        std::cout << "\nINFO::CustomList::getIterator(const unsigned int)const\n";

        if (this->head == nullptr) throw std::exception("List is empty");
        Iterator iter = Iterator(this->head);
        for (size_t i = 0; iter != this->end(); i++)
        {
            if (i == position) return iter;
            iter++;
        }
        throw std::exception("Not enough elements in the list");
    }

    Iterator end() const {
        std::cout << "\nINFO::CustomList::end()const\n";

        return Iterator(nullptr);
    }

    T& operator[](const int index) {
        std::cout << "\nINFO::CustomList::operator[const int]\n";

        if (index < 0) throw std::exception("Incorrect index");
        return this->getIterator(index).current->data;
    }
};
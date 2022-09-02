#include "CustomList.h"

#include <iostream>
#include <exception>

template<class T>
CustomList<T>::Node::Node(T value) {
    this->data = value;
    this->next = nullptr;
}

template<class T>
CustomList<T>::Node::~Node() {
    if (this->next != nullptr) delete this->next;
}

template<class T>
CustomList<T>::Iterator::Iterator() {
    this->current = nullptr;
}

template<class T>
CustomList<T>::Iterator::Iterator(const Iterator& iter) {
    this->current = iter.current;
}

template<class T>
CustomList<T>::Iterator& CustomList<T>::Iterator::operator++() {
    if (this->current->next == nullptr) throw std::exception("No more elements in the list");
    this->current = this->current->next;
    return *this;
}

template<class T>
CustomList<T>::Iterator CustomList<T>::Iterator::operator++(int) {
    if (this->current->next == nullptr) throw std::exception("No more elements in the list");
    this->current = this->current->next;
    return *this;
}

template<class T>
T CustomList<T>::Iterator::operator*() {
    return this->current->data;
}

template<class T>
T* CustomList<T>::Iterator::operator->() {
    return &(this->current->data);
}

template<class T>
bool CustomList<T>::Iterator::operator==(Iterator iter) {
    return this->current == iter.current;
}

template<class T>
bool CustomList<T>::Iterator::operator!=(Iterator iter) {
    return this->current != iter.current;
}

template<class T>
CustomList<T>::CustomList(){
    std::cout<<"\nINFO::CustomList::Constructor()\n";
    
    this->head = null;
}

template<class T>
CustomList<T>::~CustomList(){
    std::cout<<"\nINFO::CustomList::Destructor()\n";
    
    if(this->head != nullptr) delete this->head;
}

template<class T>
CustomList<T> CustomList<T>::push(T data){
    std::cout<<"\nINFO::CustomList::push(T data)\n";
    
    try
    {
        Node* curr = new Node(data);
    }
    catch (const std::exception& e)
    {
        /* TODO: response to memory overflow */
        std::cerr << "\nERROR::" << e.what() << '\n';
    }
    curr->next = this->head;
    this->head = curr;
    this->_length++;
    return *this;
}

template<class T>
CustomList<T> CustomList<T>::push_back(T data){
    std::cout<<"\nINFO::CustomList::push_back(T data)\n";
    
    Node* curr = this->head;
    while(curr->next != nullptr){
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
    }
    this->_length++;
    return *this;
}

template<class T>
T CustomList<T>::pop(){
    std::cout<<"\nINFO::CustomList::pop()\n";
    
    if (this->head == nullptr) throw std::exception("List is empty");
    T data = this->head->data;
    Node* curr = this->head;
    this->head = curr->next;
    curr->next = nullptr;
    delete curr;
    this->_length--;
    return data;
}

template<class T>
T CustomList<T>::pop_back(){
    std::cout<<"\nINFO::CustomList::pop()\n";
    
    if(this->head == nullptr) throw std::exception("List is empty");
    if(this->head->next == nullptr){
        T data = this->head->data;
        delete this->head;
        this->head = nullptr;
        return data;
    }
    
    Node* curr = this->head;
    while(curr->next->next != nullptr){
        curr = curr->next;
    }
    T data = curr->next->data;
    delete curr->next;
    curr->next = nullptr;
    this->_length--;
    return data;
}

template<class T>
unsigned int CustomList<T>::length() {
    return this->_length;
}

template<class T>
CustomList<T>::Iterator CustomList<T>::begin() {
    if (this->head == nullptr) throw std::exception("List is empty");
    Iterator iter;
    iter.current = this->head;
    return iter;
}

template<class T>
CustomList<T>::Iterator CustomList<T>::end() {
    if (this->head == nullptr) throw std::exception("List is empty");
    Iterator iter;
    iter.current = this->head;
    while (iter.current->next != nullptr)
    {
        iter++;
    }
    return iter;
}

template<class T>
CustomList<T>::Iterator CustomList<T>::getIterator(const unsigned int position) {
    if (this->head == nullptr) throw std::exception("List is empty");
    if (position == 0) return this->begin();
    Iterator iter;
    iter.current = this->head;
    for (size_t i = 1; iter.current->next != nullptr; i++)
    {
        iter++;
        if (i == position) return iter;
    }
    throw std::exception("Not enough elements in the list");
}

template<class T>
T CustomList<T>::operator[](const int index) const {
    if (index < 0) throw std::exception("Incorrect index");
    return *(this->getIterator(index));
}

template<class T>
T& CustomList<T>::operator[](const int index) {
    if (index < 0) throw std::exception("Incorrect index");
    return this->getIterator(index).current->data;
}
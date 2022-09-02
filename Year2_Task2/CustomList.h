#pragma once

template<class T>
class CustomList{
private:
    struct Node {
        T data;
        Node* next;
        Node(T value);
        ~Node();
    };
    Node* head;
    unsigned int _length;
    
    CustomList(const CustomList&) = delete;
    void operator=(const CustomList&) = delete;
public:
    class Iterator {
    private:
        Node* current;
        Iterator();
    public:
        Iterator(const Iterator& iter);

        Iterator& operator++();
        Iterator operator++(int);

        T operator*();
        T* operator->();

        bool operator==(Iterator iter);
        bool operator!=(Iterator iter);
    };

    CustomList();
    ~CustomList();
    
    CustomList push(T data);
    CustomList push_back(T data);
    
    T pop();
    T pop_back();

    unsigned int length();

    Iterator begin();
    Iterator getIterator(const unsigned int position);
    Iterator end();

    T operator[](const int index) const;
    T& operator[](const int index);
};
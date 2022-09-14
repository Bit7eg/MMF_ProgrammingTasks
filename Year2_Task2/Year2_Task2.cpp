#include <iostream>

#include "CustomList.h"

struct IntContainer {
    int data;
};

int main()
{
    CustomList<int> intList;
    CustomList<IntContainer> containerList;

    std::cout << "\n__________________________________________________________\n\n\n";

    intList.push(1);
    intList.push(2);
    int val = intList.pop();
    std::cout << "List contains: { ";
    for (CustomList<int>::Iterator iter = intList.begin(); iter != intList.end(); iter++)
    {
        std::cout << *iter << ", ";
    }
    std::cout << "}\nGets from intList: " << val << "\n";

    std::cout << "\n__________________________________________________________\n\n\n";

    containerList.push_back({ 2 });
    containerList.push_back({ 1 });
    IntContainer valContainer = containerList.pop_back();
    std::cout << "List contains: { ";
    for (CustomList<IntContainer>::Iterator iter = containerList.begin(); iter != containerList.end(); ++iter)
    {
        std::cout << iter->data << ", ";
    }
    std::cout << "\nGets from list: " << valContainer.data << "\n";

    //CustomList<int> copiedList = intList;
    //copiedList = intList;

    std::cout << "\n__________________________________________________________\n\n\n";
}
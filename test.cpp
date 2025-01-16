#include "linked_list.hpp"
#include <iostream>

int main(){
    linked_list list;
    list.push_back(10);
    list.push_back(14);
    list.push_front(20);

    std::cout << list.back() << list.front();
}
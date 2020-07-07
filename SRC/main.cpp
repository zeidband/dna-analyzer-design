#include <iostream>
#include "manager/manager.h"

int main() {
    Manager m;
    m.start();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
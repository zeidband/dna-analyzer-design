#include <iostream>
#include "manager/manager.h"

int main() {
    Manager m;
    m.start();
    std::cout << "good bye!" << std::endl;
    return 0;
}
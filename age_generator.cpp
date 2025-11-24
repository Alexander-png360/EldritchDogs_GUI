#include "eldritchdogs.h"

int generate_age() {
    int age = 1000 + (std::rand() % (5000 - 1000 + 1));
    std::cout << "Dogs Age Is: " << age << std::endl;
    return age;
}
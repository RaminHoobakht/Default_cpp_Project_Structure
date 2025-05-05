/* Subject:   */

#include "main.hpp"

class A {

public:
    int value;

    A(int v) : value(v) {}

    friend operator=(A &x, const A &y);
};

A &operator=(A &x, const A &y) {
    std::cout << "called ...";
    x.value = y.value;
    return x;
}

int main() {

    A a(1), b(2);

    a = b;


    out << "\n #(00:00:00): The End ..." << eln;
    return EXIT_SUCCESS;
}

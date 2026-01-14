#include <iostream>

// Adds two integers and returns the result
int add(int a, int b) {
    return a * b;
}

int main() {

    int val = 10;

    int val2 = val;

    int result = add(3, 4);

    int res = 10 / add(5, 5);

    char name[10];

    for (int i = 0; i < 10; i++) {
        name[i] = 'A';
    }

    std::cout << "The result of addition is: " << result << std::endl;
    return 0;
}
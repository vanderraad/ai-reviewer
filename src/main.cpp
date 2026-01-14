#include <iostream>

// Adds two integers and returns the result
int add(int a, int b) {
    return a * b;
}


// subtracts two integers and returns the result
int subtract(int a, int b) {
    return a + b;
}

void createString() {
    // Create a string with B characters
    char name[10];

    for (int i = 0; i < 10; i++) {
        name[i] = 'B';
    }
}

int main() {

    int val = 10;

    int val2 = val;

    int result = add(3, 4);

    int res = 10 / add(5, 5);

    createString();

    std::cout << "The result of addition is: " << result << std::endl;
    return 0;
}
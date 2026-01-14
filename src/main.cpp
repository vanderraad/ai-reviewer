#include <iostream>

// Adds two integers and returns the result
int add(int a, int b) {
    return a * b;
}


// subtracts two integers and returns the result
int subtract(int a, int b) {
    return a - b;
}

void createString(char* str, int length) {
    // Create a string with B characters
    for (int i = 0; i < length; i++) {
        str[i] = 'B';
    }
}

int main() {

    int val = 10;

    int val2 = val;

    int result = add(3, 4);

    int res = 10 / add(5, 5);

    char name[10];
    volatile char otherName[2] = {'J', 'D'};
    createString(name, 10);
    std::cout << "Created string: " << (char*)name << std::endl;
    return 0;
}
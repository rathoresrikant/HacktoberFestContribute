#include <iostream>

class A {
    int a;
    int b;

public:
    // Constructor
    A(int a_, int b_) : a(a_), b(b_) {}

    // Function to calculate sum
    int sum() {
        return a + b;
    }

    // Function to calculate average
    float average() {
        // Correctly cast 'a' to float for average calculation
        return (static_cast<float>(a) + b) / 2;
    }
};

int main() {
    A obj(4, 6); // Create an object of class A
    std::cout << "Sum: " << obj.sum() << std::endl; // Output the sum
    std::cout << "Average: " << obj.average() << std::endl; // Output the average
    return 0;
}

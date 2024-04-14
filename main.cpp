#include <iostream>
#include <vector>
#include <string>

template <class T, class B>
class A {
private:
    B elements;
public:
    void push(const T& element) {
        elements.push_back(element);
    }

    T pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        T element = elements.back();
        elements.pop_back();
        return element;
    }
};

int main() {
    A<int, std::vector<int>> intStack;
    intStack.push(1);
    intStack.push(2);

    try {
        std::cout << intStack.pop() << std::endl;  // Выведет 2
        std::cout << intStack.pop() << std::endl;  // Выведет 1
        std::cout << intStack.pop() << std::endl;  // Сгенерирует исключение, так как стек пустой
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    A<double, std::vector<double>> doubleStack;
    doubleStack.push(3.14);
    doubleStack.push(2.718);

    try {
        std::cout << doubleStack.pop() << std::endl;  // Выведет 2.718
        std::cout << doubleStack.pop() << std::endl;  // Выведет 3.14
        std::cout << doubleStack.pop() << std::endl;  // Сгенерирует исключение, так как стек пустой
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    A<std::string, std::vector<std::string>> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");

    try {
        std::cout << stringStack.pop() << std::endl;  // Выведет "World"
        std::cout << stringStack.pop() << std::endl;  // Выведет "Hello"
        std::cout << stringStack.pop() << std::endl;  // Сгенерирует исключение, так как стек пустой
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
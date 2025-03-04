#include <iostream>
using namespace std;

class Animal {
public:
    // Virtual function in the base class
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    // Overriding the base class method
    void sound() override { // 'override' keyword is optional, but good for clarity
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    // Overriding the base class method
    void sound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* animalPtr;  // Base class pointer

    Dog dog;
    Cat cat;

    dog.sound();
    cat.sound();

    // Pointing to Dog object
    animalPtr = &dog;
    animalPtr->sound();  // Calls Dog's overridden method

    // Pointing to Cat object
    animalPtr = &cat;
    animalPtr->sound();  // Calls Cat's overridden method

    return 0;
}

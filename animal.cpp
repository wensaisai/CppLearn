#include <iostream>

using namespace std;

class Printable {
public:
    virtual void print() = 0; // 声明虚函数，但没有定义，这意味着这个函数是纯虚函数，不能实例化对象，只能作为基类被继承
};

class Animal : public Printable {
public:
    // 不同于Java(使用 @Override 注解，所有非私有方法默认都是虚拟的) C++ 要用virtual关键字来声明虚函数，来实现多态特性
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
    virtual void print() {
        cout << "Animal is printing" << endl;
    }

};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog speaks" << endl;
    }
    void print() override {
        cout << "Dog is printing" << endl;
    }
};


int main() {
    Animal *a = new Animal();
    Animal *d = new Dog();

    a->speak();
    a->print();

    d->speak();
    d->print();


    delete a;
    delete d;

    return 0;
}
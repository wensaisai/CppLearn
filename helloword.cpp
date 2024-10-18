#include "Log.h"
#include<string>
#include<cstring>
#include<memory>
using namespace std;

// void Log(const char* message);

int s_variable = 8; 

void stringTest(){
    string str1 = "Hello world";
    string str2 = "Hello C++";
    string str3 = str1 + " " + str2;
    cout << str3 << endl;
    str1.append(" Appended string");
    cout << str1 << endl;
}

void pointerTest(){
    int a = 10;
    // type *var-name; // declares a pointer to type
    int *ptr1; 
    int* ptr2; // 这两种写法是等价的 推荐 int* ptr2;
    // 简单点理解：&：取址。* ：取值。
    ptr2 = &a; 
    cout << "Address of a: " << ptr2 << endl;
    cout << "Value of a: " << *ptr2 << endl;
    // 指针是一个整数，它指向一个内存地址 memory address，这个地址存放着一个值。

    char* buffer = new char[8]; // dynamic memory allocation
    // 分配8个字节的内存空间，初始值全部为0
    memset(buffer,1,8);
    char** ptr3 = &buffer; // 指针的指针
    cout << "Address of buffer: " << ptr3 << endl;
    cout << "Value of buffer: " << *ptr3 << endl;
    delete[] buffer; // 释放内存空间

    const int MAX_SIZE = 10;

    // const int* 等价于 int const* ，表示指向常量int的指针，不可以修改指针指向的对象的值，只能读取。 但是可以更改指针本身的值 即指针代笔的地址
    const int* ptr4 = new int;
    // *ptr4 = 10; // 指针指向的值不能修改
    cout << "Value of ptr4: " << *ptr4 << endl;
    ptr4 = &MAX_SIZE;
    cout << "Value of ptr4: " << *ptr4 << endl;

    // ptr5 是一个指向int的常量指针，不能修改指针本身的值，即地址不能修改，但是可以修改指针指向的对象的值
    int* const ptr5 = new int;
    *ptr5 = 10;
    cout << "Value of ptr5: " << *ptr5 << endl;
    // ptr5 = &a; // error: assignment of read-only variable ‘ptr5’

}

void referenceTest(){
    // 引用和指针类似，但是引用不能被修改，只能读取。区别三点如下：
    // 不存在空引用。引用必须连接到一块合法的内存。
    // 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
    // 引用必须在创建时被初始化。指针可以在任何时间被初始化。
    int a = 10;
    int& ref1 = a; // declares a reference to int
    int& ref2 = ref1; // declares another reference to int
}

// Conditions and Branches 条件和分支
void conditionalTest(){ 
    const char* ptr1 = "Hello";
    // nullptr 关键字表示空指针
    const char* ptr2 = nullptr;
    // c++ 中 if 语句判断0、NULL、nullptr都表示false 其他值都表示true 所以 if(ptr1) 等价于 if(ptr1!= nullptr)
    if(ptr1!= nullptr){
        cout << "ptr1 is not null " << ptr1 << endl;
    }
    if(ptr2 == nullptr){
        cout << "ptr2 is null" << endl;
    }

}

class Player{
    public:
        int speed;
        int health;
        string name;
        // 构造函数 不同于Java，C++不会初始化零值成员变量，而是分配内存中剩余的值，所以需要手动初始化
        Player(){
            speed = 0;
            health = 0;
            name = "";
        };
        Player(string name, int speed, int health){
            this->name = name;
            this->speed = speed;
            this->health = health;
        };
        // 析构函数 类似于Java的finalize()方法，在对象被删除时调用
        ~Player(){
            cout << "Player " << name << " is destroyed" << endl;
        };
        void printInfo(){
            cout << "Player name: " << name << endl;
            cout << "Player speed: " << speed << endl;
            cout << "Player health: " << health << endl;
        };
};
// struct 和 class区别 默认成员是public 和 private struct是为了兼容c语言，可以用来存储简单数据封装
struct vec2{
    float x,y;
    int z;
    vec2(float x, float y)
            : x(x), y(y)
    {

    }
    vec2(int z){
        // vec2* p = this; 
        this->z = z;
    }
    // const 跟在成员函数后面表示该函数不能修改成员变量
    vec2 add(const vec2& other) const{
       return vec2(x + other.x, y + other.y);
    };
    // 重载运算符
    vec2 operator+(const vec2& other) const{
       return add(other);
    };

    vec2 mulitiply(const vec2& other) const{
        return vec2(x * other.x, y * other.y);
    }

    vec2 operator*(const vec2& other) const{
        return mulitiply(other);
    }
    // 重载运算符== 和!= (在Java中要重写equals()方法)
    bool operator==(const vec2& other) const{    
        return x == other.x && y == other.y;    
    }
    bool operator!=(const vec2& other) const{        
        return !(*this == other);    
    }
    // 重载输出流运算符
    friend std::ostream& operator<<(std::ostream& os, const vec2& v){
        os << "(" << v.x << "," << v.y << ")";
        return os;
}
    
};



void testVec2(){
    vec2 speed(0.5f,1.5f);
    vec2 powerup(2.0f,3.0f);
    vec2 position(1,2);

    vec2 result1 = position.add(speed.mulitiply(powerup));
    cout << "Result: " << result1.x << " " << result1.y << endl;
    // 调用我们自己重载的运算符
    vec2 result2 = position + (speed * powerup);
    cout << result2 << endl;

}

class EnityLifeTime{
    public:
        EnityLifeTime(){
            cout << "EnityLifeTime constructor" << endl;
        }
        ~EnityLifeTime(){
            cout << "EnityLifeTime destructor" << endl;
        }
        void printInfo() const{
            cout << "EnityLifeTime info" << endl;
        }

};
// 写个类似 smart pointer delete释放内存在对象被销毁时自动释放
class ScopePtr{
    private:
        EnityLifeTime* m_Ptr;
    public:
        ScopePtr(EnityLifeTime* ptr){
            this->m_Ptr = ptr;
        }
        ~ScopePtr(){
            delete m_Ptr;
        }
        // 重载箭头运算符，返回指针指向的对象
        EnityLifeTime*  operator->(){
            return m_Ptr;
        }
        const EnityLifeTime*  operator->() const{
            return m_Ptr;
        }
};

void testEnityLifeTime(){
    EnityLifeTime* e1 = new EnityLifeTime();
    ScopePtr ptr = new EnityLifeTime();
    ptr->printInfo();
    cout << "testEnityLifeTimeOver" << endl;
}

void testSmartPointer(){
    // 标准库中的智能指针 unique_ptr 独占所有权的智能指针，同一时间只能有一个 unique_ptr 指向特定内存。
    // shared_ptr 共享所有权的智能指针，可以有多个 shared_ptr 指向同一内存，当引用计数为0时，自动释放内存。
    // weak_ptr 指向 shared_ptr 的弱引用，可以用来避免循环引用。 它不会增加引用计数，也不能直接访问 shared_ptr 指向的对象。
    // 推荐使用 make_unique() 函数创建 unique_ptr，可以自动抛出异常，避免悬空指针。

    std::shared_ptr<EnityLifeTime> e0;
    std::weak_ptr<EnityLifeTime> e1;
    {
        // std::unique_ptr<EnityLifeTime> enity = std::make_unique<EnityLifeTime>(); // 推荐使用这种方式创建智能指针，可以自动释放内存在对象被销毁时自动释放
        // std::unique_ptr<EnityLifeTime> enity(new EnityLifeTime()); // 也可以这样创建，但是这种方式在构造函数抛出异常时，会得到一个没有引用的悬空指针，所以不推荐
        // enity->printInfo();
        
        cout << "testSharedPointer begin" << endl;
        std::shared_ptr<EnityLifeTime> sharedEnity = std::make_shared<EnityLifeTime>();
        // e0 = sharedEnity; // 赋值给e0，验证shared_ptr
        e1 = sharedEnity; // 赋值给e1，避免循环引用
        
    }
    cout << "testSharedPointer end" << endl;   
}
    

// 模版 类比Java泛型    
template<typename T>
void swap(T& a, T& b){
    T temp = a; // copy a to temp    
    a = b; // copy b to a    
    b = temp; // copy temp to b
}

template<class T>
class Stack{
    private:
        T* arr;
        int top;
        int capacity;
    public:
        Stack(int capacity){
            this->capacity = capacity;
            arr = new T[capacity];
            top = -1;
        };
        ~Stack(){
            delete[] arr;
        };
        bool isEmpty(){
            return top == -1;
        };
        bool isFull(){
            return top == capacity - 1;
        };
        void push(T data){
            if(isFull()){
                cout << "Stack is full" << endl;
                return;
            }
            arr[++top] = data;
        };
        T pop(){
            if(isEmpty()){
                cout << "Stack is empty" << endl;
                return T();
            }
            return arr[top--];
        };
};

// copy constructor
class String{
    private:
        char* m_string;
        unsigned int m_size;
    public:
        String(const char* str){
            m_size = strlen(str);
            m_string = new char[m_size + 1]; // 留出一个位置给结尾字符
            // strcpy(m_string, str); // strcpy会在末尾添加一个空字符 \0 专门复制字符串
            memcpy(m_string, str, m_size); // 复制内存快 按字节复制 不会处理字符串结尾的空字符
            m_string[m_size] = '\0'; // 手动添加结尾字符
        }
        ~String(){
            delete[] m_string;
        }
        // 复制构造函数 复制一个String对象时，会调用这个构造函数
        String(const String& other){
            m_size = other.m_size;
            m_string = new char[m_size];
            strcpy(m_string, other.m_string);
            std::cout << "Copy constructor called" << std::endl;
        }
        // 重载运算符
        friend std::ostream& operator<<(std::ostream& os, const String& s){
            std::cout << s.m_string;
            return os;
        }
        // 重载下标运算符
        char& operator[](int index){
            return m_string[index];
        }

        void print(){    
            std::cout << this->m_string << std::endl;
        }       
};

// 通过引用传递参数 避免拷贝构造函数的调用
void printString(const String& s){
    cout << s << endl;
}

void testCopyConstructor(){
    String s1("Johnny");
    String s2 = s1;
    s2[1] = 'a';
    // s1.print();
    // s2.print();
    printString(s1);
    printString(s2);
}



int main(){
    // std::cout << "Hello world" << std::endl;
    // Log("Hello world");
    // twoDArray();
    // stringTest();
    // pointerTest();
    // conditionalTest();
    // testVec2();
    testEnityLifeTime();
    // testSmartPointer();
    // testCopyConstructor();
    cout << "Hello world" << endl;
}


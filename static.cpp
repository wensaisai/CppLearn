#include <iostream>
using namespace std;

// 静态变量 类似于全局变量，但只在当前文件中有效，不同于全局变量，静态变量在程序运行期间只初始化一次，
// 在vs中多个不同cpp文件中声明的全局变量，在链接时会合并到一个.obj文件中，而静态变量则会单独生成一个.obj文件。
static int x = 0;

// 对于类/结构体 中的静态成员在类中所有对象是共享的，类比Java，类名.静态成员名，来访问静态成员。
// 静态方法可以访问静态成员，但不能访问非静态成员。
// 因为静态方法属于类本身，而不是类的任何特定实例，因此，它们没有隐式的 this 引用（在Java中）或 this 指针（在C++中），这意味着它们无法直接访问实例的数据。
struct Entity{
    static int x, y;
    static void print(){
        cout << "x: " << x << " y: " << y << endl;
    }
};

int Entity::x = 0;
int Entity::y = 0;

class Example{
    public:
        Example(){
            cout << "create Example()" << endl;
        }
        Example(int x){
            cout << "create Example with "<< x << endl;
        }
};

// Constructor Initializer List 不仅仅是一种code style 对性能影响很小，而且可以避免构造函数中代码过多，
// 同时避免了多次的无用对象拷贝，提高了效率。
class MyEntity{
    private:
        string m_Name;
        int m_Age;
        Example m_Example;
    public:
        MyEntity()
            : m_Name("MyEntity"), m_Age(0), m_Example(8)
        {
            // m_Example = Example(10); // 在这里初始化 那么Example的构造函数会调用两次，一次无参，一次有参 在c++， Example m_Example; 已经创建了对象
        }
        // explicit 关键字用于防止隐式类型转换 
        explicit MyEntity(const string& name)
            : m_Name(name)
        {
            
        }
        void getName(){
            cout << "Name: " << m_Name << endl;
        }
};

int main(){
    // new 新建会分配在堆上 要手动释放
   MyEntity* e1 = new MyEntity();
   // 这两种写法都可以调用成员函数 getName
   e1->getName(); 
   (*e1).getName();
   delete e1;
   MyEntity e2(string("MyEntity2"));
   e2.getName();
   // 这种写法需要有对应的构造函数 且没有explicit修饰
   // MyEntity e3 = string("MyEntity3");
   // implicit conversion from string to const char* 隐式类型转换
   string s = "Hello World";
}
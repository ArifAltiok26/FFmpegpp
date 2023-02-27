#include "ffmpegpp.h"
// In this example, we will see how to create a custom object class.
// The main idea behind it, You create any structure, you can use default allocator or custom allocator.
// Also, you can use policy, if you want to do any operation on your custom object.
// Otherwise put "void" instead of policy template.

// Assume that our custom object is named Foo.
// As you can see, it has a constructor and two properties.

struct Foo
{
    Foo(int x, int y) : x(x), y(y)
    {
    }

    int x;
    int y;
};

// Lets define a new custom object class.
// We used ygv::Object class with the default template parameters.
// Allocator template is selected as Default<T> and Policy template is selected as void.
// More about allocator and policy, please look at that object.h file.

using FooObject = ygv::Object<Foo>;

#include <iostream>

// Also assume that there are a few function which works on the Foo structure.
void print(Foo *foo)
{
    // dummy get operation.
    std::cout << "x: " << foo->x << std::endl;
    std::cout << "y: " << foo->y << std::endl;
}

void set(Foo *foo)
{
    // dummy set operation
    foo->x = foo->x * 2;
    foo->y = foo->y + 2;
}

int main(int argc, char const *argv[])
{
    // As you can see, Foo will create with its constructor.
    FooObject foo(1, 3);

    // You can use instance of the FooObject class instead of instance of the Foo structure.
    // That's all. It is easy to create and use.
    print(foo);
    set(foo);
    print(foo);

    return 0;
}

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cassert>

#include <msgpack.hpp>

struct my_base1 {
    int a;
    MSGPACK_DEFINE(a);
};
inline bool operator==(my_base1 const& lhs, my_base1 const& rhs) {
    return lhs.a == rhs.a;
}

struct my_class {
    int a;
    MSGPACK_DEFINE(a);
};
inline bool operator==(my_class const& lhs, my_class const& rhs) {
    return lhs.a == rhs.a;
}

int main()
{
	{
        my_class my;
        my.a = 123;
        msgpack::zone z;
        msgpack::object obj(my, z);
        std::cout << obj << std::endl;
        assert(obj.as<my_class>() == my);
    }
	return 0;
}
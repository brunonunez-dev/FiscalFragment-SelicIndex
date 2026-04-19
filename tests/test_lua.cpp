#include <iostream>
#include <sol/sol.hpp>

int main()
{
    sol::state lua;
    lua.open_libraries(sol::lib::base);

    lua.script("print('Lua Integrity Test OK!')");
    lua.script("function sum(a, b) return a + b end");
    int result = lua["sum"](10, 50);

    std::cout << "Sum result: " << result << std::endl;
    return 0;
}
#include <iostream>
#include <memory>

#include "ModernJSON.hpp"

using namespace std;

int main(int argc, char **argv) {
    JSONValue arr = json_array();
    JSONValue a = json_number(10);
    JSONValue b = json_number(3);
    arr = arr + a;
    arr = arr + b;
    JSONValue arr2 = json_array();
    arr2 = arr2 + b;
    arr2 = arr2 + a;
    arr2 = arr2 + arr;
    cout << arr2->to_string() << endl;
    return 0;
}
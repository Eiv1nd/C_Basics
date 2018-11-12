#include <iostream>

// By default any variable is copied when passed to a function

// Copy - does not change num
void increment(int i)
{
    i++;
}

// Reference - changes num
// Bind once
// Type safe (can still be cast)
// Increment/decrement not supported
void incrementr(int& i)
{
    i++;
}

// Pointer - changes num
// Can be reassigned
// Can be cast to any type, including nullptr
void incrementp(int* i)
{
    *i++;
}


int main()
{
    int num = 0;
    increment(num);
    increment(num);
    increment(&num);

    return 0;
}
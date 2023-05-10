#include <iostream>
#include "Map.h"

int main()

{

    Map<int, const char*> m;

    m[10] = "C++";

    m[20] = "test";

    m[30] = "Poo";

    for (auto [key, value, index] : m)

    {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    //Count 

    int nr = m.Count();

    printf("\nCount:%d\n", nr);

    // Set

    m.Set(50, "Test");

    // Get

    const char* test;

    m.Get(10, test);

    printf("Value=%s\n", test);


    // Delete 

    m.Delete(20);

    // Includes 

    Map<int, const char*> b;

    b[10] = "C++";

    b[20] = "test";

    b[30] = "Poo";

    b.Set(50, "Ana");

    m.Includes(b);

    printf("\n");
    for (auto [key, value, index] : m)

    {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    }

    return 0;

}
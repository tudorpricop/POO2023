#include "NumberList.h"
#include <iostream>

using namespace std;

int main() {
    NumberList mylist;

    mylist.Init();

    mylist.Add(4);
    mylist.Add(9);
    mylist.Add(11);
    mylist.Add(1);
    mylist.Add(10);
    mylist.Add(16);
    mylist.Add(12);
    mylist.Add(17);
    mylist.Add(19);
    mylist.Add(6);
    mylist.Add(7);
    mylist.Add(8);

    mylist.Print();

    mylist.Sort();

    mylist.Print();

    return 0;
}

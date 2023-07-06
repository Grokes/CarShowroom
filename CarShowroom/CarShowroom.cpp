#include <iostream>
#include <list>
#include <vector>
#include <Windows.h>
#include "Showroom.h"


using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Database base;
    base.add("������1",215);
    base.add("������2", 100);
    base.add("������3",112);
    base.show();
    auto del = base.find("price", "100");
    cout << *del;
    base.del(del);

    cout << "\n\n\n";
    base.sort("price");
    base.show();



    return 0;
}
//
// Created by 吴迪 on 2021/5/31.
//

#include <iostream>

using namespace std;

void reference(int&);

int main()
{
    int r = 20;
    reference(r);

    cout << "type: " << r << endl;

    return 0;
}

void reference(int& type)
{
    cout << "type: " << type << endl;
    type = 10;
}
//
//  main.cpp
//  线性表
//
//  Created by 吴蔚然 on 2019/10/19.
//  Copyright © 2019 吴蔚然. All rights reserved.
//

#include "linkList.h"
using namespace std;

int main(int argc, const char *argv[])
{
    linkList<int> list_A;
    int m, s, n;
    cout << "input m, s, n in order:\n";
    cin >> m >> s >> n;
    list_A.create(m);
    //list_A.traverse();
    list_A.operate(s, n);
    return 0;
}

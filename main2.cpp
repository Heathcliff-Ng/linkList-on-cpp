//
//  main.cpp
//  test2
//
//  Created by 吴蔚然 on 2019/10/21.
//  Copyright © 2019 吴蔚然. All rights reserved.
//

#include "linkList.h"

int main(int argc, const char * argv[]) {
    linkList<int> lista, listb, listc;
    lista.tailCreate();
    listb.tailCreate();
    
    lista.Union(&listb);
    listc.Union(&lista);
    
    listc.traverse();
    
    lista.clear();
    listb.clear();
    
    listc.clean();
    listc.traverse();
    
    return 0;
}

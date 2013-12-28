//
//  main.cpp
//  
//
//  Created by Ashwin R S on 12/24/13.
//
//

#include "main.h"
#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
using namespace std;

int main(){
    LinkedList* l;
    l = new LinkedList();
    l->addFront(3);
    l->addFront(4);
    
    cout<<"hello world "<<l->front()<<"\n";
    
    return 0;
    
}

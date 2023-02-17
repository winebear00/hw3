#include "heap.h"
#include <iostream>
using namespace std; 

int main () {
    Heap <int> heap; 
    heap.push(9);
    cout<<heap.top()<<endl;
    heap.push(9);
    cout<<heap.top()<<endl;
    heap.push(20);
    

    cout<<"pop 1"<<endl;
    heap.pop();
    cout<<heap.top()<<endl;

    cout<<"pop 2"<<endl;
    heap.pop();
    cout<<heap.top()<<endl; 
}
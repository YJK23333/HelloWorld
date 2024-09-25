#include <iostream>
#include "Tree.h"
using namespace std;
int main()
{
    vector<int> vec;
    int a[6] = {5, 4, 6, 9, 3, 10};
    for(int i = 0; i < 6; i++)
        vec.push_back(a[i]);
    BST bst(vec);
    
    bst.OrderPrint();

    return 0;
}
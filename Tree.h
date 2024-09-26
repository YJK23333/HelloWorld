#ifndef TREE_H
#define TREE_H

#include<vector>
#include<iostream>
using std::vector;

template<class T>
class AVLNode
{
public:
    AVLNode(T val)
    {
        _parent = _left = _right = nullptr;
        _depth = 0;
        _val = val;
    }

private:
    int _depth;
    T _val;
    AVLNode* _parent;
    AVLNode* _left, _right;

};




#endif
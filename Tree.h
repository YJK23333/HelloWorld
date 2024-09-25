#ifndef TREE_H
#define TREE_H

#include<vector>
using std::vector;

template<class T>
class Node
{
public:
    Node(T val) : _val(val), _left(nullptr), _right(nullptr) {}
    ~Node() = default;

private:
    T _val;
    Node* _left;
    Node* _right;

};

template<class T>
class BST
{
    typedef Node<T> node;
public:
    BST() : _root(nullptr);
    ~BST() = default;

    BST(BST<T>& bst)
    {
        root = bst._root;
    }

    BST<T>& operator=(BST<T> bst)
    {
        std::swap(bst._root, _root);
        return *this;
    }

    BST(const vector<T>& vec)
    {
        for(int i = 0; i < vec.size(); i++)
            InsertR(_root, vec[i]);
    }

public:
    bool Find(const T& val);

    bool Insert(const T& val);

    bool Erase(const T& val);

    bool FindR(const T& val) { return _findR(_root, val);}
    bool _findR(node* root, const T& val);
    bool InsertR(const T& val) { return _insertR(_root, val);}
    bool _insertR(node* &root, const T& val);
    bool EraseR(const T& val) { return _eraseR(_root, val);}
    bool _eraseR(node* &root, const T& val);
    void OrderPrint();

private:
    node* _root;


};

template<class T>
class AVLNode
{
public:
    AVLNode(T val)
    {
        _parent = _left = _right = nullptr;
        depth = 0;
        _val = val;
    }

private:
    int _depth;
    T _val;
    AVLNode* _parent;
    AVLNode* _left, _right;

};



#endif;
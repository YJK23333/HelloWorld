#ifndef TREES_H
#define TREES_H

#include<vector>
using std::vector;

template<class T>
class Treenode
{
public:
    Treenode(T x) : val(x), left(nullptr), right(nullptr) {}

    ~Treenode() = default;

private:
    T val;
    Treenode* left;
    Treenode* right;
};


template<class T>
class BST
{
public:
    BST() {};

    void Insert(Treenode** root, T val)
    {
        if(*root == nullptr)
            *root = new Treenode(val);
        else
        {
            if(val < (*root)->val)
                Insert(&(*root)->left, val);
            else
                Insert(&(*root)->right, val);
        }
    }

    void Create(vector<T>& vec)
    {
        for(int i = 0 ; i < vec.size(); i++)
            Insert(root, vec[i]);
    }

    bool Search(Treenode* root, T val)
    {
        if(root == nullptr)
            return false;
        if(val < root->val)
            return Search(root->left, val);
        else if(val > root->val)
            return Search(root->right, val);
        else
            return true;
    }

    void DelNode(Treenode* node)
    {
        Treenode* temp = node;
        if(node->right == nullptr)
        {
            node = node->left;
            delete temp;
        }
        else
        {
            while(temp->left != nullptr)
                temp = temp->left;
            node->val = temp->val;
            delete temp;
        }
    }

    void DelSearchNode(Treenode** root, T val)
    {
        if((*root) == nullptr)
            return;
        if(val < (*root)->val)
            return DelNode(root->left, val);
        else if(val > (*root)->val)
            return DelNode((*root)->right, val);
        else
            DelNode(root);
    }

    int maxDepth(Treenode x)
    {
        if(x == nullptr)
            return 0;

        int max = 0;
        int maxL = 0;
        int maxR = 0;

        if(x->left != nullptr)
            maxL = maxDepth(x->left);
        
        if(x->right != nullptr)
            maxR = maxDepth(x->right);
        
        max = maxL > maxR ? maxL + 1 : maxR + 1;
        return max;        
    }

private:
    Treenode* root;

};




template<class T>
class AVLNode
{
public:
    AVLNode(T _val)
    {
        parent = nullptr;
        depth = 0;
        left = right = nullptr;
        this->val = _val;
    } 

private:
    int depth;
    T val;
    AVLNode* parent;
    AVLNode* left;
    AVLNode* right;

};

template<class T>
AVLNode<T> leftrotate(AVLNode<T> y)
{
    AVLNode<T> x = *y.left;
    AVLNode<T> t = *x.right;
    x.right = &y;
    y.left = &t;
}




template<class T>
class AVL
{
public:

private:

};




#endif
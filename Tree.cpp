#include"Tree.h"


template<class T>
void BST<T>::OrderPrint()
{
    if(_root == nullptr)
        return;
    OrderPrint(_root->_left);
    cout << _root->val << " ";
    OrderPrint(_root->_right);
}

template<class T>   // Find
bool BST<T>::Find(const T& val)
{
    node* cur = _root;
    while(cur != nullptr)
    {
        if(cur->_val > val)
            cur = cur->_left;
        else if(cur->_val < val)
            cur = cur->_right;
        else
            return true;
    }
    return false;
}

template<class T>   // Insert
bool BST<T>::Insert(const T& val)
{
    if(_root == nullptr)
    {
        _root = new node(val);
        return true;
    }
    node* cur = _root;
    node* parent = nullptr;

    while(cur != nullptr)
    {
        if(cur->_val > val)
        {
            parent = cur;
            cur = cur->_left;
        }
        else if(cur->_val < val)
        {
            parent = cur;
            cur = cur->_right;
        }
        else
            return false;
    }

    cur = new node(val);
    if(parent->_val > val)
        parent->_right = cur;
    else
        parent->_left = cur;
    return true;
}

template<class T>   // Erase
bool BST<T>::Erase(const T& val)
{
    node* cur = root;
    node* parent = nullptr;
    while(cur != nullptr)
    {
        if(cur->val > _val)     // _val < current node value
        {
            parent = cur;
            cur = cur->left;
        }
        else if(cur->val < _val)    // _val > current node value
        {
            parent = cur;
            cur = cur->right;
        }
        else    // Found the value
        {
            if(cur->left == nullptr)        // node's left is null
            {
                if(cur == root)
                    root = cur->right;
                else
                {
                    if(parent->left == cur)
                        parent->left = cur->right;
                    else
                        parent->right = cur->right;
                }
                delete cur;
            }
            else if(cur->right == nullptr)  // node's right is null
            {
                if(cur == root)
                    root = cur->left;
                else
                {
                    if(parent->left == cur)
                        parent->left = cur->left;
                    else
                        parent->right = cur->left;
                }
                delete cur;
            }
            else        // node have two childs.
            {
                node* pminright = cur;
                node* minright = cur->right;
                while(minright->left)
                {
                    pminright = minright;
                    minright = minright->left;
                }
                cur->val = minright->val;
                if(pminright->left == minright)
                    pminright->left = minright->right;
                else
                    pminright->right = minright->right;
                delete minright;
            }
            return true;
        }
    }
    return false;
}

template<class T>
bool BST<T>::_findR(node* root, const T& val)
{
    if(root == nullptr)
        return false;
    if(val < root->_val)
        _findR(root->_left, val);
    else if(val > root->_val)
        _findR(root->_right, val);
    else
        return true;
}

template<class T>
bool BST<T>::_insertR(node* &root, const T& val)
{
    if(root == nullptr)
    {
        root = new node(val);
        return true;
    }
    if(val < root->_val)
        _insertR(root->_left, val);
    else if(val > root->_val)
        _insertR(root->_right, val);
    else
        return false;
}

template<class T>
bool BST<T>::_eraseR(node* &root, const T& val)
{
    if(root == nullptr)
        return false;
    if(val < root->_val)
        _eraseR(root->_left, val);
    else if(val > root->_val)
        _eraseR(root->_right, val);
    else
    {
        node* del = node;
        if(root->_left == nullptr)
            root = root->_right;
        else if(root->_right == nullptr)
            root = root->_left;
        else
        {
            node* maxleft = root->_left;
            while(maxleft != nullptr)
                maxleft = maxleft->_right;
            swap(maxleft, root);
            return _eraseR(root->_left, val);
        }
        delete del;
        return true;
    }
}



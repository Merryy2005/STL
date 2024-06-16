#include <iostream>

template<typename T>
class TreeNode 
{
    public:
        T value;
        TreeNode* left;       
        TreeNode* right;    
        TreeNode(T val) : value(val), left(nullptr), right(nullptr) {}
};

template<typename T>
void InorderTraversal(TreeNode<T>* Node)
{
    if(Node == nullptr)
    {
        return;
    }
    InorderTraversal(Node -> left);
    std::cout << Node -> value << " ";
    InorderTraversal(Node -> right);
}

int main()
{
    TreeNode<int>* root = new TreeNode<int>(1);
    root -> left = new TreeNode<int>(2);
    root -> right = new TreeNode<int>(3);
    root -> left -> left = new TreeNode<int>(4);
    root -> left -> right = new TreeNode<int>(5);
    InorderTraversal(root);
    delete root;
    delete root -> left;
    delete root -> right;
    delete root -> left -> left;
    delete root -> left -> right;
    return 0;
}
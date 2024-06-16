#include <iostream>
#include <queue>

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
void LayeByLayerTraversal(TreeNode<T>* Node)
{
    std::queue<TreeNode<T>*> q;
    if(Node != nullptr)
    {
        q.push(Node);
    }
    while(!q.empty())
    {
        TreeNode<T>* s = q.front();
        std::cout << s -> value << " ";
        q.pop();
        if(s -> left != nullptr)
        {
            q.push(s -> left);
        }
        if(s -> right != nullptr)
        {
            q.push(s -> right);
        }
    }
}

int main()
{
    TreeNode<int>* root = new TreeNode<int>(1);
    root -> left = new TreeNode<int>(2);
    root -> right = new TreeNode<int>(3);
    root -> left -> left = new TreeNode<int>(4);
    root -> left -> right = new TreeNode<int>(5);
    LayeByLayerTraversal(root);
    delete root;
    delete root -> left;
    delete root -> right;
    delete root -> left -> left;
    delete root -> left -> right;
    return 0;
}
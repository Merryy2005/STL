#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>

template <typename T>
class Node
{
  public:
    std::vector<Node*> children;
    T val;
    void push(Node<T>* node)
    {
      children.push_back(node);
    }
    Node(T val) : val(val)
    {
    }
};

class Tree
{
    Node<int>* root;
    public:
    void bfs()
    {
        std::queue<Node<int>*> q;
        q.push(root);
        while (!q.empty())
        {
            Node<int>* temp = q.front();
            std::cout << temp->val << std::endl;
            q.pop();
            for(Node<int>* in : temp->children)
            {
                q.push(in);
            }
        }
    }
    Node<int>* create_tree(int depth, int cur = 0) 
    {
        if (cur < depth) 
        {
            Node<int>* node = new Node<int>(rand() % 11);
            int num = rand() % 11;
            for (int i = 0; i < num; ++i) {
                Node<int>* child = create_tree(depth, cur + 1);
                if (child) 
                {
                    node->children.push_back(child);
                }
            }
            return node;
        } 
        else 
        {
            return nullptr;
        }
    }
    Tree(int depth)
    {
        root = create_tree(depth);
    }
    void delete_tree(Node<int>* node)
    {
        if (node)
        {
            for (Node<int>* node : node->children)
            {
                delete_tree(node);
            }
            delete node;
        }
    }
    ~Tree()
    {
        delete_tree(root);
    }
};
int main()
{
  srand(time(0));
  Tree my_tree(rand()%11);
  my_tree.bfs();
  return 0;
}
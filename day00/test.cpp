#include "test.h"
using namespace std;

t_tree::node::node(int v)
{
    this->value = v;
    this->right = nullptr;
    this->left = nullptr;
}


void    build_tree(t_tree **start, t_tree *current)
{
    if (*start == nullptr)
    {
        *start = current;
        return ;
    }
    if (current->value > (*start)->value)
    {
        if ((*start)->right == nullptr)
        {
            (*start)->right = current;
            return ;
        }
        build_tree(&(*start)->right, current);
    }
    if (current->value < (*start)->value)
    {
        if ((*start)->left == nullptr)
        {
            (*start)->left = current;
            return ;
        }
        build_tree(&(*start)->left, current);
    }
    
}

void t_init(int *table, int size, t_tree    **root)
{
    int i = -1;

    while (++i < size)
        build_tree(root, new node(table[i]));
}

void    free_tree(t_tree *root)
{
    if (root == nullptr)
        return ;
    free_tree(root->left);
    free_tree(root->right);
    cout << root->value << " is freed\n"; 
    delete root;
}

void    print_tree(t_tree   *root)
{
    if (root == nullptr)
        return ;
    print_tree(root->left);
    cout << root->value << '\n';
    print_tree(root->right);
}
int main()
{
    t_tree  *root = nullptr;
    t_init(new int[]{1,8,9,6,2,3,4,5,7},9, &root);
    print_tree(root);
    free_tree(root);
    system("leaks a.out");
}

#include<iostream>
using namespace std;

typedef struct node
{
    int value;
    struct node *right;
    struct node *left;
    node(int v);
}t_tree;

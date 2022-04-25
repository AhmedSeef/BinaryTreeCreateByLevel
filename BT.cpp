#include "iostream"
using namespace std;
#include <queue>

struct Node
{
    Node *left;
    int data;
    Node *right;
} * root;

void createtree()
{
    Node *p;
    int x;
    Node *t;
    root = new Node;
    cout << " Enter root data" << endl;
    cin >> x;
    root->data = x;
    root->left = root->right = NULL;

    p = root;

    queue<Node *> gquiz;
    gquiz.push(root);

    while (!gquiz.empty())
    {
        int x;
        Node *t;
        Node *it = gquiz.front();
        gquiz.pop();

        cout << "enter left data for " << it->data << endl;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = NULL;
            it->left = t;
            gquiz.push(t);
        }

        cout << "enter rigt data for " << it->data << endl;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = NULL;
            it->right = t;
            gquiz.push(t);
        }
    }
};

void recpreorder(struct Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        recpreorder(root->left);
        recpreorder(root->right);
    }
}

void recinorder(struct Node *root)
{
    if (root != NULL)
    {
        recinorder(root->left);
        cout << root->data << " ";
        recinorder(root->right);
    }
}

void recpostorder(struct Node *root)
{
    if (root != NULL)
    {
        recpostorder(root->left);
        recpostorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    createtree();
    recpreorder(root);
    cout << endl;
    recinorder(root);
    cout << endl;
    recpostorder(root);

    return 0;
}
#include<iostream>
using namespace std;
class Container
{
public:
    virtual void insert(int value) = 0;
    // Это потом заменим на перегруженный оператор <<
    // Виртуальный деструктор
    virtual bool exists(int value) = 0;
    virtual void print() = 0;

    virtual ~Container();

};
Container::~Container() { }

class SimpleTree : public Container
{
protected:
    int R;
    struct el* k;
    struct el* c;
struct el
{
    int value;
    struct el* left;
    struct el* right;
    struct el* parent;
};
struct el* root;
    int  ValueR ;
    struct el* LeftR;
    struct el* RightR;
    struct el* ParentR;

public:
SimpleTree()
{
    c = NULL;
    k = NULL;
    root = NULL;
    ValueR = 0;
    LeftR = NULL;
    RightR = NULL;
    ParentR = NULL;
    R = 0;
}
void insert(int value)
{
    R += 1;
    if (R == 1 )
    {
        root = create(value);
        ValueR = root->value;
        LeftR = root->left;
        RightR = root->right;
        ParentR = root->parent;
    }
    else
    {
    struct el* s = create(value);
    insert(root,s);
    }
}
void print()
{
    print_tree(root);
}
bool exists(int value)
{
    struct el* c = create(value);
    struct el* k = find(root,c);
    if (k != NULL);
}
struct el* create(int a)
{ struct el* s = new struct el;
  s -> value = a;
  s -> left = NULL;
  s -> right = NULL;
  s -> parent = NULL;
  return s;
};
void insert(struct el* root, struct el* s)
{
    if (root -> value >= s -> value )
    {
        if (root -> left == NULL)
        {
            root -> left = s ;
            s -> parent = root -> left;

        }
        else
        {
            insert ( root -> left, s);
        }
    }
    else
    {
        if (root -> right == NULL)
        {
            root -> right = s ;
            s -> parent = root -> right;
        }
        else
        {
            insert (root -> right, s);
        }

    }
}
void print_tree(struct el* root)
{
    cout << root -> value << endl;
    if ( root -> left != NULL )
    {
        print_tree(root -> left);
    }
    if ( root -> right != NULL )
    {
        print_tree( root -> right);
    }
}
struct el* find(struct el* root, struct el* c)
{
    if (root -> value == c -> value)
    {
        return root;
    }
    if (root -> value < c -> value)
    {
        if (root -> right != 0)
        {
            return find(root -> right, c);
        }
        else
        {
            return NULL;
        }

    }
     if (root -> value > c -> value)
    {
        if (root -> right != 0)
        {
            return find(root -> left, c);
        }
        else
        {
            return NULL;
        }
    }
    return NULL;
};

};
int main()
{
    Container* c = new SimpleTree();
    for(int i = 1; i < 10; i++)
    c->insert(i*i);
    cout << "List after creation: " << endl ;
    c->print();
    if(c->exists(25))
    cout << "Search for value 25: found" << endl;
    if(!c->exists(111))
    cout << "Search for value 111: not found" << endl;

    return 0;
}

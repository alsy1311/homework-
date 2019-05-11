#include<stdio.h>
#include<stdlib.h>
struct el
{
    int value;
    struct el* left;
    struct el* right;
    struct el* parent;
};
struct el* create(int a)
{ struct el* s = malloc(sizeof(struct el));
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
    printf("%d", root -> value);
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
void DELETE(struct el* k, struct el* t)
{
    if (k -> right != NULL)
    {
        k -> right -> parent = k -> parent;
        if (k -> parent -> right == k )
        {
            k -> parent -> right = k -> right;
        }
        else
        {
            k -> parent -> left = k -> right;
        }
        if (k -> left != NULL)
        {
            if (k -> right -> left == NULL)
                {
                    k -> left -> parent = k -> right ;
                    k -> right -> left = k -> left;
                }
            else
                {
                    k -> left -> parent = t ;
                    t -> left = k -> left;
                }
        }
    }
    else
    {
        k -> left -> parent = k -> parent;
        if (k -> parent -> right == k )
        {
            k -> parent -> right = k -> left;
        }
        else
        {
            k -> parent -> left = k -> left;
        }
    }
   free(k);
}
struct el* LAST_ELEMENT( struct el* p )
{
    if (p != NULL)
    {
        if (p -> left != NULL)
    {
        return LAST_ELEMENT(p -> left);
    }
    else
    {
        return( p );
    }

    }
    else
    {
        return (p -> parent);
    }
};
int main()
{
    int N;
    int i = 0;
    int player;
    int a;
    int m;
    scanf("%d", &N); //количество элементов кроме корня
    scanf("%d", &player);// корень
    struct el* root = create(player);
    for (i = 0; i < N  ; i ++ )
    {
     scanf("%d", &a);
     struct el* s = create(a);
     insert (root, s);
    }
    print_tree(root);
    scanf("%d", &m);// элемент. который надо найти
    struct el* c = create(m);
    struct el* k = find (root, c);
    if ( k == NULL )
    {
        printf("NOT Found\n");
    }
    else
    {
        printf("%d\n", k -> value);
    }
    struct el* t = LAST_ELEMENT(k -> right);
    printf("%d", t -> value);
    //DELETE(k, t);
    //print_tree(root);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
}tree;

tree* create(tree* head)
{
    int ans;

    do
    {
        tree *nw = (tree*)malloc(sizeof(tree));
        printf("Enter Data: ");
        scanf("%d", &nw->data);

        nw->left = nw->right = NULL;

        if (head == NULL)
        {
            head = nw;
        }
        else
        {
            tree *p = head;

            while (1)
            {
                if (nw->data < p->data)
                {
                    if (p->left == NULL)
                    {
                        p->left = nw;
                        break;
                    }
                    p = p->left;
                }
                else if (nw->data > p->data)
                {
                    if (p->right == NULL)
                    {
                        p->right = nw;
                        break;
                    }
                    p = p->right;
                }
                else
                {
                    printf("Duplicate value not allowed!\n");
                    free(nw);
                    break;
                }
            }
        }

        printf("Do you want to insert a new node (0/1): ");
        scanf("%d", &ans);

    } while (ans == 1);

    return head;
}


int count(tree* p)
{
    if(p!= NULL)
        return 0;
    
    return 1 + count(p->left)+ count(p->right);
}

int main()
{
    tree* head = NULL;

    create(head);

    printf(count(head));

}
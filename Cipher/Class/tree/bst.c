#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
    int data;
    struct bst  *left;
    struct bst *right;
}bst;

bst* create_node(int value)
{
    bst* nw = (bst*) malloc(sizeof(bst));
    nw->data = value;
    nw->left = nw->right = NULL;
    return nw;
}

bst* insert(bst* root , int value)
{
    if(root == NULL)
        return create_node(value);

    if(value < root->data)
        root->left = insert(root->left , value);
    
    else if(value > root->data)
        root->right = insert(root->right , value);
    
    return root;
}

void inorder(bst* root)
{
    if(root!= NULL)
    {
        inorder(root->left);
        printf("%d " , root->data);
        inorder(root->right);
    }
}

void preorder(bst* root)
{

    if(root!= NULL)
    {
        printf("%d " , root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(bst* root)
{
    if(root!= NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d " , root->data);
    }
}

int count(bst* p)
{
    if(p == NULL)
        return 0;
    return 1+count(p->left)+count(p->right);
}

int findMin(bst* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }

    return root->data;
}

int findMax(bst* root)
{
    while(root->right != NULL)
    {
        root = root->right;
    }

    return root->data;
}

int countEvenOdd(bst* root , int *even , int *odd)
{
    if(root == NULL)
        return 0;

    if(root->data %2 == 0 )
    {
        (*even)++;
    }
    else
    {
        (*odd)++;
    }

    countEvenOdd(root->left , even , odd);
    countEvenOdd(root->right , even , odd);

}


int search(bst* root , int key)
{
    if(root == NULL)
        return 0;

    if(root->data > key)
        return search(root->left , key);

    else if(root->data < key)
        return search(root->right , key);

    else if(root->data == key)
        return 1;
}


// count leaf nodes

int countLeafNode(bst* root)
{

    if (root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;
    
    return countLeafNode(root->left) + countLeafNode(root->right);
    
}

// height of bst

int height(bst *root)
{
    if(root == NULL)
        return -1;

    int lh = height(root->left);
    int rh = height(root->right);

    return (lh > rh ? lh : rh ) + 1;
}


//deleet node from bst 
// to do



bst* deleteNode()
{ 
    // Incomplete

}

int main()
{

    bst* root  = NULL;
    // bst* root = create_node(20);
    // root = insert(root , 17);
    // root = insert(root , 10);
    // root = insert(root , 5);
    // root = insert(root , 30);
    // root = insert(root , 25);
    // root = insert(root , 18);
    // root = insert(root , 12);
    // root = insert(root , 19);
    // root = insert(root , 38);
    // root = insert(root , 26);



    int choice , value;

    printf("\n======================Menu Driven=============================\n");

    printf("1. Insert\n");
    printf("2. Inorder\n");
    printf("3. Preorder\n");
    printf("4. Postorder\n");
    printf("5. Search\n");
    printf("6. Delete\n");
    printf("7. MinOrMax\n");
    printf("8. Count Node\n");
    printf("9. Count Nodes\n");
    printf("10. Height\n");
    printf("11. Exit\n");

    printf("Enter Choice: ");

    scanf("%d" , &choice);


    do{
        switch(choice)
        {
            case 1:
                printf("Enter Value: ");
                scanf("%d" , &value);
                root = insert(root , value);
                break;
            
            case 2:
                printf("Inorder : ");
                inorder(root);
                break;

            case 3:
                printf("Preorder : ");
                preorder(root);
                break;

            case 4:
                printf("Postorder: ");
                postorder(root);
                break;
                
            case 5:
                if(search(root , value))
                {
                    printf("Value Found");
                }
                else
                {
                    printf("Value Not Found");
                }
                break;

            case 6:
                printf("Enter value to delete");
                scanf("%d" , &value);
                deleteNode(value);
                break;

            case 7:
                printf("Min: %d " , findMin(root));
                printf("Max: %d " , findMax(root));
                break;

            case 8:
                printf("Node Count: %d" , count(root));
                break;

            case 9:
                printf("Leaf Nodes %d: " , countLeafNode(root));
                break;

            case 10:
                printf("Height: %d" , height(root));
                break;
            
            default:
                printf("Enter a valid choice \n");
                break;

        }
    }while(choice != 11);
}

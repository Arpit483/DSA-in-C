/*
Singly Linked List 
Steps:
    1. Create list + show list
    2. Insert Start
    3. Insert End
    4. Insert After + Insert Before
    5. Get Start / Get End + pop_start / pop_end /
    6. Remove_start / Remove_end / Remove_data + find + length
    7. Destroy_list (cleanup)
*/

/*Step 1 : Create_list + show_list*/

/*=======================================================*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

/*Create an empty list with a head (dummy) node */

struct node* create_list(void)
{
    struct node* head = malloc(sizeof(struct node));
    if(!head)
    {
        puts("Out Of Memory");
        exit(EXIT_FAILURE);
    }
    head->data = 0;
    head->next = NULL;
    return head;
}

void show_list(struct node* head , const char* msg)
{
    if(msg)
        puts(msg);
        
    printf("[Start]->");
    struct node* it = head->next;
        while(it)
        {
            printf("[%d]->" , it->data);
            it = it->next;
        }
        printf("[END]\n");

}

/*
STEP 2: insert_start 
*/

void insert_start(struct node* head , int data)
{
    struct node* n = malloc(sizeof(struct node));
    if(!n)
    {
        puts("Out Of Memory");
        exit(EXIT_FAILURE);
    }
    n->data = data;
    n->next = head->next;
    head->next = n;
}

/*
STEP 3: insert_end
*/
void insert_end(struct node *head , int data)
{
    struct node *n = malloc(sizeof(struct node));
    if(!n)
    {
        puts("Out of memory");
        exit(EXIT_FAILURE);
    }
    n->data = data;
    n->next = NULL;
    struct node *it = head;
    while(it->next)
        it = it->next;
    it->next = n;
}


// Insert After + Before

int insert_after(struct node* head , int after , int data)
{
    struct node* it = head->next;
    while(it){
        if(it->data == after){
            struct node *n = malloc(sizeof(struct node));
            if(!n){
                exit(1);
            } 
            n->data = data;
            n->next = it->next;
            it->next = n;
            return 1;
        }
        it = it->next;
    }
    return 0;
}

int insert_before(struct node*head,int before ,  int data){
    struct node *it = head;
    while(it->next){
        if(it->next->data == before){
            struct node *n = malloc(sizeof(struct node));
            if(!n){
                exit(1);
            }
            n->data = data ;
            n->next = it->next;
            it->next = n;
            return 1;
        }
        it=it->next;
    }
    return 1;
}

/*
Step 5:
Get start / Get End  + pop start /pop end
*/
int get_start(struct node* head , int *out){
    if(!head ->next){
        return 0;
    }
    *out = head->next->data;
    return 1;
}


int get_end (struct node *head , int *out){
    if(!head->next){
        return 0;
    }
    struct node *it = head->next;
    while(it->next){
        it = it->next;
    }
    *out = it->data;
    return 1;
}

int pop_start(struct node *head, int *out){
    if(!head->next){
        return 0;
    }
    struct node* t = head->next;
    *out = t->data;
    head->next = t->next;
    free(t);
    return 1;
}

int pop_end(struct node* head , int *out){
    if(!head->next){
        return 0;
    }
    struct node *it = head;
    while(it->next && it->next->next){
        it = it->next;
    }
    struct node* t = it->next;
    *out = t->data;
    it->next = NULL;
    free(t);
    return 1;
}

// Remove start / remove end / remove data

int remove_start(struct node *head){
    if(!head->next){
        return 0;
    }
    struct node* t = head->next;
    head->next = t->next;
    free(t);
    return 1;
}

int remove_end(struct node *head){
    if(!head->next){
        return 0;
    }
    struct node *it = head;
    while(it->next && it->next->next){
        it = it->next;
    }
    struct node* t = it->next;
    it->next = NULL;
    free(t);
    return 1;

}

int remove_data(struct node* head , int data){
    struct node *it = head;
    while(it->next){
        if(it->next->data == data){
            struct node* t = it->next;
            it->next = t->next;
            free(t);
        }else{
        it = it->next;
        }
    }
}

// Find + length;

int find(struct node *head , int data){
    struct node *it = head->next;
    while(it){
        if(it->data == data){
            return 1;
        }
        it = it->next;
    }
    return 0;
}

int length (struct node *head){
    int count = 0;
    struct node* it = head->next;
    while(it){
        count++;
        it = it->next;
    }
    return count;
}


// Destroy list

void destroy_list(struct node* head){
    struct node *it = head;
    while(it){
        struct node*t = it;
        it=it->next;
        free(t);
    }
}



int main(void)
{
    struct node* list = create_list();

    puts("Steps 1. Create List and Show List");
    show_list(list, "\nList right after creation : ");

    insert_start(list , 10);
    insert_start(list ,20);
    insert_start(list , 30);

    show_list(list , "\nAfter insert_start Operation : ");

    insert_end(list , 5);
    insert_end(list , 15);
    insert_end(list , 25);
    show_list(list , "\nAfter insert_end operation : ");

    insert_after(list,10,15);
    insert_before(list ,5,1);
    show_list(list , "\n After Insertion: ");

    int x = get_start(list, &x);
    printf("\nFirst Element = %d \n" ,x);

    get_end(list, &x);
    printf("Last Element = %d \n" , x);

    pop_start(list , &x);
    printf("\n Popped from start %d. \n" , x);

    show_list(list , "After Popping");

    remove_start(list);
    remove_end(list);
    remove_data(list , 10);
    show_list(list , "After removal");

    printf("\n Find 15? : %s " , find(list,15)?"YES":"NO");

    printf("Length = %d", length(list));

    destroy_list(list);

    /*Cleanup*/

    struct node* it = list;
    while(it)
    {
        struct node *t = it;
        it = it->next;
        free(t);
    }
    return 0;
}


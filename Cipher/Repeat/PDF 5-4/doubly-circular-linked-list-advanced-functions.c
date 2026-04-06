#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef enum status
{
    SUCCESS = 1,
    TRUE = 1,
    FALSE = 0,
    LIST_DATA_NOT_FOUND = 2,
    LIST_EMPTY = 3
}status_t;

typedef int data_t;
typedef struct node node_t;
typedef node_t list_t;

struct node
{
    data_t data;
    struct node* prev;
    struct node* next;
};

list_t* create_list(void);
status_t insert_start(list_t* p_list, data_t new_data);
status_t insert_end(list_t* p_list, data_t new_data);
void show(list_t* p_list, const char* msg);
status_t destroy_list(list_t** pp_list);

// Immutable concat
status_t concat(list_t* p_list_1, list_t* p_list_2, list_t** pp_list);
// Mutable concat
status_t append(list_t* p_list_1, list_t** pp_list_2);

status_t to_array(list_t* p_list, data_t** pp_array, size_t* p_array_size);
status_t to_list(data_t* p_array, size_t size, list_t** pp_list);

// Immutable reversal
status_t get_reversed_list(list_t* p_list, list_t** pp_reversed_list);
// Mutable reversal
status_t reverse_list(list_t* p_list);

void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end);
void generic_delete(node_t* p_delete_node);
node_t* get_node(data_t new_data);
void* xmalloc(size_t size);

int main(void)
{
    return (EXIT_SUCCESS);
}

list_t* create_list(void)
{
    list_t* p_list = NULL;

    p_list = get_node(0);
    p_list->prev = p_list;
    p_list->next = p_list;

    return (p_list);
}

status_t insert_start(list_t* p_list, data_t new_data)
{
    generic_insert(p_list, get_node(new_data), p_list->next);
    return (SUCCESS);
}

status_t insert_end(list_t* p_list, data_t new_data)
{
    generic_insert(p_list->prev, get_node(new_data), p_list);
    return (SUCCESS);
}

void show(list_t* p_list, const char* msg)
{
    node_t* run = NULL;
    if(msg)
        puts(msg);

    printf("[START]<->");
    run = p_list->next;
    while(run != p_list)
    {
        printf("[%d]<->", run->data);
        run = run->next;
    }
    puts("[END]");
}

status_t destroy_list(list_t** pp_list)
{
    list_t* p_list = NULL;
    node_t* run = NULL;
    node_t* run_next = NULL;

    p_list = *pp_list;

    run = p_list->next;
    while(run != p_list)
    {
        run_next = run->next;
        free(run);
        run = run_next;
    }

    *pp_list = NULL;
    return (SUCCESS);
}

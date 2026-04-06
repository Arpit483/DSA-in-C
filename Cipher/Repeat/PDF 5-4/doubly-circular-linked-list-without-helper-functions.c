// Header files
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Symbolic constants
enum status
{
    SUCCESS            = 1,
    TRUE               = 1,
    FALSE              = 0,
    LIST_DATA_NOT_FOUND= 2,
    LIST_EMPTY         = 3
};

// Typedefs
typedef int             data_t;
typedef int             len_t;
typedef enum status     status_t;
typedef struct node     node_t;
typedef node_t          list_t;

// Node layout definition
struct node
{
    data_t data;
    struct node* prev;
    struct node* next;
};

// Declarations of interface functions

// Create list function
list_t* create_list(void);

// Insertion functions
status_t insert_start(list_t* p_list, data_t new_data);
status_t insert_end(list_t* p_list, data_t new_data);
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data);
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data);

// Get and pop functions
status_t get_start(list_t* p_list, data_t* p_start_data);
status_t get_end(list_t* p_list, data_t* p_end_data);
status_t pop_start(list_t* p_list, data_t* p_start_data);
status_t pop_end(list_t* p_list, data_t* p_end_data);

// Remove functions
status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, data_t e_data);

// Miscallaneous functions
status_t find(list_t* p_list, data_t search_data);
status_t is_list_empty(list_t* p_list);
len_t get_list_length(list_t* p_list);
void show(list_t* p_list, const char* msg);

// Destroy function
status_t destroy_list(list_t** pp_list);

int main(void)
{
    list_t* p_list = NULL;
    data_t data;
    data_t first_data;
    data_t last_data;
    status_t status;

    p_list = create_list();
    assert(p_list != NULL);

    assert(is_list_empty(p_list) == TRUE);
    assert(get_start(p_list, &first_data) == LIST_EMPTY);
    assert(get_end(p_list, &last_data) == LIST_EMPTY);
    assert(pop_start(p_list, &first_data) == LIST_EMPTY);
    assert(pop_end(p_list, &last_data) == LIST_EMPTY);
    assert(remove_start(p_list) == LIST_EMPTY);
    assert(remove_end(p_list) == LIST_EMPTY);
    assert(get_list_length(p_list) == 0);

    show(p_list, "Empty list(just after creation):");

    // Insert data at start
    for(data = 1; data <= 5; ++data)
        assert(insert_start(p_list, data*10) == SUCCESS);
    show(p_list, "After insert_start():");

    // Insert data at end
    for(data = 6; data <= 10; ++data)
        assert(insert_end(p_list, data*10) == SUCCESS);
    show(p_list, "After insert_end():");

    // Insert after : wrong data
    assert(insert_after(p_list, -100, 1000) == LIST_DATA_NOT_FOUND);

    // Insert before : wrong data
    assert(insert_before(p_list, -300, 2000) == LIST_DATA_NOT_FOUND);

    // Insert after and insert before : SUCCESS cases
    assert(insert_after(p_list, 50, 1000) == SUCCESS);
    show(p_list, "After successful insert_after():");

    assert(insert_before(p_list, 50, 2000) == SUCCESS);
    show(p_list, "After successful insert_before():");

    // Get & pop functions
    show(p_list, "Before get_start():");
    status = get_start(p_list, &first_data);
    assert(status == SUCCESS);
    printf("Start data = %d\n", first_data);
    show(p_list, "After get_start():");

    show(p_list, "Before get_end():");
    status = get_end(p_list, &last_data);
    assert(status == SUCCESS);
    printf("Last data = %d\n", last_data);
    show(p_list, "After get_end():");

    show(p_list, "Before pop_start():");
    status = pop_start(p_list, &first_data);
    assert(status == SUCCESS);
    printf("Start data = %d\n", first_data);
    show(p_list, "After pop_start():");

    show(p_list, "Before pop_end():");
    status = pop_end(p_list, &last_data);
    assert(status == SUCCESS);
    printf("Last data = %d\n", last_data);
    show(p_list, "After pop_end():");

    // Remove functions
    show(p_list, "Before remove_start():");
    assert(remove_start(p_list) == SUCCESS);
    show(p_list, "After remove_start():");

    show(p_list, "Before remove_end():");
    assert(remove_end(p_list) == SUCCESS);
    show(p_list, "After remove_end():");

    // remove_data() : Wrong case
    assert(remove_data(p_list, -200) == LIST_DATA_NOT_FOUND);

    // remove_data() : SUCCESS case
    show(p_list, "Before remove_data():");
    assert(remove_data(p_list, 20) == SUCCESS);
    show(p_list, "After remove_data():");

    // Miscallaneous functions

    // find : Wrong case
    status = find(p_list, -700);
    if(status == FALSE)
        puts("-700 is not found in list");
    else
        puts("find():unexpected error:-700");

    // find : SUCCESS case
    status = find(p_list, 1000);
    if(status == SUCCESS)
        puts("1000 is found in list");
    else
        puts("find():unexpected error:1000");

    // Length function
    len_t length = get_list_length(p_list);
    printf("Length of non-empty list = %d\n", length);

    // is empty test
    assert(is_list_empty(p_list) == FALSE);
    puts("List is not empty at this point");

    // List destruction
    status = destroy_list(&p_list);
    assert(status == SUCCESS && p_list == NULL);

    puts("List destroyed and tested successfully");

    return (EXIT_SUCCESS);
}

// Declarations of interface functions

// Create list function
list_t* create_list(void)
{
    list_t* p_list = NULL;

    p_list = (list_t*)malloc(sizeof(list_t));
    if(NULL == p_list)
    {
        puts("create_list():malloc():failed");
        exit(EXIT_FAILURE);
    }

    p_list->data = 0;
    p_list->prev = p_list;
    p_list->next = p_list;

    return (p_list);
}

// Insertion functions
status_t insert_start(list_t* p_list, data_t new_data)
{
    node_t* new_node = NULL;

    new_node = (node_t*)malloc(sizeof(node_t));
    if(NULL == new_node)
    {
        puts("insert_start():malloc():failed");
        exit(EXIT_FAILURE);
    }

    new_node->data = new_data;

    new_node->next = p_list->next;
    new_node->prev = p_list;
    p_list->next->prev = new_node;
    p_list->next = new_node;

    return (SUCCESS);
}

status_t insert_end(list_t* p_list, data_t new_data)
{
    node_t* new_node = NULL;

    new_node = (node_t*)malloc(sizeof(node_t));
    if(NULL == new_node)
    {
        puts("insert_end():malloc():failed");
        exit(EXIT_FAILURE);
    }

    new_node->data = new_data;

    new_node->next = p_list;
    new_node->prev = p_list->prev;
    p_list->prev->next = new_node;
    p_list->prev = new_node;

    return (SUCCESS);
}

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data)
{
    node_t* existing_node = NULL;
    node_t* new_node = NULL;
    node_t* run = NULL;

    run = p_list->next;
    while(run != p_list)
    {
        if(run->data == existing_data)
            break;
        run = run->next;
    }

    if(run == p_list)
        return (LIST_DATA_NOT_FOUND);

    existing_node = run;

    new_node = (node_t*)malloc(sizeof(node_t));
    if(NULL == new_node)
    {
        puts("insert_after():malloc():failed");
        exit(EXIT_FAILURE);
    }

    new_node->data = new_data;

    new_node->next = existing_node->next;
    new_node->prev = existing_node;
    existing_node->next->prev = new_node;
    existing_node->next = new_node;

    return (SUCCESS);
}

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data)
{
    node_t* existing_node = NULL;
    node_t* new_node = NULL;
    node_t* run = NULL;

    run = p_list->next;
    while(run != p_list)
    {
        if(run->data == existing_data)
            break;
        run = run->next;
    }

    if(run == p_list)
        return (LIST_DATA_NOT_FOUND);

    existing_node = run;

    new_node = (node_t*)malloc(sizeof(node_t));
    if(NULL == new_node)
    {
        puts("insert_before():malloc():failed");
        exit(EXIT_FAILURE);
    }

    new_node->data = new_data;

    new_node->next = existing_node;
    new_node->prev = existing_node->prev;
    existing_node->prev->next = new_node;
    existing_node->prev = new_node;

    return (SUCCESS);
}

// Get and pop functions
status_t get_start(list_t* p_list, data_t* p_start_data)
{
    if(p_list->prev == p_list && p_list->next == p_list)
        return (LIST_EMPTY);

    *p_start_data = p_list->next->data;
    return (SUCCESS);
}

status_t get_end(list_t* p_list, data_t* p_end_data)
{
    if(p_list->prev == p_list && p_list->next == p_list)
        return (LIST_EMPTY);

    *p_end_data = p_list->prev->data;
    return (SUCCESS);
}

status_t pop_start(list_t* p_list, data_t* p_start_data)
{
    node_t* delete_node = NULL;

    if(p_list->prev == p_list && p_list->next == p_list)
        return (LIST_EMPTY);

    *p_start_data = p_list->next->data;

    delete_node = p_list->next;
    delete_node->prev->next = delete_node->next;
    delete_node->next->prev = delete_node->prev;
    free(delete_node);

    return (SUCCESS);
}

status_t pop_end(list_t* p_list, data_t* p_end_data)
{
    node_t* delete_node = NULL;

    if(p_list->prev == p_list && p_list->next == p_list)
        return (LIST_EMPTY);

    *p_end_data = p_list->prev->data;

    delete_node = p_list->prev;
    delete_node->prev->next = delete_node->next;
    delete_node->next->prev = delete_node->prev;
    free(delete_node);

    return (SUCCESS);
}

// Remove functions
status_t remove_start(list_t* p_list)
{
    node_t* delete_node = NULL;

    if(p_list->next == p_list && p_list->prev == p_list)
        return (LIST_EMPTY);

    delete_node = p_list->next;

    delete_node->prev->next = delete_node->next;
    delete_node->next->prev = delete_node->prev;

    free(delete_node);

    return (SUCCESS);
}

status_t remove_end(list_t* p_list)
{
    node_t* delete_node = NULL;

    if(p_list->prev == p_list && p_list->next == p_list)
        return (LIST_EMPTY);

    delete_node = p_list->prev;

    delete_node->prev->next = delete_node->next;
    delete_node->next->prev = delete_node->prev;

    free(delete_node);

    return (SUCCESS);
}

status_t remove_data(list_t* p_list, data_t e_data)
{
    node_t* run = NULL;
    node_t* delete_node = NULL;

    run = p_list->next;
    while(run != p_list)
    {
        if(run->data == e_data)
            break;
        run = run->next;
    }

    if(run == p_list)
        return (LIST_DATA_NOT_FOUND);

    delete_node = run;

    delete_node->prev->next = delete_node->next;
    delete_node->next->prev = delete_node->prev;

    free(delete_node);

    return (SUCCESS);
}

// Miscallaneous functions
status_t find(list_t* p_list, data_t search_data)
{
    node_t* run = NULL;

    run = p_list->next;
    while(run != p_list)
    {
        if(run->data == search_data)
            return (TRUE);
        run = run->next;
    }

    return (FALSE);
}

status_t is_list_empty(list_t* p_list)
{
    return (p_list->prev == p_list && p_list->next == p_list);
}

len_t get_list_length(list_t* p_list)
{
    len_t length = 0;
    node_t* run = NULL;

    run = p_list->next;
    while(run != p_list)
    {
        length += 1;
        run = run->next;
    }

    return (length);
}

void show(list_t* p_list, const char* msg)
{
    node_t* run = NULL;

    if(msg)
        printf("%s:", msg);

    printf("[START]<->");
    run = p_list->next;
    while(run != p_list)
    {
        printf("[%d]<->", run->data);
        run = run->next;
    }
    printf("[END]\n");
}

// Destroy function
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

    free(p_list);

    p_list = NULL;
    *pp_list = NULL;

    return (SUCCESS);
}


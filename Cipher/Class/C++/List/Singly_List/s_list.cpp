#include <iostream>
#include "s_list.hpp"
#include "s_list_exceptions.cpp"

node::node(int _data) : data(_data), next(0){}

    list::list()
    {
        head_node = new node(0);
        head_node->next = NULL;
    }

    list::~list()
    {
        node *run_next = 0;

        for (node *run = head_node; run != NULL; run = run_next)
        {
            run_next = run->next;
            delete run;
        }

        delete head_node;
        
    }



    // generic insert
    void list::generic_insert(node* p_start, node* p_mid, node* p_end)
    {
        p_mid->next = p_end;
        p_start->next = p_mid;
    }
    
    // generic delete
    void list::generic_delete(node* p_prev_node, node* p_delete_node)
    {
        p_prev_node->next = p_delete_node->next;
        delete p_delete_node;
    }
    
    // search node
    node* list::search_node(int search_data)
    {
        for(node* run = head_node->next; run != NULL; run = run->next)
        {
            if(run->data == search_data)
                return run;
        }
        return NULL;
    }



void list::insert_start(int new_data)
{
    generic_insert(head_node, new node(new_data), head_node->next);
}

void list::insert_end(int new_data)
{
    node *run = head_node;
    while(run->next != NULL)
        run = run->next;

    generic_insert(run, new node(new_data), NULL);
}

void list::insert_after(int existing_data, int new_data)
{
    node *existing_node = this->search_node(existing_data);
    if(existing_node == 0)
    {
        throw list_data_not_found("List::Insert_after(Invalid Existing Data)");
    }
    generic_insert(existing_node, new node(new_data), existing_node->next);
}

void list::insert_before(int existing_data, int new_data)
{
    node *existing_node = search_node(existing_data);
    if(existing_node == 0)
    {
        throw list_data_not_found("List::Insert_before(Invalid Existing Data)");
    }

    node *prev_node = head_node;
    while(prev_node->next != NULL && prev_node->next != existing_node)
    {
        prev_node = prev_node->next;
    }

    generic_insert(prev_node, new node(new_data), existing_node);
}


void list::get_start(int* p_start_data)
{
    if(empty())
        throw list_empty("get_start(Empty List)");

    *p_start_data = head_node->next->data;
}


void list::get_end(int* p_end_data)
{
    if(empty())
        throw list_empty("get_start(Empty List)");

    node *run = head_node->next;
    while(run->next != NULL)
            run = run->next;
        
    *p_end_data = run->data;
}


void list::pop_start(int* p_start_data)
{
    if(empty())
        throw list_empty("pop_start(Empty List)");

    *p_start_data = head_node->next->data;
    generic_delete(head_node, head_node->next);
}

void list::pop_end(int* p_end_data)
{
    if(empty())
        throw list_empty("pop_start(Empty List)");

    
    node* prev = head_node;
    while(prev->next->next != NULL)
        prev = prev->next;
        
    *p_end_data = prev->next->data;
    generic_delete(prev, prev->next);
}

void list::remove_start()
{
    if(empty())
        throw list_empty("remove_end(Empty List)");

    generic_delete(head_node, head_node->next);
}


void list::remove_end()
{
    if(empty())
        throw list_empty("remove_end(Empty List)");

        
        node* prev = head_node;
        while(prev->next->next != NULL)
            prev = prev->next;
        
        generic_delete(prev, prev->next);
}

void list::remove_data(int r_data)
{
    node* prev = head_node;

    while(prev->next != NULL && prev->next->data != r_data)
        prev = prev->next;
    
    if(prev->next == NULL)
        throw list_data_not_found("not found");
    
    generic_delete(prev, prev->next);
}

std::size_t list::size() const 
{   
    std::size_t N = 0; 

    node *run = head_node;
    while(run != NULL && run->next != NULL)
    {
        ++N;
        run = run->next;
    }
    return N; 
}

bool list::empty() const
{
    return head_node->next == NULL;
}

void list::show(const char* msg)const
{
    if(msg)
        std::cout << msg << std::endl;

    std::cout << "[START]->";
    for(node* run = head_node; run != NULL; run = run->next)
        std::cout << "[" << run->data << "]->"; 

    std::cout << "[END]" << std::endl;
}

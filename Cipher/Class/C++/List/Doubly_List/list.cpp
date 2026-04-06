#include <iostream>
#include "list_exceptions.hpp"
#include "list.hpp"

//  ===============================CLASS NODE===============================
node::node(int _data) : data(_data), prev(0), next(0)
{

    //  ===============================CLASS LIST===============================

    list::list() 
    {
        head_node = new node(0);
        head_node->prev = head_node; 
        head_node->next = head_node; 
    }
    
    list::~list() 
    {
        node* run_next = 0; 
    
        for(node* run = head_node->next; run != head_node; run = run_next)
        {
            run_next = run->next; 
            delete run; 
        }
    
        delete head_node; 
    }

}


void::insert_start(int new_data)
{
    generic_insert(head_node, new node(new_data), head_node->next);
}

void::insert_end(int new_data)
{
    generic_insert(head_node->prev, new node(new_data), head_node);
}


void::insert_after(int existing_data, int new_data)
{
    node *existing_node = this->search_node(existing_data);
    if(existing_node ==0)
    {
        throw list_data_not_found("List::Insert_after(Invalid Existing Data)");

    }

    generic_insert(existing_node, new node(new_data), existing_node->next);
}

void::insert_before(int existing_data, int new_data)

{
    node *existing_node = search_node(existing_data);
    if(existing_node == 0)
    {
        throw list_data_not_found("List::Insert_before(Invalid Existing Data)");
    }
    generic_insert(existing_node->prev, new node(new_data), existing_node);
}

void list::get_start(int* p_start_data)
{
    if(empty) 
        throw list_empty("get_start(Empty List)");

    *p_start_data = head_node->next->data;
}

void list::get_end(int* p_end_data)
{
    if(empty) 
        throw list_empty("get_end(Empty List)");

    *p_end_data = head_node->prev->data;
}

void list::pop_start(int* p_start_data)
{
    if(empty) 
        throw list_empty("pop_start(Empty List)");

    *p_start_data = head_node->next->data;
    generic_delete(head_node->next);
}

void list::pop_end(int* p_end_data)
{
    if(empty) 
        throw list_empty("pop_end(Empty List)");

    *p_end_data = head_node->prev->data;
    generic_delete(head_node->prev);
}

void list::remove_start()
{
    if(empty) 
        throw list_empty("remove_start(Empty List)");

    generic_delete(head_node->next);
}

void list::remove_end()
{
    if(empty) 
        throw list_empty("remove_end(Empty List)");

    generic_delete(head_node->prev);
}

void list::remove_data(int r_data)
{
    node* r_node = search_node(r_data); 
    if(r_node == 0)
        throw list_data_not_found("list::remove_data():invalid remove data"); 
    generic_delete(r_node); 
}

std::size_t list::size() const 
{   
    std::size_t N = 0; 

    for(node* run = head_node->next; run != head_node; run = run->next)
        ++N; 

    return N; 
}

bool list::empty() const 
{
    return head_node->next == head_node && head_node->prev == head_node; 
}

void list::show(const char* msg) const 
{
    if(msg)
        std::cout << msg << std::endl; 

    std::cout << "[START]<->"; 
    for(node* run = head_node->next; run != head_node; run = run->next)
        std::cout << "[" << run->data << "]<->"; 

    std::cout << "[END]" << std::endl; 
}

list* list::concat(list* other)const
{
    list *concatenated_list = new list;
    for (node *run = head_node->next; run != head_node; run = run->next)
    {
        concatenated_list->insert_end(run->data);

    }

    for (node *run = other->head_node->next; run!= other->head_node)
    {
        concatenated_list->list_end(run->data);
    }
    return concatenated_list;
}

void list::append(list* other)
{
    if(!other->empty)
    {
        head_node->prev->next = other->head_node->next;
        other->head_node->next->prev;
        head_node->prev = other->head_node->prev;
        other->head_node->prev->next = head_node;
        other->head_node->next = other->head_node;
        delete other;
    }
}


list* list::merge(list* other) const 
{
    list* merged_list = new list; 

    node* run1 = head_node->next; 
    node* run2 = other->head_node->next; 

    int data; 

    while(true)
    {
        if(run1 == head_node)
        {
            while(run2 != other->head_node)
            {
                merged_list->insert_end(run2->data); 
                run2 = run2->next; 
            }

            break; 
        }

        if(run2 == other->head_node)
        {
            while(run1 != head_node)
            {
                merged_list->insert_end(run1->data); 
                run1 = run1->next; 
            }

            break; 
        }

        if(run1->data <= run2->data)
        {
            data = run1->data;
            run1 = run1->next; 
        }
        else 
        {
            data = run2->data; 
            run2 = run2->next; 
        }

        merged_list->insert_end(data); 
    }

    return merged_list; 
}

list* list::to_list(int* p_array, std::size_t N)
{
    list *list_from_array = new list;
    for (std::size_t i = 0;i < N; ++i)
    {
        list_from_array->insert_end(p_array[i]);
    }
    return list_from_array;

}

void list::to_array(int** pp_array, std::size_t*pN , const)
{
    size_t N = size();
    *p N = N;
    int *p_array = new int[N];
    std::size_t N = size();
    *pN = N;
    int* p_array = new int[N];
    
    std::size_t i = 0;
    for(node* run = head_node->next; run != head_node; run = run->next)
    {
        p_array[i++] = run->data;
    }
    *pp_array = p_array;
}

list* list::get_reversed_list() const 
{
    list* reversed_list = new list; 

    for(node* run = head_node->next; run != head_node; run = run->next)
        reversed_list->insert_start(run->data); 

    return reversed_list; 
}





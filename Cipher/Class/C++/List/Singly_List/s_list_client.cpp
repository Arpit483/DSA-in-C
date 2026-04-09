#include<iostream>
#include "s_list.hpp"

void test_interlist_fn() {};
void test_single_list_fn();

{
    int main()
    test_interlist_fn();
    test_single_list_fn();
}

void test_single_list_fn()
{
    list *L = new list();
    int data;
    int start_data, end_data;

    if(L->empty())
    {
        std::cout << "List is Empty\n";
    }
    else
    {
        std::cerr << "Unexpected Error\n";
    }

    try
    {
        L->get_start(&start_data);
    }
    catch(const list_empty &e)
    {
        std::cerr << "get_start(): " << e.what() << std::endl;
    }

    try{
        L->pop_start(&start_data);

    }
    catch(const list_empty &e)
    {
        std::cerr << "pop_start(): " << e.what() << std::endl;
    }

    try{
        L->pop_end(&end_data);
    }
    catch(const list_empty &e)
    {
        std::cerr<<"pop_end(): "<<e.what()<<std::endl;
    }

    try{
        L->remove_start();
    }
    catch(const list_empty &e)
    {
        std::cerr<<"remove_start(): "<<e.what()<<std::endl;
    }
    try{
        L->remove_end();
    }
    catch(const list_empty &e)
    {
        std::cerr<<"remove_end(): "<<e.what()<<std::endl;
    }

    for(data=10;data<=50;data+=10)
    {
        L->insert_end(data);
    }
    L->show("\nList L after inserting data at end: ");
    for(data=60;data<=100;data+=10)
    {
        L->insert_start(data);
    }
    L->show("\nList L after inserting data at start: ");
    
    try{
        L->insert_after(-100,200);
    }
    catch(const list_data_not_found &e)
    {
        std::cerr<<e.what()<<std::endl;
    }

    try{
        L->insert_before(-300,200);
    }
    catch(const list_data_not_found &e)
    {
        std::cerr<<e.what()<<std::endl;
    }
    L->insert_after(10,1000);
    L->insert_before(10,2000);
    L->show("\nAfter: insert_after(),insert_before(): ");

    L->get_start(&start_data);
    std::cout<<"Start_data: "<<start_data<<std::endl;
    L->show("After get_start(): ");
    
    L->get_end(&end_data);
    std::cout<<"End_data: "<<end_data<<std::endl;
    L->show("After get_end(): ");


    L->pop_start(&start_data);
    std::cout<<"Start_data: "<<start_data<<std::endl;
    L->show("After pop_start(): ");
    
    L->pop_end(&end_data);
    std::cout<<"End_data: "<<end_data<<std::endl;
    L->show("After pop_end(): ");

    L->remove_start();
    L->show("After remove_start(): ");
    
    L->remove_end();
    L->show("After remove_end(): ");

    try
    {
        L->remove_data(-10);
    }
    catch(const list_data_not_found &e)
    {
        std::cerr<<e.what()<<std::endl;
    }

    L->remove_data(10);
    L->show("After remove_data(10): ");

    if(!L->empty())
    {
        std::cout<<"List is not empty (expected)\n";
    }
    else{
        std::cerr<<"List is empty (unexpected error)\n";
    }

    std::cout<<"L->size(): "<<L->size()<<std::endl;

   /*  List* reversed_list=L->get_reverse();
    L->show("L: ");
    reversed_list->show("Reversed version of L:");
    L->show("Before L->reversed: ");
    L->reverse();
    L->show("After L->reversed: ");

    delete L;
    delete reversed_list; */
}

/* void test_interlist_functions()
{
    List* L1=new List;
    List* L2=new List;
    for(int data=0;data<=50;data+=10)
        L1->insert_end(data);
    for(int data=5;data<=75;data+=10)
        L2->insert_end(data);
    List* concatenated_list=L1->concate(L2);
    List* merged_list=L1->merge(L2);
    L1->show("L1:");
    L2->show("L2:");
    concatenated_list->show("Concatenated_List:");
    merged_list->show("merged_list_List:");

    //Show concatenated list with iterator
    for(List::Iterator iter=concatenated_list->begin();
    iter!=concatenated_list->end();
    ++iter
    )
    {
        std::cout<<"*iter= "<<*iter<<std::endl;
    }
    L1->append(L2);
    L1->show("After L1->append(L2): ");
    L2=0;
    delete L1;
    L1=0;
    delete concatenated_list;
    concatenated_list=0;
    delete merged_list;
    merged_list=0;
}



 */
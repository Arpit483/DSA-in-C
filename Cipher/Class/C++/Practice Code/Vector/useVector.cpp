#include "vector.hpp"
#include <iostream> 

void test_vector(); 

int main()
{
    test_vector(); 
    std::cout << "main():Program exited successfully" << std::endl; 
    return EXIT_SUCCESS; 
}

void test_vector() 
{
    vector* pVec = new vector; 

    pVec->push_back(100); 
    pVec->push_back(200); 
    pVec->push_back(300); 
    pVec->push_back(400); 
    pVec->push_back(500); 

    std::cout << "pVec->size():" << pVec->size() << std::endl; 

    for(int i = 0; i < pVec->size(); ++i)
    {
        int current_val = pVec->get_value_at_index(i); 
        std::cout << "Value at index:" << i << " is " << current_val << std::endl; 
    }

    std::cout << "Setting Value at each index to (index + 1) * 10" << std::endl; 
    for(int i = 0; i < pVec->size(); ++i)
        pVec->set_value_at_index(i, (i+1) * 10); 

    std::cout << "Showing vector after setting value at index to (index + 1) * 10" << std::endl; 
    for(int i = 0; i < pVec->size(); ++i)
    {
        int current_val = pVec->get_value_at_index(i); 
        std::cout << "Value at index:" << i << " is " << current_val << std::endl; 
    }

    std::cout << "Deleting vector" << std::endl; 
    delete pVec; 
    pVec = 0; 
}


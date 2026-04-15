#ifndef VECTOR_HPP 
#define VECTOR_HPP 

class vector 
{
    private: 
        int* p_array;
        int a_size; 

    public: 
        vector();   //  Constructor 
        ~vector();  //  Destructor 

        void push_back(int new_data); 

        int get_value_at_index(int index); 
        void set_value_at_index(int index, int value); 
        int size(); 
}; 


#endif
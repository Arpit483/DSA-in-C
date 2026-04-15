/* 
 new opeartor of C++ programming language enables programmer to allocate 
 dynamic object with automated call to constructor 
 Reason : new is a langauge operator and not a library function 
 Therefore, compiler must take the responsibility to generate assembly code for it 
 Therefore, compiler can generate an equivalent assembly code which in part 1 
 invokes malloc() like function to allocate memory dynamically and in part 2 
 places an automated call to the constructor  
 */


 #include <iostream>
 #include <cstdlib>

 class Date 
 {
    private:
        int day, month, year;

    public:
        Date(int init_day ,int init_month , int init_year )
        {
            this->day = init_day;
            this->month = init_month;
            this->year = init_year;

            std::cout << "Date::Date(): Object at address : " << this
                      << "is initialized with " << init_day << "/" << init_month
                      << "/" << init_year << " values " << std::endl;
        }

        void show()
        {
            std::cout << this->day << "/" << this->month << "/" << this->year << std::endl;
        }
 };

 int main()
 {
     Date *p_date = new Date(31, 01, 2026);
   
     /* 
     Assembly code generated for above statement looks like this 
     pushl   $12     # 12 is a size in bytes of object of class Date 
     call    malloc  # Allocate 12 bytes dynamically
                     # malloc() returns address of newly allocated memory 
                     # block in eax register 

     # PART 2: Date::Date(address_returned_by_malloc, 1, 2026)
     pushl   $2026 
     pushl   $1 
     pushl   $31 
     pushl   %eax 
     call    Date::Date 
     movl    %eax, -4(%ebp)
 
 */

    p_date->show();

    delete p_date;
    p_date = 0;

    return EXIT_SUCCESS;
 }

 /*
void f() 
{
    int n; 

    delete &n; //   segfault 
}
*/
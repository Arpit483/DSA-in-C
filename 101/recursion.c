#include <stdio.h>

// Recursion Fn calling itself
// Factorial

int fact (int a) {
    int f = 1 ; 
    for (int i = a ; i > 0  ; i--){
         f = f*i;
    }
    return f;
}

int recc (int n ){
    int i;
    if(n!=1){
        return n*fact(n-1);
    }
    return 1;

}

int main () { 

    int n = 10;
    int ans = recc(n);
    printf("%d" , ans);
    return 0;
}
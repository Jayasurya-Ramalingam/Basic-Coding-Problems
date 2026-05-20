#include <stdio.h>

void add(int a,int b)
{
    printf("Sum:%d\n",a+b);
}


void main()
{
    //Wrong Initialization
    //void *ptr(int,int) = add(3,6);
    
    // void (*ptr)(int,int) = add;
    
    // (*ptr)(5,6);
    
    void (*ptr)(int, int);

    ptr = add;

    ptr(3, 6);
    
    //Wrong declaration
    //void (*ptt)(int,int)[2];
   // void ((*ptt)[2])(int,int);
    void (*ptt[2])(int,int);
    
    ptt[0] = add;
    ptt[1] = add;
    
    ptt[0](2,3);
    ptt[1](2,0);

}

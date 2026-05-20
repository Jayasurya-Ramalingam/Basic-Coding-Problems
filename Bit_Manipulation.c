#include <stdio.h>

#define SET_BIT(x,n)     (1<<(x))| (n)  
#define CLEAR_BIT(x,n)   (~(1<<(x))) & (n)
#define TOGGLE_BIT(x,n)     (1<<(x)) ^ (n)

int main() {
	// your code goes here
	//Set a Bit
    printf("%d", (1<<3)|16);  //11000
    //Clear a Bit
    printf("%d", (~(1<<3)) & 24);//10000
    //Toggle a Bit
    printf("%d\n", (1<<3)^16);
    
    
    //Macro
    printf("Set a Bit:%d\n", SET_BIT(3,16));
    printf("Clear a Bit:%d\n", CLEAR_BIT(3,24));
    printf("Toggle a Bit:%d\n", TOGGLE_BIT(3,16));
}

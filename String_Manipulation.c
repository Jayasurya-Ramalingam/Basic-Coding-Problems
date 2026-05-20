#include <stdio.h>
#include <string.h>


int main() {

    //String Manipulation
    char str[120] = "Jaysurya";
    
    printf("Length of a string:%d\n",strlen(str));
    
    //Declaration of a string
    //char *str_1 = "Jay"; //Correct
    
    //Allocate memory and use scanf
    //char *str_1; 
    // scanf("%s",str_1); //Wrong
    //printf("Length of a string:%d\n",strlen(str_1));
   
    char str_2[10];
    scanf("%s",&str_2);
    printf("Length:%s\n",str_2);
    
    //Assign Strings
    char str_3[] = {'a','b','c','d','\0'};
    //char str_3[] = {'a','b','c','d'}; Wrong
    printf("Length:%d\n",strlen(str_3));
}

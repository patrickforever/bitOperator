#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void print1(void)
{
    printf("fun=1\n");
}
void print2(void)
{
    printf("fun=2\n");
}
void print4(void)
{
    printf("fun=4\n");
}
void print8(void)
{
    printf("fun=8\n");
}
void print16(void)
{
    printf("fun=16\n");
}
void print32(void)
{
    printf("fun=32\n");
}

unsigned int valueArray[6] = {1,2,4,8,16,32};
void (*printArray[])(void) = {print1,print2,print4,print8,print16,print32};
void (*pFN)(void);
void printfOpenFN(int number);
void openFunction(int number);
void closeFunction(int number);
int g_contorlFNNumber;

int main()
{
    unsigned int number , i;

    printf("insert a number to function open \n");
    scanf("%u",&number);
    //printf("%d",number);
    g_contorlFNNumber = number;
    printfOpenFN(g_contorlFNNumber);


    printf("which function open :\n");
    scanf("%u",&number);
    openFunction(number);
    printfOpenFN(g_contorlFNNumber);

    printf("which function close :\n");
    scanf("%u",&number);
    closeFunction(number);
    printfOpenFN(g_contorlFNNumber);
}
void printfOpenFN(int number)
{
    int i ;
    for(i=0;i<6;i++){
       // printf("number = %d valueArray[i] = %d\n",number,valueArray[i]);
        if( (number & valueArray[i])){
            //printf("%d = %d\n",i,valueArray[i]);
            pFN = printArray[i];
            pFN();
        }
    }
}
void openFunction(int number)
{
    g_contorlFNNumber |= number;
}
void closeFunction(int number)
{
    g_contorlFNNumber &= (~number);
}

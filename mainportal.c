//student billing class teacher
//enroll, change,  delete
//roll number auto enrll
#include <stdio.h>
#include <stdlib.h>
#include <C:\Users\Aryan\Desktop\Aryan Docs\School portal\modules\teacherModule\teacherPortal.c>
int main()
{
    int portalchoice;
    printf("Hello!\n");
    printf("Welcome to Tan dr school portal\n");
    printf("How may we assist you today?\n");
    printf("\n");
    printf("1. Enter Student portal\n");
    printf("2. Enter Teacher portal\n");
    printf("3. Enter Class portal\n");
    printf("4. Enter Billing portal\n");
    scanf("%d", &portalchoice);    
    getchar();
    if(portalchoice == 1){
        //studentportal
    }
    if(portalchoice == 2){
        teacherPortal();
    }
    if(portalchoice == 3){
        //Classportal
    }
    if(portalchoice == 4){
        //billingportal
    }
}
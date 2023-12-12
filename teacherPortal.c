#include <stdio.h>
#include <stdlib.h>
#include <C:\Users\Aryan\Desktop\Aryan Docs\School portal\teacherPrint.c>
#include <C:\Users\Aryan\Desktop\Aryan Docs\School portal\teacherAdd.c>


int main()
{
    FILE *fptr = NULL;
    FILE *teachfptr;
    int choice;
    printf("TEACHER PORTAL\n");
    printf("1. Display teacher information\n");
    printf("2. Add teacher\n");
    printf("3. Edit teacher\n");
    printf("4. Remove teacher\n");
    scanf("%d", &choice);
    switch(choice){
        case(1):
        displayteacher(fptr);
        break;
        case(2):
        addTeacher(teachfptr);
        break;
        case(3):
        //edit teacher
        break;
        case(4):
        //remove teacher
        break;
    }
}
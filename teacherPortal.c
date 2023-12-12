#include <stdio.h>
#include <stdlib.h>
#include <C:\Users\Aryan\Desktop\Aryan Docs\School portal\teacherPrint.c>
#include <C:\Users\Aryan\Desktop\Aryan Docs\School portal\teacherAdd.c>
#include "C:\Users\Aryan\Desktop\Aryan Docs\School portal\structTeacher.h"


int main()
{
    FILE *fptr = NULL;
    FILE *teachfptr;
    int choice;
    char addChoice;
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
        getchar();
        addTeacher(teachfptr);
        do
        { printf("Do you want to add another teacher (y/n): ");
          scanf(" %c", &addChoice);
          getchar();
          if (addChoice == 'y' || addChoice == 'Y')
          {
            addTeacher(teachfptr);
          }
        } while (addChoice == 'y' || addChoice == 'Y');
        break;
        case(3):
        //edit teacher
        break;
        case(4):
        //remove teacher
        break;
    }
}
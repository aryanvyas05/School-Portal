#include <stdio.h>
#include <stdlib.h>
#include <C:\Users\Aryan\Desktop\Aryan Docs\School portal\Addstudent.c>

int main()
{
    FILE *fptr = NULL;
    int choice;
    char addchoice;
    printf("STUDENT PORTAL\n");
    printf("1. Add student\n");
    printf("2. Edit student\n");
    printf("3. Remove student\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
        addstudent(fptr);
        do
        { printf("Do you want to add another student? (y/n): ");
          scanf(" %c", &addchoice);
          if (addchoice == 'y' || addchoice == 'Y')
          {
            addstudent(fptr);
          }
        } while (addchoice == 'y' || addchoice == 'Y');
        
        break;

        break;
        case 2:
        //edit student
        break;
        case 3:
        //remove student
        break;
    }
}
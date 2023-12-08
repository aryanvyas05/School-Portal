#include <stdio.h>
#include <stdlib.h>


struct teacher{
    char name[50];
    int grade;
    char section;
    
    };
int main()
{
    struct teacher* head = NULL;
    struct teacher* current = NULL;
    char teacherName[50];
    int teacherGrade;
    char teacherSection;
    FILE * teachfptr;
    printf("Name : ");
    fgets(teacherName, sizeof(teacherName), stdin);
    teacherName[strcspn(teacherName, "\n")] = '\0';


}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <C:\Users\Aryan\Desktop\Aryan Docs\School portal\structTeacher.c>

void displayteacher(FILE *fptr)
{
    struct teacher t;
    int grade;
    char section;
    char lowsection;
    printf("Please enter grade : ");
    scanf("%d", &grade);
    getchar();
    printf("Please enter section :");
    scanf("%c", &section);
    getchar();
    lowsection = tolower(section);

    fptr = fopen("Teacher.txt", "r");
    


    while(fscanf(fptr, "%49[^,]"",%d,%c", t.name, &t.grade, &t.section) != EOF){
    if(t.grade == grade && tolower(t.section) == lowsection){
        printf("%s %d %c", t.name, t.grade, t.section);
    }       
}
}

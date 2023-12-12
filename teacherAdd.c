#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <C:\Users\Aryan\Desktop\Aryan Docs\School portal\structTeacher.c>



void addTeacher(FILE *teachfptr)
{
    struct teacher* head = NULL;
    struct teacher* current = NULL;
    char buffer[10];
    char teacherName[50];
    int teacherGrade;
    char teacherSection;    
    char filename[100] = "Teacher.csv";
    teachfptr = fopen(filename, "a+");
    fseek(teachfptr, 0, SEEK_SET);
      if (fgets(buffer, sizeof(buffer), teachfptr) == NULL) {
        fprintf(teachfptr, "Roll no,Name,age,Father's name,Address\n");

      }
      fseek(teachfptr, 0, SEEK_END);
    printf("Name : ");
    fgets(teacherName, sizeof(teacherName), stdin);
    teacherName[strcspn(teacherName, "\n")] = '\0';
    printf("Grade : ");
    scanf("%d", &teacherGrade);
    getchar();
    printf("Section: ");
    scanf("%c", &teacherSection);   
    head = (struct teacher * ) malloc(sizeof(struct teacher));
    current = head;
    strcpy(current -> name, teacherName );
    current -> grade = teacherGrade;
    current -> section = teacherSection;
    current -> next = NULL;
    fprintf(teachfptr,"%s, %d, %c\n", current -> name, current -> grade, current -> section);
    

}
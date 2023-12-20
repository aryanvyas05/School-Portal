#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structTeacher.h"

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
        fprintf(teachfptr, "Name,Class,Section\n");

      }
      fseek(teachfptr, 0, SEEK_END);
    
    printf("Name : ");
    fgets(teacherName, sizeof(teacherName), stdin);
    teacherName[strcspn(teacherName, "\n")] = '\0';
    while (1) {
        printf("Please enter grade: ");
        if (scanf("%d", &teacherGrade) == 1) {
            getchar();
            break;
        } else {
            printf("Invalid input. Please enter a valid grade.\n");
            while (getchar() != '\n');
        }
    }
    while (1) {
        printf("Please enter section: ");
        if (scanf(" %c", &teacherSection) == 1) {
            getchar();
            break;
        } else {
            printf("Invalid input. Please enter a valid section.\n");
            while (getchar() != '\n');
        }
    }     
    head = (struct teacher * ) malloc(sizeof(struct teacher));
    head->name = (char *)malloc(strlen(teacherName) + 1);
    current = head;
    strcpy(current -> name, teacherName );
    current -> grade = teacherGrade;
    current -> section = tolower(teacherSection);
    current -> next = NULL;
    fprintf(teachfptr,"%s, %d, %c\n", current -> name, current -> grade, current -> section);
    

}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "structTeacher.h"

void displayTeacher(FILE *fptr) {
    struct teacher t;
    int grade;
    char section;
    int count = 0;
    while (1) {
        printf("Please enter grade: ");
        if (scanf("%d", &grade) == 1) {
            getchar();
            break;
        } else {
            printf("Invalid input. Please enter a valid grade.\n");
            while (getchar() != '\n');
        }
    }

    while (1) {
        printf("Please enter section: ");
        if (scanf(" %c", &section) == 1) {
            getchar();
            break;
        } else {
            printf("Invalid input. Please enter a valid section.\n");
            while (getchar() != '\n');
        }
    }
    fptr = fopen("Teacher.csv", "r");

    if (fptr == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fscanf(fptr, "%*[^\n]\n");
    t.name = malloc(50 * sizeof(char));

    while (fscanf(fptr, " %49[^,],%d, %c", t.name, &t.grade, &t.section) == 3) {
        if (t.grade == grade && tolower(t.section) == tolower(section)) {
            printf("%s %d %c\n", t.name, t.grade, t.section);
            count = count+1;
        }
    }
    if(count == 0){
        printf("No value");
    }

    fclose(fptr);
}

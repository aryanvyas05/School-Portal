#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "structTeacher.h"

void displayTeacher(FILE *fptr) {
    struct teacher t;
    int grade;
    char section;
    printf("Please enter grade : ");
    scanf("%d", &grade);
    getchar();
    printf("Please enter section :");
    scanf(" %c", &section);
    getchar();

    fptr = fopen("Teacher.csv", "r");

    if (fptr == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fscanf(fptr, "%*[^\n]\n");

    while (fscanf(fptr, " %49[^,],%d, %c", t.name, &t.grade, &t.section) == 3) {
        if (t.grade == grade && tolower(t.section) == tolower(section)) {
            printf("%s %d %c\n", t.name, t.grade, t.section);
        }
    }

    fclose(fptr);
}

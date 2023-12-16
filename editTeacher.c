#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct editTeacher {
    char *name;
    int grade;
    char section;
    struct teacher* next;
};

void editTeacher()
{
    FILE *fptr, *tempFile;
    struct editTeacher t;
    int grade;
    char section;
    char newName[50];

    printf("Please enter grade: ");
    scanf("%d", &grade);
    getchar();

    printf("Please enter section: ");
    scanf(" %c", &section);
    getchar();

    fptr = fopen("Teacher.csv", "r");
    tempFile = fopen("tempTeacher.csv", "w");

    if (fptr == NULL || tempFile == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }
    char header[100];
    if (fgets(header, sizeof(header), fptr) != NULL) {
        fprintf(tempFile, "%s", header);
    }

    printf("Enter new name: ");
    fgets(newName, sizeof(newName), stdin);
    newName[strcspn(newName, "\n")] = '\0';

    while (fscanf(fptr, " %49[^,],%d, %c", t.name, &t.grade, &t.section) == 3) {
        if (t.grade == grade && tolower(t.section) == tolower(section)) {
            free(t.name);
            t.name = strdup(newName);
        }

        fprintf(tempFile, "%s,%d,%c\n", t.name, t.grade, t.section);
    }

    fclose(fptr);
    fclose(tempFile);

    remove("Teacher.csv");
    rename("tempTeacher.csv", "Teacher.csv");

    return 0;
}

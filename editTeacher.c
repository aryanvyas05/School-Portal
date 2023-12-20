#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <C:\Users\Aryan\Desktop\Aryan Docs\School portal\structTeacher.h>

void editTeacher(int grade, char section)
{
    FILE *tempFile,*editfptr;
    struct teacher t;
    char newName[50];


    editfptr = fopen("Teacher.csv", "r");
    tempFile = fopen("tempTeacher.csv", "w");

    if (editfptr == NULL || tempFile == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }
    char header[100];
    if (fgets(header, sizeof(header), editfptr) != NULL) {
        fprintf(tempFile, "%s", header);
    }

    printf("Enter new name: ");
    fgets(newName, sizeof(newName), stdin);
    newName[strcspn(newName, "\n")] = '\0';

    while (fscanf(editfptr, " %49[^,],%d, %c", t.name, &t.grade, &t.section) == 3) {
    if (t.grade == grade && tolower(t.section) == tolower(section)) {
        strcpy(t.name, newName);
    }

    fprintf(tempFile, "%s,%d,%c\n", t.name, t.grade, t.section);
}

    fclose(editfptr);
    fclose(tempFile);

    remove("Teacher.csv");
    rename("tempTeacher.csv", "Teacher.csv");

}

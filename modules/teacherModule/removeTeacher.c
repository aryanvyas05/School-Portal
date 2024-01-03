#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <C:\Users\Aryan\Desktop\Aryan Docs\School portal\modules\teacherModule\structTeacher.h>

void removeTeacher(int grade, char section)
{
    FILE *tempFile,*editfptr, *fptr;
    struct teacher t;
    char choice, newName[50];
    int count =0;

    
    fptr = fopen("Teacher.csv", "r");

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
        return;
    }

    fclose(fptr);
    
    printf("Are you sure you want to delete? (y/n): ");
    scanf("%c", &choice);
    if(choice == 'y' || choice == 'Y'){
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

    while (fscanf(editfptr, " %49[^,],%d, %c", t.name, &t.grade, &t.section) == 3) {
    if (t.grade == grade && tolower(t.section) == tolower(section)) {
        continue;
    }

    fprintf(tempFile, "%s,%d,%c\n", t.name, t.grade, t.section);
}

    fclose(editfptr);
    fclose(tempFile);

    remove("Teacher.csv");
    rename("tempTeacher.csv", "Teacher.csv");
    }
    else{
        printf("Exit");
    }

}
#include <stdio.h>
#include <stdlib.h>

struct student {
    int rollno;
    char *name;
    int age;
    char *fathername;
    char *address;
};

int main() {
    FILE *fptr;
    struct student s;
    int rollno;
    int count = 0;

    while (1) {
        printf("Please enter rollno: ");
        if (scanf("%d", &rollno) == 1) {
            getchar();
            break;
        } else {
            printf("Invalid input. Please enter a valid roll number.\n");
            while (getchar() != '\n');
        }
    }

    fptr = fopen("student.csv", "r");
    if (fptr == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fscanf(fptr, "%*[^\n]\n");

    s.name = malloc(50 * sizeof(char));
    s.fathername = malloc(50 * sizeof(char));
    s.address = malloc(100 * sizeof(char));

    while (fscanf(fptr, "%d,%49[^,],%d,%49[^,],%99[^\n]", &s.rollno, s.name, &s.age, s.fathername, s.address) == 5) {
        if (s.rollno == rollno) {
            printf("%d. %s %d %s %s\n", s.rollno, s.name, s.age, s.fathername, s.address);
            count = count + 1;
        }
    }

    if (count == 0) {
        printf("No matching roll number found.\n");
    }
    free(s.name);
    free(s.fathername);
    free(s.address);

    fclose(fptr);

    return 0;
}

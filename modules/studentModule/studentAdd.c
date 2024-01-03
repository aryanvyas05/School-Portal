    #include <stdio.h>

    #include <stdlib.h>

    #include <string.h>

    struct student {
      int rollno;
      char * name;
      int age;
      char * fathername;
      char * address;
      struct student * next;
    };
    void addstudent(FILE * fptr) {
      struct student * head = NULL;
      struct student * current = NULL;
      char filename[100] = "Student.csv";
      char buffer[10];
      char name1[50];
      int age1;
      char fathername1[60];
      char address1[120];
      char line[200];
      fptr = fopen(filename, "a+");
      fseek(fptr, 0, SEEK_SET);
      if (fgets(buffer, sizeof(buffer), fptr) == NULL) {
        fprintf(fptr, "Roll no,Name,age,Father's name,Address\n");

      }
      fseek(fptr, 0, SEEK_END);
      getchar();
      printf("Name : ");
      fgets(name1, sizeof(name1), stdin);
      name1[strcspn(name1, "\n")] = '\0';
      printf("Age : ");
      scanf("%d", & age1);
      getchar();
      printf("Father's name : ");
      fgets(fathername1, sizeof(fathername1), stdin);
      fathername1[strcspn(fathername1, "\n")] = '\0';
      printf("Address : ");
      fgets(address1, sizeof(address1), stdin);
      address1[strcspn(address1, "\n")] = '\0';
      head = (struct student * ) malloc(sizeof(struct student));
      current = head;
      current -> name = (char * ) malloc(strlen(name1) + 1);
      strcpy(current -> name, name1);
      current -> age = age1;
      current -> fathername = (char * ) malloc(strlen(fathername1) + 1);
      strcpy(current -> fathername, fathername1);
      current -> address = (char * ) malloc(strlen(address1) + 1);
      strcpy(current -> address, address1);
      current -> next = NULL;
      if (fptr == NULL) {
        printf("Error opening file");
        exit(1);
      }

      fprintf(fptr, "%d, %s, %d, %s, %s\n", current -> rollno, current -> name, current -> age, current -> fathername, current -> address);

    }
#include <stdio.h>

#include <stdlib.h>

#include <C:\Users\Aryan\Desktop\Aryan Docs\School portal\modules\teacherModule\teacherPrint.c>

#include <C:\Users\Aryan\Desktop\Aryan Docs\School portal\modules\teacherModule\teacherAdd.c>

#include <C:\Users\Aryan\Desktop\Aryan Docs\School portal\modules\teacherModule\editTeacher.c>

#include <C:\Users\Aryan\Desktop\Aryan Docs\School portal\modules\teacherModule\removeTeacher.c>

#include "structTeacher.h"


void teacherPortal () {
  FILE * fptr = NULL;
  FILE * teachfptr = NULL;
  FILE * editfptr = NULL;
  int choice, grade;
  char addChoice, editchoice, remchoice, section;
  printf("TEACHER PORTAL\n");
  printf("1. Display teacher information\n");
  printf("2. Add teacher\n");
  printf("3. Edit teacher\n");
  printf("4. Remove teacher\n");
  scanf("%d", & choice);
  switch (choice) {
  case (1):
    displayTeacher(fptr);
    break;
  case (2):
    getchar();
    addTeacher(teachfptr);
    do {
      printf("Do you want to add another teacher (y/n): ");
      scanf(" %c", & addChoice);
      getchar();
      if (addChoice == 'y' || addChoice == 'Y') {
        addTeacher(teachfptr);
      }
    } while (addChoice == 'y' || addChoice == 'Y');
    break;
  case (3):
    getchar();
    while (1) {
      printf("Please enter grade: ");
      if (scanf("%d", & grade) == 1) {
        getchar();
        break;
      } else {
        printf("Invalid input. Please enter a valid grade.\n");
        while (getchar() != '\n');
      }
    }

    while (1) {
      printf("Please enter section: ");
      if (scanf(" %c", & section) == 1) {
        getchar();
        break;
      } else {
        printf("Invalid input. Please enter a valid section.\n");
        while (getchar() != '\n');
      }
    }

    editTeacher(grade, section);
    do {
      printf("Do you want to edit another teacher (y/n): ");
      scanf(" %c", & editchoice);
      getchar();
      if (editchoice == 'y' || editchoice == 'Y') {
        while (1) {
          printf("Please enter grade: ");
          if (scanf("%d", & grade) == 1) {
            getchar();
            break;
          } else {
            printf("Invalid input. Please enter a valid grade.\n");
            while (getchar() != '\n');
          }
        }

        while (1) {
          printf("Please enter section: ");
          if (scanf(" %c", & section) == 1) {
            getchar();
            break;
          } else {
            printf("Invalid input. Please enter a valid section.\n");
            while (getchar() != '\n');
          }
        }

        editTeacher(grade, section);
      }
    } while (editchoice == 'y' || editchoice == 'Y');
    break;
  case (4):
    while (1) {
      printf("Please enter grade: ");
      if (scanf("%d", & grade) == 1) {
        getchar();
        break;
      } else {
        printf("Invalid input. Please enter a valid grade.\n");
        while (getchar() != '\n');
      }
    }

    while (1) {
      printf("Please enter section: ");
      if (scanf(" %c", & section) == 1) {
        getchar();
        break;
      } else {
        printf("Invalid input. Please enter a valid section.\n");
        while (getchar() != '\n');
      }
    }
    removeTeacher(grade, section);

    do {
      printf("Do you want to remove another teacher (y/n): ");
      scanf(" %c", & remchoice);
      getchar();
      if (remchoice == 'y' || remchoice == 'Y') {
        while (1) {
          printf("Please enter grade: ");
          if (scanf("%d", & grade) == 1) {
            getchar();
            break;
          } else {
            printf("Invalid input. Please enter a valid grade.\n");
            while (getchar() != '\n');
          }
        }

        while (1) {
          printf("Please enter section: ");
          if (scanf(" %c", & section) == 1) {
            getchar();
            break;
          } else {
            printf("Invalid input. Please enter a valid section.\n");
            while (getchar() != '\n');
          }
        }

        removeTeacher(grade, section);
      }
    } while (remchoice == 'y' || remchoice == 'Y');
    break;
  }
}
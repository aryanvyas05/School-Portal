#ifndef STRUCT_STUDENT_H
#define STRUCT_STUDENT_H

struct student {
    int rollno;
    char *name;
    int age;
    char * fathername;
    char * address;
    struct student* next;
};

#endif
#ifndef STRUCT_TEACHER_H
#define STRUCT_TEACHER_H

struct teacher {
    char name[50];
    int grade;
    char section;
    struct teacher* next;
};

#endif
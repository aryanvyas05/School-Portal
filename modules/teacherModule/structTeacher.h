#ifndef STRUCT_TEACHER_H
#define STRUCT_TEACHER_H

struct teacher {
    char *name;
    char *subject;
    int grade;
    char section;
    struct teacher* next;
};

#endif
#ifndef SCHOOL_H_
#define SCHOOL_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"Std_Types.h"

/*Student Data */
struct Student {
    u8 name[50];
    u8 date_of_Birth[10];
    u32 id;
    u8 address[50];
    u8 phoneNumber[15];
    f32 computerScienceScore;
};

/*Linked list node*/
struct Node {
    struct Student data; // student data is stored in it.
    struct Node* next;   // Pointer that point to the next node.
};

/*prototypes of functions*/
void print();
void MAIN_MENU(struct Node** studentsList, int* numStudents);
/*
This function display welcome screen and the activities that specialized for evevy student.
*/
void NEW_STUDENT(struct Node** studentsList, int* numStudents);
/*
This function create new student account.
evevy account include name-date_of_birth-id-address-phoneNumber .
*/
void STUDENT_EDIT(struct Node* studentsList);
/*
This function use to change the data(updateing data) about any student.
*/
void STUDENT_LIST(struct Node* studentsList);
/*
This function used to display information such that (name-data_of_birth-id-address-phoneNumber) about any student.
*/
void DELETE_STUDENT(struct Node** studentsList, int* numStudents);
/*
This function for delete any student account.
*/
void RANK_STUDENT(struct Node* studentsList);


#endif
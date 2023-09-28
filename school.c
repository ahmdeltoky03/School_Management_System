//
// Created by: ahmed abdelkader eltokhy
// date: 9/26/2023.
//
#include "school.h"
#define MAX_SIZE 10
void print(){
    printf("*********************************************\n");
    printf("*********************************************\n");
    printf("**** WELCOME TO SCHOOL MANAGEMENT SYSTEM ****\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
}
void MAIN_MENU(struct Node** studentsList, int* numStudents) {
    printf("*******************************************\n");
    printf("*************Logged in successfully***********\n");
    printf("*******************************************\n");
    printf("****WELCOME TO SCHOOL MANAGEMENT SYSTEM****\n");
    printf("*******************************************\n");
    printf("To Add a new student Enter [1] \n");
    printf("To Update Data about Student Enter [2] \n");
    printf("To Delete a student Enter [3]\n");
    printf("To View studentlist Enter [4] \n");
    printf("To Count number of students Enter [5]\n");
    printf("To Rank the top students Enter [6]\n");
    printf("To Exit_SYSTEM Enter [7]\n");

    u32 choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            NEW_STUDENT(studentsList, numStudents);
            break;

        case 2:
            STUDENT_EDIT(*studentsList);
            break;

        case 3:
            DELETE_STUDENT(studentsList, numStudents);
            break;

        case 4:
            STUDENT_LIST(*studentsList);
            break;

        case 5:
            printf("Number_of_students= %d\n", *numStudents);
            break;

        case 6:
            RANK_STUDENT(*studentsList);
            break;


        case 7:
            printf("\n Exiting the program \n\t Goodbye\n");
            exit(0);

        default:
            printf("\nPlease Enter a Valid Choice.\n");
            break;
    }
}

void NEW_STUDENT(struct Node** studentsList, int* numStudents) {

    /* Check if the maximum limit of students has been reached */
    if (*numStudents >= MAX_SIZE) {//max_size =10 students
        printf("\nCannot add more students.\n");
        return;
    }

    /* Create a new node for the new student */
    struct Node* currentNode = (struct Node*)malloc(sizeof(struct Node));

    /* Check the memory allocation success  */
    if (currentNode == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    printf("\nEnter the details for the new student:\n");

    printf("Name: ");
    //fgets(currentNode->data.name,sizeof(currentNode->data.name),stdin);
    fflush(stdin);
    gets(currentNode->data.name);


    printf("Date of Birth in the form of (day-month-year): ");
    fflush(stdin);
    gets(currentNode->data.date_of_Birth);
    //fgets(currentNode->data.date_of_Birth,sizeof(currentNode->data.date_of_Birth),stdin);



    printf("ID: ");
    scanf("%lu", &currentNode->data.id);//%d

    printf("Address: ");
    //fgets(currentNode->data.address,sizeof(currentNode->data.address),stdin);
    fflush(stdin);
    gets(currentNode->data.address);

    printf("Phone Number: ");
    fflush(stdin);
    gets(currentNode->data.phoneNumber);
    //fgets(currentNode->data.phoneNumber,sizeof(currentNode->data.phoneNumber),stdin);

    printf("Ente ComputerScienceScore: ");
    scanf("%f", &currentNode->data.computerScienceScore);


    currentNode->next = *studentsList;  /* Link the new node(currentNode) to the existing list */
    *studentsList = currentNode;        /* To update the pointer to point the new node */
//Increment the number of students
    (*numStudents)++;

    printf("\nStudent added successfully\n\n\n");
}

void STUDENT_EDIT(struct Node* studentsList) {
    u32 idd;

    /*Ask the user for the ID of the student they want to update */
    printf("\nEnter the ID of the student you want to update: ");
    scanf("%d", &idd);

    /* Start from the beginning of the linked list */
    struct Node* currentNode = studentsList;

    /* Check the linked list to find the student with the given ID */
    while (currentNode != NULL) {
        if (currentNode->data.id == idd) {
            printf("Found student with ID %d. Updating information:\n", idd);

            printf("Name: ");
            //fgets(currentNode->data.name,sizeof(currentNode->data.name),stdin);
             fflush(stdin);
            gets(currentNode->data.name);

            printf("Date_of_Birth: ");
            fflush(stdin);
            gets(currentNode->data.date_of_Birth);
            //fgets(currentNode->data.date_of_Birth,sizeof(currentNode->data.date_of_Birth),stdin);

            printf("Address: ");
            fflush(stdin);
            gets(currentNode->data.address);
            //fgets(currentNode->data.address,sizeof(currentNode->data.address),stdin);

            printf("PhoneNumber: ");
            fflush(stdin);
            gets(currentNode->data.phoneNumber);
            //fgets(currentNode->data.phoneNumber,sizeof(currentNode->data.phoneNumber),stdin);

            printf("Enter ComputerScienceScore: ");
            scanf("%f", &currentNode->data.computerScienceScore);

            printf("\n\nStudent information updated successfully.\n\n");
            return; /* Exit the function after updating the student's information */
        }
        currentNode = currentNode->next;  /* point to the next node in the linked list */
    }
    /* If the loop finishes without finding a matching student ID */
    printf("\n Student not found.\n\n");
    printf("#################################\n\n");
}

void DELETE_STUDENT(struct Node** studentsList, int* numStudents) {
/* Check if the student list is empty */
    if (*studentsList == NULL) {
        printf("There is no students in the list.Cannot delete.\n");
        return;
    }

    u32 idd;
    printf("Enter the ID of the student you want to delete: ");
    scanf("%d", &idd);

    /* create two poinetrs currentNode and previousNode from userDefineddatatype struct node */
    struct Node* currentNode = *studentsList;
    struct Node* previousNode = NULL; /* Previous node to keep track of the node before current */

    // linked list to find the student to delete
    while (currentNode != NULL) {
        if (currentNode->data.id == idd) {
            //The student to delete is the first node
            if (previousNode == NULL) {

                /* Update the List pointer to skip the current node */
                *studentsList = currentNode->next;
            } else {

                /* Link previous node to the node after current, effectively skipping current */
                previousNode->next = currentNode->next;
            }

            free(currentNode);    /* Free the memory of the current node */
            (*numStudents)--; /* Decrement the number of students*/
            printf("\nStudent with ID %d deleted successfully.\n", idd);
            return;
        }

        /* Move to the next node */
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    printf("\nStudent not found. Cannot delete.\n");
}

void STUDENT_LIST(struct Node* studentsList) {

    /* Check if the linked list is empty or not */
    if (studentsList == NULL) {
        printf("No students in the list .\n");
        return;
    }

    printf("\n===== STUDENT LIST =====\n");

    /* Start from the beginning of the linked list */
    struct Node* currentNode = studentsList;

    /* Go through the linked list and print each student's information */
    while (currentNode != NULL) {
        printf("Name: %s\n", currentNode->data.name);
        printf("ID: %d\n", currentNode->data.id);
        printf("Date of Birth: %s\n", currentNode->data.date_of_Birth);
        printf("Address: %s\n", currentNode->data.address);
        printf("Phone Number: %s\n", currentNode->data.phoneNumber);
        printf("ComputerScienceScore: %.2f\n", currentNode->data.computerScienceScore);
        printf("\n*************************************\n\n");

        currentNode = currentNode->next; /* point to the next node in the linked list */
    }
}

void RANK_STUDENT(struct Node* studentsList) {
    /*check if linked list is empty or not */
    if (studentsList == NULL) {
        printf("\nNo students in the list .\n\n");
        return;
    }

    struct Node* studentArray[MAX_SIZE]; /* Array of pointer to store student in it */
    struct Node* currentNode = studentsList;
    int counter = 0;

    while (currentNode != NULL && counter < MAX_SIZE) {
        studentArray[counter] = currentNode;
        currentNode = currentNode->next;
        counter++;
    }

    /* Sort the array of pointers based on computer science score
     swap function
    */
    for (int i = 0; i < counter - 1; i++) {
        for (int j = 0; j < counter - i - 1; j++) {
            if (studentArray[j]->data.computerScienceScore < studentArray[j + 1]->data.computerScienceScore) {
                struct Node* temp = studentArray[j];
                studentArray[j] = studentArray[j + 1];
                studentArray[j + 1] = temp;
            }
        }
    }

    /* function to display the top  students */
    printf("\n********* TOP STUDENTS **********\n");
    for (int i = 0; i<counter; i++) {
        printf("Rank %d:\n", i + 1);
        printf("Name: %s\n", studentArray[i]->data.name);
        printf("Computer Science Score: %.2f\n", studentArray[i]->data.computerScienceScore);
        printf("\n");
    }
}

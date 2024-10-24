#include "school.h"

int main() {
    // number of attempt = 5
    u32 attempt = 1;
    u32 Max_Number_of_Attempts = 5;
    u32 numberStudents = 0;
    u32 Number_of_attempts = Max_Number_of_Attempts;
    u8 password[]="ahmed";
    u8 userpassword [40];
    struct Node* studentsList = NULL;

    while (Number_of_attempts > 0) {

        for (attempt; attempt <= Max_Number_of_Attempts; attempt++) {
            print();
            printf("Please enter password: ");
            scanf("%s",userpassword);
            fflush(stdin);

            if (strcmp(userpassword, password)== 0){
                MAIN_MENU(&studentsList, &numberStudents);
                break;
            }
            else {
                Number_of_attempts--;
                printf("Invalid password Try again\n\n");
                // printf("Number of attempts left  %d \n\n",Number_of_attempts );

            }

            if (Number_of_attempts == 0) {
                printf("\nAccess is denied\n");
            }
        }

    }


    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int *month;
    int year;
} DOB;


typedef struct {
    int reg_no;
    char *name;
    char address[100];
} STU_INFO;


typedef struct {
    char *college_name;
    char university_name[100];
} COLLEGE;

typedef struct {
    DOB *dob;
    STU_INFO stu_info;
    COLLEGE college;
} STUDENT;

int main() {

    STUDENT *student = (STUDENT *)malloc(sizeof(STUDENT));
    student->dob = (DOB *)malloc(sizeof(DOB));
    student->dob->month = (int *)malloc(sizeof(int));
    student->stu_info.name = (char *)malloc(50 * sizeof(char));
    student->college.college_name = (char *)malloc(50 * sizeof(char));


    printf("Enter day of birth: ");
    scanf("%d", &student->dob->day);
    printf("Enter month of birth: ");
    scanf("%d", student->dob->month);
    printf("Enter year of birth: ");
    scanf("%d", &student->dob->year);


    printf("Enter registration number: ");
    scanf("%d", &student->stu_info.reg_no);
    printf("Enter name: ");
    scanf("%s", student->stu_info.name);
    printf("Enter address: ");
    scanf("%s", student->stu_info.address);


    printf("Enter college name: ");
    scanf("%s", student->college.college_name);
    printf("Enter university name: ");
    scanf("%s", student->college.university_name);


    printf("\nStudent Details:\n");
    printf("DOB: %d-%d-%d\n", student->dob->day, *student->dob->month, student->dob->year);
    printf("Registration Number: %d\n", student->stu_info.reg_no);
    printf("Name: %s\n", student->stu_info.name);
    printf("Address: %s\n", student->stu_info.address);
    printf("College Name: %s\n", student->college.college_name);
    printf("University Name: %s\n", student->college.university_name);

    free(student->dob->month);
    free(student->dob);
    free(student->stu_info.name);
    free(student->college.college_name);
    free(student);

    return 0;
}


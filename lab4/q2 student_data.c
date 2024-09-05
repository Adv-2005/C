#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i,j;
typedef struct {
    char name[50];
    int roll_number;
    float cgpa;
} Student;


Student* readStudent() {
    Student* student = (Student*)malloc(sizeof(Student));
    if (student == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter name: ");
    scanf("%s", student->name);
    printf("Enter roll number: ");
    scanf("%d", &student->roll_number);
    printf("Enter CGPA: ");
    scanf("%f", &student->cgpa);
    return student;
}


void displayStudent(Student* student) {
    if (student == NULL) {
        printf("No student data to display\n");
        return;
    }
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->roll_number);
    printf("CGPA: %.2f\n", student->cgpa);
}


void sortStudents(Student** students, int n) {
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - 1 - i; j++) {
            if (students[j]->roll_number > students[j + 1]->roll_number) {
                Student* temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);


    Student** students = (Student**)malloc(n * sizeof(Student*));
    if (students == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for ( i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        students[i] = readStudent();
    }


    printf("\nStudent data before sorting:\n");
    for ( i = 0; i < n; i++) {
        displayStudent(students[i]);
    }


    sortStudents(students, n);


    printf("\nStudent data after sorting by roll number:\n");
    for ( i = 0; i < n; i++) {
        displayStudent(students[i]);
    }


    for ( i = 0; i < n; i++) {
        free(students[i]);
    }
    free(students);

    return 0;
}


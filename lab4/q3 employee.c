#include <stdio.h>
#include <stdlib.h>
int i;

typedef struct {
    int day;
    int month;
    int year;
} DateOfBirth;


typedef struct {
    int house_number;
    int zip_code;
    char state[50];
} Address;


typedef struct {
    char name[50];
    DateOfBirth dob;
    Address address;
} Employee;


Employee* readEmployee() {
    Employee* emp = (Employee*)malloc(sizeof(Employee));
    if (emp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter name: ");
    scanf("%s", emp->name);
    printf("Enter date of birth (day month year): ");
    scanf("%d %d %d", &emp->dob.day, &emp->dob.month, &emp->dob.year);
    printf("Enter house number: ");
    scanf("%d", &emp->address.house_number);
    printf("Enter zip code: ");
    scanf("%d", &emp->address.zip_code);
    printf("Enter state: ");
    scanf("%s", emp->address.state);
    return emp;
}

void displayEmployee(Employee* emp) {
    if (emp == NULL) {
        printf("No employee data to display\n");
        return;
    }
    printf("Name: %s\n", emp->name);
    printf("Date of Birth: %02d/%02d/%04d\n", emp->dob.day, emp->dob.month, emp->dob.year);
    printf("Address: %d, %d, %s\n", emp->address.house_number,emp->address.state, emp->address.zip_code );
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);


    Employee** employees = (Employee**)malloc(n * sizeof(Employee*));
    if (employees == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }


    for ( i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        employees[i] = readEmployee();
    }

    printf("\nEmployee data:\n");
    for ( i = 0; i < n; i++) {
        displayEmployee(employees[i]);
    }


    for ( i = 0; i < n; i++) {
        free(employees[i]);
    }
    free(employees);

    return 0;
}


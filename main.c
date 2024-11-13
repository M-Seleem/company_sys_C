#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char f_name[15];
    char l_name[15];
    char dep[20];
    float salary;
    int manager_id;
} Employee;

typedef struct {
    Employee employee;
    int teamSize;
} Manager;

void addEmployee(Employee employees[], int *empCount, const Manager managers[], int mgrCount);
void addManager(Manager managers[], int *mgrCount);
void editEmployee(Employee employees[], int empCount);
void editManager(Manager managers[], int mgrCount);
void displayEmployees(const Employee employees[], int empCount);
void displayManagers(const Manager managers[], int mgrCount);
void searchEmployee(const Employee employees[], int empCount);
void searchManager(const Manager managers[], int mgrCount);
void deleteEmployee(Employee employees[], int *empCount);
void deleteManager(Manager managers[], int *mgrCount);
void displayEmployeesUnderManager(const Employee employees[], int empCount, const Manager managers[], int mgrCount);



int main() {
    Employee employees[100]; // Array n5azen feh employee info
    Manager managers[50]; // Array n5azen feh manager info
    int empCount = 0; // 3dd el emp el 7aly
    int mgrCount = 0; // 3dd el mangers el 7aly
    int choice;

    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Add Manager\n");
        printf("3. Edit Employee\n");
        printf("4. Edit Manager\n");
        printf("5. Display Employees\n");
        printf("6. Display Managers\n");
        printf("7. Search Employee\n");
        printf("8. Search Manager\n");
        printf("9. Delete Employee\n");
        printf("10. Delete Manager\n");
        printf("11. Display Employees Under Manager\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &empCount, managers, mgrCount);
                break;
            case 2:
                addManager(managers, &mgrCount);
                break;
            case 3:
                editEmployee(employees, empCount);
                break;
            case 4:
                editManager(managers, mgrCount);
                break;
            case 5:
                displayEmployees(employees, empCount);
                break;
            case 6:
                displayManagers(managers, mgrCount);
                break;
            case 7:
                searchEmployee(employees, empCount);
                break;
            case 8:
                searchManager(managers, mgrCount);
                break;
            case 9:
                deleteEmployee(employees, &empCount);
                break;
            case 10:
                deleteManager(managers, &mgrCount);
                break;
            case 11:
                displayEmployeesUnderManager(employees, empCount, managers, mgrCount);
                break;
            case 12:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addEmployee(Employee employees[], int *empCount, const Manager managers[], int mgrCount) {
    int manager_id;
    char dep[20];


    printf("Enter Employee ID: ");
    scanf("%d", &employees[*empCount].id);
    printf("Enter Employee First Name: ");
    scanf("%s", employees[*empCount].f_name);
    printf("Enter Employee Last Name: ");
    scanf("%s", employees[*empCount].l_name);
    printf("Enter Employee Department: ");
    scanf("%s", employees[*empCount].dep);
    printf("Enter Employee Salary: ");
    scanf("%f", &employees[*empCount].salary);

    printf("Enter Manager ID: "); // 3ashan ne3raf anhy manger 3aleeh
    scanf("%d", &employees[*empCount].manager_id);

     for (int i = 0; i < mgrCount; i++) {
        if (managers[i].employee.id == manager_id) {
            if (strcmp(managers[i].employee.dep, dep) == 0) {
                // Manager exists and department matches
                employees[*empCount].manager_id = manager_id;
                strcpy(employees[*empCount].dep, dep);
                (*empCount)++;
                printf("Employee added successfully!\n");
                return;
            } else {
                printf("The employee's department does not match the manager's department!\n");
                return;
            }
        }
    }
    printf("Manager with ID %d not found!\n", manager_id);
}

void addManager(Manager managers[], int *mgrCount) {
    char department[20];
    printf("Enter Manager Department: ");
    scanf("%s", department);

    // check en manger wa7ed l kol dep
    for (int i = 0; i < *mgrCount; i++) {
        if (strcmp(managers[i].employee.dep, department) == 0) {
            printf("A manager for the department %s already exists!\n", department);
            return;
        }
    }

    printf("Enter Manager ID: ");
    scanf("%d", &managers[*mgrCount].employee.id);
    printf("Enter Manager First Name: ");
    scanf("%s", managers[*mgrCount].employee.f_name);
    printf("Enter Manager Last Name: ");
    scanf("%s", managers[*mgrCount].employee.l_name);
    printf("Enter Manager Salary: ");
    scanf("%f", &managers[*mgrCount].employee.salary);
    printf("Enter Team Size: ");
    scanf("%d", &managers[*mgrCount].teamSize);

    // Copy the department to the manager's structure
    strcpy(managers[*mgrCount].employee.dep, department);

    (*mgrCount)++;
    printf("Manager added successfully!\n");
}

void editEmployee(Employee employees[], int empCount) {
    int id, i;
    printf("Enter Employee ID to edit: ");
    scanf("%d", &id);

    for (i = 0; i < empCount; i++) {
        if (employees[i].id == id) {
            printf("Enter new Employee First Name: ");
            scanf("%s", employees[i].f_name);
            printf("Enter new Employee Last Name: ");
            scanf("%s", employees[i].l_name);
            printf("Enter new Employee Department: ");
            scanf("%s", employees[i].dep);
            printf("Enter new Employee Salary: ");
            scanf("%f", &employees[i].salary);

            printf("Enter new Manager ID: ");
            scanf("%d", &employees[i].manager_id);

            printf("Employee edited successfully!\n");
            return;
        }
    }
    printf("Employee with ID %d not found!\n", id);
}

void editManager(Manager managers[], int mgrCount) {
    int id, i;
    printf("Enter Manager ID to edit: ");
    scanf("%d", &id);

    for (i = 0; i < mgrCount; i++) {
        if (managers[i].employee.id == id) {
            printf("Enter new Manager First Name: ");
            scanf("%s", managers[i].employee.f_name);
            printf("Enter new Manager Last Name: ");
            scanf("%s", managers[i].employee.l_name);
            printf("Enter new Manager Department: ");
            scanf("%s", managers[i].employee.dep);
            printf("Enter new Manager Salary: ");
            scanf("%f", &managers[i].employee.salary);
            printf("Enter new Team Size: ");
            scanf("%d", &managers[i].teamSize);
            printf("Enter new Department: ");
            printf("Manager edited successfully!\n");
            return;
        }
    }
    printf("Manager with ID %d not found!\n", id);
}

void displayEmployees(const Employee employees[], int empCount) {
    int i;
    if (empCount == 0) {
        printf("No employees to display!\n");
        return;
    }

    printf("\nEmployee List:\n");
    for (i = 0; i < empCount; i++) {
        printf("ID: %d\n", employees[i].id);
        printf("First Name: %s\n", employees[i].f_name);
        printf("Last Name: %s\n", employees[i].l_name);
        printf("Department: %s\n", employees[i].dep);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("Manager ID: %d\n", employees[i].manager_id);

        printf("--------------------------\n");
    }
}

void displayManagers(const Manager managers[], int mgrCount) {
    int i;
    if (mgrCount == 0) {
        printf("No managers to display!\n");
        return;
    }

    printf("\nManager List:\n");
    for (i = 0; i < mgrCount; i++) {
        printf("ID: %d\n", managers[i].employee.id);
        printf("First Name: %s\n", managers[i].employee.f_name);
        printf("Last Name: %s\n", managers[i].employee.l_name);
        printf("Department: %s\n", managers[i].employee.dep);
        printf("Salary: %.2f\n", managers[i].employee.salary);
        printf("Team Size: %d\n", managers[i].teamSize);
        printf("--------------------------\n");
    }
}

void searchEmployee(const Employee employees[], int empCount) {
    int id, i;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < empCount; i++) {
        if (employees[i].id == id) {
            printf("\nEmployee Found:\n");
            printf("ID: %d\n", employees[i].id);
            printf("First Name: %s\n", employees[i].f_name);
            printf("Last Name: %s\n", employees[i].l_name);
            printf("Department: %s\n", employees[i].dep);
            printf("Salary: %.2f\n", employees[i].salary);
            printf("Manager ID: %d\n", employees[i].manager_id);

            printf("--------------------------\n");
            return;
        }
    }
    printf("Employee with ID %d not found!\n", id);
}

void searchManager(const Manager managers[], int mgrCount) {
    int id, i;
    printf("Enter Manager ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < mgrCount; i++) {
        if (managers[i].employee.id == id) {
            printf("\nManager Found:\n");
            printf("ID: %d\n", managers[i].employee.id);
            printf("First Name: %s\n", managers[i].employee.f_name);
            printf("Last Name: %s\n", managers[i].employee.l_name);
            printf("Department: %s\n", managers[i].employee.dep);
            printf("Salary: %.2f\n", managers[i].employee.salary);
            printf("Team Size: %d\n", managers[i].teamSize);
            printf("--------------------------\n");
            return;
        }
    }
    printf("Manager with ID %d not found!\n", id);
}

void deleteEmployee(Employee employees[], int *empCount) {
    int id, i, j;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < *empCount; i++) {
        if (employees[i].id == id) {
            for (j = i; j < *empCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            (*empCount)--;
            printf("Employee deleted successfully!\n");
            return;
        }
    }
    printf("Employee with ID %d not found!\n", id);
}

void deleteManager(Manager managers[], int *mgrCount) {
    int id, i, j;
    printf("Enter Manager ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < *mgrCount; i++) {
        if (managers[i].employee.id == id) {
            for (j = i; j < *mgrCount - 1; j++) {
                managers[j] = managers[j + 1];
            }
            (*mgrCount)--;
            printf("Manager deleted successfully!\n");
            return;
        }
    }
    printf("Manager with ID %d not found!\n", id);
}

void displayEmployeesUnderManager(const Employee employees[], int empCount, const Manager managers[], int mgrCount) {
    int id, i, found = 0;
    printf("Enter Manager ID: ");
    scanf("%d", &id);

    for (i = 0; i < mgrCount; i++) {
        if (managers[i].employee.id == id) {
            printf("\nEmployees under Manager ID %d (%s %s):\n", id, managers[i].employee.f_name, managers[i].employee.l_name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Manager with ID %d not found!\n", id);
        return;
    }

    found = 0;

    for (i = 0; i < empCount; i++) {
        if (employees[i].manager_id == id) {
            printf("ID: %d\n", employees[i].id);
            printf("First Name: %s\n", employees[i].f_name);
            printf("Last Name: %s\n", employees[i].l_name);
            printf("Department: %s\n", employees[i].dep);
            printf("Salary: %.2f\n", employees[i].salary);
            printf("--------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No employees found under Manager ID %d\n", id);
    }
}

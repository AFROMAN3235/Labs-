#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int studentID;
    char name[50];
    char group[10];
    double score;
};

void printStudents(struct Student *students, int size) {
    printf("List of students:\n");
    for (int i = 0; i < size; i++) {
        printf("Student ID: %d\n", students[i].studentID);
        printf("Name: %s\n", students[i].name);
        printf("Group: %s\n", students[i].group);
        printf("Score: %f\n\n", students[i].score);
    }
}

int main() {
    struct Student *students = NULL;
    int size = 0;

    char choice = ' ';

    do {
        printf("Choose an option:\n");
        printf("1. Add a new student\n");
        printf("2. Delete students with a score lower than 1\n");
        printf("3. Print the list of students\n");
        printf("4. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': {
                size++;
                students = (struct Student*)realloc(students, size * sizeof(struct Student));
                printf("Enter student ID: ");
                scanf("%d", &students[size - 1].studentID);
                printf("Enter student name: ");
                scanf(" %[^\n]", students[size - 1].name);
                printf("Enter student group: ");
                scanf(" %s", students[size - 1].group);
                printf("Enter student score: ");
                scanf("%lf", &students[size - 1].score);
                printf("Student added successfully.\n");
                break;
            }
            case '2': {
                int count = 0;
                for (int i = 0; i < size; i++) {
                    if (students[i].score < 1.0) {
                        count++;
                    }
                }

                if (count > 0) {
                    struct Student *newList = (struct Student*)malloc((size - count) * sizeof(struct Student));
                    if (newList == NULL) {
                        fprintf(stderr, "Memory allocation error\n");
                        exit(1);
                    }
                    int j = 0;
                    for (int i = 0; i < size; i++) {
                        if (students[i].score >= 1.0) {
                            newList[j] = students[i];
                            j++;
                        }
                    }
                    free(students);
                    students = newList;
                    size -= count;
                    printf("Students with a score lower than 1 removed.\n");
                } else {
                    printf("No students with a score lower than 1 found.\n");
                }
                break;
            }
            case '3':
                printStudents(students, size);
                break;
            case '4':
                printf("Exiting program.\n");
                free(students);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '4');

    return 0;
}

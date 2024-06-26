#include <stdlib.h>
#include <string.h>
#include "myhead.h"


// Comparison function for qsort
int compareStudents(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    return strcmp(studentA->sid, studentB->sid);
}

// Comparison function by name
int compareStudentsByName(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    return strcmp(studentA->name, studentB->name);
}

// Comparison function by department for SRecord
int compareSRecordsByDepartment(const void* a, const void* b) {
    SRecord* srecordA = (SRecord*)a;
    SRecord* srecordB = (SRecord*)b;
    return strcmp(srecordA->student.department, srecordB->student.department);
}

// Comparison function by rawScore for SRecord
int compareSRecordsByrawScore(const void* a, const void* b) {
    SRecord* srecordA = (SRecord*)a;
    SRecord* srecordB = (SRecord*)b;
    if (srecordA->rawScore < srecordB->rawScore) return -1;
    if (srecordA->rawScore > srecordB->rawScore) return 1;
    return 0;
}
// Comparison function by SID for SRecord
int compareSRecordsBySID(const void* a, const void* b) {
    SRecord* srecordA = (SRecord*)a;
    SRecord* srecordB = (SRecord*)b;
    return strcmp(srecordA->student.sid, srecordB->student.sid);
}

void sortStudents(Student* students, int numStudents, const char* sortBy) {
    if (strcmp(sortBy, "sid") == 0) {
        qsort(students, numStudents, sizeof(Student), compareStudents);
    } else if (strcmp(sortBy, "name") == 0) {
        qsort(students, numStudents, sizeof(Student), compareStudentsByName);
    } else {
        // Handle invalid sortBy parameter
        // You can throw an error, print a message, or take any other appropriate action
    }
}

void printarray(SRecord* srecords , int numStudents) {
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-14s | %-8s | %-10s | %-5s | %-5s | %-7s | %-5s | %-5s | %-5s |\n", "Name", "Department", "Grade", "SID", "HW", "Quiz", "Midterm", "Final", "Other", "rawScore");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    resetColor();
    for (int i = 0; i < numStudents; i++) {
       if(srecords[i].rawScore < 60) {
            printf("| %-15s    | %-14s   | %-8d | %-10s | %-5.1f | %-5.1f | %-7.1f | %-5.1f | %-5.1f ", srecords[i].student.name, srecords[i].student.department, srecords[i].student.grade, srecords[i].student.sid, srecords[i].homework, srecords[i].quiz, srecords[i].midterm, srecords[i].final, srecords[i].other);
            setColor(RED);
            printf("| %-8.1f |\n", srecords[i].rawScore);
            resetColor();
       }else{
            printf("| %-15s    | %-14s   | %-8d | %-10s | %-5.1f | %-5.1f | %-7.1f | %-5.1f | %-5.1f | %-8.1f |\n", srecords[i].student.name, srecords[i].student.department, srecords[i].student.grade, srecords[i].student.sid, srecords[i].homework, srecords[i].quiz, srecords[i].midterm, srecords[i].final, srecords[i].other, srecords[i].rawScore);
       
       }
    }
     printf("-----------------------------------------------------------------------------------------------------------------\n");
}

void sortSRecords(SRecord* srecords, int numSRecords, const char* sortBy) {
    if (strcmp(sortBy, "department") == 0) {
        qsort(srecords, numSRecords, sizeof(SRecord), compareSRecordsByDepartment);
    } else if (strcmp(sortBy, "rawScore") == 0) {
        qsort(srecords, numSRecords, sizeof(SRecord), compareSRecordsByrawScore);
    } else if (strcmp(sortBy, "sid") == 0) {
        qsort(srecords, numSRecords, sizeof(SRecord), compareSRecordsBySID);
    } else {
        // Handle invalid sortBy parameter
        // You can throw an error, print a message, or take any other appropriate action
    }
}

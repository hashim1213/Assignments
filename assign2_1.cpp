#include <iostream>
#include <string>
#include <simplecpp>

struct Student {
    int studentId;
    string studentName;
    int studentAge;
    float studentGrade;
};

void inputStudentDetails(Student& student) {
    cout << "Enter student ID: ";
    cin >> student.studentId;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, student.studentName);
    cout << "Enter student age: ";
    cin >> student.studentAge;
    cout << "Enter student grade: ";
    cin >> student.studentGrade;
}

void displayStudentDetails(const Student& student) {
    cout << "Student ID: " << student.studentId << endl;
    cout << "Student Name: " << student.studentName << endl;
    cout << "Student Age: " << student.studentAge << endl;
    cout << "Student Grade: " << student.studentGrade << endl;
}

float calculateAverageGrade(const Student students[], int numStudents) {
    float totalGrade = 0;
    for (int i = 0; i < numStudents; i++) {
        totalGrade += students[i].studentGrade;
    }
    return totalGrade / numStudents;
}

void searchStudentById(const Student students[], int numStudents, int studentId) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].studentId == studentId) {
            displayStudentDetails(students[i]);
            return;
        }
    }
    cout << "Student with ID " << studentId << " not found." << endl;
}

main_program {
    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int numStudents = 0;

    // Input student details
    cout << "Enter the number of students: ";
    cin >> numStudents;
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter details for student " << i + 1 << ":" << endl;
        inputStudentDetails(students[i]);
    }

    // Display student details
    cout << "Student details:" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        displayStudentDetails(students[i]);
        cout << endl;
    }

    // Calculate and display average grade
    float averageGrade = calculateAverageGrade(students, numStudents);
    cout << "Average grade: " << averageGrade << endl;

    // Search for a student by ID
    int searchId;
    cout << "Enter student ID to search: ";
    cin >> searchId;
    searchStudentById(students, numStudents, searchId);

    return 0;
}
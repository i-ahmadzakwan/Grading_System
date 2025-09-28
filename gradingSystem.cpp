#include <iostream>
using namespace std;

class Course {
public:
    string courseName;

    // Maximum marks
    int maxAssignment = 30;
    int maxQuiz = 30;
    int maxExam = 50;

    // Obtained marks
    float assignmentMarks;
    float quizMarks;
    float examMarks;

    // Weightages
    int weightAssignment = 25;
    int weightQuiz = 25;
    int weightExam = 50;

    // Results
    double totalScore;
    char gradeObtained;

    void calculateGrade() {
        double assignmentTotal = (assignmentMarks / maxAssignment) * weightAssignment;
        double quizTotal       = (quizMarks / maxQuiz) * weightQuiz;
        double examTotal       = (examMarks / maxExam) * weightExam;

        totalScore = assignmentTotal + quizTotal + examTotal;

        if (totalScore >= 75) {
            gradeObtained = 'A';
        }
        else if (totalScore >= 65) {
            gradeObtained = 'B';
        }
        else {
            gradeObtained = 'F';
        }
    }
};

class Student {
public:
    string name;
    int id;
    Course courses[3];   // Each student can take 3 courses

    void getInfo() {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter student ID: ";
        cin >> id;

        for (int i = 0; i < 3; i++) {
            cout << "\n--- Enter details for Course " << i + 1 << " ---\n";

            cout << "Course name: ";
            cin >> courses[i].courseName;

            cout << "Assignment marks (out of 30): ";
            cin >> courses[i].assignmentMarks;

            cout << "Quiz marks (out of 30): ";
            cin >> courses[i].quizMarks;

            cout << "Exam marks (out of 50): ";
            cin >> courses[i].examMarks;

            courses[i].calculateGrade(); // calculate grade for this course
        }
    }

    void display() {
        cout << "\n--- Student Information ---\n";
        cout << "Name : " << name << endl;
        cout << "ID   : " << id << endl;

        for (int i = 0; i < 3; i++) {
            cout << "\nCourse " << i + 1 << ": " << courses[i].courseName << endl;
            cout << "  Assignment : " << courses[i].assignmentMarks << " / " << courses[i].maxAssignment << endl;
            cout << "  Quiz       : " << courses[i].quizMarks << " / " << courses[i].maxQuiz << endl;
            cout << "  Exam       : " << courses[i].examMarks << " / " << courses[i].maxExam << endl;
            cout << "  Total      : " << courses[i].totalScore << " %" << endl;
            cout << "  Grade      : " << courses[i].gradeObtained << endl;
        }
    }
};

int main() {
    int totalStudents;
    cout << "Enter total number of students: ";
    cin >> totalStudents;

    Student* s = new Student[totalStudents];

    for (int i = 0; i < totalStudents; i++) {
        cout << "\n=== Enter Information for Student " << i + 1 << " ===\n";
        s[i].getInfo();
    }

    for (int i = 0; i < totalStudents; i++) {
        cout << "\n=== Details of Student " << i + 1 << " ===";
        s[i].display();
    }

    delete[] s; // Free allocated memory
    return 0;
}

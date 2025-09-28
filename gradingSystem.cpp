
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
    Course c;

    void getInfo() {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter student ID: ";
        cin >> id;

        cout << "Enter course name: ";
        cin >> c.courseName;

        cout << "Enter assignment marks (out of 30): ";
        cin >> c.assignmentMarks;

        cout << "Enter quiz marks (out of 30): ";
        cin >> c.quizMarks;

        cout << "Enter exam marks (out of 50): ";
        cin >> c.examMarks;

        c.calculateGrade(); // calculate grade
    }

    void display() {
        cout << "\n--- Student Information ---\n";
        cout << "Name          : " << name << endl;
        cout << "ID            : " << id << endl;
        cout << "Course        : " << c.courseName << endl;
        cout << "Assignment    : " << c.assignmentMarks << " / " << c.maxAssignment << endl;
        cout << "Quiz          : " << c.quizMarks << " / " << c.maxQuiz << endl;
        cout << "Exam          : " << c.examMarks << " / " << c.maxExam << endl;
        cout << "Total Score   : " << c.totalScore << " %" << endl;
        cout << "Final Grade   : " << c.gradeObtained << endl;
    }
};

int main() {
    int totalStudents;
    cout << "Enter total number of students: ";
    cin >> totalStudents;

    Student* s = new Student[totalStudents];

    for (int i = 0; i < totalStudents; i++) {
        cout << "\n--- Enter Information for Student " << i + 1 << " ---\n";
        s[i].getInfo();
    }

    for (int i = 0; i < totalStudents; i++) {
        cout << "\n=== Details of Student " << i + 1 << " ===";
        s[i].display();
    }

    delete[] s; // free memory
    return 0;
}

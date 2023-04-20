#ifndef LAB1_H
#define LAB1_H

#include <iostream>
#include <string>

#define INIT_STUDENT_COUNT 100

class Semester{
private:
    int _assignment;
    int _test;
    int _exam;
public:
    Semester(int assignment, int test, int exam) : _assignment(assignment), _test(test), _exam(exam){}
};

class Student{
protected:
    std::string Name;
    std::string DateOfBirth;
    std::string SchoolName;
    std::string CourseName;
    int Score;
    
public:
    Student(std::string name = "", int score = 0, std::string dateOfBirth = "", std::string schoolName = "", std::string courseName = "");
    void SetName(std::string name);
    void SetScore(int score);
    std::string GetName();
    int GetScore();
    std::string GetDateOfBirth();
    std::string GetSchoolName();
    std::string GetCourseName();
};

class UniStudent : public Student{
private: 
    Semester **_semesters;
    const int NumSemester = 8;
    const int NumAssignment = 3;
    const int NumTest = 2;
    const int NumExam = 1;

public:
    UniStudent(std::string name, int score, std::string dateOfBirth = "", std::string schoolName = "", std::string courseName = ""): 
    Student(name, score, dateOfBirth, schoolName, courseName){
        _semesters = new Semester*[NumSemester];
        for(int i = 0 ; i < NumSemester; i++){
            Semester * semester = new Semester(NumAssignment, NumTest, NumExam);
            _semesters[i] = semester;
        }
    }

};

class CollegeStudent : public Student{
private: 
    Semester **_semesters;
    const int NumSemester = 4;
    const int NumAssignment = 1;
    const int NumTest = 1;
    const int NumExam = 1;

public:
    CollegeStudent(std::string name, int score, std::string dateOfBirth = "", std::string schoolName = "", std::string courseName = ""): 
    Student(name, score, dateOfBirth, schoolName, courseName){
        _semesters = new Semester*[NumSemester];
        for(int i = 0 ; i < NumSemester; i++){
            Semester * semester = new Semester(NumAssignment, NumTest, NumExam);
            _semesters[i] = semester;
        }
    }

};

class StudentManagementSystem {
private:
    Student **_studentsList;
    int _numStudents;
    int _maxStudents;

private:
    void CreateStudent(std::string universityName);
    
public:
    StudentManagementSystem(int maxStudents = INIT_STUDENT_COUNT);
    ~StudentManagementSystem();

    void AddStudent(std::string universityName);
    void DisplayStudents();
    void RemoveStudent();
    void DisplayBestStudents();
};

class School{
protected:
    std::string SchoolName;
    StudentManagementSystem Sms;

public:
    School(std::string schoolName, int maxStudents): SchoolName{schoolName} {
        Sms = StudentManagementSystem(maxStudents);
    }

    void AddStudent() {
        Sms.AddStudent(SchoolName);
    }

    void DisplayStudents() {
        Sms.DisplayStudents();
    }

    void RemoveStudent() {
        Sms.RemoveStudent();
    }

    void DisplayBestStudents() {
        Sms.DisplayBestStudents();
    }
};

class University: public School {
private:

public:
    University(std::string name, int maxStudents = INIT_STUDENT_COUNT) : School(name, maxStudents) {}
};

#endif // LAB1_H

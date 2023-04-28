#ifndef LAB1_H
#define LAB1_H

#include <iostream>
#include <string>

#define INIT_STUDENT_COUNT 100

class Semester{
public:
    int *Assignments;
    int *Tests;
    int *Exams;

    int AssignmentCount;
    int TestCount;
    int ExamCount;
public:
    Semester(int assignment, int test, int exam): AssignmentCount{assignment}, TestCount{test}, ExamCount{exam}{
        Assignments = new int[AssignmentCount];
        Tests = new int[TestCount];
        Exams = new int[ExamCount];

        for (size_t i = 0; i < AssignmentCount; i++)
        {
            Assignments[i] = 0;
        }

        for (size_t i = 0; i < TestCount; i++)
        {
            Tests[i] = 0;
        }

        for (size_t i = 0; i < ExamCount; i++)
        {
            Exams[i] = 0;
        }
    }
    
    int GetTotalScore(){
        int total = 0;
        for (size_t i = 0; i < AssignmentCount; i++)
        {
            total += Assignments[i];
        }

        for (size_t i = 0; i < TestCount; i++)
        {
            total += Tests[i];
        }

        for (size_t i = 0; i < ExamCount; i++)
        {
            total += Exams[i];
        }
        
        return total;
    }

    void DisplayScores(){
        std::cout <<"\tAssignment Score: ";
        for (size_t i = 0; i < AssignmentCount; i++)
        {
            std::cout<<Assignments[i] <<", ";
        }

        std::cout <<"\n\tTest Score: ";
        for (size_t i = 0; i < TestCount; i++)
        {
            std::cout<<Tests[i] <<", ";
        }

        std::cout <<"\n\tExam Score: ";
        for (size_t i = 0; i < ExamCount; i++)
        {
            std::cout<<Exams[i] <<", ";
        }

        std::cout <<"\n\tTotal Semester Score: "<< GetTotalScore() << "\n";
    }

    ~Semester(){
        delete [] Assignments;
        delete [] Tests;
        delete [] Exams;
    }
};

class Student{
protected:
    int Score;
    std::string Name = "";
    std::string DateOfBirth = "";
    std::string SchoolName = "";
    std::string CourseName = "";
    
    
public:
    Student(std::string name = "", int score = 0, std::string dateOfBirth = "", std::string schoolName = "", std::string courseName = "");
    void SetName(std::string name);
    void SetScore(int score);
    std::string GetName();
    std::string GetDateOfBirth();
    std::string GetSchoolName();
    std::string GetCourseName();

    int GetRandomScore(){
        return rand() % 11; // score from 0-10
    }

    virtual int GetScore(){return Score;}
    virtual void DoAssignment(){}
    virtual void TakeTest(){}
    virtual void TakeExam(){}
    virtual void DisplayScore(){}
    
};

class UniStudent : public Student{
private: 
    Semester **_semesters;
    const int NumSemester = 8;
    const int NumAssignment = 3;
    const int NumTest = 2;
    const int NumExam = 1;

public:
    UniStudent(std::string name = "", int score = 0, std::string dateOfBirth = "", std::string schoolName = "", std::string courseName = ""): 
    Student(name, score, dateOfBirth, schoolName, courseName){
        _semesters = new Semester*[NumSemester];
        for(int i = 0 ; i < NumSemester; i++){
            Semester * semester = new Semester(NumAssignment, NumTest, NumExam);
            _semesters[i] = semester;
        }
    }
    
    int GetScore() override {
        int total = 0;
        for(int i = 0; i < NumSemester; i++) {
            total += _semesters[i]->GetTotalScore();
        }
        return total;
    }

    void DoAssignment() override {
        for(int i = 0; i < NumSemester; i++) {
            for(int j = 0; j < NumAssignment; j++) {
                _semesters[i]->Assignments[j] = GetRandomScore(); 
            }
        }
        Score = GetScore();
    }

    void TakeTest() override {
        for(int i = 0; i < NumSemester; i++) {
            for(int j = 0; j < NumAssignment; j++) {
                _semesters[i]->Tests[j] = GetRandomScore(); 
            }
        }
        Score = GetScore();
    }

    void TakeExam() override {
        for(int i = 0; i < NumSemester; i++) {
            for(int j = 0; j < NumAssignment; j++) {
                _semesters[i]->Exams[j] = GetRandomScore(); 
            }
        }
        Score = GetScore();
    }

    void DisplayScore() override {
        for(int i = 0; i < NumSemester; i++) {
            std::cout<<"Semester "<< i+1 <<":\n";
            _semesters[i]->DisplayScores();
        }
        std::cout<<"Total Score: "<< Score <<":\n";
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

    int GetScore() override {
        int total = 0;
        for(int i = 0; i < NumSemester; i++) {
            total += _semesters[i]->GetTotalScore();
        }
        return total;
    }

    void DoAssignment() override {
        for(int i = 0; i < NumSemester; i++) {
            for(int j = 0; j < NumAssignment; j++) {
                _semesters[i]->Assignments[j] = GetRandomScore(); 
            }
        }
        Score = GetScore();
    }

    void TakeTest() override {
        for(int i = 0; i < NumSemester; i++) {
            for(int j = 0; j < NumAssignment; j++) {
                _semesters[i]->Tests[j] = GetRandomScore(); 
            }
        }
        Score = GetScore();
    }

    void TakeExam() override {
        for(int i = 0; i < NumSemester; i++) {
            for(int j = 0; j < NumAssignment; j++) {
                _semesters[i]->Exams[j] = GetRandomScore(); 
            }
        }
        Score = GetScore();
    }

    void DisplayScore() override {
        for(int i = 0; i < NumSemester; i++) {
            std::cout<<"Semester "<< i+1 <<":\n";
            _semesters[i]->DisplayScores();
        }
        std::cout<<"Total Score: "<< Score <<":\n";
    }
};

template <class T>
class StudentManagementSystem {
private:
    T **_studentsList;
    int _numStudents = 0;
    int _maxStudents = 0;

private:
    void CreateStudent(std::string universityName);
    
public:
    StudentManagementSystem(int maxStudents = INIT_STUDENT_COUNT);
    ~StudentManagementSystem();

    void AddStudent(std::string universityName);
    void DisplayStudents();
    void RemoveStudent();
    void DisplayBestStudents();

    void DoAssignment(){
        for(int i = 0; i < _numStudents; i++){
            _studentsList[i]->DoAssignment();
        }
    }

    void TakeTest(){
        for(int i = 0; i < _numStudents; i++){
            _studentsList[i]->TakeTest();
        }
    }

    void TakeExam(){
        for(int i = 0; i < _numStudents; i++){
            _studentsList[i]->TakeExam();
        }
    }
};

template <class T>
class School{
protected:
    std::string SchoolName;
    StudentManagementSystem<T> Sms;

public:
    School(std::string schoolName, int maxStudents): SchoolName{schoolName} {
        Sms = StudentManagementSystem<T>(maxStudents);
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

    void DoAssignment(){
        Sms.DoAssignment();
    }

    void TakeTest(){
        Sms.TakeTest();
    }

    void TakeExam(){
        Sms.TakeExam();
    }
};

#endif // LAB1_H

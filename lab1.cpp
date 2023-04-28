#include "lab1.h"


Student::Student(std::string name, int score, std::string dateOfBirth, std::string schoolName, std::string courseName): 
    Name{name}, Score{score}, DateOfBirth{dateOfBirth}, SchoolName{schoolName}, CourseName{courseName}
{

}

void Student::SetName(std::string name) {
    this->Name = name;
}

void Student::SetScore(int score) {
    this->Score = score;
}

std::string Student::GetName() {
    return this->Name;
}

std::string Student::GetDateOfBirth() {
    return this->DateOfBirth;
}

std::string Student::GetSchoolName() {
    return this->SchoolName;
}

std::string Student::GetCourseName() {
    return this->CourseName;
}

// Constructor for the StudentManagementSystem class
template <class T>
StudentManagementSystem<T>::StudentManagementSystem(int maxStudents) {
    this->_studentsList = new T*[maxStudents];
    this->_numStudents = 0;
    this->_maxStudents = maxStudents;
}

// Destructor for the StudentManagementSystem class
template <class T>
StudentManagementSystem<T>::~StudentManagementSystem() {
    for(int i = 0 ; i<this->_numStudents; i++){
        delete _studentsList[i];
    }
    delete[] this->_studentsList;
}


template <class T>
void StudentManagementSystem<T>::AddStudent(std::string universityName) {
    // if the array is full, increase its capacity by doubling it
    if (_numStudents >= _maxStudents) {
        _maxStudents *= 2;
    
        T **new_students = new T*[_maxStudents]; 
        for (int i = 0; i < _numStudents; i++) {
            new_students[i] = _studentsList[i];
        }
        delete[] _studentsList;
        _studentsList = new_students;
        
    }

    std::string name = "";
    int score = 0;
    std::string dateOfBirth = ""; 
    std::string courseName = ""; 
    int type = 0;
    
    std::cout << "Enter student name: ";
    std::cin >> name;
    std::cout << "Enter student date of birth: ";
    std::cin >> dateOfBirth;
    std::cout << "Enter student course name: ";
    std::cin >> courseName;

    _studentsList[_numStudents] = new T(name, score, dateOfBirth, universityName, courseName);
    _numStudents++;

    std::cout << "Student added successfully." << std::endl;
}


template <class T>
void StudentManagementSystem<T>::DisplayStudents() {
    if (_numStudents == 0) {
        std::cout << "No students found!" << std::endl;
        return;
    }

    std::cout << "List of students:" << std::endl;
    for (int i = 0; i < _numStudents; i++) {
        std::cout << i + 1 << ": " << _studentsList[i]->GetName() << " (date of birth: " << _studentsList[i]->GetDateOfBirth() << ")" << " (school name: " << _studentsList[i]->GetSchoolName() << ")"<< " (course name: " << _studentsList[i]->GetCourseName() << ")" << std::endl;
        _studentsList[i]->DisplayScore();
    }
}


template <class T>
void StudentManagementSystem<T>::DisplayBestStudents() {
    if (_numStudents == 0) {
        std::cout << "No students found!" << std::endl;
        return;
    }

    int highest_score = -1;
    for (int i = 0; i < _numStudents; i++) {
        if(highest_score < _studentsList[i]->GetScore()){
            highest_score = _studentsList[i]->GetScore();
        }
    }

    std::cout << "List of Best students:" << std::endl;
    for (int i = 0; i < _numStudents; i++) {
        if(_studentsList[i]->GetScore() == highest_score) {
            std::cout << i + 1 << ": " << _studentsList[i]->GetName() << " (date of birth: " << _studentsList[i]->GetDateOfBirth() << ")" << " (school name: " << _studentsList[i]->GetSchoolName() << ")"<< " (course name: " << _studentsList[i]->GetCourseName() << ")" << std::endl;
            _studentsList[i]->DisplayScore();
        }
    }
}


template <class T>
void StudentManagementSystem<T>::RemoveStudent() {
    if (_numStudents == 0) {
        std::cout << "No students found!" << std::endl;
        return;
    }

    std::string name;
    std::cout << "Enter student name: ";
    std::cin >> name;

    bool found = false;
    for (int i = 0; i < _numStudents; i++) {
        if (_studentsList[i]->GetName() == name) {
            found = true;

            // Remove the student by shifting all the elements after it
            // one position to the left
            for (int j = i; j < _numStudents - 1; j++) {
                _studentsList[j]->SetName(_studentsList[j+1]->GetName());
                _studentsList[j]->SetScore(_studentsList[j+1]->GetScore());
            }

            _numStudents--;

            std::cout << "Student removed successfully." << std::endl;

            break;
        }
    }

    if (!found) {
        std::cout << "Student not found!" << std::endl;
    }
}

int main() {
    School<UniStudent> university("Bach Khoa University", INIT_STUDENT_COUNT);
    School<CollegeStudent> college("Cao Thang Technical College", INIT_STUDENT_COUNT);
    
    while (true) {
        int choice = 0, type = 0;
        while(type < 1 || type > 3){
            std::cout << "Enter student school type (1-2): \n1: Bach Khoa University\n2: Cao Thang Technical College\n3: Quit\n";
            std::cin >> type;

            switch (type)
            {
            case 1:
                std::cout << "Entering Bach Khoa University, Choose an option:" << std::endl;
                break;
            case 2:
                std::cout << "Entering Cao Thang Technical College, Choose an option:" << std::endl;
                break;
            case 3:
                std::cout << "Application Quit!\n";
                return 0;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
            }

        }

        while(choice < 1 || choice > 8){
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Add a student" << std::endl;
        std::cout << "2. Display all students" << std::endl;
        std::cout << "3. Display best students" << std::endl;
        std::cout << "4. Remove a student" << std::endl;
        std::cout << "5. Give Assigment to all students" << std::endl;
        std::cout << "6. Give Test to all students" << std::endl;
        std::cout << "7. Give Exam to all students" << std::endl;
        std::cout << "8. Return choosing school" << std::endl;
        std::cin >> choice;

        switch (type)
        {
            case 1:

                    switch (choice) {
                case 1:
                    university.AddStudent();
                    break;
                case 2:
                    university.DisplayStudents();
                    break;
                case 3:
                    university.DisplayBestStudents();
                    break;
                case 4:
                    university.RemoveStudent();
                    break;
                case 5:
                    university.DoAssignment();
                    break;
                case 6:
                    university.TakeTest();
                    break;
                case 7:
                    university.TakeExam();
                    break;
                case 8:
                    break;
                default:
                    std::cout << "Invalid choice!" << std::endl;
                    break;
                }
            
                break;

            case 2:

                    switch (choice) {
                case 1:
                    college.AddStudent();
                    break;
                case 2:
                    college.DisplayStudents();
                    break;
                case 3:
                    college.DisplayBestStudents();
                    break;
                case 4:
                    college.RemoveStudent();
                    break;
                case 5:
                    college.DoAssignment();
                    break;
                case 6:
                    college.TakeTest();
                    break;
                case 7:
                    college.TakeExam();
                    break;
                case 8:
                    break;
                default:
                    std::cout << "Invalid choice!" << std::endl;
                    break;
                }
            
                break;
            }
        }
        
    }
}
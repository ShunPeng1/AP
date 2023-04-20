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

int Student::GetScore() {
    return this->Score;
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
StudentManagementSystem::StudentManagementSystem(int maxStudents) {
    this->_studentsList = new Student*[maxStudents];
    this->_numStudents = 0;
    this->_maxStudents = maxStudents;
}

// Destructor for the StudentManagementSystem class
StudentManagementSystem::~StudentManagementSystem() {
    for(int i = 0 ; i<this->_numStudents; i++){
        delete _studentsList[i];
    }
    delete[] this->_studentsList;
}


void StudentManagementSystem::AddStudent(std::string universityName) {
    // if the array is full, increase its capacity by doubling it
    if (_numStudents >= _maxStudents) {
        _maxStudents *= 2;
    
        Student **new_students = new Student*[_maxStudents]; 
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
    std::cout << "Enter student score: ";
    std::cin >> score;
    std::cout << "Enter student date of birth: ";
    std::cin >> dateOfBirth;
    std::cout << "Enter student school type (1-2): \n1: University\n2: College\n";
    std::cin >> type;
    std::cout << "Enter student course name: ";
    std::cin >> courseName;


    Student *new_student;
    switch (type)
    {
    case 1:
        new_student = new UniStudent(name, score, dateOfBirth, universityName, courseName);
        /* code */
        break;
    case 2:
        new_student = new CollegeStudent(name, score, dateOfBirth, universityName, courseName);
        /* code */
        break;
    default:
        new_student = new Student(name, score, dateOfBirth, universityName, courseName);
        break;
    }


    _studentsList[_numStudents] = new_student;
    _numStudents++;

    std::cout << "Student added successfully." << std::endl;

}

void StudentManagementSystem::DisplayStudents() {
    if (_numStudents == 0) {
        std::cout << "No students found!" << std::endl;
        return;
    }

    std::cout << "List of students:" << std::endl;
    for (int i = 0; i < _numStudents; i++) {
        std::cout << i + 1 << ". " << _studentsList[i]->GetName() << " (score: " << _studentsList[i]->GetScore() << ")"<< " (date of birth: " << _studentsList[i]->GetDateOfBirth() << ")" << " (school name: " << _studentsList[i]->GetSchoolName() << ")"<< " (course name: " << _studentsList[i]->GetCourseName() << ")" << std::endl;
    }
}

void StudentManagementSystem::DisplayBestStudents() {
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
        if(_studentsList[i]->GetScore() == highest_score) std::cout << i + 1 << ". " << _studentsList[i]->GetName() << " (score: " << _studentsList[i]->GetScore() << ")"<< " (date of birth: " << _studentsList[i]->GetDateOfBirth() << ")" << " (school name: " << _studentsList[i]->GetSchoolName() << ")"<< " (course name: " << _studentsList[i]->GetCourseName() << ")" << std::endl;
    }
}

void StudentManagementSystem::RemoveStudent() {
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
    University university("Bach Khoa University", INIT_STUDENT_COUNT);

    int choice;
    while (true) {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Add a student" << std::endl;
        std::cout << "2. Display all students" << std::endl;
        std::cout << "3. Display best students" << std::endl;
        std::cout << "4. Remove a student" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cin >> choice;

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
                return 0;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
    }
}
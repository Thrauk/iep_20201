#include<iostream>
#include<stdlib.h>
#include<vector>
#include<numeric>

class Student {
    
private:
    typedef std::string string;
    string first_name;
    string last_name;
    int age;
    std::vector<float> grades;
    float final_grade;

    float calculate_final_grade() {
        if(!grades.empty())
        {
            int no_grades = grades.size();
            float sum_grades = std::accumulate(grades.begin(), grades.end(), 0);
            return sum_grades / no_grades;  
        }
        return 0;
    }

public:
    Student(string first_name, string last_name,
            int age, std::vector<float> grades) : 
    first_name(first_name),
    last_name(last_name),
    age(age),
    grades(grades) {
       final_grade = calculate_final_grade();
    }

    Student() : first_name("N/A"),
                last_name("N/A"),
                age(0),
                grades(std::vector<float>()),
                final_grade(0) {}

    
    // Copy Constructor
    Student(const Student& s)
	{
		first_name = s.first_name;
        last_name = s.last_name;
        age = s.age;
        grades = s.grades;
        final_grade = s.final_grade;
		std::cout << "Inside copy contructor\n";
	}

    // Destructor
	~Student()
	{
        std::cout << "Inside destructor\n";
	}

    // Copy assigment operator
	Student& operator = (const Student& s)
	{

        this->first_name = s.first_name;
        this->last_name = s.last_name;
		this->age = s.age;
        this->grades = s.grades;
        this->final_grade = s.final_grade;
        std::cout << "Inside copy assigment operator\n";
		return *this;
	}

    void print() {
        std::cout << "Student " << first_name << " " << last_name << "'s final grade is: " << final_grade << std::endl;
    }

};


class Professor {
    public:
        std::string name;
        Professor():name("N/A") {}
        Professor(const Professor& p) = delete;
    private:
        Professor& operator = (const Professor& s) {}
};

int main() {
    std::vector<float> student_grades {10,9,10};


    // Calling a constructor
    Student student1("Mihai", "Ionescu", 20, student_grades);
    student1.print();

    // Calling a copy-constructor
    Student student2 = student1;
    student2.print();

    // Using a copy assigment operator
    Student student3;
    student3 = student1;
    student3.print();

    Professor professor_1;
    
    // copy constructor deleted
    // Professor professor_2 = professor_1;


    // copy assigment operator is unavailable
    // Professor professor_3;
    // professor_3 = professor_1;

    return 0;

}
// Lesson 3 260523.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iterator>

//Person  класс родитель остальные это классы наследники
class Person {
protected:
    std::string name;
    int age;
public:
    virtual void ShowData() = 0;
    
    Person(std::string name, int age) { //из-за того что имена одинаковые используем this
        this->name = name;
        this->age = age;
    }

};

class Student:public Person {
private:
    std::vector<int>_marks;

public:
    Student(std::string name, int age, std::vector<int>&marks) :Person(name, age) {
        _marks = marks;
    }

    void ShowData() override {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age:  " << age << std::endl;
        std::cout << "Marks:   " << '\n';
        for (const auto& it : _marks)
            std::cout << it<<", ";
        std::cout << std::endl;
    }
};

class Professor : public Person {
private:
    std::string _degree;

public:
    Professor (std::string name, int age, std::string degree) :Person(name, age) {
        _degree = degree;

    }
    void ShowData() override {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age:  " << age << std::endl;
        std::cout << "Degree: " << _degree << std::endl;
    }
};

//Задача 2

class Worker {
   
private:
    std::string _name;
    int _age;
    float _bill;
public:
    Worker(std::string name, int age):_name(name), _age(age), _bill(0) {}
    virtual void Work() = 0; //чистая виртуальная ф-ция

    void Bill(int hours) {
        _bill = 250.0f * hours;
        std::cout << "Bill: " << _bill << '\n';
    }

    std::string GetName() {
        return _name;
    }
    int GetAge() {
        return _age;
    }
    float GetBill() {
        return _bill;
    }
};

class Buyer :public Worker
{
public:
    Buyer(std ::string name, int age):Worker(name, age){}
    void Work()override
    {
        std::cout << GetName() << " - " << GetAge() << "years old"<<": "<< " is buying something" << '\n';
       
    }
};

class Builder :public Worker
{
public:
    Builder(std::string name, int age) :Worker(name, age) {}
    void Work()override
    {
        std::cout << GetName() << " - " << GetAge() <<"years old" << " : " << " is building something" << '\n';
    }
};

int main()
{
    /*std::vector <int>marks = {12,5, 6,4,8,12};
    Student student("John", 20, marks);
    Professor professor("Alex", 15, "Bakalavr");
    std::cout << "Student: " << '\n';
    student.ShowData();
    std::cout << "Professor:" << '\n';
    professor.ShowData();*/
    
    //Задача 2.
    
    Buyer buy("John", 20);
    Builder build("Alex", 30);
    
    buy.Work();
    buy.Bill(20);
    std::cout << "\n\n";
    build.Work();
    build.Bill(30);
    
    
    return 0;
}



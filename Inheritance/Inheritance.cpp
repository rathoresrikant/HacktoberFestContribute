#include<iostream>

class Person
{
public:
    Person()
    {
         _name = "";
        _age = 0;
    }
    Person(std::string name_ , int age_)
    {
        _name = name_;
        _age = age_;
    }
    void printMe() const
    {
        std::cout<< "\nName : "<<_name;
        std::cout<< "\nAge : "<<_age;
    }
    void setName(std::string name_)
    {
        _name = name_;

    }
    void setAge(int age_)
    {
        _age = age_;

    }
    

private:
    int _age;
    std::string _name;

};

class Student : public Person                 //Student class inherited from Person
{
    
public:
    Student( std::string name_ , int age_ , std::string course_ , int courseDuration_)
    {
        Person p(name_,age_);
        
        _course = course_;
        _courseDuration= courseDuration_;
        

    }
    void print() const
    {
        std::cout<<"\nCourse :" <<_course;
        std::cout<<"\nDuration :" <<_courseDuration;

    }

private:
    std::string _course;
    int _courseDuration;
    
};


int main()
{
    std::string name = "Anoop";
    Student  s(name, 22,"it",4);
    s.print();
    s.printMe();


}

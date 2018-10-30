#include<iostream>

class Student
{
    std::string _name;
    int _rollNumber;
    int _mark;

public:


    Student(std::string name_ = "ABC")
    {
        _name = name_;
        _rollNumber = 0;
        _mark=0; 
    }

    Student(std::string name_ , int rollNumber_)
    {
        _name = name_;
        _rollNumber = rollNumber_;
        _mark=0;
    }
    void setMark(int mark_)
    {
        _mark = mark_;
    }
    void setName(std::string name_)
    {
        _name= name_;
    }
    int getMark()
    {
        return  _mark;// = mark_;
    }

    void setRollNumber(int rollNumber_)
    {
        _rollNumber = rollNumber_;
    }

    int getRollNumber()
    {
        return _rollNumber;
    }
    std::string getName()
    {
        return _name;
    }
        

    
    
};


int main()
{
    /*
    Student s("Anoop P");
    s.setRollNumber(14);
    s.setMark(98);
    std::cout<<"Name : "<<s.getName()<<std::endl;
    std::cout<<"Roll Number : "<<s.getRollNumber()<<std::endl;
    std::cout<<"Mark : "<<s.getMark()<<std::endl;


    Student p("ABCD",25);
    p.setMark(85);
    std::cout<<"Name : "<<p.getName()<<std::endl;
    std::cout<<"Roll Number :"<<p.getRollNumber()<<std::endl;
    std::cout<<"Mark : "<<p.getMark()<<std::endl;
    */
    int n;
    std::cout<<"*********STUDENT RECORDS*********"<<std::endl<<std::endl;

    std::cout<<"Enter the Number of students you want to enter"<<std::endl;
    std::cin>>n;


    Student *studentList = new Student[n];
    for(int i=0;i<n;i++){
        
        std::cout<<"Enter the Name"<<i+1<<" : ";
        std::string name;
        std::cin>>name;

        std::cout<<"Enter the Roll Number"<<i+1<<" : ";
        int rl;
        std::cin>>rl;

        std::cout<<"Enter the Mark"<<i+1<<" : ";
        int mk;
        std::cin>>mk;

        studentList[i].setName(name);
        studentList[i].setRollNumber(rl);
        studentList[i].setMark(mk);


    }

     for(int i=0;i<n;i++){
         std::cout<<"*************************"<<std::endl;
         std::cout<<"Name : "<< studentList[i].getName()<<std::endl;;
       std::cout<<"Roll Number : "<< studentList[i].getRollNumber()<<std::endl;;
        std::cout<<"Mark : "<<studentList[i].getMark()<<std::endl;;


    }

     delete studentList;
     /*for(int i=0;i<n;i++){
         std::cout<<"*************************"<<std::endl;
         std::cout<<"Name : "<< studentList[i].getName()<<std::endl;;
       std::cout<<"Roll Number : "<< studentList[i].getRollNumber()<<std::endl;;
        std::cout<<"Mark : "<<studentList[i].getMark()<<std::endl;;


        }*/

    
    
    
    


}

    

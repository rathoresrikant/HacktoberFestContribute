student::Student(std::string name_ = "ABC")
    {
        _name = name_;
        _rollNumber = 0;
        _mark=0; 
    }

   student:: Student(std::string name_ , int rollNumber_)
    {
        _name = name_;
        _rollNumber = rollNumber_;
        _mark=0;
    }
    student::void setMark(int mark_)
    {
        _mark = mark_;
    }
   void student:: setName(std::string name_)
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

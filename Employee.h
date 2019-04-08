//
// Created by DivYesh Patel on 2019-04-08.
//

#ifndef PAYROLL_NEW_EMPLOYEE_H
#define PAYROLL_NEW_EMPLOYEE_H

#endif //PAYROLL_NEW_EMPLOYEE_H

#include <iostream>

class Employee{

private:

    int id;
    string firstName;
    string lastName;
    float rate;
    float hours;



public:


    Employee()
    {
        cout << "Enter an employee's data by the order of ID number, first name, lastname, rate, hours:" << endl;

    }

    //Setters
    void setLastName(string last_name){
        this->lastName = last_name;
    };

    void setFirstName(string first_name){
        this->firstName = first_name;
    };

    void setId(int id){
        this->id = id;
    };

    void setRate(float rate){
        this->rate = rate;
    };

    void setHours(float hours){
        this->hours = hours;
    };

    //Getters
    string getLastName(){
        return this->lastName;
    };

    string getFirstName(){
        return this->firstName;
    };

    int getId(){
        return this->id;
    };

    float getRate(){
        return this->rate;
    };

    float getHours(){
        return this->hours;
    };

    float computeAndReturnWage(){
        return this->rate * this->hours;
    };

    // overloading ==
    friend bool operator == (Employee& emp1, Employee& emp2){
        if emp1.getId() == emp2.getId() return true;
        else return false;
    }

    //overloading !=
    friend bool operator !=(Employee& emp1, Employee& emp2){
        if emp1.getId() == emp2.getId() return true;
        else return false;
    }

    //overloading >>
    friend istream& operator>> (istream &in, Employee &myemp){
        //extract employee info here
    }

    //overloading <<
    friend ostream& operator<< (ostream& out, Employee myemp){
        out << myemp.getId() << myemp.getFirstName() << myemp.getLastName << myemp.getRate() << myemp.getHours() << myemp.computeAndReturnWage() << endl;
        return out;
    }
};
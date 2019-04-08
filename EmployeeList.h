//
// Created by DivYesh Patel on 2019-04-08.
//

#ifndef PAYROLL_NEW_EMPLOYEELIST_H
#define PAYROLL_NEW_EMPLOYEELIST_H

#endif //PAYROLL_NEW_EMPLOYEELIST_H

#include "Employee.h"

class EmployeeList{

public:
    int count = 0;
    char answer;

    Employee employee_list[];
    int no_of_employee_objects_in_list = 0;

    EmployeeList(){
        cout << "EmployeeList default Constructor" << endl;
    };

    bool addEmployee(Employee emp){
        for(count = 0; count < no_of_employee_objects_in_list; count++){
            if(emp == employee_list[count]){
                //add emp to employee_list
                return true;
            }
            else{
                return false;
            }
        }
    };

    bool deleteEmployee(Employee emp){
        if(no_of_employee_objects_in_list > 0){
            for(count = 0; count < no_of_employee_objects_in_list; count++){
                if(emp == employee_list[count]){
                    //delete employee_list[count]
                    return true;
                }
                else{
                    return false; // employees are there, but not found !
                }
            };
        }
        else{
            return false; // no employees are there
        }
    };

    int searchEmployee(int id){
        if(no_of_employee_objects_in_list > 0){
            for(count = 0; count < no_of_employee_objects_in_list; count++){
                if(id == employee_list[count].getId()){
                    //return index of employee_list[count]
                }
                else{
                    return -1; // employee is not available !
                }
            };
        }
        else{
            cout << "No Employees in list" << endl;
            return -1;
        }
    };

    void modifyEmployeeData(int index){
        //should modify employee_list[index]'s object values
        cout << "Change id? y/n -->" ;
        cin >> answer;
        if(answer == 'y'){
            cout << "Enter new ID: " ;
            employee_list[index].setId(cin); //need to confirm wether this is valid
        }

        cout << "Change first name? y/n -->" ;
        cin >> answer;
        if(answer == 'y'){
            cout << "Enter new first name: " ;
            employee_list[index].setFirstName(cin);
        }

        cout << "Change last name? y/n -->" ;
        cin >> answer;
        if(answer == 'y'){
            cout << "Enter new last name: " ;
            employee_list[index].setLastName(cin);
        }
        cout << "Change reate? y/n -->" ;
        cin >> answer;
        if(answer == 'y'){
            cout << "Enter new rate: " ;
            employee_list[index].setRate(cin);
        }
        cout << "Change hours worked? y/n -->" ;
        cin >> answer;
        if(answer == 'y'){
            cout << "Enter new hours: " ;
            employee_list[index].setHours(cin);
        }
    };

    int return_total_employee_in_list(){
        return no_of_employee_objects_in_list;
    };

    Employee returnEmp(int index){
        return employee_list[index];
    };

};
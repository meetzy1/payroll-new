#include<iostream>
#include "Employee.h"
#include "EmployeeList.h"
using namespace std;

//to run g++ -o output main.cpp
// >./output

void addNewEmployees(EmployeeList&){
    char response;
    do{
        cout << "Enter an employee's data by the order of ID number, first name, last name, rate, hours:" << endl;
        //take and extract data
        cout << endl << "Another employee? y/n -->" ;
        cin >> response;
    }while(response != 'n');
};

void modifyEmployeeData(EmployeeList&){
    int employee_id;
    int searchedEmp;
    cout << "Enter employee's current id: " ;
    cin >> employee_id;
    searchedEmp = EmployeeList.searchEmployee(employee_id);
    if(searchedEmp != -1){
        cout << "This employee has following data:" << endl;
        cout << EmployeeList.employee_list[searchedEmp]; //setup << operator to print proper details
        EmployeeList.modifyEmployeeData(searchedEmp);
    }
    else{
        cout << "No such employee in the database." << endl;
    }

};

void deleteEmployees(EmployeeList&){
    cout << "Enter the employee's data to delete by the order of id, first Name, last Name, rate, hours:" << endl;
    // cin take stream result and extract it
    //search, if exist -> delete
    //else cout << "No such employee."
};

void displayEmployeeData(const EmployeeList&){
    int count = 0;
    cout << "XXX Company Payroll System" << endl;
    cout << "ID \t First Name \t Last Name \t Rate \t Hours \t Wage" << endl;
    for (count = 0; count < EmployeeList.no_of_employee_objects_in_list; count++){
        cout << EmployeeList.employee_list[count] //modify to print proper data
    };
};

void printMenu(){
    cout << "******************************************************************************" << endl;
    cout << "**                                   Menu                                   **" << endl;
    cout << "** 1. Add new employees to the database.                                    **" << endl;
    cout << "** 2. Modify employees data in the data base.                               **" << endl;
    cout << "** 3. Delete employees from the database.                                   **" << endl;
    cout << "** 4. Display employee data to the screen.                                  **" << endl;
    cout << "** 5. Quit the system                                                       **" << endl;
    cout << "******************************************************************************";
};


int main(){
    char response;
    int ch; // for menu choices
    EmployeeList empList;
    cout << "Create the employee database:" << endl;

    addNewEmployees(empList);
    cout << "The employee database has been created." ;

    main_execution:
    printMenu();
    cout << "Please enter your choice: ";
    cin >> ch;

    switch(ch){
        case 1:
            addNewEmployees(empList); //we have to pass employeelist object
            goto main_execution;
        case 2:
            modifyEmployeeData(empList);
            goto  main_execution;
        case 3:
            deleteEmployees(empList);
            goto main_execution;
        case 4:
            displayEmployeeData(empList);
            goto main_execution;
        case 5:
            cout << "Thanks for using XXXX Company Payroll System! All employee information can be viewed in the file “employee_list.dat”" << endl;
            //update employee_list.dat file with empList data
            return 0;
        default:
            cout << "wrong choice!" << endl;
            break;
    }
    return 0;
}
#include<iostream>
#include<iomanip>
#include <fstream>
using namespace std;
#include "Employee.h"
#include "EmployeeList.h"


//to run g++ -o output main.cpp
// >./output

void addNewEmployees(EmployeeList empList){
    int id;
    string fname;
    string lname;
    float rate;
    float hour;
    char response;
    do{
        cout << "Enter an employee's data by the order of ID number, first name, last name, rate, hours:" << endl;
        cin >> id >> fname >> lname >> rate >> hour ;
        cin.clear();
        while ((id < 0) || (rate<0) || (hour<0))
        {
            cout << "You must enter a non negative value. Try again!"<<endl;
            cin >> id >> rate >> hour;
        }
        cout << "Another employee? y/n -->" ;
        cin >> response;
        cin.clear();

        // Although parameterized constructor can be used
        Employee myemp;
        myemp.setId(id);
        myemp.setFirstName(fname);
        myemp.setLastName(lname);
        myemp.setRate(rate);
        myemp.setHours(hour);

        empList.addEmployee(myemp);
    }while(response != 'n');
};

void modifyEmployeeData(EmployeeList empList){
    int employee_id;
    int searchedEmp;
    cout << "Enter employee's current id: " ;
    cin >> employee_id;
    searchedEmp = empList.searchEmployee(employee_id);
    if(searchedEmp != -1){
        cout << "This employee has following data:" << endl;
        cout << empList.employee_list[searchedEmp]; //setup << operator to print proper details
        empList.modifyEmployeeData(searchedEmp);
    }
    else{
        cout << "No such employee in the database." << endl;
    }

};

void deleteEmployees(EmployeeList empList){
    int id;
    string fname;
    string lname;
    float rate;
    float hour;
    int index;
    cout << "Enter the employee's data to delete by the order of id, first Name, last Name, rate, hours:" << endl;
    cin >> id >> fname >> lname >> rate >> hour ;
    cin.clear();
    index = empList.searchEmployee(id);
    if(index != -1){
        //delete karvanu baki chhe - empList.deleteEmployee ma karvanu....particular object from employee_list Array
        empList.deleteEmployee(empList.employee_list[index]);
        cout << "This employee's data is deleted." << endl;
    }
    else{
        cout << "No such employee." << endl;
    }
};

void displayEmployeeData(const EmployeeList empList){
    int count = 0;
    cout << "XXX Company Payroll System" << endl;
    cout << "ID" << setw(10) << "First Name" << setw(10) << "Last Name" << setw(10) << "Rate" << setw(10) << "Hours" << setw(10) << "Wage" << endl;
    for (count = 0; count < empList.no_of_employee_objects_in_list; count++){
        cout << empList.employee_list[count];//modify to print proper data
    };
};

void printMenu() {
    cout << "******************************************************************************" << endl;
    cout << "**                                   Menu                                   **" << endl;
    cout << "** 1. Add new employees to the database.                                    **" << endl;
    cout << "** 2. Modify employees data in the data base.                               **" << endl;
    cout << "** 3. Delete employees from the database.                                   **" << endl;
    cout << "** 4. Display employee data to the screen.                                  **" << endl;
    cout << "** 5. Quit the system                                                       **" << endl;
    cout << "******************************************************************************" << endl;
}


int main(){
    int ch;
    ofstream outputfile;
    EmployeeList empList;
    cout << "Create the employee database:" << endl;

    addNewEmployees(empList);
    cout << "The employee database has been created." << endl;

    main_execution:
    printMenu();
    cout << "Please enter your choice: ";
    cin >> ch;

    switch(ch){
        case 1:
            addNewEmployees(empList);
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
            outputfile.open("employee_list.dat");
            //outputfile << displayEmployeeData(empList); // we need to pass displayEmployeeData to fstream
            outputfile.close(); //close output file
            return 0;
        default:
            cout << "wrong choice!" << endl;
            break;
    }
    return 0;
}
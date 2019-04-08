#include<iostream>
using namespace std;

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
    cout << "Enter employee's current id: " ;
    cin >> employee_id;
    searchedEmp = EmployeeList.searchEmployee(employee_id);
    if(searchEmp != -1){
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
            break;
        case 2:
            modifyEmployeeData(empList);
            goto  main_execution;
            break;
        case 3:
            deleteEmployees(empList);
            goto main_execution;
            break;
        case 4:
            displayEmployeeData(empList);
            goto main_execution;
            break;
        case 5:
            cout << "Thanks for using XXXX Company Payroll System! All employee information can be viewed in the file “employee_list.dat”" << endl;
            //update employee_list.dat file with empList data
            exit();
        default:
            cout << "wrong choice!" << endl;
            break;
    }
    return 0;
}
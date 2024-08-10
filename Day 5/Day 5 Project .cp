#include <iostream>
#include <vector>
#include<string>
using namespace std;

class Employee{
    private:
    int id;
    double salary;
    string name;
    string position;
    double benefits;
    double deduction;
    double hoursWorked;

    public:
    Employee(int id, string name, string position, double salary,
    double benefits=0,double deduction=0,double hoursWorked=0){
        this->id = id;
        this->name= name;
        this->position= position;
        this->salary= salary;
        this->benefits= benefits;
        this->deduction= deduction;
        this->hoursWorked= hoursWorked;

    
    }
    

    void setBenefits(double health, double retirement){
        benefits = health + retirement;
    }
    
    void setDeduction(double tax, double insurance){
        deduction = tax+ insurance;
    }

    void addWorkHours(double hours){
        hoursWorked+= hours;
    }

    double getGrossSalary(){
        return salary+benefits;
    }

    double getNetSalary(){
        return getNetSalary()-deduction;
    }

    void printEmployeeDetails(){
        cout << "ID: " << id << endl << "Name: "<< name << endl 
        << "Position: " << position << "\n Gross salary: "<< getGrossSalary()<< 
        "\n Net salary: "<< getNetSalary()<< endl;


    }

    int getId(){
        return id;
    }
};

class SalaryCaculator{
    public:

    double calculateGrossSalary(Employee &Employees){
        return Employees.getGrossSalary();
    }

    double calculateNetSalary(Employee &Employees){
        return Employees.getNetSalary();
    }

};

class UserInterface{
    public:
    void displayMenu(){
        cout<< "1. Add employee \n 2. Update Employee \n 3. Delete Employee \n 4. Calculate Salary \n 5.Generate Report \n6. Exit\n";

    }

    int getInput(){
        int choice;
        cin >> choice;
        return choice;
    }

    void displayOutput(string &output){
        cout << output<<endl;
    }
};

class PayrollSystem{
    private:
    vector<Employee> Employees;

    public:
    void addEmployee(){
        int id;
        string name,position;
        double salary;
        cout<< "Enter employee id: ";
        cin >> id;
        cin.ignore();
        cout<< "Enter name: ";
        getline(cin,position);
        cout<< "Enter position: ";
        getline(cin,position);
        cout<< "Enter salary: ";
        cin >> salary;

        Employees.push_back(Employee(id,name,position,salary));
    }


    void updateEmployee(){
        int id;
        cout<< "Emter the employee to update: ";
        cin >> id;

        for(auto &emp : Employees){
            if(emp.getId() == id){
                double health, retirement , tax , insurance;
                cout << "Enter health benefits: ";
                cin >> health;
                cout << "Enter retirement benefits: ";
                cin >> retirement;
                cout << "Enter tax deductions: ";
                cin >> tax;
                cout << "Enter insurance deductions: ";
                cin >> insurance;

                emp.setDeduction(tax,insurance);
                emp.setBenefits(health, retirement);

                cout << "Employee updated successfully";
                return;
            }
        }
        cout<< "Employee not found";    

    }

    void deleteEmployee(){
        int id;
        cout<< "Enter the id to delete: ";
        cin >> id;

        for(auto it = Employees.begin(); it != Employees.end(); it++){
            if(it->getId()==id){
                Employees.erase(it);
                cout<< "Employee deleted successfully";
                return;
            }
        }
        cout<< "Employee not found"; 
    }


    void calculateSalary(){
         int id;
        cout<< "Enter the id to calculate salary: ";
        cin >> id;
        
        for(auto &emp : Employees){
            if(emp.getId() == id){
                SalaryCaculator sc;
                double grossSalary = sc.calculateGrossSalary(emp);
                double netSalary = sc.calculateNetSalary(emp);
                cout<< "Gross salary: "<<grossSalary<<"\n Net salary: "<< 
                netSalary;
                return;
            }
            
        }
        cout<< "Employee not found"; 
    }

    void generateReport(){
        for(auto &emp : Employees){
            emp.printEmployeeDetails();
            cout<<"---------------------------------------\n";
        }
    }
};


int main(){
    UserInterface ui;
    PayrollSystem ps;

    while (true)
    {
        ui.displayMenu();
        int choice = ui.getInput();
        
        switch(choice){
            
            case 1:
            ps.addEmployee();
            break;

            case 2:
            ps.addEmployee();
            break;

            case 3:
            ps.deleteEmployee();
            break;

            case 4:
            ps.calculateSalary();
            break;

            case 5:
            ps.generateReport();
            break;

            case 6:
            return 0;

            default:
            cout<< "Invalid choice";

        }
    }
    
}

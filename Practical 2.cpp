#include<iostream>
#include <string>
using namespace std;
struct Employee
{
    int empID;
    string name;
    float salary;
    Employee *next;
};
Employee *head = NULL;
void insertEmployee()
{
    Employee *newNode = new Employee;
    cout << "Enter Employee ID: ";
    cin >> newNode->empID;
    cout << "Enter Employee Name: ";
    cin >> newNode->name;
    cout << "Enter Employee Salary: ";
    cin >> newNode->salary;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Employee *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Employee inserted successfully!\n";
}
void deleteEmployee()
{
    if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;
    Employee *temp = head;
    Employee *prev = NULL;
    if (temp != NULL && temp->empID == id)
    {
        head = temp->next;
        delete temp;
        cout << "Employee deleted successfully!\n";
        return;
    }
    while (temp != NULL && temp->empID != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Employee not found!\n";
        return;
    }
    prev->next = temp->next;
    delete temp;
    cout << "Employee deleted sucly!\n";
}
void searchEmployee()
{
    if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }
    int id;
    cout << "Enter Employee ID to search: ";
    cin >> id;
    Employee *temp = head;
    while (temp != NULL)
    {
        if (temp->empID == id)
        {
            cout << "\nEmployee Found\n";
            cout << "Employee ID : " << temp->empID << endl;
            cout << "Name        : " << temp->name << endl;
            cout << "Salary      : " << temp->salary << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Employee not found!\n";
}
void displayEmployee()
{
	if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }
    Employee *temp = head;
     cout << "\n-------------------------------------------\n";
    cout << "Employee Records\n";
    cout << "-------------------------------------------\n";
    cout << "ID\tName\t\tSalary\n";
    cout << "-------------------------------------------\n";
    while (temp != NULL)
    {
        cout << temp->empID << "\t"
             << temp->name << "\t\t"
             << temp->salary << endl;
        temp = temp->next;
    }
}

int main()
{
	int choice;
    do
    {
        cout << "\n====== Employee Management System ======\n";
        cout << "1. Insert Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Search Employee\n";
        cout << "4. Display Employees\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insertEmployee();
            break;
        case 2:
            deleteEmployee();
            break;
        case 3:
            searchEmployee();
            break;
        case 4:
            displayEmployee();
            break;
        case 5:
            cout << "Exiting Program...\n";
            break;
        default:
            cout << "Invalid Choice! Try Again.\n";
        }
    } while (choice != 5);
    return 0;
}


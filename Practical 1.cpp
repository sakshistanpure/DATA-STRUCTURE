#include <iostream>
using namespace std;
struct Student
{
    int roll;
    char name[100];
    float marks;
    double mobile;
};
void setStudentDetails(Student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of Student " << i + 1 << endl;
        cout << "Student Roll Number: ";
        cin >> s[i].roll;
        cout << "Student Name: ";
        cin >> s[i].name;
        cout << "Student Marks: ";
        cin >> s[i].marks;       
    }
}
void displayStudentDetails(Student *s, int n)
{
    cout << "\n********** Student Information **********\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Student Roll Number: " <<(s + i)->roll << endl;
        cout << "Student Name: " <<(s + i)->name << endl;
        cout << "Student Marks: " <<(s + i)->marks << endl;
    }
}
int main()
{
    Student s[100];
    int n;
    cout<<"\n Enter no of Students :";
    cin>>n;
    setStudentDetails(s, n);
    displayStudentDetails(s, n);
}


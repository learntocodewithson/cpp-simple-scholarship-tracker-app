#include<iostream>
#include<string>
#include <sstream>
#include <fstream>
using namespace std;

bool isStudentIdExists(string student_id){
 string row, studentid, name, surname, scholarship_status;
 bool found = 0;

 ifstream Students("students.csv");

 while(getline(Students, row)){
  istringstream ss(row);
  getline(ss, studentid, ',');
  if(studentid == student_id){
   found = 1;
   break;
  }
 }

 Students.close();

 return found;
}

void displayStudentInformation(string student_id){
 string row, studentid, name, surname, scholarship_status;

 ifstream Students("students.csv");

 while(getline(Students, row)){
  istringstream ss(row);
  getline(ss, studentid, ',');
  getline(ss, name, ',');
  getline(ss, surname, ',');
  getline(ss, scholarship_status, ',');

  if(studentid == student_id){
   cout << endl << "Student Information:";
   cout << endl << "Student ID: " << studentid;
   cout << endl << "Name: " << name;
   cout << endl << "Surname: " << surname;
   cout << endl << "Scholarhip Status: " << scholarship_status << endl;
   break;
  }
 }

 Students.close();
}

int main(){
 string student_id;
 bool found = 0;

 cout << endl << "Simple Scholarship Tracker APP" << endl;

 do {
   cout << endl << "Enter your student id: ";
   cin >> student_id;

  if(isStudentIdExists(student_id)){
   displayStudentInformation(student_id);
   found = 1;
  }else{
   cout << "Student Id not found." << endl;
  }
 } while (!found);

 return 0;
}

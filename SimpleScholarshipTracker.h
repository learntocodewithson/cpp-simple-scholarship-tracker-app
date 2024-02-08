#ifndef SIMPLESCHOLARSHIPTRACKER_H
#define SIMPLESCHOLARSHIPTRACKER_H
#include<string>
#include <sstream>
#include <fstream>
using namespace std;
 class SimpleScholarshipTracker {
  public:
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

   string displayStudentInformation(string student_id){
    string row, studentid, name, surname, scholarship_status, result_message;

    ifstream Students("students.csv");

    while(getline(Students, row)){
     istringstream ss(row);
     getline(ss, studentid, ',');
     getline(ss, name, ',');
     getline(ss, surname, ',');
     getline(ss, scholarship_status, ',');

     if(studentid == student_id){
      result_message = "\nStudent Information: \nStudent ID: " + studentid + "\nName: " + name + "\nSurname: " + surname + "\nScholarship Status: " + scholarship_status; 
      break;
     }
    }
    Students.close();

    return result_message;
   }
 };
#endif

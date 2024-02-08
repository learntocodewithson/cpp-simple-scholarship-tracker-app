#include<iostream>
#include "SimpleScholarshipTracker.h"

int main(){
 string student_id;
 bool found = 0;
 SimpleScholarshipTracker simple_scholarship_tracker;

 cout << endl << "Simple Scholarship Tracker APP" << endl;
  
 do {
   cout << endl << "Enter your student id: ";
   cin >> student_id;
   if(simple_scholarship_tracker.isStudentIdExists(student_id)){
    cout << simple_scholarship_tracker.displayStudentInformation(student_id);
    found = 1;
   } else {
    cout << "Student Id not found." << endl;
   }
 } while (!found);
 
 return 0;
}

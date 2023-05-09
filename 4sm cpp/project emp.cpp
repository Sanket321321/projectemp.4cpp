Design a two base classes Employee (Name, Designation) and Project(Project_Id, title).
Derive a class Emp_Proj(Duration) from Employee and Project. Write a menu driven
program to
a. Build a master table.
b. Display a master table
c. Display Project details in the ascending order of duration.

*/
#include <iostream>
using namespace std;
class Employee {
public:
char Name[20], Designation[20];
};

class Project {
   public:
   int Project_Id;
   char title[20];
};

class Emp_Proj:public Project,public Employee{
   public:
   int duration;
   
   void accept ();
};

class master:public Emp_Proj{
  public:
  void accept();
  void display (master[], int size);
  void asending (master[],int size);
};



void master::accept(){
  cout<<"Enter the Emp Name:";
  cin>>Name;

  cout<<"Enter the Designation:";
  cin>>Designation;

  cout<<"Enter the Project_Id:";
  cin>>Project_Id;

  cout<<"Enter the project title:";
  cin>>title;

  cout<<"Enter the duration:";
  cin>>duration;  
}

void master::display(master a[], int size){
  for (int i=0;i<size;i++){
  cout<<"\n\n"<<i+1<<" info"<<endl;
    cout<<"Emp Name:"<<a[i].Name<<endl;

  cout<<"Enter the Designation: "<<a[i].Designation<<endl;

  cout<<"Enter the Project_Id:"<<a[i].Project_Id<<endl;

  cout<<"Enter the project title:"<<a[i].title<<endl;

  cout<<"Enter the duration:"<<a[i].duration<<endl;  
  }
}


void master::asending (master m[],int size){
  master temp;
  for(int i=0;i<size-1;i++){
    for(int j=0;j<size-i-1;j++){
      if(m[j].duration > m[j+1].duration)
      {
        temp = m[j];
        m[j] = m[j+1];
        m[j+1] = temp;
      }
    }
  }
}



int main() {
  master m[50];
  int n;
  cout<<"Enter the total:";
  cin>>n;

  for(int i=0;i<n;i++){
    cout<<"\nEnter the "<<i+1<<" info"<<endl;
     m[i].accept();
  }
  m[n].display(m, n) ;

  cout<<"\n\nAfter the asending oerder\n";
  m[n].display(m, n);
}
#include<iostream> 
using namespace std; 

int charge_per_day;
int no_of_days_admitted; 
class Patient //Base Class 
{ 
 char patient_name[50],addr[15]; 
 int age; 
 char gender[10]; 

 public: 
 void accept_patient_details() 
 { 
 cout<<"\n Enter Patient Details"; 
 cout<<"\n Patient Name : "; 
 cin>>patient_name; 
 cout<<"\n Patient address : "; 
 cin>>addr; 
 cout<<"\n Patient Age : "; 
 cin>>age; 
 cout<<"\n Gender : "; 
 cin>>gender; 
 } 

 void display_patient_details() 
 { 
 cout<<"\n Displaying Patient Details"; 
 cout<<"\n Patient Name : "<<patient_name; 
 cout<<"\n Patient address : "<<addr; 
 cout<<"\n Patient Age : "<<age; 
 cout<<"\n Gender : "<<gender; 
 } 

}; 


class IPD //Base Class 
{ 
 int ward_no; 
 int bed_no; 


 public: 
 void accept_ipd_details() 
 { 
 cout<<"\n Enter IPD Details "; 
 cout<<"\n Ward No. : "; 
 cin>>ward_no; 
 cout<<"\n Bed No. : "; 
 cin>>bed_no; 
 cout<<"\n Charge Per Day : "; 
 cin>>charge_per_day; 
 } 

 void display_ipd_details() 
 { 
 cout<<"\n Displaying IPD Details"; 
 cout<<"\n Ward No. : "<<ward_no; 
 cout<<"\n Bed No. : "<<bed_no; 
 cout<<"\n Charge Per Day : "<<charge_per_day<<" Rs"; 
 } 

}; 


class IPDPatient : public IPD, public Patient //Class IPDPatient is derived from Class IPD and Class Patient 
{ //Multiple inheritance 


 public: 
 void accept_ipd_patient_details() 
 { 
 accept_patient_details(); 
 accept_ipd_details(); 
 cout<<"\n\n Enter No. of Days Admitted : "; 
 cin>>no_of_days_admitted; 
 } 

 void display_ipd_patient_details() 
 { 
 display_patient_details(); 
 display_ipd_details(); 
 cout<<"\n\n No. of Days Admitted : "<<no_of_days_admitted << endl; 
 
 int total = no_of_days_admitted * charge_per_day;
 cout << "Total Expense of Patient -> " << total << " Rs" << endl;
 } 

}; 


int main()
{ 
 IPDPatient *ipdt; // ipdt is a object of derived class IPDPatient 
 int i,n; 
 cout<<"\n Enter the number of Patient details you want = "; 
 cin>>n; 
 ipdt=new IPDPatient[n]; //The new operator denotes a request for memory allocation on the Free store. 
 for(i=0;i<n;i++) 
 { 
 ipdt[i].accept_ipd_patient_details(); 
 ipdt[i].display_ipd_patient_details(); 
 } 
 
 return 0; 
}
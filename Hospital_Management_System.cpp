/***********************************************
************************************************
**                                            **
**          BEIMNET GENENE                    **
**       HOSPITAL MANAGEMENT                  **
**  PROJECT Telegram Channel t.me/Birranaye   **
************************************************
************************************************/
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
//Global variables and Functions
int clinic_class();
void AllDatabase();
int Addpatient();
int Outpatient();
short int getway;
int depstart;
int checker;
int operation_department[50];
	string operation_holder[50];
	string operation_waiter[50];
	string operation_holder1[50];
//sample patients and things we need to register new patients
struct Patient{
    string Fname[30]={"Abebe","Melat","Brhanu","Abebech","Kirubel","Abdurezak","Geleta","Abebe"};
	string Mname[30]={"Brhanu","Shemels","Demsew","Abate","Alemu","Mehamed","Adugna","Brhanu"};
	string Lname[30]={"Smegnew","Werkneh","Asefa","Smegnew","Abebe","Abdela","Burka","Smegnew"};
	int age[30]={23,21,33,30,13,25,38,23};
	char gender[30]={'M','F','M','F','M','M','M','M'};
	short int department[30]={1,1,2,2,3,3,4,5};//to identify the illnes of the patient
	char blood[30][4]={"A+","AB+","B-","O+","B+","AB-","O+","B+"};
	int phone[30]={11245323,114347645,11345762,116535456,115233455,116435567,116345654,114563233};
	string adress[30]={"Kasanchis","Doromanekia","Arada","Piasa","Merkato","Lamberet","Megenagna","Menagesha"};
	};
	Patient Patient; // Struct Variable initialization
	//here our sample doctors database for taking the operation of patients
struct Doctors{
string Docname[10]={"Widad KidhaneMariam","Werkneh Eshete","Hadas Maleda","Aklilu Lema",
    "Aster Tsegaye","Kaleab Wasyehun","Robel Beyene","Henok Beyene","Mamitu Gashe","Mekdes Birhanu"};
    int Specialized[10]={1,3,2,4,2,5,1,3,5,4};//used to set the doctors specialitiy
    int DoctorId;//ID number for doctors

};
//used to beutify the top of user interfece
void TopDesign()
{
    for(int i=0;i<10;i++)
{
    for(int j=i;j<=10;j++)
    {
        cout<<"*";
        for(int i=0;i<j;i++)
        cout<<" ";
    }
cout<<endl;
}
}
//used to beutify the buttom user interfece
void BottomDesign()
{
    for(int i=0;i<=41;i++)
{
    cout<<"+";
}
}
//function used to connect or link the patient with doctors and to start the operation
void DoctorsList()
{
Doctors Doctors;
    int i;
    for(int i=0;i<10;i++)
{
    if(getway==Doctors.Specialized[i])
{
    cout<<"ID Number :  "<<i<<endl;
    cout<<Doctors.Docname[i]<<endl;
}
}
    cout << "Enter the Doctor ID number to verify and initiate the operation\n";
again:
    cin >>Doctors.DoctorId;
    if(Doctors.Docname[Doctors.DoctorId]=="" || Doctors.Specialized[Doctors.DoctorId]!=getway)
{
    cout << "Invalid ID Number input the correct ID";
goto again;
}
    else if(Doctors.Docname[Doctors.DoctorId]!="" && Doctors.Specialized[Doctors.DoctorId]==getway)
{
for(int i=0;i<50;i++){
        if(Doctors.Docname[Doctors.DoctorId]==operation_holder1[i])
{
cout<<"\nDoctor  "<<Doctors.Docname[Doctors.DoctorId];
cout<<"\n\tis bussy now by taking the operation of patient"<<operation_holder[i]<<" "<<operation_holder[i+1];

 if(getway==Doctors.Specialized[i]&&Doctors.Docname[Doctors.DoctorId]!=operation_holder1[i])
{
    cout<<"\nwe have free doctors swap the operation for them\n";
    cout<<"ID Number :  "<<i<<endl;
    cout<<Doctors.Docname[i]<<endl;
}else if(Doctors.Docname[Doctors.DoctorId]==operation_holder1[i])
{
    cout<<"\nWe have no free doctor at the moment this patient must wait while free doctors available\n";
    cout<<"the operation of  patient  "<<Patient.Fname[depstart]<<" is in progress Automatically starts when Free doctors are available";
    if(operation_waiter[i]==""){
operation_waiter[i]=Patient.Fname[depstart];
    }
        cout<<"\n5-> Go Back or Exit";
      cin>>getway;
      if(getway==5)
      {
      clinic_class();
      }
}
goto again;
}
}
for(int i=0;i<50;i++){
    if(operation_holder[i]==""&&operation_holder1[i]=="")
{
    operation_holder[i]=Patient.Fname[depstart];
   operation_holder1[i]=Doctors.Docname[Doctors.DoctorId];
   operation_holder[i+1]=Patient.Mname[depstart];
    operation_department[i]=Patient.department[depstart];
break;
}
            }
    cout<<"\nThe Operation Starts Successfully\n";
}
    cout<<"\n5-> Go Back or Exit";
      cin>>getway;
      if(getway==5)
      {
      clinic_class();
      }
}
//function used to initial the operation for all dipartments
int OperationClass()
{
Doctors Doctors;
switch(getway){
case 1:
        cout<<"\t----> General Operation <----\n";
        break;
case 2:
        cout<<"\t----> Heart Operation <----\n";
        break;
case 3:
        cout<<"\t----> Dentis Operation <----\n";
        break;
case 4:
        cout<<"\t----> Bone Operation <----\n";
        break;
case 5:
        cout<<"\t----> To Kidney Operation <----\n";
        break;
        }
    cout<<"Choose Patients below\n";
//used to output patients list fr operation class
        cout<<"3-> to see patients list\n";
        cin>>checker;
    if(checker==3)
            Outpatient();
   cout<<"\nEnter the ID Number of the patient to take in to the operation\n";
    again:
        cin>>depstart;
       if(Patient.Fname[depstart]=="" || Patient.department[depstart]!=getway)
       {
        cout<<"There is no patient registered by this ID number try another ID";
        goto again;
        }
        else if(Patient.Fname[depstart]!="" && Patient.department[depstart]==getway)
        {
        for(int i=0;i<50;i++){
        if(Patient.Fname[depstart]==operation_holder[i]&& Patient.department[depstart]==getway)
{
cout<<"\nSorry this patient is already waiting for his operation take another one\n";
goto again;
}
}
            cout<<"You Choose  "<<Patient.Fname[depstart];
            cout<<"\nnow choose the Doctor who takes the operation\n";
            DoctorsList();
        }
        }

//used to display all current patient operations
void OperationDisplay()
{
Doctors Doctors;
    if(operation_holder[0]!="")
{
    if(operation_department[0]==getway){
for(int i=0;operation_holder[i]!="";i++)
{
    cout<<"\nDoctor "<<operation_holder1[i];
    cout<<"\n\ttook the operation of patient ";
    cout<<operation_holder[i]<<" ";
    cout<<operation_holder[i+1];
    if(operation_waiter[i]==""){}
    else if(operation_waiter[i]!=""){
    cout<<"\n\n\nOperation orderd patients list";
    cout<<"\n\t\t"<<operation_waiter[i];
    }
    i++;
    }
    }
    else
            cout<<"\nthere is no operation in this department at the moment\n";
}
else if(operation_holder[0]==""){
    cout<<"\nthere is no started operation at the moment\n";
    }
    cout<<"\n5-> Go Back or Exit";
      cin>>getway;
      if(getway==5)
      {
      clinic_class();
      }
    }
//core of the project serve as database and link all outputing, adding, taking to operation and displaying operation functions
	void AllDatabase()
{
	cin>>depstart;
switch(depstart)
{
case 1:
    Addpatient();

	break;
case 2:
    Outpatient();
	break;
case 3:
	OperationClass();
case 4:
    OperationDisplay();
case 5:
	clinic_class();
}
}
//sub class of the departments and used to connect with the database function
void contents()
{
        system("cls");
        cout<<"\t\tEnter your choice\n";
        cout<<"\t";BottomDesign();
        cout<<"\n\t";BottomDesign();
        cout<<"\n\t++                                     \t++\n";
        cout<<"\t++     1-> Register New patient      \t++\n";
        cout<<"\t++     2-> Display patient list        \t++\n";
        cout<<"\t++     3-> Take patient to operation    ++\n";
        cout<<"\t++     4-> Display ongoing operations   ++\n";
        cout<<"\t++     5-> Go back or exit \t\t++\n";
        cout<<"\t++                                     \t++\n";
        cout<<"\t";BottomDesign();
        cout<<"\n\t";BottomDesign();
        AllDatabase();
}
//this function is the first to display and provides department choice's
int clinic_class()
{
system("cls");
TopDesign();
cout<<"\t*************************************\n";
cout<<"\t**      GLORIOUS HOSPITAL          **\n";
cout<<"\t*************************************\n";
cout<<"\t       WELCOME ENTER YOUR CHOICE\n";
cout<<"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t||\t\t\t\t   ||\n";
cout<<"\t||     1-> GENERAL CLINIC          ||\n";
cout<<"\t||     2-> HEART CLINIC            ||\n";
cout<<"\t||     3-> TEETH CLINIC            ||\n";
cout<<"\t||     4-> BONE CLINIC             ||\n";
cout<<"\t||     5-> KIDNEY CLINIC           ||\n";
cout<<"\t||     6-> GO BACK OR EXIT         ||\n";
cout<<"\t||_________________________________||\n";
again:
cin>>getway;
switch(getway)
{
case 1:
        cout<<"\tGENERAL CLINIC\n\n\n\tEnter your choice\n";
        contents();
        break;
case 2:
        cout<<"\tHEART CLINIC\n\n\n\tEnter your choice\n";
        contents();
        break;
case 3:
        cout<<"\tTEETH CLINIC\n\n\n\tEnter your choice\n";
        contents();
        break;
case 4:
        cout<<"\tBONE CLINIC\n\n\n\tEnter your choice\n";
        contents();
        break;
case 5:
        cout<<"\tKIDNEY CLINIC\n\n\n\tEnter your choice\n";
        contents();
        break;
case 6:
        cout<<"\t\t----THANK YOU----";
        return 0;
        break;
default:
        cout<<"Please Enter the Correct Choice\n";
        goto again;
        break;
}
}
//this function is used to add patient for each departments
int Addpatient()
{
system("cls");
for(int i=8;i<20;i++)
    {
     if(Patient.Fname[i]=="")
    {
	cout<<"\nFill the Patient form\n\n\n";
	cout<<"First Name	:  ";cin>>Patient.Fname[i];
	cout<<"Middle Name	:  ";cin>>Patient.Mname[i];
	cout<<"Last Name	:  ";cin>>Patient.Lname[i];
	cout<<"Age		:  ";cin>>Patient.age[i];
	cout<<"Gender(m/f)	:  ";cin>>Patient.gender[i];
	Patient.department[i]=getway;
	again:
	cout<<"Blood		:  ";cin>>Patient.blood[i];
	if((strcmp(Patient.blood[i],"A+")==0)||(strcmp(Patient.blood[i],"a+")==0)||(strcmp(Patient.blood[i],"A-")==0)||(strcmp(Patient.blood[i],"a-")==0)||
      (strcmp(Patient.blood[i],"B+")==0)||(strcmp(Patient.blood[i],"b+")==0)||(strcmp(Patient.blood[i],"B-")==0)||(strcmp(Patient.blood[i],"b-")==0)||
      (strcmp(Patient.blood[i],"O+")==0)||(strcmp(Patient.blood[i],"o+")==0)||(strcmp(Patient.blood[i],"O-")==0)||(strcmp(Patient.blood[i],"o-")==0)||
      (strcmp(Patient.blood[i],"AB+")==0)||(strcmp(Patient.blood[i],"ab+")==0)||(strcmp(Patient.blood[i],"AB-")==0)||(strcmp(Patient.blood[i],"ab-")==0));

    else
    {
        cout<<"\n   Invalid Blood Group Try Again..\n\n";
        goto again;
        }
	cout<<"Phone		:  ";cin>>Patient.phone[i];
	cout<<"Adress    : ";cin>>Patient.adress[i];
	cout<<"\n--Patient Successfully registered--\n";
	cout<<"Enter 5 to end the process else enter any key to continue registeration\n";
	cin>>getway;
	if(getway==5)
	{
		clinic_class();
		 break;
		}else Addpatient();
}else if(Patient.Fname[i]!="")
{
i++;
};
}

	}
	//This Function is used to Output the patient
int Outpatient()
	{
	system("cls");
if(Patient.Fname[0]!="")
{
for(int i=0;Patient.Fname[i]!="";i++)
{
if(getway==Patient.department[i])
{
    cout<<endl;
    cout<<"ID NO: "<<i<<endl;
	cout<<"Full Name    :       "<<Patient.Fname[i]<<" "<<Patient.Mname[i]<<" "<<Patient.Lname[i];
	cout<<endl;
	cout<<"Age          :       "<<Patient.age[i];
	cout<<endl;
	cout<<"Gender       :       "<<Patient.gender[i];
	cout<<endl;
	cout<<"Blood        :       "<<Patient.blood[i];
	cout<<endl;
	cout<<"Phone        :       "<<Patient.phone[i];
	cout<<endl;
	cout<<"Adress       :       "<<Patient.adress[i];
	cout<<endl<<endl<<endl;
	}
	}
	}
	if(depstart==3)
	{
	return 0;
	}else
	cout<<"\nEnter 5 to get back";
      cin>>getway;
      if(getway==5)
      {
      clinic_class();
      }
	}
int main()
{
system("cls");
system("color 2");//used to coloring the whole system works only on windows operating system
clinic_class();
return 0;
}

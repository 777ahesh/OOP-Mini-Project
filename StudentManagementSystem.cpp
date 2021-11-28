#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<stdio.h>
#include<fstream>
using namespace std;

char un[20];
class Admin
{
    char name[20];
    int totsub;
    char subject[10] [10];
    char mobile[15],mail[50],fname[20];
    char passwd[20],rpasswd[20];
    public:
        char rollno[15];
        // This functions is used to get the student dataaentry from the ADMIN
        // portal...all the records entries are made by this method.
        void getstdata(){
            cout<<"\nEnter The Student Name : ";
            gets(name);
            cout<<"\nEnter The Student ID/RollNo. : ";
            cin>>rollno;
            cout<<"\nEnter The Student's Father Name : ";
            gets(fname);
            cout<<"\nEnter The Student's Mobile Number : ";
            gets(mobile);
            cout<<"\nEnter The Student's E-Mail ID: ";
            gets(mail);
            cout<<"\nEnter The Student's Total Subjects: ";
            cin>>totsub;
            for(int i=0;i<totsub;i++){
                cout<<"\nEnter the Subject "<<i+1<<"'s Name :";
                cin>>subject[i];
            }
            cout<<"\nCreate Your Login Password : ";
            cin>>passwd;
            cout<<"\nEnter The Unique Keyword to Recover password : ";
            cin>>rpasswd;
            cout<<"\n\nPlease Note Your Username is ID/Roll No.\n";
        }
        
        //this function authenticates the login of both the student and 
        // faculties With reference to there unique ID/Password login is Provided.

        int login(){
            if((strcmp(::un, rollno))==0){
                cout<<"\nEnter the Login Password : ";
                int len=0;
                len = strlen(passwd);
                char inputpasswd[20];
                for(int i=0;i<len;i++){
                    inputpasswd[i] = getch();
                    cout<<"#"; 
                } 
                // inputpasswd [i]=NULL 
                //cout<<"\nThe Entered Password is "<<inputpasswd; 
                if ((strcmp (::un, rollno) == 0) && (strcmp (passwd, inputpasswd) == 0) ) 
                    return 1; 
                    else 
                    return 0; 
                }
                else 
                  return 0;
            }      
//        this function help both the students&faculties to recover the Dase. 
//        with the help of unique keyword provided by the Admin 
         int recover (){
            //cout <<" \nThe Input Username is "<<: :un; 
            char key[20];
            if(strcmp(::un, rollno)==0){
                cout<<" \nEnter the Unique Keyword (Provided by Admin ): ";
                cin>>key;
                if((strcmp(key,rpasswd)==0)){
                    cout<<"\nYou are a Valid User.";
                    cout<<"\nYour Password is "<<passwd;
                    cout<<"\nPlease Exit to Login Again ";
                    return 1;
                }
                else{
                    return 0;
                }
            }else{
                return 0;
            }
         }
         //This function displays the faculty profile to the faculty at their respective portals 

          int faprofile () 
           { 
            if ( (strcmp (:: un, rollno) ==0)) 
            {
            cout<< "\nFaculty Name "<<name;
            cout<<" \nFaculty Father's Name "<<fname; 
            cout<<"\nFaculty Mobile No. "<<mobile;
            cout<<" \nFaculty E-Mail ID"<<mail; 
            return 1; 
            }
            else 
            return 0; 
        }
        //This function displays the different subjects of the faculty at their Respective Portals

        int knowfasub(){
            if((strcmp(::un,rollno)==0)){
                cout<<"\nFaculty Total Subjects : "<<totsub;
                for(int i=0;i<totsub;i++){
                    cout<<"\n\tSubject"<<i+1<<" : "<<subject[i];
                }
                return 1;
            }
            else{
                return 0;
            }
        }
        //this function helps a facultty to add a subject in their module. 
        void addfasub(){
            if ((strcmp(:: un, rollno) ==0) ){
            cout<<"\nEnter the New Subject : ";
            cin>>subject[totsub];
            totsub++; 
            cout<<"\n\nNew Subject Added Successful1ly. . ."; 
            }
        }
        //this fuction helps a faculty to delete a subject from their module.
        void delfasub (){
            knowfasub (); 
            int de=0; 
            if((strcmp (::un,rollno) ==0)){
                if (totsub==0 || totsub<0){
                    totsub=0; 
                    cout<<"\nNone Subjects Exist. .."; 
                    getch ();
                    exit(0); 
                }
                cout<<" \nEnter the Subject No. to be Deleted: ";
                cin>>de; 
                if (de==totsub) {
                    totsub--;
                    strcpy(subject [totsub], " ") ;
                }
                else if (totsub==1) {
                    totsub=0; 
                    strcpy (subject [totsub], " ");
                }
                else{
                  de--;
                  strcpy(subject[totsub]," ");
                  for(int p=de;p<totsub;p++){
                      strcpy(subject[p],subject[p+1]);
                  } 
                  totsub--;
                }
                cout<<"\nRecords Updated Successfully...";
            }
        }
        //this function helps a faculty to modify his personal profile
        void modfaprofile(){
            if((strcmp (::un,rollno) ==0)){
                cout<<"\nThe Profile Details are : ";
                cout<<" \n 1. Faculty E-Mail : "<<mail; 
                cout<<" \n 2. Facultty Mobile: "<<mobile; 
                int g= -1 ; 
                cout<<" \n\nEnter the Detail No. to be Modified:" ;
                cin>>g;
                if(g==1){
                    char nmail [50]; 
                    cout<<" \nEnter the New Mail Address:";
                    strcpy (mail, nmail) ; 
                    cout<<" \nRecords Updated Successfully."; 
                }
                else if(g==2){
                    char nmobile [15] ; 
                    cout<< " \nEnter the New Mobile No. "; 
                    gets (nmobile) ; 
                    strcpy (mobile, nmobile); 
                    cout<< " \nRecords Updated Successfully. .. ";
                }
                else{
                    cout<<"\nInvalid Input Provided...";
                }
            }
        }
        //This function displays the students profile at the students portal
        int stprofile(){
            if((strcmp (::un,rollno) ==0)){
                cout<<" \nStudent Name :"<<name; 
                cout<< " \nStudent Father 's Name : "<<fname; 
                cout<< " \nStudent Mobile No.  "<<mobile; 
                cout<<" \nStudent E-Mail ID "<<mail; 
                return 1;
            }
            else{
                return 0;
            }
        } 
        //This function displays the different enrolled subjects of the respective students ...
        // according to their profile.
        int knowstsub(){
          if((strcmp (::un,rollno) ==0)){
              cout<<"\nStudents Total Subjects : "<<totsub;
              for(int i=0;i<totsub;i++){
                  cout<<"\n\tSubject "<<i+1<<" : "<<subject[i];
              }
              return 1;
        }else{
            return 0;
        }
    }
    // this function allows the student to add a subiects in total subjects of the student profile..
    
    void addstsub()
    {
        if ((strcmp(::un,rollno)==0))
        {
            cout<<"\n\nNew Subject Added Successfully...";
        }
    }
    //this function allows the student to delete a Subject in total subjects of the student profile...
    
    void delstsub()
    {
        knowstsub();
        int de=0;
        if((strcmp(::un,rollno)==0))
        {
            if(totsub==0||totsub<0)
            {
                totsub=0;
                cout<<"\nNone Subjects Exist....";
                getch();
                exit(0);
            }
            cout<<"\nEnter the subject No. to be Deleted: ";
            cin>>de;
            if(de==totsub)
            {
                totsub--;
                strcpy(subject[totsub]," ");
            }
            else if(totsub==1)
            {
                totsub=0;
                strcpy(subject[totsub]," ");
            }
            else
            {
                de--;
                strcpy(subject[totsub]," ");
                for(int p=de;p<totsub;p++)
                {
                    strcpy(subject[p],subject[p+1]);
                }
                totsub--;
            }
               cout<<"\n Records Updated Successfully....";
            }
    }
    //this function allows the student to modify their personal at the student portal
    
    void modstprofile()
    {
        if ((strcmp(::un,rollno) ==0))
        {
            cout<<"\nThe Profile Details are : ";
            cout<<"\n 1. Student E-Mail : "<<mail;
            cout<<"\n 2. student Mobile : "<<mobile;
            int g=-1;
            cout<<"\n\nEnter the Detail No. to be modified : ";
            cin>>g;
            if(g==1)
            {
                char nmail[50];
                cout<<"\nEnter the New Mail Address : ";
                strcpy(mail,mail);
                cout<<"\nRecords Updated Successfully....";
            }
            else if(g==2)
            {
                char nmobile[15];
                cout<<"\nEnter the New Mobile No. : ";
                gets(nmobile);
                strcpy(mobile,nmobile);
                cout<<"\nRecords Updated Successfully....";
              }
            else
                cout<<"\nInvalid Input Provided....";
        }
    }
    //This function allow the ADMIN to make a new Record Entry for the
    //different new faculties....new faculty records are updated with the help of this function
    
            void getfadata()
            {
                cout<<"\nEnter the faculty name : ";
                gets(name);
                cout<<"\nEnter the Faculty ID/Roll no. : ";
                cin>>rollno;
                cout<<"\nEnter the Faculty Father's Name :";
                gets(fname);
                cout<<"\nEnter the E-Mail Id : ";
                gets(mail);
                cout<<"\nEnter the Mobile no. : ";
                gets(mobile);
                cout<<"\nEnter the Total Subjects : ";
                cin>>totsub;
                //cout<<"\nThe total subjects choosen are : "<<totsub;
                for(int i=0;i<totsub;i++){
                    cout<<"\nEnter the Subject "<<i+1<<"Name : ";
                    cin>>subject[i];
                }
                cout<<"\nCreate your Login Password : ";
                cin>>passwd;
                cout<<"\nEnter the Unique Keyword to Recover Password : ";
                cin>>rpasswd;
                cout<<"\n\n Please note your Username is ID/Roll no. \n";        
        }
        // This function Displays all the relevant information to the admin related
        // to the Students at the ADMIN portals
        void stdisplay(){
            cout<<"\n Students Name                   : "<<name;
            cout<<"\n Students ID/Roll No             : "<<rollno;
            cout<<"\n Students Father's Name          : "<<fname;
            cout<<"\n Students Mobile No              : "<<mobile;
            cout<<"\n Students E-mail Id              : "<<mail;
            cout<<"\n Students Subjects               : "<<totsub;
            for(int i=0;i<totsub;i++){
                cout<<"\n     Subject  "<<i+1<<" : "<<subject[i];
            }
            if(totsub == 0){
                cout<<"(None Of the Subjects are Specified... )";
            }
            
        }

        // This function displays all the relevant information to the admin related
        // to the faculty at the Admin portals
        void fadisplay(){
            cout<<"\n Faculty Name                   : "<<name;
            cout<<"\n Faculty ID/Roll No             : "<<rollno;
            cout<<"\n Faculty Father's Name          : "<<fname;
            cout<<"\n Faculty Mobile No              : "<<mobile;
            cout<<"\n Faculty E-mail Id              : "<<mail;
            cout<<"\n Faculty Subjects               : "<<totsub;
            for(int i=0;i<totsub;i++){
                cout<<"\n     Subject  "<<i+1<<" : "<<subject[i];
            }
            if(totsub == 0){
                cout<<"(None Of the Subjects are Specified... )";
            }
            
        }
 }a;
 Admin f;

// a & f are the objects of the class Admin

void main(){
    int ch;
    system("cls");//Clrscr() was giving errors so i used system("clr")
    cout<<"\n\n\t\t\tEnter to Coninue ";
    cout<<"\n\n\t\t\tWelcome to OOP Mini Project Portal ";
    getch();
    system("cls");//Clrscr() was giving errors so i used system("clr")
    cout<<"\n\n\t\t\tPress 1 For Admin Portal ";
    cout<<"\n\t\t\tPress 2 For Faculty Portal ";
    cout<<"\n\t\t\tPress 3 For Students Portal ";
    cout<<"\n\t\t\tEnter Your Choice : ";
    cin>>ch;
    system("cls");//Clrscr() was giving errors so i used system("clr")
    if(ch == 1){
      char adminuser [20] , adminpass [20]; 
      cout<<" \n\t\t\tWelcome To Admin Login Portal "; 
      cout<<"\nEnter the UserName : ";
      cin>>adminuser;  
      cout<<"\nEnter the Password : ";
      int k;
      for( k=0 ;k<8;k++){
          adminpass[k] = getch();
          cout<<"*";
      }  
      getch();
      adminpass[k]=NULL;
      if((strcmp(adminuser,"admin")==0)&&(strcmp(adminpass,"password")==0)){
            system("cls");
      } 
      else{
          cout<<"\n\n\t\t\t Invalid Access to Portal ";
          cout<<"\n\n\t\t\t\t  Thank You !!!";
          getch();
          exit(0);
      } 
      char opera='y';
      do{
          int tmp;
          cout<<"\n\t\t\t\t Welcome to Admin Panel";
          cout<<"\n\n Press 1 to Add Faculty Record";
          cout<<"\n Press 2 to Add Multiple Records of Faculty";
          cout<<"\n Press 3 to View All Records of Faculty ";
          cout<<"\n Press 4 to Delete a Faculty Record ";
          cout<<"\n Press 5 to Add Student Record";
          cout<<"\n Press 6 to Add Multiple Records of Students ";
          cout<<"\n Press 7 to View All Records of Students ";          
          cout<<"\n Press 8 to Delete a Student Record ";
          cout<<"\n Press 9 to Exit ";
          cout<<"\n\n Enter Your Choice : ";
          cin>>tmp;
          system("cls");//Clrscr() was giving errors so i used system("clr")
          //This is for entering single faculty Record
          if(tmp==1){
              cout<<"\nEnter the Details :- ";
              fstream fs;
              fs.open("fainfo.txt", ios::in|ios::out | ios::ate);
              a.getfadata();
              fs.write((char *)&a,sizeof(Admin));
              fs.close();
              cout<<"\nRecords Entered Successfully..."; 
          }  
          //This is for entering multiple faculty Record
          if(tmp==2){
              int m=0;  
              fstream fs;
              fs.open("fainfo.txt", ios::in|ios::out | ios::ate);
              
              do
              {
              cout<<"\nEnter the Details :-";
              a.getfadata();
              fs.write((char *)&a,sizeof(Admin));
              cout<<"Press 0 if you want to add More Records : ";
              cin>>m;
              }while(m==0);
              fs.close();
              cout<<"\nRecords Entered Successfully...";
          }
          //This is for entering multiple faculty Record
          //For viewing all faculty Records
          if(temp==3){
              fstream fs;
              fs.open("fainfo.txt",ios::in);
              fs.seekg(0);
              while(!fs.eof()){
                  fs.read((char *)&a,sizeof(Admin));
                  a.fadisplay();
              }
              fs.close();
          } 
          //For viewing all faculty Records
        //   For Deleting a faculty Record
          if(temp==4){
              
          } 
        //   For Deleting a faculty Record
      }while(true);
    }


}

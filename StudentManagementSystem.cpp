#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<stdio.h>
#include<fstream>
#include<conio.h>
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
    
};

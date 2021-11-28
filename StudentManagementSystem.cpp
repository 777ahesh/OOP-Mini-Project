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
          if(tmp==3){
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
          if(tmp==4){
              char tmpfaid[15];
              int de=0,result=-1;
              cout<<"\nEnter the Faculty ID/Roll No : ";
              cin>>tmpfaid;
              fstream fs;
              fs.open("fainfo.txt",ios::in);
              fstream fs1;
              fs1.open("fanewinfo.txt",ios::out|ios::ate);
              while(!fs.eof()){
                  fs.read((char *)&a,sizeof(Admin));
                  result = strcmp(tmpfaid,a.rollno);
                  if(result == 0){
                      de=1;
                  }
                  else{
                      fs1.write((char *)&a,sizeof(Admin));
                  }
                } 
                  if(de == 1){
                      cout<<"\nRecord Deleted Successfully...";
                  }else{
                      cout<<"\nRecord Not Found...";
                  }
                  fs.close();
                  fs1.close();
                  remove("fainfo.txt");
                  rename("fanewinfo.txt","fainfo.txt");
          } 
        //   For Deleting a faculty Record
        // For Single Student Record Entry
          if(tmp == 5)
          {
              cout<<"\nEnter the Details :- ";
              fstream fs;
              fs.open("stinfo.txt", ios::in|ios::out | ios::ate);
              a.getstdata();
              fs.write((char *)&a,sizeof(Admin));
              fs.close();
              cout<<"\nRecords Entered Successfully..."; 
          }
            // For Single Student Record Entry
            //for multiple student record input
           if(tmp==6){
              int m=0;  
              fstream fs;
              fs.open("stinfo.txt", ios::in|ios::out | ios::ate);
              
              do
              {
              cout<<"\nEnter the Details :-";
              a.getstdata();
              fs.write((char *)&a,sizeof(Admin));
              cout<<"Press 0 if you want to add More Records : ";
              cin>>m;
              }while(m==0);
              fs.close();
              cout<<"\nRecords Entered Successfully...";
           } 
             //for multiple student record input
            //for view of all student record
            if(tmp==7){
              fstream fs;
              fs.open("stinfo.txt",ios::in);
              fs.seekg(0);
              while(!fs.eof()){
                  fs.read((char *)&a,sizeof(Admin));
                  a.stdisplay();
              }
              fs.close();
            }
            //for view of all student record
            //for deleting a student record 
            if(tmp==8){
              char tmpstid[15];
              int de=0,result=-1;
              cout<<"\nEnter the Students ID/Roll No : ";
              cin>>tmpstid;
              fstream fs;
              fs.open("stinfo.txt",ios::in);
              fstream fs1;
              fs1.open("stnewinfo.txt",ios::out|ios::ate);
              while(!fs.eof()){
                  fs.read((char *)&a,sizeof(Admin));
                  result = strcmp(tmpstid,a.rollno);
                  if(result == 0){
                      de=1;
                  }
                  else{
                      fs1.write((char *)&a,sizeof(Admin));
                  }
                } 
                  if(de == 1){
                      cout<<"\nRecord Deleted Successfully...";
                  }else{
                      cout<<"\nRecord Not Found...";
                  }
                  fs.close();
                  fs1.close();
                  remove("stinfo.txt");
                  rename("stnewinfo.txt","stinfo.txt");
            }
            //for deleting a student record 
            // For Exit
            if(tmp==9){
                cout<<"\n\n\n\n\t\t\t Thank You !!!";
                getch();
                exit(0);
            } 
            // For Exit
            //For Invalid Input
            if(tmp<1 || tmp>9){
                system("cls");//Clrscr() was giving errors so i used system("clr")
                cout<<"\n\n\n\n\t\t\t Invalid Input...";
            } 
            //For Invalid Input
            getch();
            cout<<"\n\nPress y for coninuing Otherwise Press n";
            cin>>opera;
            if(opera != 'y'){
                getch();
                system("cls");//Clrscr() was giving errors so i used system("clr")
                cout<<"\n\n\n\n\n\t\t\t\t\tThank You!!!";
                getch();
            }//closing of thankyou
      }while(opera == 'Y'||opera =='y');
    }//closing of admin login

    // Begin of Faculty View Portal
    if(ch==2){
        system("cls");//Clrscr() was giving errors so i used system("clr")
        char un[20];
        int val ,s=0;
        cout<<"\n\t\tWelcome to Faculty Login Page ";
        cout<<"\n\nEnter the Username : ";
        cin>>::un;
        fstream fs;
        fs.open("fainfo.txt",ios::in|ios::binary);
        fs.seekg(0);
        while(!fs.eof()){
            val =-1;
            fs.read((char *)&f,sizeof(Admin));
            val=f.login();
            if(val==1){
                s=1;
                break;
            }
        }
        fs.close();
        //if First Login is valid
        if(s==1){
            system("cls");//Clrscr() was giving errors so i used system("clr")
        }
        //if First Login is valid

        // If first Login is Invalid then
        if(s!=1){
            system("cls");//Clrscr() was giving errors so i used system("clr")
            int ho = 0;
            cout<<"\n\n\t\tYour Login Credentials are In-Correct";
            cout<<"\nThe username is Your id/RollNo";
            cout<<"\nThe Password is Case-Sensitive";
            cout<<"\n1.Press 1 to recover Password ";
            cout<<"\n2.Press 2 to to Reattempt with Login ";
            cout<<"\nEnter Your Choice : ";
            cin>>ho;
            // Recover Password
            if(ho==1){
                cout<<"\nEnter the Username : ";
                cin>>::un;
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                int re,su=-1;
                while(!fs.eof()){
                    re=-1;
                    fs.read((char *)&f,sizeof(Admin));
                    re=f.recover();
                    if(re==1){
                        su=1;
                        break;
                    }
                }
                fs.close();
                if(su==1){
                    getch();
                    system("cls");//Clrscr() was giving errors so i used system("clr")
                    cout<<"\n\n\n\n\t\t\tThank You!!!";
                    getch();
                    exit(0);
                }
                else{
                    cout<<"\nYou are a Invalid User ";
                    getch();
                    exit(0);
                }
            }
            // Recover Password
            // Reattempt of Login
                if(ho ==2){
                    cout<<"\n\nEnter the Username : ";
                    cin>>::un;
                    fstream fs;
                    fs.open("fainfo.txt",ios::in |ios::binary);
                    fs.seekg(0);
                    int suc = -1,valu;
                    while(!fs.eof()){
                        valu =-1;
                        fs.read((char *)&f,sizeof(Admin));
                        valu = f.login();
                        if(valu == 1){
                            suc = 1;
                            break;
                        }
                    }
                    fs.close();
                    if(suc==1){
                        system("cls");//Clrscr() was giving errors so i used system("clr")
                    }else{
                    getch();
                    cout<<"\n You are a Invalid User ...";
                    cout<<"\n\n\n\n\t\t\tThank You!!!";
                    getch();
                    exit(0);
                    exit(0);
                    }

                }
            if(ho!= 1 || ho!=2){
                cout<<" \n\nInvalid Input Provided. ";
                cout<<" \n\n\t\t\tThank You !!!", 
                getch (); 
                exit (0);  
            }
            // Reattempt of Login
        } 
        // If first Login is Invalid then 
    }
    char con='y';
    do{
        system("cls");//Clrscr() was giving errors so i used system("clr")
        cout<<" \n\n\t\t\twelcome to Faculty Panel ";
        cout<<" \n\n\t\t\t\t\t\t Your UserId is "<<::un; 
        cout<<" \n\nPress 1 to View Your Profile. "; 
        cout<<" \nPress 2 to Know Your Subjects. "; 
        cout<<" \nPress 3 to Add a Subject."; 
        cout<<" \nPress 4 to Delete a Subject . "; 
        cout<<" \nPress 5 to Modify Your Profile. ";
        int choice;
        cout<<"\n\nEnter Your Choice : ";
        cin>>choice;
        if(choice==1){
            fstream fs;
            fs.open("fainfo.txt",ios::in);
            fs.seekg(0);
            int x;
            while(!fs.eof()){
                x=0;
                fs.read((char *)&f,sizeof(Admin));
                x=f.faprofile();
                if(x==1){
                    break;
                }
            }
            fs.close();
        }//closing of choice == 1
        if(choice==2){
            fstream fs;
            fs.open("fainfo.txt",ios::in);
            fs.seekg(0);
            int y;
            while(!fs.eof()){
                y=0;
                fs.read((char *)&f,sizeof(Admin));
                int y=f.knowfasub();
                if(y==1){
                    break;
                }
            }
            fs.close();
        }//closing of choice == 2

        if(choice==3){
            fstream fs;
            fstream fs1;
            fs.open ("fainfo.txt", ios::in|ios::binary); 
            fs1.open ("tmpfainfo.txt", ios::out |ios::ate);
            fs.seekg(0);
            while(!fs.eof()){
                fs.read((char *)&f,sizeof(Admin));
                f.addfasub();
                fs1.write((char *)&f, sizeof(Admin));
            }
            fs.close();
            fs1.close();
            remove("fainfo.txt");
            rename("tmpfainfo.txt","fainfo.txt");
        }//closing of choice == 3
        if(choice ==4){
            fstream fs;
            fs.open("fainfo.txt",ios::in|ios::binary);
            fstream fs1;
            fs1.open("delfainfo.txt",ios::out|ios::ate);
            fs.seekg(0);
            while(!fs.eof()){
                fs.read((char *)&f,sizeof(Admin));
                f.delfasub();
                fs1.write((char *)&f,sizeof(Admin));
            }
            fs.close();
            fs1.close();
            remove("fainfo.txt");
            rename("delfainfo.txt","fainfo.txt");
        }//closing of choice==4
        if(choice==5){
            fstream fs;
            fstream fs1;
            fs.open("fainfo.txt",ios::in|ios::binary);
            fs.seekg(0);
            fs1.open("modfainfo.txt",ios::out|ios::ate);
            while(!fs.eof()){
                fs.read((char *)&f,sizeof(Admin));
                f.modfaprofile();
                fs1.write((char *)&f,sizeof(Admin));
            }
            fs.close();
            fs1.close();
            remove("fainfo.txt");
            rename("modfainfo.txt","fainfo.txt");
        } //end of choice == 5

        if (choice<1 || choice>5){
            cout<<"\nInvalid Input...";
        }
        cout<<"\n\n\t\t\tPress Enter to continue";
        getch();
        cout<<"\n\n\t\t\t\tPress y to continue other vise press n";
        cin>>con;

        if (con!= 'y' && con!='Y') {
        system("cls");//Clrscr() was giving errors so i used system("clr") 
        cout<<" \n\n\n \n\n\t\t\t\tThank You !!! "; 
        getch (); 
        exit (0);
        }
    }while (con== 'y'||con== 'Y');
    // End of Faculty View Portal
    // Begin of Student View portal

      if(ch==3){
        system("cls");//Clrscr() was giving errors so i used system("clr")
        // char un[20];
        int value ,s1=0;
        cout<<"\n\t\tWelcome to Students Login Page ";
        cout<<"\n\nEnter the Username : ";
        cin>>::un;
        fstream fs;
        fs.open("stinfo.txt",ios::in|ios::binary);
        fs.seekg(0);
        while(!fs.eof()){
            value =-1;
            fs.read((char *)&f,sizeof(Admin));
            value=f.login();
            if(value==1){
                s1=1;
                break;
            }
        }
        fs.close();
        //if First Login is valid
        if(s1==1){
            system("cls");//Clrscr() was giving errors so i used system("clr")
            //Welcome to Students Login Page first input is valid
        }
        //if First Login is valid

        // If first Login is Invalid then
        if(s1!=1){
            system("cls");//Clrscr() was giving errors so i used system("clr")
            int sho = 0;
            cout<<"\n\n\t\tYour Login Credentials are In-Correct";
            cout<<"\nThe username is Your id/RollNo";
            cout<<"\nThe Password is Case-Sensitive";
            cout<<"\n1.Press 1 to recover Password ";
            cout<<"\n2.Press 2 to to Reattempt with Login ";
            cout<<"\nEnter Your Choice : ";
            cin>>sho;
            // Recover Password
            if(sho==1){
                cout<<"\nEnter the Username : ";
                cin>>::un;
                fstream fs;
                fs.open("stinfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                int re,su=-1;
                while(!fs.eof()){
                    re=-1;
                    fs.read((char *)&f,sizeof(Admin));
                    re=f.recover();
                    if(re==1){
                        su=1;
                        break;
                    }
                }
                fs.close();
                if(su==1){
                    getch();
                    system("cls");//Clrscr() was giving errors so i used system("clr")
                    cout<<"\n\n\n\n\t\t\tThank You!!!";
                    getch();
                    exit(0);
                }
                else{
                    cout<<"\nYou are a Invalid User ";
                    cout<<"\nThank You !!! ";
                    getch();
                    exit(0);
                }
            }
            // Recover Password
            // Reattempt of Login
                if(sho ==2){
                    cout<<"\n\nEnter the Username : ";
                    cin>>::un;
                    fstream fs;
                    fs.open("stinfo.txt",ios::in |ios::binary);
                    fs.seekg(0);
                    int suc = -1,valu;
                    while(!fs.eof()){
                        valu =-1;
                        fs.read((char *)&f,sizeof(Admin));
                        valu = f.login();
                        if(valu == 1){
                            suc = 1;
                            break;
                        }
                    }
                    fs.close();
                    if(suc==1){
                        system("cls");//Clrscr() was giving errors so i used system("clr")
                    }else{
                    getch();
                    cout<<"\n You are a Invalid User ...";
                    cout<<"\n\n\n\n\t\t\tThank You!!!";
                    getch();
                    exit(0);
                    exit(0);
                    }

                }
            if(sho!= 1 || sho!=2){//corrections
                cout<<" \n\nInvalid Input Provided. ";
                cout<<" \n\n\t\t\tThank You !!!", 
                getch (); 
                exit (0);  
            }
            // Reattempt of Login
        } 
        // If first Login is Invalid then 
    }
    // Begin of Student Panel
    char moreop='y';
    do{
        system("cls");//Clrscr() was giving errors so i used system("clr")
        cout<<" \n\n\t\t\twelcome to Student Panel ";
        cout<<" \n\n\t\t\t\t\t\t Your UserId is "<<::un; 
        cout<<" \n\nPress 1 to View Your Profile. "; 
        cout<<" \nPress 2 to Know Your Subjects. "; 
        cout<<" \nPress 3 to Add a Subject."; 
        cout<<" \nPress 4 to Delete a Subject . "; 
        cout<<" \nPress 5 to Modify Your Profile. ";
        int inchoice;
        cout<<"\n\nEnter Your Choice : ";
        cin>>inchoice;
        if(inchoice==1){
            fstream fs;
            fs.open("stinfo.txt",ios::in);
            fs.seekg(0);
            int x;
            while(!fs.eof()){
                x=0;
                fs.read((char *)&f,sizeof(Admin));
                x=f.stprofile();
                if(x==1){
                    break;
                }
            }
            fs.close();
        }//closing of inchoice == 1
        if(inchoice==2){
            fstream fs;
            fs.open("stinfo.txt",ios::in);
            fs.seekg(0);
            int y;
            while(!fs.eof()){
                y=0;
                fs.read((char *)&f,sizeof(Admin));
                int y=f.knowstsub();
                if(y==1){
                    break;
                }
            }
            fs.close();
        }//closing of inchoice == 2

        if(inchoice==3){
            fstream fs;
            fstream fs1;
            fs.open ("stinfo.txt", ios::in|ios::binary); 
            fs1.open ("tmpstinfo.txt", ios::out |ios::ate);
            fs.seekg(0);
            while(!fs.eof()){
                fs.read((char *)&f,sizeof(Admin));
                f.addstsub();
                fs1.write((char *)&f, sizeof(Admin));
            }
            fs.close();
            fs1.close();
            remove("stinfo.txt");
            rename("tmpstinfo.txt","stinfo.txt");
        }//closing of inchoice == 3
        if(inchoice ==4){
            fstream fs;
            fs.open("stinfo.txt",ios::in|ios::binary);
            fstream fs1;
            fs1.open("delstinfo.txt",ios::out|ios::ate);
            fs.seekg(0);
            while(!fs.eof()){
                fs.read((char *)&f,sizeof(Admin));
                f.delstsub();
                fs1.write((char *)&f,sizeof(Admin));
            }
            fs.close();
            fs1.close();
            remove("stinfo.txt");
            rename("delstinfo.txt","stinfo.txt");
        }//closing of inchoice==4
        if(inchoice==5){
            fstream fs;
            fstream fs1;
            fs.open("stinfo.txt",ios::in|ios::binary);
            fs.seekg(0);
            fs1.open("modstinfo.txt",ios::out|ios::ate);
            while(!fs.eof()){
                fs.read((char *)&f,sizeof(Admin));
                f.modstprofile();
                fs1.write((char *)&f,sizeof(Admin));
            }
            fs.close();
            fs1.close();
            remove("stinfo.txt");
            rename("modstinfo.txt","stinfo.txt");
        } //end of inchoice == 5

        if (inchoice<1 || inchoice>5){
            cout<<"\nInvalid Input...";
        }
        cout<<"\n\n\t\t\tPress Enter to continue";
        getch();
        cout<<"\n\n\t\t\t\tPress y to continue other vise press n";
        cin>>moreop;

        if (moreop!= 'y' && moreop!='Y') {
        system("cls");//Clrscr() was giving errors so i used system("clr") 
        cout<<" \n\n\n \n\n\t\t\t\tThank You !!! "; 
        getch (); 
        exit (0);
        }
    }while(moreop== 'y'|| moreop== 'Y');
    
}  

    // End of Student View portal



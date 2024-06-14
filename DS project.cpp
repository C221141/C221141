#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(short x, short y) //Custom gotoxy() function
{
    COORD pos= {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);

}
class Node /// it is for students
{
public:
    string roll_no,sem,course,re_course,section;
    string name;

    double c1,c1Lab,eee,eeeLab,math,phy,eng,urem;///for marks
    double marks, per;
    Node *next_add;
};
class Linked_List
{
public:
    Node *head = NULL;
    string roll_no;
    double c1,c1Lab,eee,eeeLab,math,phy,eng,urem; ///for 1ST SEMESTER marks
 double i=0,ii=0,iii=0,iv=0,v=0,vi=0,vii=0,viii=0;

    void Insert()
    {
        string n,se,sec;///n=name
        double m;

        cout << "\n\n Enter Roll no. : ";
        cin >> roll_no;
        cin.ignore();
        cout << "\n\n Enter Name : ";

        getline(cin,n);
        cout << "\n\n Enter Semester : ";
        cin>>se;
        cout << "\n\n Enter Section : ";
        cin>>sec;

        //cout << "\n\n Enter Marks : ";

        //cin >> m;
        Node *new_node = new Node;
        new_node->roll_no = roll_no;
        new_node->name = n;
        new_node->sem = se;
        new_node->section = sec;
        ///new_node->marks = m;
        new_node->per = m / 100 * 100;
        new_node->next_add = NULL;
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next_add != NULL)
            {
                ptr = ptr->next_add;
            }
            ptr->next_add = new_node;
        }
        cout << "\n\n\n NEW STUDENT INSERTED SUCCESSFULLY...";
    }
    void search()
    {
        if (head == NULL)
        {
            cout << "\n\n LIST is Empty...";
        }
        else
        {

            int found = 0;
            cout << "\n\n Enter RoLL No. For Search : ";
            cin >> roll_no;
            Node *ptr = head;
            while (ptr != NULL)
            {
                if (roll_no == ptr->roll_no)
                {
                    cout << "\n\n Roll No : "<<ptr->roll_no;
                    cout << "\n\n Name : "<<ptr->name;
                    cout << "\n\n Semester: "<<ptr->sem;
                    cout << "\n\n Section: "<<ptr->section;
                    found++;
                }
                ptr = ptr->next_add;
            }
            if (found == 0)
            {
                cout << "\n\n Search Roll No. " << roll_no << "can't found...";
            }
        }
    }
    void count()
    {
        if (head == NULL)
        {
            cout << "\n\n Linked List is Empty...";
        }
        else
        {
            int c = 0;
            Node *ptr = head;
            while (ptr != NULL)
            {
                c++;
                ptr = ptr->next_add;
            }
            cout << "\n\n Total No. of Students : " << c;
        }
    }
    void Update()
    {
        if (head == NULL)
        {
            cout << "\n\n Link LIst is Empty...";
        }
        else
        {

            int found = 0;
            cout << "\n\n Enter Roll No. For Updation : ";
            cin >> roll_no;
            Node *ptr = head;
            while (ptr != NULL)
            {
                if (roll_no == ptr->roll_no)
                {
                    cout << "\n\n Enter New ROll no. : ";
                    cin >> ptr->roll_no;
                    cin.ignore();
                    cout << "\n\n Enter Name : ";
                    string nam,s,sc;
                    getline(cin,nam);
                    cin.ignore();
                    ptr->name=nam;
                    cout << "\n\n Enter Semester: ";
                    cin>>s;
                    ptr->sem=s;

                    cout << "\n\nEnter Section: ";
                    cin>>sc;
                    ptr->section=sc;
                    found++;
                }
                ptr = ptr->next_add;
            }
            if (found == 0)
            {
                cout << "\n\n Search Roll No. " << roll_no << "can't found...";
            }
        }
    }

    void Del()
    {
        if (head ==NULL)
        {
            cout << "\n\n Linked list is empty";
        }
        else
        {

            int found = 0;
            cout << "\n\n Enter Roll no. for deletion : ";
            cin >> roll_no;
            if (roll_no == head->roll_no)
            {
                Node *ptr = head;
                head = head->next_add;
                cout << "\n\n Record Deleted successfully";
                found++;
                delete ptr;
            }
            else
            {
                Node *pre = head;
                Node *ptr = head->next_add;
                while (ptr != NULL)
                {
                    if (roll_no == ptr->roll_no)
                    {
                        pre->next_add = ptr->next_add;
                        cout << "\n\n Record Deleted successfully";
                        found++;
                        delete ptr;
                        break;
                    }
                    pre = ptr;
                    ptr = ptr->next_add;
                }
            }
            if (found == 0)
            {
                cout << "\n\n Delete roll no. " << roll_no << " can't Found....";
            }
        }
    }
    void Log_search()
    {
LOGIN:
        string id,pass;
        cout<<"**N:B: ID AND PASSWORD WILL BE SAME**";
        cout<<"?\n\n============================================================="<<endl;
        cout<<"\n ENTER YOUR ID : ";
        cin>>id;
        cout<<"\n ENTER YOUR PASS : ";
        cin>>pass;
        roll_no=id;
        if (head == NULL)
        {
            cout << "\n\n LIST is Empty...";
        }
        else
        {

            int found = 0,f;
            Node *ptr = head;
            while (ptr != NULL)
            {
                if (roll_no == ptr->roll_no)
                {

                    system("cls");
                    cout<<"============================================================="<<endl;
                    cout << "\n\n 1.CHECK RESULT -->";
                    cout << "\n\n 2.CHECK WAIVER STATUS -->";
                    cout << "\n\n 3.CHECK SYLLABUS -->";
                    cout << "\n\n 4.CHECK RTAKE COURSE -->";
                    cout << "\n\n 5.TO GO BACK -->";
                    cout<<"\n============================================================="<<endl;

                    cout << "\n\n\n ENTER YOUR CHOICE : ";
                    int sc;
                    cin >> sc;
                    switch (sc)
                    {
                    case 1:
                        system("cls");
                        int sem;
                        cout<<"ENTER YOUR SEMESTER (Ex :1/2/3/4) :";
                        cin>>sem;
                        cout<<"COURSE CODE        COURSE TITLE             CREDIT    POINTS "<<endl;
                        cout<<"CSE-1121       Computer Programming I	       3      "<<i<<endl;
                        cout<<"CSE-1122     Computer Programming I Lab       1.5      "<<ii<<endl;
                        cout<<"EEE-1121    Basic Electrical Engineering        3      "<<iii<<endl;
                        cout<<"EEE-1122    Basic Electrical Engineering Lab  1.5      "<<iv<<endl;
                        cout<<"MATH-1107          Mathematics I                3      "<<v<<endl;
                        cout<<"PHY-1101             Physics I                  3      "<<vi<<endl;
                        cout<<"UREL-1106         Advanced English              2      "<<vii<<endl;
                        cout<<"UREM-1101     Text of Ethics and Morality       1      "<<viii<<endl;
                        cout<<"========================================================="<<endl;
                         double gpa;
                         gpa=(i*3)+(ii*1.5)+(iii*3)+(iv*1.5)+(v*3)+(vi*3)+(vii*2)+(viii*1);
                        double cgpa;
                        cgpa=gpa/18;
                        cout<<"YOUR CGPA IS "<<cgpa<<endl<<endl;;
                        cout<<"PRESS 1 TO GO LOGIN PAGE : ";
                        int si;
                        cin>>si;
                        if (si==1)
                        {
                            system("cls");
                        goto LOGIN;

                        }
                        break;
                    case 2:
                        system("cls");
                        if (cgpa>=3.65)
                        {
                            cout<<" CGPA >=3.65 WILL BE ELIGIBLE..."<<endl;
                            cout<<" \ YOUR CGPA IS "<<cgpa<<" SO, ";
                            cout<<" CONGRATULATIONS... YOU ARE ELIGIBLE FOR WAIVER"<<endl;
                        }

                        else
                        {   cout<<" CGPA >=3.65 WILL BE ELIGIBLE..."<<endl;
                             cout<<" \YOUR CGPA IS "<<cgpa<<" SO, ";
                             cout<<"UNFORTUNATELY YOU ARE NOT ELIGIBLE FOR WAIVER"<<endl;
                        }
                        break;
                    case 3:
                        system("cls");
                        cout<<"YOUR WHOLE SYLLABUS IS GIVEN BELOW:"<<endl<<endl;

                        cout<<"FIRST SEMESTER : "<<endl;
                        cout<<"========================================================="<<endl;
                        cout<<"COURSE CODE        COURSE TITLE             CREDIT    "<<endl;
                        cout<<"CSE-1121       Computer Programming I	       3      "<<endl;
                        cout<<"CSE-1122     Computer Programming I Lab       1.5      "<<endl;
                        cout<<"EEE-1121    Basic Electrical Engineering        3      "<<endl;
                        cout<<"EEE-1122    Basic Electrical Engineering Lab  1.5      "<<endl;
                        cout<<"MATH-1107          Mathematics I                3      "<<endl;
                        cout<<"PHY-1101             Physics I                  3      "<<endl;
                        cout<<"UREL-1106         Advanced English              2      "<<endl;
                        cout<<"UREM-1101     Text of Ethics and Morality       1      "<<endl;
                        cout<<"========================================================="<<endl;

                        cout<<"SECOND SEMESTER:"<<endl;
                        cout<<"========================================================="<<endl;
                        cout<<"CSE-1221      Computer Programming II           3 "<<endl;
                        cout<<"CSE-1222      Computer Programming II LAB     1.5 "<<endl;
                        cout<<"CSE-1223          Discrete Mathematics          3 "<<endl;
                        cout<<"CSE-1230      Competitive Programming I         1 "<<endl;
                        cout<<"EEE-1221            Electronics                 3 "<<endl;
                        cout<<"EEE-1222            Electronics LAB           1.5 "<<endl;
                        cout<<"MATH-1207           Mathematics II              3 "<<endl;
                        cout<<"PHY-1201              Physics II                3 "<<endl;
                        cout<<"URED-1201	   Basic Principles of Islam       2 "<<endl;
                        cout<<"PHY-1204	          Physics II Lab             1.5 "<<endl;
                        cout<<"========================================================="<<endl;
                        cout<<"THIRD SEMESTER:"<<endl;
                        cout<<"========================================================="<<endl;
                        cout<<"CSE-2321           Data Structures              3 "<<endl;
                        cout<<"CSE-2322         Data Structures Lab            1 "<<endl;
                        cout<<"CSE-2340       Software Development I           2 "<<endl;
                        cout<<"            # OTHER COURSES WILL BE ADDED SOON...."<<endl;
                        break;
                    case 4:
                        system("cls");
                        cout<<" \n\nSTILL WORKING ON Retake courseS....."<<endl;
                        cout<<" IT IS COMING SOON... * WE ARE APOLOGIZE FOR IT....."<<endl;
                        break;
                    case 5:
                        system("cls");
                        goto LOGIN;
                        break;
                        ;
                    default:
                        cout << "\n\n\n Invalid choice...please try again";
                    }
                    getch();

                    found++;
                    break;
                }
                ptr = ptr->next_add;
            }
            if (found == 0 || head ==NULL)
            {
                int time1=4500;

                cout << "\nACCOUNT WITH " << roll_no << " CAN'T FOUND...";
                Sleep( time1);
                system("CLS");
            }
        }
    }
    void teacher()
    {
        cout<<"\n ENTER STUDENT ID: ";
        string id;
        cin>>id;
        if (head == NULL)
        {
            int time1=4500;
            cout << "\n\n STUDENT LIST is Empty...";
            Sleep( time1);
            system("CLS");
        }
        else
        {

            int found = 0;
            Node *ptr = head;
            while (ptr != NULL)
            {
                if (id == ptr->roll_no)
                {
                    system("CLS");

                    cout<<"\nSTUDENT FOUND"<<endl;
                    cout<<"NOW YOU CAN ADD MARKS OF 1ST SEMESTER COURSES -->>"<<endl<<endl;
                    cout<<"MAKE SURE THAT ENTER MARKS AS POINT (EX-3.00/3.25/3.50) -->>"<<endl;
                    cout<<"========================================================="<<endl;

                    cout<<"POINTS OF  COMPUTER PROG I = ";
                    cin>>i;
                    ptr->c1=i;
                    cout<<"\nPOINTS OF  COMPUTER PROG I LAB = ";
                    cin>>ii;
                    ptr->c1Lab=ii;
                    cout<<"\nPOINTS OF  Basic Electrical Engineering = ";
                    cin>>iii;
                    ptr->eee=iii;
                    cout<<"\nPOINTS OF  Basic Electrical Engineering Lab = ";
                    cin>>iv;
                    ptr->eeeLab=iv;
                    cout<<"\nPOINTS OF  Mathematics I  = ";
                    cin>>v;
                    ptr->math=v;
                    cout<<"\nPOINTS OF  Physics I  = ";
                    cin>>vi;
                    ptr->phy=vi;
                    cout<<"\nPOINTS OF  Advanced English = ";
                    cin>>vii;
                    ptr->eng=vii;
                    cout<<"\nPOINTS OF  Text of Ethics and Morality = ";
                    cin>>viii;
                    ptr->urem=viii;
                    int time1=4500;
                    cout<<"MARKS ADDED SUCCESSFULLY -./ RETURNING BACK..."<<endl;
                      Sleep( time1);
                system("CLS");

                    found++;
                }
                ptr = ptr->next_add;
            }
            if (found == 0)
            {
                int time1=4500;

                cout << "\nACCOUNT WITH " << roll_no << " CAN'T FOUND...";
                cout << "\nRETURNING BACK...";
                Sleep( time1);
                system("CLS");
            }
        }


    }
    void Show()
    {
        if (head == NULL)
        {
            cout << "\n\n Linked list is empty";
        }
        else
        {
            Node *ptr = head;
            while (ptr != NULL)
            {
                    cout << "\n\n Roll No : "<<ptr->roll_no;
                    cout << "\n\n Name : "<<ptr->name;
                    cout << "\n\n Semester: "<<ptr->sem;
                    cout << "\n\n Section: "<<ptr->section;
                ptr = ptr->next_add;
            }
        }
    }
};
main()
{
    Linked_List obj;

    int time=20;/// time duration of animation..........................................................
    gotoxy(6,7);
    SetConsoleTextAttribute(h,12);
    cout<<"**PLEASE DON'T MAKE FULL SCREEN OF YOUR CONSOLE TO GET BETTER EXPERIENCE"<<endl;

    int time1=4500;
    Sleep( time1);
    system("CLS");

    for (int i=0; i<4; i++) ///starting animation W
    {
        int x1=12,y1=2;
        gotoxy(x1+i, y1+i);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);
    }
    for (int i=0; i<3; i++)
    {
        int x1=16,y1=5;
        gotoxy(x1+i, y1-i);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<3; i++)
    {
        int x1=18,y1=3;
        gotoxy(x1+i, y1+i);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<4; i++)
    {
        int x1=21,y1=5;
        gotoxy(x1+i, y1-i);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<4; i++) ///E letter starting
    {
        int x1=26,y1=2;
        gotoxy(x1, y1+i);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<5; i++)
    {
        int x1=26,y1=2;
        gotoxy(x1+i, y1);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<3; i++)
    {
        int x1=27,y1=3;
        gotoxy(x1+i, y1);
        SetConsoleTextAttribute(h,14);
        cout<<"_";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<4; i++)
    {
        int x1=27,y1=5;
        gotoxy(x1+i, y1);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<4; i++)///L starting
    {
        int x1=33,y1=2;
        gotoxy(x1, y1+i);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<4; i++)
    {
        int x1=33,y1=5;
        gotoxy(x1+i, y1);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<4; i++)
    {
        int x1=42,y1=2;
        gotoxy(x1-i, y1);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<4; i++)
    {
        int x1=38,y1=2;
        gotoxy(x1, y1+i);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<5; i++)
    {
        int x1=38,y1=5;
        gotoxy(x1+i, y1);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<4; i++) ///O starting
    {
        int x1=45,y1=2;
        gotoxy(x1, y1+i);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<5; i++)
    {
        int x1=45,y1=5;
        gotoxy(x1+i, y1);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }

    for (int i=0; i<4; i++)
    {
        int x1=50,y1=5;
        gotoxy(x1, y1-i);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<4; i++)
    {
        int x1=49,y1=2;
        gotoxy(x1-i, y1);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<4; i++) ///M starting
    {
        int x1=53,y1=2;
        gotoxy(x1, y1+i);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<3; i++)
    {
        int x1=54,y1=2;
        gotoxy(x1+i, y1+i);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<3; i++)
    {
        int x1=56,y1=4;
        gotoxy(x1+i, y1-i);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<4; i++)
    {
        int x1=59,y1=2;
        gotoxy(x1, y1+i);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<4; i++) ///  E letter starting
    {
        int x1=61,y1=2;
        gotoxy(x1, y1+i);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<5; i++)
    {
        int x1=61,y1=2;
        gotoxy(x1+i, y1);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<3; i++)
    {
        int x1=62,y1=3;
        gotoxy(x1+i, y1);
        SetConsoleTextAttribute(h,14);
        cout<<"_";
        fflush(stdout);
        Sleep(time);

    }
    for (int i=0; i<5; i++)
    {
        int x1=61,y1=5;
        gotoxy(x1+i, y1);
        SetConsoleTextAttribute(h,14);
        cout<<"#";
        fflush(stdout);
        Sleep(time);

    }
    ///End of animation///======================================================================

    gotoxy(39,7);
    cout<<"TO";
    gotoxy(18,8);
    cout<<"   _________STUDENT REPORT CARD_________"<<endl<<endl;


Start:

    int select;
    cout<<"============================================================="<<endl;
    cout << "\n PRESS 1 FOR  ADMIN   LOGIN -->";
    cout << "\n\n PRESS 2 FOR STUDENT  LOGIN -->";
    cout << "\n\n PRESS 3 FOR TEACHERS LOGIN -->";
    cout << "\n\n PRESS 4 FOR  CLOSE PROGRAM -->";
    cout<<"\n============================================================="<<endl;
    cout << " #SELECT ANY OPTION [";
    cin>>select;
    switch (select)
    {
    case 1:
        system("cls");
        goto p;
        break;
    case 2:
        system("cls");
        goto STUDENT;
        break;
    case 3:
        system("cls");

        cout<<"\n\n============================================================="<<endl;
        cout << "\n 1.ADD STUDENT'S RESULT -->";
        cout << "\n\n 2.SEARCH STUDENT -->";
        cout << "\n\n 3.TO GO BACK -->";

        cout<<"\n============================================================="<<endl;

        cout << "\n ENTER YOUR CHOICE : ";
        int ts;
        cin>>ts;
        if (ts==1)
        {
            system("cls");
            obj.teacher();
        }
        if (ts==2)
        {
            system("cls");
            obj.search();
        }
        if (ts==3)
        {
            system("cls");
            goto Start;
        }
        else
        {
            system("cls");
            goto Start;

        }

        break;
    case 4:
        exit(0);
    default:
        cout << "\n\n\n Invalid choice...please try again";
    }
    getch();
    system("cls");
    goto Start;
p:
    system("cls");
    int choice;
    cout<<"============================================================="<<endl;
    cout << "\n 1.ADD STUDENTS -->";
    cout << "\n\n 2.SEARCH STUDENT -->";
    cout << "\n\n 3.TOTAL NUMBER OF STUDENTS -->";
    cout << "\n\n 4.UPDATE STUDENTS INFO -->";
    cout << "\n\n 5.DELETE STUDENTS -->";
    cout << "\n\n 6.SHOW ALL STUDENTS INFO -->";
    cout << "\n\n 7.TO GO BACK -->";
    cout<<"\n============================================================="<<endl;

    cout << "\n ENTER YOUR CHOICE : ";

    cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        obj.Insert();
        break;
    case 2:
        system("cls");
        obj.search();
        break;
    case 3:
        system("cls");
        obj.count();
        break;
    case 4:
        system("cls");
        obj.Update();
        break;
    case 5:
        system("cls");
        obj.Del();
        break;
    case 6:
        system("cls");
        obj.Show();
        break;
    case 7:
        system("cls");
        goto  Start;
        break;
        ;
    default:
        cout << "\n\n\n Invalid choice...please try again";
    }
    getch();
    goto p;
STUDENT:
    system("cls");
    int sc; ///student select

    obj.Log_search();



SUCCESS:

    goto STUDENT;

}


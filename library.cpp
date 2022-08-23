#include<iostream>
#include<iomanip>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<ctime>
using namespace std;
void login();
void registration();
void welcomeMessage();
void takeMenuInput();
void printMenu();
void takeStudentSubmenuInput();
void printStudentSubmenu();
void takeBookSubmenuInput();
void printBookSubmenu();
//CLASS FOR STUDENT'S INFORMATION
class stu_info
{
    int stu_id;
    string stu_name,stu_dept,stu_sem,stu_batch,stu_phone;
    public:
        void get_stu_info();
        void write_stu_info();
        void display_stu_info();
        void search_stu();
        void update_stu();
        void delete_stu();
        void check_int();
        void check_registered_id();
};
//CLASS FOR BOOK'S INFORMATION
class book_info
{
    int book_id,storage;
    string book_name,author_name,publisher_name,dep_name;
    public:
        void get_book_info();
        void check_int_id();
        void check_int_storage();
        void check_registered_id();
        void write_book_info();
        void display_book_info();
        void display_by_dept();
        void search_by_dept();
        void update_book();
        void delete_book();
};
//CLASS FOR BORROWING AND RETURNING INFORMATION
class borrow_info
{
    char book_name[20],stu_name[20];
    int book_id,stu_id,late_return_day;
    string stu_dept,stu_phone,receive_date,return_date,late_return_date;
    public:
        void get_borrow_info();
        void check_int_book_id();
        void check_int_stu_id();
        void check_registered_id();
        void write_borrow_info();
        void update_borrow_book_stock();
        void get_return_info();
        void display_return_info();
        void update_return_book_stock();
        void update_borrow_status();
        void display_borrow_status();

};
//FUNCTION FOR CHECKING THE INTEGER INPUT VALUE FOR BOOK ID
void book_info:: check_int_id()
{
    while(!(cin>>book_id))
    {
        cout<<"\n\t\t\t\t**only integer value.";
        cin.clear();
        cin.ignore(123,'\n');
    }
}
//FUNCTION FOR CHECKING THE INTEGER INPUT VALUE FOR BOOK stock
void book_info:: check_int_storage()
{
    while(!(cin>>storage))
    {
        cout<<"\n\t\t\t\t**only integer value.";
        cin.clear();
        cin.ignore(123,'\n');
    }
}
//FUNCTION FOR GETTING BOOK'S INFORMATION
void book_info :: get_book_info()
{
    system("cls");
    cout<<"\n\n\t\t\t\t\t\t\"BOOK'S INFORMATION \""<<endl;
    cout<<"\n\n\n\n\tEnter Book's Name\t: ";
    cin>>book_name;
    cout<<"\n\tEnter Book's Id\t\t: ";
    check_int_id();
    cout<<"\n\tEnter Author's Name\t: ";
    cin>>author_name;
    cout<<"\n\tEnter Publisher's name\t: ";
    cin>>publisher_name;
    cout<<"\n\tEnter Department's Name\t: ";
    cin>>dep_name;
    cout<<"\n\tEnter Quantity \t\t: ";
    check_int_storage();
    check_registered_id();
}
//FUNCTION FOR CHECKING BOOK ID IF ALREADY REGISTERED OR NOT
void book_info::check_registered_id()
{
    ifstream file;
    file.open("book_info.txt", ios::in);
    if(file.fail())
    {
        cerr<<"File Couldn't be found.";
        exit(0);
    }
    int book_id1,found=0;
    string book_name1,author1,publisher1,dept1,stroage1;
    file>>book_name1>>book_id1>>author1>>publisher1>>dept1>>stroage1;
    while(!file.eof())
    {
        if(book_id==book_id1)
        {
            system("cls");
            found++;
            cout<<"\n\n\n\n\t\tID "<<book_id<<" already REGISTERED.!!!";
            cout<<"\n\n\n\t\t\t\tPress Enter to continue..";
            getch();
            break;
        }
        file>>book_name1>>book_id1>>author1>>publisher1>>dept1>>stroage1;
    }
    if(found==0)
    {
            write_book_info();
    }
    file.close();
}
//FUNCTION FOR WRITTING BOOK'S INFORMATION
void book_info::write_book_info()
{
    ofstream file;
    file.open("book_info.txt",ios::out|ios::app);
    if(file.fail())
    {
        cerr<<"File Couldn't be found.";
        exit(0);
    }
    file<<book_name<<" "<<book_id<<" "<<author_name<<" "<<publisher_name<<" "<<dep_name<<" "<<storage<<endl;
    file.close();
    system("cls");
    cout<<"\n\n\n\n\t\tBook added successfully..."<<endl;
    cout<<"\n\n\n\t\t\t\tPress Enter to continue..";
    getch();
}
//FUNCTION FOR DISPLAYING ALL BOOK'S INFORMATION
void book_info::display_book_info()
{
	system("cls");
	ifstream file;
    file.open("book_info.txt",ios::in);
    if(file.fail())
    {
        cerr<<"File Couldn't be found.";
        exit(0);
    }
    cout<<"\n\n\n\t\t\t======================================================"<<endl;
    cout<<"\t\t\t\t\tALL BOOK'S INFORMATION"<<endl;
    cout<<"\t\t\t======================================================"<<endl;
    cout<<"\n\t--------------------------------------------------------------------------------------\n";
    cout<<left<<"\t"<<setw(15)<<"BOOK NAME"<<setw(15)<<"BOOK ID"<<setw(15)<<"AUTHOR"<<setw(15)<<"PUBLISHER"<<setw(15)<<"DEPARTMENT"<<setw(15)<<"QUANTITY"<<right<<endl;
    cout<<"\t--------------------------------------------------------------------------------------\n";
    string book_name1,book_id1,author1,publisher1,dept1,quantity1;
    file>>book_name1>>book_id1>>author1>>publisher1>>dept1>>quantity1;
    while(!file.eof())
    {
        cout<<left<<"\t"<<setw(15)<<book_name1<<setw(15)<<book_id1<<setw(15)<<author1<<setw(15)<<publisher1<<setw(15)<<dept1<<setw(15)<<quantity1<<endl<<right;
        file>>book_name1>>book_id1>>author1>>publisher1>>dept1>>quantity1;
    }
    file.close();
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t Press ENTER to continue....";
    getch();
}
//FUNCTION FOR DISPLAYING BOOK'S INFORMATION BY DEPT
void book_info :: display_by_dept()
{
    system("cls");
	ifstream file;
    file.open("book_info.txt",ios::in);
    if(file.fail())
    {
        cerr<<"File Couldn't be found.";
        exit(0);
    }
    string book_name1,book_id1,author1,publisher1,quantity1;
    char dept1[20],search_dept[20];
    int found=0;
    cout<<"\n\n\n\t\t\t======================================================"<<endl;
    cout<<"\t\t\t\tALL BOOK'S INFORMATION BY DEPARTEMENT"<<endl;
    cout<<"\t\t\t======================================================"<<endl;
    cout<<"\n\n\n\n\n\tEnter Department Name : ";
    cin>>search_dept;
    file>>book_name1>>book_id1>>author1>>publisher1>>dept1>>quantity1;
    while(!file.eof())
    {
        if(stricmp(search_dept,dept1)==0)
          {
              found++;
              if(found==1)
              {
                  cout<<"\n\t--------------------------------------------------------------------------------------\n";
                  cout<<left<<"\t"<<setw(15)<<"BOOK NAME"<<setw(15)<<"BOOK ID"<<setw(15)<<"AUTHOR"<<setw(15)<<"PUBLISHER"<<setw(15)<<"DEPARTMENT"<<setw(15)<<"QUANTITY"<<right<<endl;
                  cout<<"\t--------------------------------------------------------------------------------------\n";
              }
              cout<<left<<"\t"<<setw(15)<<book_name1<<setw(15)<<book_id1<<setw(15)<<author1<<setw(15)<<publisher1<<setw(15)<<dept1<<setw(15)<<quantity1<<endl<<right;
          }
        file>>book_name1>>book_id1>>author1>>publisher1>>dept1>>quantity1;
    }
    if(found==0)
        {
            cout<<"\n\n\n\tNo books found from "<<strupr(search_dept)<<" departmanet."<<endl;
        }
    file.close();
    cout<<"\n\n\n\n\n\n\n\tPress ENTER to continue....";
    getch();
}
//FUNCTION FOR SEARCHING BOOK'S INFORMATION BY DEPT
void book_info :: search_by_dept()
{
    system("cls");
	ifstream file;
    file.open("book_info.txt",ios::in);
    if(file.fail())
    {
        cerr<<"File Couldn't be found.";
        exit(0);
    }
    string book_id1,publisher1,quantity1;
    char book_name1[20],author1[20],dept1[20],search_dept[20],search_name[20],search_author[20];
    int found=0;
    cout<<"\n\n\n\t\t\t======================================================"<<endl;
    cout<<"\t\t\t\tSEARCH BOOK'S INFORMATION BY DEPARTEMENT"<<endl;
    cout<<"\t\t\t======================================================"<<endl;
    cout<<"\n\n\n\n\n\tEnter Department Name\t: ";
    cin>>search_dept;
    cout<<"\n\tEnter Book's Name\t: ";
    cin>>search_name;
    cout<<"\n\tEnter Author's Name\t: ";
    cin>>search_author;
    file>>book_name1>>book_id1>>author1>>publisher1>>dept1>>quantity1;
    while(!file.eof())
    {
        if((stricmp(search_dept,dept1)==0) && (stricmp(search_name,book_name1)==0) && (stricmp(search_author,author1)==0))
          {
            found++;
            if(found==1)
            {
                cout<<"\n\t--------------------------------------------------------------------------------------\n";
                cout<<left<<"\t"<<setw(15)<<"BOOK NAME"<<setw(15)<<"BOOK ID"<<setw(15)<<"AUTHOR"<<setw(15)<<"PUBLISHER"<<setw(15)<<"DEPARTMENT"<<setw(15)<<"QUANTITY"<<right<<endl;
                cout<<"\t--------------------------------------------------------------------------------------\n";
            }
              cout<<left<<"\t"<<setw(15)<<book_name1<<setw(15)<<book_id1<<setw(15)<<author1<<setw(15)<<publisher1<<setw(15)<<dept1<<setw(15)<<quantity1<<endl<<right;
          }
        file>>book_name1>>book_id1>>author1>>publisher1>>dept1>>quantity1;
    }
    if(found==0)
    {
        cout<<"\n\n\n\n\tNo book found writen by "<<strupr(search_author) <<" from "<<strupr(search_dept)<<" Department."<<endl;
    }
    file.close();
    cout<<"\n\n\n\n\n\n\n\tPress ENTER to continue....";
    getch();
}
//FUNCTION FOR UPDATING BOOK'S INFORMATION
void book_info :: update_book()
{
    system("cls");
    ifstream infile;
    infile.open("book_info.txt",ios::in);
    ofstream outfile;
    outfile.open("new_info.txt",ios::out);
    string book_name1,author1,publisher1,dept1,quantity1,up_name,up_author,up_publisher,up_dept;
    int book_id1,search_id,up_id,up_quantity,found=0;
    cout<<"\n\n\n\t\t\t======================================================"<<endl;
    cout<<"\t\t\t\tUPDATE BOOK'S INFORMATION BY DEPARTEMENT"<<endl;
    cout<<"\t\t\t======================================================"<<endl;
    cout<<"\n\n\n\n\n\tEnter Book's ID : ";
    cin>>search_id;
    infile>>book_name1>>book_id1>>author1>>publisher1>>dept1>>quantity1;
    while(!infile.eof())
    {
        if(search_id!=book_id1)
        {
            outfile<<book_name1<<" "<<book_id1<<" "<<author1<<" "<<publisher1<<" "<<dept1<<" "<<quantity1<<endl;
        }
        else
        {
            cout<<"\n\t--------------------------------------------------------------------------------------\n";
            cout<<left<<"\t"<<setw(15)<<"BOOK NAME"<<setw(15)<<"BOOK ID"<<setw(15)<<"AUTHOR"<<setw(15)<<"PUBLISHER"<<setw(15)<<"DEPARTMENT"<<setw(15)<<"QUANTITY"<<right<<endl;
            cout<<"\t--------------------------------------------------------------------------------------\n";
            cout<<left<<"\t"<<setw(15)<<book_name1<<setw(15)<<book_id1<<setw(15)<<author1<<setw(15)<<publisher1<<setw(15)<<dept1<<setw(15)<<quantity1<<endl<<right;
            cout<<"\n\n\n\n\n\n\t Press ENTER to update ....";
            found++;
            getch();
            cout<<"\n\n\n\n\n\tEnter Updated Book's Name\t: ";
            cin>>up_name;
            cout<<"\n\tEnter Updated Book's Id\t\t: ";
            cin>>up_id;
            cout<<"\n\tEnter Updated Author's Name\t: ";
            cin>>up_author;
            cout<<"\n\tEnter Updated Publisher's Name \t: ";
            cin>>up_publisher;
            cout<<"\n\tEnter Updated Department\t: ";
            cin>>up_dept;
            cout<<"\n\tEnter Updated Quantity\t\t: ";
            cin>>up_quantity;
            outfile<<up_name<<" "<<up_id<<" "<<up_author<<" "<<up_publisher<<" "<<up_dept<<" "<<up_quantity<<endl;
            system("cls");
            cout<<"\n\n\n\n\t\tUpdated successfully..."<<endl;
        }
        infile>>book_name1>>book_id1>>author1>>publisher1>>dept1>>quantity1;
    }
    if(found==0)
        {
            cout<<"\n\n\n\tBook Id "<<search_id<<" Not Found,...."<<endl;
        }
    cout<<"\n\n\n\n\n\t\t\tPress ENTER to continue..";
    infile.close();
    outfile.close();
    remove("book_info.txt");
    rename("new_info.txt","book_info.txt");
    getch();
}
//FUNCTION FOR DELETING BOOK'S INFORMATION
void book_info :: delete_book()
{
    system("cls");
    ifstream infile;
    infile.open("book_info.txt",ios::in);
    ofstream outfile;
    outfile.open("new_info.txt",ios::out);
    string book_name1,author1,publisher1,dept1,quantity1,up_name,up_id,up_author,up_publisher,up_dept,up_quantity;
    int book_id1,search_id,found=0;
    cout<<"\n\n\n\t\t\t======================================================"<<endl;
    cout<<"\t\t\t\tDELETE BOOK'S INFORMATION BY DEPARTEMENT"<<endl;
    cout<<"\t\t\t======================================================"<<endl;
    cout<<"\n\n\n\n\n\tEnter Book's ID : ";
    cin>>search_id;
    infile>>book_name1>>book_id1>>author1>>publisher1>>dept1>>quantity1;
    while(!infile.eof())
    {
        if(search_id!=book_id1)
        {
            outfile<<book_name1<<" "<<book_id1<<" "<<author1<<" "<<publisher1<<" "<<dept1<<" "<<quantity1<<endl;
        }
        else
        {
            cout<<"\n\t--------------------------------------------------------------------------------------\n";
            cout<<left<<"\t"<<setw(15)<<"BOOK NAME"<<setw(15)<<"BOOK ID"<<setw(15)<<"AUTHOR"<<setw(15)<<"PUBLISHER"<<setw(15)<<"DEPARTMENT"<<setw(15)<<"QUANTITY"<<right<<endl;
            cout<<"\t--------------------------------------------------------------------------------------\n";
            cout<<left<<"\t"<<setw(15)<<book_name1<<setw(15)<<book_id1<<setw(15)<<author1<<setw(15)<<publisher1<<setw(15)<<dept1<<setw(15)<<quantity1<<endl<<right;
            cout<<"\n\n\n\n\n\n\t Press ENTER to delete ....";
            getch();
            found++;
            system("cls");
            cout<<"\n\n\n\n\n\t\tRecord successfully deleted."<<endl;
        }
        infile>>book_name1>>book_id1>>author1>>publisher1>>dept1>>quantity1;
    }
    if(found==0)
        {
            cout<<"\n\n\n\tBook Id "<<search_id<<" Not Found,...."<<endl;
        }
        cout<<"\n\n\n\n\n\t\t\tPress ENTER to continue..";
        infile.close();
        outfile.close();
        remove("book_info.txt");
        rename("new_info.txt","book_info.txt");
        getch();
}
//FUNCTION FOR CHECKING THE INTEGER INPUT VALUE FOR STUDENT-ID
void stu_info:: check_int()
{
    while(!(cin>>stu_id))
    {
        cout<<"\n\t\t\t\t**only integer value.";
        cin.clear();
        cin.ignore(123,'\n');
    }
}
//FUNCTION FOR GETTING STUDENT'S INFORMATION FOR NEW REGISTER
void stu_info::get_stu_info()
{
    system("cls");
    cout<<"\n\n\t\t\t\t\t\t\"STUDENT'S INFORMATION \""<<endl;
    cout<<"\n\n\n\n\tEnter Student's Name\t: ";
    cin>>stu_name;
    cout<<"\n\tEnter Student's Id\t: ";
    check_int();
    cout<<"\n\tEnter Student's Dept\t: ";
    cin>>stu_dept;
    cout<<"\n\tEnter Student's Sem\t: ";
    cin>>stu_sem;
    cout<<"\n\tEnter Student's batch\t: ";
    cin>>stu_batch;
    cout<<"\n\tEnter Student's phone\t: ";
    cin>>stu_phone;
    check_registered_id();
}
//FUNCTION FOR CHECKING STUDENT ID IF ALREADY REGISTERED OR NOT
void stu_info::check_registered_id()
{
    ifstream file;
    file.open("student_info.txt", ios::in);
    if(file.fail())
    {
        cerr<<"File Couldn't be found.";
        exit(0);
    }
    int stu_id1,found=0;
    string stu_name1,stu_dept,stu_sem,stu_batch,stu_phone;
    file>>stu_name1>>stu_id1>>stu_dept>>stu_sem>>stu_batch>>stu_phone;
    while(!file.eof())
    {
        if(stu_id==stu_id1)
        {
            system("cls");
            found++;
            cout<<"\n\n\n\n\t\tID "<<stu_id<<" already REGISTERED.!!!";
            cout<<"\n\n\n\t\t\t\tPress Enter to continue..";
            getch();
            break;
        }
        file>>stu_name1>>stu_id1>>stu_dept>>stu_sem>>stu_batch>>stu_phone;
    }
    if(found==0)
    {
        write_stu_info();
    }
    file.close();
}
//FUNCTION FOR WRITTING STUDENT'S INFORMATION
void stu_info::write_stu_info()
{
    ofstream file;
    file.open("student_info.txt",ios::out|ios::app);
    if(file.fail())
    {
        cerr<<"File Couldn't be found.";
        exit(0);
    }
    file<<stu_name<<" "<<stu_id<<" "<<stu_dept<<" "<<stu_sem<<" "<<stu_batch<<" "<<stu_phone<<endl;
    file.close();
    system("cls");
    cout<<"\n\n\n\n\t\tRegistered successfully..."<<endl;
    cout<<"\n\n\n\t\t\t\tPress Enter to continue..";
    getch();
}
//FUNCTION FOR DISPLAYING STUDENT'S INFORMATION
void stu_info::display_stu_info()
{
	system("cls");
	ifstream file;
    file.open("student_info.txt",ios::in);
    if(file.fail())
    {
        cerr<<"File Couldn't be found.";
        exit(0);
    }
    cout<<"\n\n\n\t\t\t======================================================"<<endl;
    cout<<"\t\t\t\t\tALL STUDENT'S INFORMATION"<<endl;
    cout<<"\t\t\t======================================================"<<endl;
    cout<<"\n\t--------------------------------------------------------------------------------------\n";
    cout<<left<<"\t"<<setw(15)<<"NAME"<<setw(15)<<"ID"<<setw(15)<<"DEPARTMENT"<<setw(15)<<"SEMESTER"<<setw(15)<<"BATCH"<<setw(15)<<"PHONE"<<right<<endl;
    cout<<"\t--------------------------------------------------------------------------------------\n";
    string stu_name1,stu_id1,stu_dept1,stu_sem1,stu_batch1,stu_phone1;
    file>>stu_name1>>stu_id1>>stu_dept1>>stu_sem1>>stu_batch1>>stu_phone1;
    while(!file.eof())
    {
        cout<<left<<"\t"<<setw(15)<<stu_name1<<setw(15)<<stu_id1<<setw(15)<<stu_dept1<<setw(15)<<stu_sem1<<setw(15)<<stu_batch1<<setw(15)<<stu_phone1<<endl<<right;
        file>>stu_name1>>stu_id1>>stu_dept1>>stu_sem1>>stu_batch1>>stu_phone1;
    }
    file.close();
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t Press ENTER to continue....";
    getch();
}
//FUNCTION FOR SEARCHING STUDENT'S INFORMATION
void stu_info::search_stu()
{
    ifstream file;
    file.open("student_info.txt", ios::in);
    if(file.fail())
    {
        cerr<<"File Couldn't be found.";
        exit(0);
    }
    string stu_name1,stu_dept1,stu_sem1,stu_batch1,stu_phone1;
    int search_id,stu_id1,found=0;
    system("cls");
    cout<<"\n\n\n\t\t\t============================================================"<<endl;
    cout<<"\t\t\t\t\tSEARCH STUDENT'S INFORMATION"<<endl;
    cout<<"\t\t\t============================================================"<<endl;
    cout<<"\n\n\n\n\t\tEnter Student's ID : ";
    cin>>search_id;
    file>>stu_name1>>stu_id1>>stu_dept1>>stu_sem1>>stu_batch1>>stu_phone1;
    while(!file.eof())
    {
        if(search_id==stu_id1)
        {
            cout<<"\n\n\n\n\t\t--------------------------------------------------------------------------------------\n";
            cout<<left<<"\t\t"<<setw(15)<<"NAME"<<setw(15)<<"ID"<<setw(15)<<"DEPARTMENT"<<setw(15)<<"SEMESTER"<<setw(15)<<"BATCH"<<setw(15)<<"PHONE"<<right<<endl;
            cout<<"\t\t--------------------------------------------------------------------------------------\n";
            cout<<left<<"\t\t"<<setw(15)<<stu_name1<<setw(15)<<stu_id1<<setw(15)<<stu_dept1<<setw(15)<<stu_sem1<<setw(15)<<stu_batch1<<setw(15)<<stu_phone1<<endl<<right;
            found++;
            break;
        }
        file>>stu_name1>>stu_id1>>stu_dept1>>stu_sem1>>stu_batch1>>stu_phone1;
    }
    if(found==0)
    {
        cout<<"\n\n\n\t\tSearched ID ("<<search_id<<") details not found..."<<endl;
    }
    file.close();
    cout<<"\n\n\n\n\n\n\n\t\tPress ENTER to continue ....";
    getch();
}
//FUNCTION FOR UPDATING STUDENT'S INFORMATION
void stu_info :: update_stu()
{
    system("cls");
    ifstream infile;
    infile.open("student_info.txt",ios::in);
    ofstream outfile;
    outfile.open("new_info.txt",ios::out);
    string stu_name,stu_dept,stu_sem,stu_batch,stu_phone,up_name,up_id,up_dept,up_sem,up_batch,up_phone;
    int stu_id,search_id,found=0;
    cout<<"\n\n\n\t\t\t============================================================"<<endl;
    cout<<"\t\t\t\t\tUPDATE STUDENT'S INFORMATION"<<endl;
    cout<<"\t\t\t============================================================"<<endl;
    cout<<"\n\n\n\t\tEnter Student's ID : ";
    cin>>search_id;
    infile>>stu_name>>stu_id>>stu_dept>>stu_sem>>stu_batch>>stu_phone;
    while(!infile.eof())
    {
        if(search_id!=stu_id)
        {
            outfile<<stu_name<<" "<<stu_id<<" "<<stu_dept<<" "<<stu_sem<<" "<<stu_batch<<" "<<stu_phone<<endl;
        }
        else
        {
            cout<<"\n\n\n\n\t\t--------------------------------------------------------------------------------------\n";
            cout<<left<<"\t\t"<<setw(15)<<"NAME"<<setw(15)<<"ID"<<setw(15)<<"DEPARTMENT"<<setw(15)<<"SEMESTER"<<setw(15)<<"BATCH"<<setw(15)<<"PHONE"<<right<<endl;
            cout<<"\t\t--------------------------------------------------------------------------------------\n";
            cout<<left<<"\t\t"<<setw(15)<<stu_name<<setw(15)<<stu_id<<setw(15)<<stu_dept<<setw(15)<<stu_sem<<setw(15)<<stu_batch<<setw(15)<<stu_phone<<endl<<right;
            cout<<"\n\n\n\n\n\n\t\t Press ENTER to update ....";
            found++;
            getch();
            cout<<"\n\n\n\n\t\tEnter Student's Updated  Name\t: ";
            cin>>up_name;
            cout<<"\n\t\tEnter Student's Updated Id\t: ";
            cin>>up_id;
            cout<<"\n\t\tEnter Student's Updated Dept\t: ";
            cin>>up_dept;
            cout<<"\n\t\tEnter Student's Updated Sem\t: ";
            cin>>up_sem;
            cout<<"\n\t\tEnter Student's Updated batch\t: ";
            cin>>up_batch;
            cout<<"\n\t\tEnter Student's Updated phone\t: ";
            cin>>up_phone;
            outfile<<up_name<<" "<<up_id<<" "<<up_dept<<" "<<up_sem<<" "<<up_batch<<" "<<up_phone<<endl;
            system("cls");
            cout<<"\n\n\n\n\n\t\t UPDATED SUCCESSFULLY..."<<endl;
            cout<<"\n\n\n\t\t\tPress ENTER to continue..";
        }
        infile>>stu_name>>stu_id>>stu_dept>>stu_sem>>stu_batch>>stu_phone;
    }
    if(found==0)
        {
            cout<<"\n\n\n\t\tStudent ID ("<<search_id<<") Not Found,...."<<endl;
            cout<<"\n\n\n\n\n\n\n\n\t\t\t\tPress ENTER to continue..";
        }
    infile.close();
    outfile.close();
    remove("student_info.txt");
    rename("new_info.txt","student_info.txt");
    getch();
}
//FUNCTION FOR DELETING STUDENT'S INFORMATION
void stu_info :: delete_stu()
{
    system("cls");
    ifstream infile;
    infile.open("student_info.txt",ios::in);
    ofstream outfile;
    outfile.open("new_info.txt",ios::out);
    string stu_name,stu_dept,stu_sem,stu_batch,stu_phone;
    int stu_id,search_id,found=0;
    cout<<"\n\n\n\t\t\t============================================================"<<endl;
    cout<<"\t\t\t\t\tDELETE STUDENT'S INFORMATION"<<endl;
    cout<<"\t\t\t============================================================"<<endl;
    cout<<"\n\n\n\n\t\tEnter Student's ID : ";
    cin>>search_id;
    infile>>stu_name>>stu_id>>stu_dept>>stu_sem>>stu_batch>>stu_phone;
    while(!infile.eof())
    {
        if(search_id!=stu_id)
        {
            outfile<<stu_name<<" "<<stu_id<<" "<<stu_dept<<" "<<stu_sem<<" "<<stu_batch<<" "<<stu_phone<<endl;
        }
        else
        {
            cout<<"\n\n\n\n\t\t--------------------------------------------------------------------------------------\n";
            cout<<left<<"\t\t"<<setw(15)<<"NAME"<<setw(15)<<"ID"<<setw(15)<<"DEPARTMENT"<<setw(15)<<"SEMESTER"<<setw(15)<<"BATCH"<<setw(15)<<"PHONE"<<right<<endl;
            cout<<"\t\t--------------------------------------------------------------------------------------\n";
            cout<<left<<"\t\t"<<setw(15)<<stu_name<<setw(15)<<stu_id<<setw(15)<<stu_dept<<setw(15)<<stu_sem<<setw(15)<<stu_batch<<setw(15)<<stu_phone<<endl<<right;
            cout<<"\n\n\n\n\n\n\t\t Press ENTER to delete ....";
            found++;
            getch();
            system("cls");
            cout<<"\n\n\n\n\n\t\tRecord successfully deleted."<<endl;

        }
        infile>>stu_name>>stu_id>>stu_dept>>stu_sem>>stu_batch>>stu_phone;
    }
        if(found==0)
        {
            cout<<"\n\n\n\n\t\tSearched ID ("<<search_id<<") Not Found,...."<<endl;
        }
    infile.close();
    outfile.close();
    remove("student_info.txt");
    rename("new_info.txt","student_info.txt");
    cout<<"\n\n\n\n\n\t\t\tPress Enter to process..";
    getch();
}
//FUNCTION FOR CHECKING THE INTEGER INPUT VALUE FOR BOOK ID
void borrow_info:: check_int_book_id()
{
    while(!(cin>>book_id))
    {
        cout<<"\n\t\t\t\t**only integer value.";
        cin.clear();
        cin.ignore(123,'\n');
    }
}
//FUNCTION FOR CHECKING THE INTEGER INPUT VALUE FOR STUDENT ID
void borrow_info:: check_int_stu_id()
{
    while(!(cin>>stu_id))
    {
        cout<<"\n\t\t\t\t**only integer value.";
        cin.clear();
        cin.ignore(123,'\n');
    }
}
//FUNCTION FOR GETTING BORROWING-BOOK INFORMATION
void borrow_info::get_borrow_info()
{
    system("cls");
    cout<<"\n\n\t\t\t\t\t\t\"PROVIDE THE FOLLOWING INFORMATION \""<<endl;
    cout<<"\n\n\n\n\tEnter Book's Name\t\t: ";
    cin>>book_name;
    cout<<"\n\tEnter Book's ID\t\t\t: ";
    check_int_book_id();
    cout<<"\n\tEnter Student's Name\t\t: ";
    cin>>stu_name;
    cout<<"\n\tEnter Student's Id\t\t: ";
    check_int_stu_id();
    cout<<"\n\tEnter Student's Dept\t\t: ";;
    cin>>stu_dept;
    cout<<"\n\tEnter Student's phone\t\t: ";
    cin>>stu_phone;
    cout<<"\n\tReceiving date(dd/mm/yy)\t: ";
    cin>>receive_date;
    cout<<"\n\tReturning date(dd/mm/yy)\t: ";
    cin>>return_date;
    check_registered_id();
}
//FUNCTION FOR CHECKING BOOK ID/STUDENT ID, IF ALREADY REGISTERED OR NOT
void borrow_info::check_registered_id()
{
    ifstream file1,file2;
    file1.open("book_info.txt", ios::in);
    file2.open("student_info.txt", ios::in);
    if(file1.fail()&& file2.fail())
    {
        cerr<<"File Couldn't be found.";
        exit(0);
    }
    int book_id1,stu_id1,storage1,found=0;
    char book_name1[20],stu_name1[20];
    string author1,publisher1,dept1,stu_dept1,stu_sem1,stu_batch1,stu_phone1;
    file1>>book_name1>>book_id1>>author1>>publisher1>>dept1>>storage1;
    file2>>stu_name1>>stu_id1>>stu_dept1>>stu_sem1>>stu_batch1>>stu_phone1;
    while(!file1.eof())
    {
        if(book_id==book_id1 && (stricmp(book_name,book_name1)==0) && storage1 >0)
        {
             break;
        }
        file1>>book_name1>>book_id1>>author1>>publisher1>>dept1>>storage1;
    }
    while(!file2.eof())
    {
        if(book_id==book_id1 && stu_id==stu_id1 && (stricmp(stu_name,stu_name1)==0))
        {
             found++;
             file1.close();
             file2.close();
             write_borrow_info();
             getch();
             break;
        }
        file2>>stu_name1>>stu_id1>>stu_dept1>>stu_sem1>>stu_batch1>>stu_phone1;
    }
    if(found==0)
    {
       //cout<<"\n\n\n\n\n\tBook ID "<<book_id<<" or Student ID "<<stu_id<<" not found in the registered list..";
        cout<<"\n\n\n\n\t\tBorrowed Unsuccessfully..Check Book Id/Student Id/Book stock";
        cout<<"\n\n\n\n\t\tPress Enter to continue..";
        getch();
    }
}
//FUNCTION FOR WRITING BORROWING-BOOK INFORMATION
void borrow_info::write_borrow_info()
{
    ofstream file;
    file.open("borrow_info.txt",ios::out|ios::app);
    if(file.fail())
    {
        cerr<<"File Couldn't be found.";
        exit(0);
    }
    file<<book_name<<" "<<book_id<<" "<<stu_name<<" "<<stu_id<<" "<<stu_dept<<" "<<stu_phone<<" "<<receive_date<<" "<<return_date<<endl;
    file.close();
    system("cls");
    cout<<"\n\n\n\n\t\tBorrow information Recorded successfully..."<<endl;
    cout<<"\n\n\n\t\t\t\tPress Enter to continue..";
    getch();
    update_borrow_book_stock();
}
//FUNCTION FOR UPDATING BOOK-STOCK INFORMATION AFTER BORROWING
void borrow_info::update_borrow_book_stock()
{
    ifstream infile;
    infile.open("book_info.txt",ios::in);
    ofstream outfile;
    outfile.open("new_info.txt",ios::out);
    char book_name1[20];
    int book_id1,stroage1;
    string author1, publisher1, dept1;
    if(infile.fail())
    {
        cerr<<"File Couldn't be found.";
        exit(0);
    }
    infile>>book_name1>>book_id1>>author1>>publisher1>>dept1>>stroage1;
    while(!infile.eof())
    {
        if((book_id!=book_id1))
            {
              outfile<<book_name1<<" "<<book_id1<<" "<<author1<<" "<<publisher1<<" "<<dept1<<" "<<stroage1<<endl;
            }
        else
            {
               outfile<<book_name1<<" "<<book_id1<<" "<<author1<<" "<<publisher1<<" "<<dept1<<" "<<stroage1-1<<endl;
            }
            infile>>book_name1>>book_id1>>author1>>publisher1>>dept1>>stroage1;
    }
    infile.close();
    outfile.close();
    remove("book_info.txt");
    rename("new_info.txt","book_info.txt");
}
//FUNCTION FOR GETTING RETURNING-BOOK INFORMATION
void borrow_info::get_return_info()
{
    system("cls");
    cout<<"\n\n\t\t\t\t\t\t\"PROVIDE THE FOLLOWING INFORMATION \""<<endl;
    cout<<"\n\n\n\n\tEnter Book's ID\t\t: ";
    check_int_book_id();
    cout<<"\n\tEnter Student's Id\t: ";
    check_int_stu_id();
    display_return_info();
}
//FUNCTION FOR DISPLAYING RETURNING-BOOK INFORMATION
void borrow_info::display_return_info()
{
    ifstream file;
    file.open("borrow_info.txt",ios::in);
    int book_id1,stu_id1,found=0;
    string book_name1,stu_name1,stu_dept1,stu_phone1,receive_date1,return_date1;
    if(file.fail())
    {
        cerr<<"File Couldn't be found.";
        exit(0);
    }
    file>>book_name1>>book_id1>>stu_name1>>stu_id1>>stu_dept1>>stu_phone1>>receive_date1>>return_date1;
    while(!file.eof())
    {
        if((book_id==book_id1)&&(stu_id==stu_id1))
        {
            cout<<"\n\n\n\n\t--------------------------------------------------------------------------------------------------------------------\n";
            cout<<left<<"\t"<<setw(15)<<"BOOK NAME"<<setw(15)<<"BOOK ID"<<setw(15)<<"STUDENT NAME"<<setw(15)<<"STUDENT ID"<<setw(15)<<"DEPARTMENT"<<setw(15)<<"PHONE"<<setw(15)<<"RECEIVE DATE"<<setw(15)<<"RETURN DATE"<<right<<endl;
            cout<<"\t--------------------------------------------------------------------------------------------------------------------\n";
            cout<<left<<"\t"<<setw(15)<<book_name1<<setw(15)<<book_id1<<setw(15)<<stu_name1<<setw(15)<<stu_id1<<setw(15)<<stu_dept1<<setw(15)<<stu_phone1<<setw(15)<<receive_date1<<setw(10)<<return_date1<<endl<<right;
            found++;
            cout<<"\n\n\n\n\tReceive date\t\t: "<<receive_date1<<endl;
            cout<<"\n\tExpected Return date\t: "<<return_date1<<endl;
            cout<<"\n\tReturn date\t\t: ";
            cin>>late_return_date;
            cout<<"\n\tLate return days\t: ";
            cin>>late_return_day;
            cout<<"\n\tLate return fine\t: "<<late_return_day*20<<" (**late fine per day 20 taka.)"<<endl;
            //late_fine_calculation();
            cout<<"\n\n\n\n\n\n\n\n\t Press ENTER to return....";
            //caculation need to added
            break;
        }
        file>>book_name>>book_id1>>stu_name1>>stu_id1>>stu_dept1>>stu_phone1>>receive_date1>>return_date1;
    }
    if(found==0)
    {
        cout<<"\n\n\n\tSearching details not found..."<<endl;
    }
    file.close();
    getch();
    update_return_book_stock();
}
//FUNCTION FOR UPDATING BOOK-STOCK INFORMATION AFTER RETURNING
void borrow_info::update_return_book_stock()
{
    ifstream infile;
    infile.open("book_info.txt",ios::in);
    ofstream outfile;
    outfile.open("new_info.txt",ios::out);
    char book_name1[20];
    int book_id1,stroage1;
    string author1, publisher1, dept1;
    if(infile.fail())
    {
        cerr<<"File Couldn't be found.";
        exit(0);
    }
    infile>>book_name1>>book_id1>>author1>>publisher1>>dept1>>stroage1;
    while(!infile.eof())
    {
        if((book_id!=book_id1))
            {
              outfile<<book_name1<<" "<<book_id1<<" "<<author1<<" "<<publisher1<<" "<<dept1<<" "<<stroage1<<endl;
            }
        else
            {
               outfile<<book_name1<<" "<<book_id1<<" "<<author1<<" "<<publisher1<<" "<<dept1<<" "<<stroage1+1<<endl;
            }
            infile>>book_name1>>book_id1>>author1>>publisher1>>dept1>>stroage1;
    }
    infile.close();
    outfile.close();
    remove("book_info.txt");
    rename("new_info.txt","book_info.txt");
    update_borrow_status();
}
//FUNCTION FOR UPDATING BORROW STATUS INFORMATION AFTER RETURNING
void borrow_info::update_borrow_status()
{
    ifstream infile;
    infile.open("borrow_info.txt",ios::in);
    ofstream outfile;
    outfile.open("new_info.txt",ios::out);
    char book_name1[20];
    int book_id1,stu_id1;
    string stu_name1,stu_dept1,stu_phone1,receive_date,return_date;
    if(infile.fail())
    {
        cerr<<"File Couldn't be found.";
        exit(0);
    }
    infile>>book_name1>>book_id1>>stu_name1>>stu_id1>>stu_dept1>>stu_phone1>>receive_date>>return_date;
    while(!infile.eof())
    {
        if((book_id!=book_id1) ||(stu_id!=stu_id1))
            {
              outfile<<book_name1<<" "<<book_id1<<" "<<stu_name1<<" "<<stu_id1<<" "<<stu_dept1<<" "<<stu_phone1<<" "<<receive_date<<" "<<return_date<<endl;
            }
            infile>>book_name1>>book_id1>>stu_name1>>stu_id1>>stu_dept1>>stu_phone1>>receive_date>>return_date;
    }
    infile.close();
    outfile.close();
    remove("borrow_info.txt");
    rename("new_info.txt","borrow_info.txt");
}

//FUNCTION FOR DISPLAYING BORROW STATUS INFORMATION AFTER RETURNING
void borrow_info:: display_borrow_status()
{
    system("cls");
    ifstream infile;
    infile.open("borrow_info.txt",ios::in);
    if(infile.fail())
    {
        cerr<<"File Couldn't be found.";
        exit(0);
    }
    string book_name1,book_id1,stu_name1,stu_id1,stu_dept1,stu_phone1,receive_date1,return_date1;
    infile>>book_name1>>book_id1>>stu_name1>>stu_id1>>stu_dept1>>stu_phone1>>receive_date1>>return_date1;
    cout<<"\n\n\n\n\t\t\t\t============================================================"<<endl;
    cout<<"\t\t\t\t\t\tALL BORROW-BOOK'S INFORMATION"<<endl;
    cout<<"\t\t\t\t============================================================"<<endl;
    cout<<"\n\t--------------------------------------------------------------------------------------------------------------------\n";
    cout<<left<<"\t"<<setw(15)<<"BOOK NAME"<<setw(15)<<"BOOK ID"<<setw(15)<<"STUDENT NAME"<<setw(15)<<"STUDENT ID"<<setw(15)<<"DEPARTMENT"<<setw(15)<<"PHONE"<<setw(15)<<"RECEIVE DATE"<<setw(15)<<"RETURN DATE"<<right<<endl;
    cout<<"\t--------------------------------------------------------------------------------------------------------------------\n";
    while(!infile.eof())
    {
        cout<<left<<"\t"<<setw(15)<<book_name1<<setw(15)<<book_id1<<setw(15)<<stu_name1<<setw(15)<<stu_id1<<setw(15)<<stu_dept1<<setw(15)<<stu_phone1<<setw(15)<<receive_date1<<setw(10)<<return_date1<<endl<<right;
        infile>>book_name1>>book_id1>>stu_name1>>stu_id1>>stu_dept1>>stu_phone1>>receive_date1>>return_date1;
    }
    infile.close();
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t Press ENTER to continue....";
    getch();
}
//FUNCTION FOR LOGIN INTO THE SYSTEM
void login()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t=============================================================="<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t\tWELCOME TO LOGIN\n"<<endl;
    cout<<"\t\t\t\t\t\t=============================================================="<<endl;
    char username[30],password[30],username1[30],password1[30];
    int found=0;
    cout<<"\n\n\n\n\t\t\tEnter the username( use sharmin) : ";
    cin>>username;
    cout<<"\n\t\t\tEnter the password( use 1234)\t : ";
    cin>>password;
    ifstream file;
    file.open("login_info.txt",ios::in);
    if(file.fail())
    {
        cerr<<"File Couldn't be found.";
        exit(0);
    }
    file>>username1>>password1;
    while(!file.eof())
    {
        if((stricmp(username,username1)==0) && (stricmp(password,password1)==0))
        {
            found++;
            break;
        }
        else
        {
            cout<<"\n\n\n\n\n\n\t\t\tInvalid username or password";
            getch();
            break;
        }
        file>>username1>>password1;
    }
    if(found==1)
    {
        welcomeMessage();
            while(true)
            {
              takeMenuInput();
            }
    }
    file.close();
    getch();
}
void registration()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t======================================================"<<endl;
    cout<<"\n\t\t\t\t\t\t\t\tWELCOME TO REGISTRATION \n"<<endl;
    cout<<"\t\t\t\t\t\t======================================================="<<endl;
    char username[30],password[30];
    cout<<"\n\n\n\n\t\t\tEnter the username : ";
    cin>>username;
    cout<<"\n\t\t\tEnter the password : ";
    cin>>password;
    ofstream file;
    file.open("login_info.txt",ios::out|ios::app);
    if(file.fail())
    {
        cerr<<"File Couldn't be found.";
        exit(0);
    }
    file<<username<<" "<<password<<" "<<endl;
    file.close();
    getch();
}
//printing welcoming message
void welcomeMessage()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t======================================================"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\tWELCOME TO \n"<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t\"LIBRARY MANAGEMENT SYSTEM\" of"<<endl;
    cout<<"\n\t\t\t\t\t\t   \"SHANTO MARIUM UNIVERSITY OF CREATIVE TECHNOLOGY\""<<endl;
    cout<<"\t\t\t\t\t\t======================================================="<<endl;
    cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tPRESS ENTER TO CONTINUE....";
    getch();
}
//function for printing submenu of book
void printBookSubmenu()
{
    system("cls");
    cout<<"\n\n\n\tSUBMENU OF BOOK\n"<<endl;
    cout<<"\t1. VIEW ALL BOOKS\n"<<endl;
    cout<<"\t2. VIEW BY DEPT\n"<<endl;
    cout<<"\t3. SEARCH BY DEPT\n"<<endl;
    cout<<"\t4. ADD NEW BOOK\n"<<endl;
    cout<<"\t5. UPDATE EXISTING BOOK\n"<<endl;
    cout<<"\t6. DELETE EXISTING BOOK\n"<<endl;
    cout<<"\t7. BACK TO MAIN MENU \n"<<endl;
    cout<<"\tEnter your choce : ";

}
//function for printing submenu of book and taking input
void takeBookSubmenuInput()
{
    book_info book;
    printBookSubmenu();
    int userInput;
    cin>>userInput;
    switch(userInput)
    {
    case 1:
        book.display_book_info();
        break;
    case 2:
        book.display_by_dept();
        break;
    case 3:
        book.search_by_dept();
        break;
    case 4:
        book.get_book_info();
        break;
    case 5:
        book.update_book();
        break;
    case 6 :
        book.delete_book();
        break;
    case 7:
        takeMenuInput();
        break;
    default:
        exit(0);
    }
}
//function for printing submenu of student
void printStudentSubmenu()
{
    system("cls");
    cout<<"\n\n\n\tSUBMENU OF STUDENT\n"<<endl;
    cout<<"\t1. NEW REGISTER\n"<<endl;
    cout<<"\t2. SEARCH STUDENT\n"<<endl;
    cout<<"\t3. ALL STUDENT\n"<<endl;
    cout<<"\t4. UPDATE STUDENT'S RECORD\n"<<endl;
    cout<<"\t5. DELETE STUDENT'S RECORD\n"<<endl;
    cout<<"\t6. BACK TO MAIN MENU \n"<<endl;
    cout<<"\tEnter your choce : ";

}
//function for printing submenu of student and taking input
void takeStudentSubmenuInput()
{
    stu_info student;
    printStudentSubmenu();
    int userInput;
    cin>>userInput;
    switch(userInput)
    {
    case 1:
        student.get_stu_info();
        break;
    case 2:
        student.search_stu();
        break;
    case 3:
        student.display_stu_info();
        break;
    case 4:
        student.update_stu();
        break;
    case 5:
        student.delete_stu();
        break;
    case 6 :
        takeMenuInput();
        break;
    default:
        exit(0);
    }
}
//function for printing main menu
void printMenu()
{
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\"SHANTO-MARIAM UNIVERSITY OF CREATIVE TECHNOLOGY \""<<endl;
    cout<<"\n\n\n\tMAIN MENU..\n"<<endl;
    cout<<"\t1. BOOKS\n"<<endl;
    cout<<"\t2. STUDENT\n"<<endl;
    cout<<"\t3. BORROW BOOK \n"<<endl;
    cout<<"\t4. RETURN BOOK\n"<<endl;
    cout<<"\t5. BORROW STATUS\n"<<endl;
    cout<<"\t6. EXIT\n"<<endl;
    cout<<"\tEnter your opinion : ";
}
//function for printing mainmenu and taking input
void takeMenuInput()
{
    borrow_info b;
    system("cls");
    printMenu();
    int userInput;
    cin>>userInput;
    switch(userInput)
    {
    case 1:
        takeBookSubmenuInput();
        break;
    case 2:
        takeStudentSubmenuInput();
        break;
    case 3:
        b.get_borrow_info();
        break;
    case 4:
        b.get_return_info();
        break;
    case 5:
        b.display_borrow_status();
        break;
    default:
        exit(0);
    }
}
int main()
{
    login();
    return 0;
}




//Covid test kit management system
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <iomanip>
#include <time.h>
#define num_of_test_kits 300
using namespace std;
int password();
void menu();
void show();
class testKits
{
    int age;
    int temperature;
    int blood_pressure;
    char gender;
    string name;
    string aadhar;
    string symptoms;
    string address;
    string mobile_number;
    int cnt;

public:
    void search_data();
    void add_new();
    void setdata();
    void view_testKits();
    void showdata();
    void search_by_aadhar();
    void search_by_age();
    void search_by_symptoms();
    void search_by_gender();
    void show_list();
};
void show()
{
    cout << setw(20) << setiosflags(ios::left) << "Name ";
    cout << setw(20) << "Aadhar No.";
    cout << setw(15) << "Mobile No.";
    cout << setw(10) << "Age";
    cout << setw(7) << "gender";
    cout << setw(8) << "B.P.";
    cout << setw(15) << "Temperature";
    cout << setw(18) << "Symptoms";
    cout << "Address" << endl;
}
void testKits ::view_testKits()
{
    ifstream ind;
    int i = 0;
    ind.open("testKitstrial.txt");
    ind.seekg(0, ios::beg);
    while (ind.read((char *)this, sizeof(testKits)))
    {
        i++;
    }
    ind.close();
    int ch;
    int s = num_of_test_kits - i;
    cout << "\n\n\t\t          TEST KITS MANAGEMENT SYSTEM           \n\n"
         << endl;

    cout << "\n\t\t\t-----------------------------------------------\n";
    cout << "\t\t\t\tTEST KITS STATISTICS";
    cout << "\n\t\t\t-----------------------------------------------\n\n";
    cout << "\t\t 1. Enter new stock of test kits        \t\t\t2.View available test kits\n\t\t\t\t\t 3. Go Back" << endl;
    cin >> ch;
    int f_var = 0;
    fstream file("count.txt");
    file >> f_var;
    switch (ch)
    {
    case 1:
        int m;
        cout << "\t Enter number of new Test Kits  " << endl;
        cin >> m;
        f_var = f_var + m;
        file.seekg(0);
        file << f_var;
        cout << "\t\t Now total number of Test Kits  : " << f_var + s;
        break;
    case 2:
        cout << "\n\nAvailable number of Test Kits  :  " << s + f_var;
        break;
    case 3:
        system("cls");
        menu();
    default:
        system("cls");
        cout << "\n The option you entered is not valid" << endl;
        menu();
    }
    file.close();
    getch();
}
void testKits::show_list()
{
    cout << "\n";
    cout << setw(20) << setiosflags(ios::left) << name;
    cout << setw(20) << aadhar;
    cout << setw(10) << age;
    cout << setw(18) << symptoms;
    cout << setw(8) << blood_pressure;
    cout << setw(15) << temperature;
    cout << setw(7) << gender;
    cout << setw(15) << mobile_number;
    cout << address << endl;
}
void testKits::search_data()
{
    testKits item;
    cout << "\n\n\t\t         TEST KITS MANAGEMENT SYSTEM            \n\n"
         << endl;

    cout << "\n\t\t\t-----------------------------------------\n";
    cout << "\t\t\t\tSearch info : ";
    cout << "\n\t\t\t-----------------------------------------\n\n";
    cout << "From which option you want to perform searching " << endl;
    cout << "\n\t\t 1. By aadhar \t\t\t 2. By Age " << endl;
    cout << "\n\t\t 3. By symptoms \t\t 4. By gender " << endl;
    cout << "\n\n\t\tEnter your choice ";
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
        system("cls"); //clear screen
        search_by_aadhar();
        getch();
        break;
    case 2:
        system("cls");
        search_by_age();
        getch();
        break;
    case 3:
        system("cls");
        search_by_symptoms();
        getch();
        break;
    case 4:
        system("cls");
        search_by_gender();
        getch();
        break;
    default:
        system("cls");
        cout << "The option you entered  is not valid" << endl;
        menu();
    }
}
void testKits::search_by_aadhar()
{
    ifstream in("testKitstrial.txt");
    int flag = 0;
    string adh_num;
    cout << "\n\n\t\t        TEST KITS MANAGEMENT SYSTEM              \n\n"
         << endl;

    cout << "\n\t\t\t-----------------------------------------\n";
    cout << "\t\t\t\t Search by adhar";
    cout << "\n\t\t\t-----------------------------------------\n\n";
    cout << "Enter your Aadhar number " << endl;
    fflush(stdin);
    getline(cin, adh_num);
    in.read((char *)this, sizeof(testKits));
    while (!in.eof())
    {
        if (adh_num.compare(aadhar) == 0)
        {
            showdata();
            flag = 1;
            break;
        }
        in.read((char *)this, sizeof(testKits));
    }
    if (flag == 0)
    {
        cout << "Aadhar number not found " << endl;
    }
    in.close();
}
void testKits::search_by_age()
{
    ifstream in("testKitstrial.txt");
    int flag = 0;
    int a, p = 0;
    cout << "\n\n\t\t             TEST KITS MANAGEMENT SYSTEM              \n\n"
         << endl;
    cout << "\n\t\t\t-----------------------------------------\n";
    cout << "\t\t\t\t Search by age";
    cout << "\n\t\t\t-----------------------------------------\n\n";
    cout << "enter Age by which you want to search " << endl;
    cin >> a;
    show();
    in.read((char *)this, sizeof(testKits));
    while (!in.eof())
    {
        if (a == age)
        {
            show_list();
            flag = 1;
            p++;
        }
        in.read((char *)this, sizeof(testKits));
    }
    if (flag == 0)
    {
        cout << "Age you entered is not found" << endl;
    }
    cout << "\n\n\n\nNO of people tested  by this age" << p;
    in.close();
}
void testKits::search_by_symptoms()
{
    ifstream in("testKitstrial.txt");
    int flag = 0;
    int p = 0;
    string prof;
    cout << "\n\n\t\t             TEST KITS MANAGEMENT SYSTEM              \n\n"
         << endl;

    cout << "\n\t\t\t-----------------------------------------\n";
    cout << "\t\t\t\t Search by symptoms ";
    cout << "\n\t\t\t-----------------------------------------\n\n";
    cout << "enter symptoms by which you want to search " << endl;
    fflush(stdin);
    getline(cin, prof);
    show();
    in.read((char *)this, sizeof(testKits));
    while (!in.eof())
    {
        if (prof.compare(symptoms) == 0)
        {
            show_list();
            flag = 1;
            p++;
        }
        in.read((char *)this, sizeof(testKits));
    }
    if (flag == 0)
    {
        cout << "The symptoms you have Enter does not exist" << endl;
    }
    cout << "\n\n\n NO of people tested by this symptoms " << p << endl;
    in.close();
}
void testKits::search_by_gender()
{
    ifstream in("testKitstrial.txt");
    int flag = 0;
    char g;
    int p = 0;
    cout << "\n\n\t\t             TEST KITS MANAGEMENT SYSTEM              \n\n"
         << endl;
    cout << "\n\t\t\t-----------------------------------------n";
    cout << "\t\t\t\t Search by Gender";
    cout << "\n\t\t\t-----------------------------------------n\n";
    cout << "Enter gender by which you want to search " << endl;
    cin >> g;
    show();
    in.read((char *)this, sizeof(testKits));
    while (!in.eof())
    {
        if (toupper(g) == toupper(gender))
        {
            show_list();
            flag = 1;
            p++;
        }
        in.read((char *)this, sizeof(testKits));
    }
    if (flag == 0)
    {
        cout << "The gender you entered does not exist " << endl;
    }
    cout << "\n\n\n NO. of people tested by this gender " << p << endl;
    in.close();
}
void testKits::setdata()
{
    cout << "\n\n\t\t             TEST KITS MANAGEMENT SYSTEM              \n\n"
         << endl;

    cout << "\n\t\t\t--------------------------------------------\n";
    cout << "\t\t\t\t Search by adhar ";
    cout << "\n\t\t\t--------------------------------------------\n\n";
    fflush(stdin);
    cout << "\n\t\t Enter your name :-  ";
    getline(cin, name);
    cout << "\n\t\t Enter your aadhar :-  ";
    getline(cin, aadhar);
    cout << "\n\t\t Enter your gender (M|F) :-  ";
    cin >> gender;
    cout << "\n\t\t Enter your age:- ";
    cin >> age;
    fflush(stdin);
    cout << "\n\t\t Enter your symptoms :-  ";
    getline(cin, symptoms);
    cout << "\n\t\t Enter your B.P. :-  ";
    cin >> blood_pressure;
    cout << "\n\t\t Enter your Body temperature:-  ";
    cin >> temperature;
    fflush(stdin);
    cout << "\n\t\t Enter your permanent address :-  ";
    getline(cin, address);
    cout << "\n\t\t Enter your Mobile number :- ";
    getline(cin, mobile_number);
}
void testKits::showdata()
{
    cout << "\n\n\t\t             TEST KITS MANAGEMENT SYSTEM              \n\n"
         << endl;

    cout << "\n\t\t\t-----------------------------------------\n";
    cout << "\t\t\t\t DETAILS  ";
    cout << "\n\t\t\t-----------------------------------------\n\n";
    cout << "\t\t Name is: " << name << endl;
    cout << "\t\t Aadhar number is: " << aadhar << endl;
    cout << "\t\t Your age is : " << age << endl;
    cout << "\t\t symptoms are : " << symptoms << endl;
    cout << "\t\t Gender is : " << gender << endl;
    cout << "\t\t Blood pressure is :" << blood_pressure << endl;
    cout << "\t\t Body temperature is : " << temperature << endl;
    cout << "\t\t Address is " << address << endl;
    cout << "\t\t Mobile number is: " << mobile_number << endl;
}
void testKits::add_new()
{
    fstream outin;
    outin.open("testKitstrial.txt", ios::app | ios::in);
    setdata();
    outin.write((char *)this, sizeof(testKits));
    cout << "Data inserted successfully " << endl;
    getch();
    outin.close();
}
void menu()
{
    system("cls");
    cout << "\n\n\t\t             TEST KITS MANAGEMENT SYSTEM              \n\n"
         << endl;

    cout << "\n\t\t\t------------------------------------\n";
    cout << "\t\t\t\t\tMENU";
    cout << "\n\t\t\t------------------------------------\n";
    cout << "\n\t\t1: Add NEW PATIENT\t\t\t 2: View Test Kits data" << endl;
    cout << "\n\t\t3: search   \t\t\t\t 4: exit" << endl;
}
int main()
{
    testKits obj;
    int k = 3;
    int num_vac;
    cout << "\n\n\t\t             TEST KITS MANAGEMENT SYSTEM              \n\n"
         << endl;
    cout << "\t\n\n Press enter key to continue.............  " << endl;
    getch();
B:
    system("cls");
    cout << "\n\n\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t\tEnter User name and Password\n";
    cout << "\t\t\t\t-----------------------------------------\n";
    while (k >= 1)
    {
        int c = password();
        if (c == 1)
            break;
        else
            cout << "\n\n\t\t Wrong Password Or User Name \n\n\t\t You Can try Only " << k - 1 << " times more";
        k--;
        if (k < 1)
        {
            for (int i = 30; i >= 0; i--)
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\t\t\t\t\tYOU ARE BLOCKED FOR 30 seconds!!";
                cout << "\n\n\n\n\n\n\t\t\t\t\tTRY AFTER " << i << " SECONDS.....";
                Sleep(1000);
            }
            k = 3;
            goto B;
        }
    }
    int ch;
    do
    {
        cout << "\n\n\t\t             TEST KITS MANAGEMENT SYSTEM              \n\n"
             << endl;
        cout << "\t\t\t\t\t\t Made by - Rahul & Siddharth " << endl;
        menu();
        cout << "\n\t\n\tChoose options : ";
        cin >> ch;
        testKits v1;
        switch (ch)
        {
        case 1:
            system("cls");
            obj.add_new();
            break;
        case 2:
            system("cls");
            obj.view_testKits();
            break;
        case 3:
            system("cls");
            obj.search_data();
            break;
        case 4:
            system("cls");
            exit(0);
        default:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHANK YOU!!";
            Sleep(3000);
            exit(0);
        }
    } while (ch != 0);

    return 0;
}
int password()
{
    char cname[30], pass[20];
    int ch, i = 0, cap = 0, capt = 0;
    cout << "\n\n\n\n\n\t\t\t\t\tENTER YOUR USER NAME:  ";
    fflush(stdin);
    gets(cname);
    cout << "\n\t\t\t\t\tENTER YOUR PASSWORD:    ";
    while ((ch = getch()) != 13)
    {
        cout << "*";
        pass[i] = ch;
        i++;
    }
    pass[i] = '\0';
    srand(time(0));
    cap = rand();
    cout << "\n\t\t\t\t\t CAPTCHA:->  " << cap << endl;
    cout << " Please enter the valid CAPTCHA :-   ";
    cin >> capt;
    if ((strcmp(cname, "appolo") == 0) && (strcmp(pass, "12345") == 0) && cap == capt)
        return 1;
    else
        return 0;
}

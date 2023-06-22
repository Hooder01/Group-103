#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void menu();

void login();

void signup();

void read(string inputUsername, string inputPassword);

bool logged;

string user;

int main()
{
    menu();

    //return
    return 0;
}

void menu()
{
    system("CLS");
    int opt;
    if (logged)
    {
        cout << "\tSchool Lunch Menu\tHello, " << user <<"\n1. order\n\n >> ";
        cin >> opt;
    }
    else
    {
        cout << "\tSchool Lunch Menu\n1.login\t\t2.sign-up\t3.guest\n\n>> ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            login();
            break;
        case 2:
            signup();
            break;
        }
    }
    
    
 
}

void signup()
{
    system("CLS");
    //clear
    bool clear = false;
    //declare
    string username, password;
    string ch;
    ofstream clr;
    fstream fout;
    ifstream fin;
    //create + write
    fout.open("user_data.txt", ios::app);
    //create password
    cout << "enter username\n>> ";
    cin >> username;
    cout << "\n\nenter password\n>> ";
    cin >> password;
    //write
    fout << "[" << username << "|" << password << "]";
    //close/commit
    fout.close();
    //clear
    if (clear == true)
    {
        clr.open("user_data.txt", ofstream::out | ofstream::trunc);
        clr.close();
    }
    //read
    fin.open("user_data.txt");
    while (!fin.eof())
    {
        fin >> ch;
        cout << ch << " ";
    }
    //close
    fin.close();
    cout << endl;
    system("pause");
    system("CLS");
    cout << "successfully signed up\n";
    system("pause");
    menu();
}

void login()
{
    system("CLS");
    string username, password;
    cout << "enter username\n>> ";
    cin >> username;
    cout << "\n\nenter password\n>> ";
    cin >> password;
    read(username, password);
}

void read(string inputUsername, string inputPassword )
{
    bool flag = false;
   
    string data, load, build = "";
    fstream fout;
    ifstream fin;
    fin.open("user_data.txt");
    while (!fin.eof())
    {
        fin >> data;
        load += data;
    }
    //detect
    for (int i = 0; i < load.length(); ++i)
    {
        if (load[i] == '[')
        {
           
            ++i;
            while (load[i] != '|')
            {
                build += load[i];
                ++i;
            }
            if (build == inputUsername)
            {
                user = build;
                build = "";
                ++i;
                while (load[i] != ']')
                {
                    build += load[i];
                    ++i;
                }
                if (build == inputPassword)
                {
                    flag = true;
                    logged = true;
                    build = "";
                    break;
                }
                else
                {
                    build = "";
                }
            }
            else
            {
                build = "";
            }
        }
        ++i;
    }
    if (flag)
    {
        cout << "\nsuccessfully logged in.";
    }
    else
    {
        cout << "username or password is incorrect, please try again.";
    }
    //close
    fin.close();
    cout << endl;
    system("pause");
    menu();
}


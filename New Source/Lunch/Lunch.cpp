#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void menu();

void initilize();

void login();

void signup();

void read(string inputUsername, string inputPassword);

void order();

bool logged;

string user;

struct MENU {
    int ID[4];
    string item[4];
    string price[4];
};

int ORD[50];

int cur = 0;

MENU page[7];

int main()
{ 
    
    initilize();
    system("pause");
    menu();
    //return
    return 0;
}

void initilize()
{
    fstream fout;
    ifstream fin;
    string data, load, build = "";
    fin.open("menu.txt");
    int t = 0, id = 0;
    for (int p = 0; p < 7; ++p)
    {
        fin >> data;
        for (int i = 0; i < data.length(); ++i)
        {
            if (data[i] == '_')
            {
                data[i] = ' ';
            }
        }
        
            for (int i = 0; i < data.length(); ++i)
            {
                if (data[i] == '[')
                {
                    //start
                    ++i;
                    while (data[i] != '{')
                    {
                        build += data[i];
                        ++i;
                    }
                    page[p].ID[t] = id;
                    ++id;
                    page[p].item[t] = build;
                    build = "";
                    ++i;
                    while (data[i] != '}')
                    {
                        build += data[i];
                        ++i;
                    }
                    page[p].price[t] = build;
                    build = "";
                    if (t < 4)
                    {
                        ++t;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            t = 0;  
            
    }
}
    
void order()
{

    int P = 0, X = 0;
    char choice;
    bool fin = false;
    while (!fin)
    {
        system("CLS");
        cout << "\t    \t\t    Menu\n\t~~~~~~~~~~~~~~~~~~~******~~~~~~~~~~~~~~~~~~~\n\n";
        for (int i = 0; i < 4; ++i)
        {
            cout << "[" << i + 1 << "]\t" << page[P].item[i] << "\t$" << page[P].price[i] << endl << endl;
        }
        cout << "\t<<[b]\t\t    page "<< P + 1 << "\t\t[f] >> \n\n[e] Exit\n\n >> ";
        cin >> choice;
        if (choice == 'b' || choice == 'B')
        {
            --P;
            if (P < 0)
            {
                P = 0;
            }
        }
        else if (choice == 'f' || choice == 'F')
        {
            ++P;
            if (P > 6)
            {
                P = 6;
            }
        }
        else if (choice == 'e' || choice == 'E')
        {
            menu();
        }
        else if (choice == '1')
        {
            ORD[cur] = page[P].ID[0];
            ++cur;
        }
        else if (choice == '2')
        {
            ORD[cur] = page[P].ID[1];
            ++cur;
        }
        else if (choice == '3')
        {
            ORD[cur] = page[P].ID[2];
            ++cur;
        }
        else if (choice == '4')
        {
            ORD[cur] = page[P].ID[3];
            ++cur;
        }
    }
    system("pause");
    system("CLS");

}

void menu()
{
    system("CLS");
    int opt = 0;
    if (logged)
    {
        cout << "\tSchool Lunch Menu\n\t  Hello, " << user << "\n1.order\n\n>> ";
        cin >> opt;
        if (opt == 1)
        {
            order();
        }
        else
        {
            menu();
        }
    }
    else
    {
        cout << "\tSchool Lunch Menu\n1.login\t\t\t2.sign-up\n\n>> ";
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
    //
    bool flag = false;
    //declare
    string username, password;
    string ch;
    ofstream clr;
    fstream fout;
    ifstream fin;
    string data, load, build = "";
    //create + write
    fout.open("user_data.txt", ios::app);
    fin.open("user_data.txt");
    while (!fin.eof())
    {
        fin >> data;
        load += data;
    }
    while (!flag)
    {
        cout << "enter username\n>> ";
        cin >> username;
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
                if (build == username)
                {
                    system("CLS");
                    cout << "username already taken, please try again.\n\n";
                    system("pause");
                    system("CLS");
                    build = "";
                    i = 0;
                    flag = false;
                    break;
                }
                if (build != username)
                {
                    build = "";
                    flag = true;
                }
                if (load[i] == '|')
                {
                    while (load[i] != ']')
                    {
                        ++i;
                    }
                }
            }
        }
    }
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

void read(string inputUsername, string inputPassword)
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
        cout << "\nusername or password is incorrect, please try again.";
    }
    //close
    fin.close();
    cout << endl;
    system("pause");
    menu();
}


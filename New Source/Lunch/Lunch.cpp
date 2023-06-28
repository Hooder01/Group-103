#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include<regex>

using namespace std;

void menu();

void initilize();

void login();

void signup();

void read(string inputUsername, string inputPassword);

void order();

void cart();

void editUD();

void editSplash();

void editMENU();

void nameEditor(int a, int b);

void priceEditor(int a, int b);

void showOrders();

bool logged;

bool Alogged;

string user, email, splash;

struct MENU {
    int ID[4];
    string item[4];
    string price[4];
};

int ORD[50];

string TotalUsers[50];

int cur = 0, cur1 = 0;

MENU page[7];

int main()
{ 
    initilize();
    menu();
    //return
    return 0;
}

void initilize()
{  
    fstream fout;
    ifstream fin;
    string data, load, build = "";
    int t = 0, id = 0;
    logged = false;
    Alogged = false;
    fin.open("menu.txt");
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
    fin.close();
    //
    fin.open("user_data.txt");
    fin >> data;
    for (int i = 0; i < data.length(); ++i)
    {
        if (data[i] == '[')
        {

            ++i;
            while (data[i] != '|')
            {
                build += data[i];
                ++i;
            }
            TotalUsers[cur1] = build;
            build = "";
            ++cur1;
            if (data[i] == '|')
            {
                while (data[i] != '}')
                {
                    ++i;
                }
            }
        }
    }
    fin.close();
    //
    build = "";
    string conv, curr;
    fout.open("splash.txt", ios::app);
    fin.open("splash.txt");
    while (!fin.eof())
    {
        fin >> curr;
        build += curr;
    }
    for (int i = 0; i < build.length(); ++i)
    {
        if (build[i] == '_')
        {
            build[i] = ' ';
        }
    }
    splash = build;
    fin.close();
    fout.close();
}
    
void order()
{

    int P = 0, X = 0;
    char choice;
    while (true)
    {
        system("CLS");
        cout << "\t    \t\t    Menu\n\t~~~~~~~~~~~~~~~~~~~******~~~~~~~~~~~~~~~~~~~\n\n   \t"<< splash <<"\n\n";
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
            cout << "\033[32m" << "\n\nSuccessfully added \"" << page[P].item[0] << "\" to your cart!\n\n" << "\033[0m";
            system("pause");
        }
        else if (choice == '2')
        {
            ORD[cur] = page[P].ID[1];
            ++cur;
            cout << "\033[32m" << "\n\nSuccessfully added \"" << page[P].item[1] << "\" to your cart!\n\n" << "\033[0m";
            system("pause");
        }
        else if (choice == '3')
        {
            ORD[cur] = page[P].ID[2];
            ++cur;
            cout << "\033[32m" << "\n\nSuccessfully added \"" << page[P].item[2] << "\" to your cart!\n\n" << "\033[0m";
            system("pause");
        }
        else if (choice == '4')
        {
            ORD[cur] = page[P].ID[3];
            ++cur;
            cout << "\033[32m" << "\n\nSuccessfully added \"" << page[P].item[3] << "\" to your cart!\n\n" << "\033[0m";
            system("pause");
        }
    }
    

}

void menu()
{

    system("CLS");
    char opt;
    if (logged)
    {
        cout << "\tSchool Lunch Menu\n\t  Hello, " << user << "\n1.order\t\t\t2.cart\n\n>> ";
        cin >> opt;
        if (opt == '1')
        {
            order();
        }
        else if (opt == '2')
        {
            cart();
        }
        else
        {
            menu();
        }
    }
    else if (Alogged)
    {
        cout << "\tSchool Lunch Menu\n\t ADMIN  CONTROLS" << "\n\n1.view/edit user data\n\n2.edit deal text\n\n3.edit menu\n\n4.view orders\n\n>> ";
        cin >> opt;
        if (opt == '1')
        {
            editUD();
        }
        else if (opt == '2')
        {
            editSplash();
        }
        else if (opt == '3')
        {
            editMENU();
        }
        else if (opt == '4')
        {
            showOrders();
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
        if (opt == '1')
        {
            login();
        }
        else if (opt == '2')
        {
            signup();
        }
        else
        {
            menu();
        }
    }
}

void cart()
{
    fstream fout;
    string cardNo, cardDt, cardCVC;
    char choice, choice2;
    double total = 0;
    fout.open("order_data.txt", ios::app);
    system("CLS");
    cout << "\t    \t\t    Cart\n\t~~~~~~~~~~~~~~~~~~~******~~~~~~~~~~~~~~~~~~~\n\n";
    for (int i = 0; i < cur; ++i)
    {     
        for (int x = 0; x < 7; ++x)
        {
            for (int y = 0; y < 4; ++y)
            {
                if (page[x].ID[y] == ORD[i])
                {
                    cout << "\033[0m" << page[x].item[y] << " : ";
                    cout << "\033[32m" << "$" << page[x].price[y] << endl << endl;
                    total += stod(page[x].price[y]);
                }
            }
        }
    }
    cout << "\033[47m" << "\033[30m" << "Total : " << "\033[92m" << "$" << total << endl << endl << "\033[0m";
    cout << "\n\n[p]Proceed to Billing\t[e]Exit\n\n>> ";
    cin >> choice;
    if (choice == 'e' || choice == 'E')
    {
        menu();
    }
    else if (choice == 'p' || choice == 'P')
    {
        cout << "\n\n\t    \t\t    Billing\n\t~~~~~~~~~~~~~~~~~************~~~~~~~~~~~~~~~~~\n\n";
        cout << "---Please select payment type---\n1." << "\033[35m" << "VISA" << "\033[0m"<< "\t2." << "\033[33m" <<"MASTERCARD" << "\033[0m" << "\n\n>> ";
        cin >> choice;
        while (true)
        {
            if (choice == '1')
            {
                cout << "\033[35m" << "\n\n\t    \t\t    VISA" << "\033[0m" << "\n\t~~~~~~~~~~~~~~~~~********~~~~~~~~~~~~~~~~~";
                while (cardNo.length() != 19)
                {
                    cout << "\n\nPlease enter your VISA card number (XXXX-XXXX-XXXX-XXXX)";
                    cout << "\n\n>> ";
                    cin >> cardNo;
                }
                while (cardDt.length() != 4)
                {
                    cout << "\n\nPlease enter your card's expiry date (X/XX)";
                    cout << "\n\n>> ";
                    cin >> cardDt;
                }
                while (cardCVC.length() != 3)
                {
                    cout << "\n\nPlease enter your card's CVC (XXX)";
                    cout << "\n\n>> ";
                    cin >> cardCVC;
                }
                cout << "\n\nPlease confirm your purchase of $" << total << " with VISA ..." << cardNo[15] << cardNo[16] << cardNo[17] << cardNo[18] << "[y/n]\n>> ";
                cin >> choice2;
                if (choice2 == 'y' || choice2 == 'Y')
                {
                    cout << "\n\nThanks for confirming your purchase, your receipt will be email to " << email << endl << endl;
                    system("pause");
                    system("CLS");
                    cout << "\n\n\t    \t\t    RECEIPT\n\t~~~~~~~~~~~~~~~~~************~~~~~~~~~~~~~~~~~\n";
                    cout << "**************************************************************\n";
                    for (int i = 0; i < cur; ++i)
                    {
                        for (int x = 0; x < 7; ++x)
                        {
                            for (int y = 0; y < 4; ++y)
                            {
                                if (page[x].ID[y] == ORD[i])
                                {
                                    cout << "\033[37m" << page[x].item[y] << " : ";
                                    cout << "\033[32m" << "$" << page[x].price[y] << endl << endl;
                                }
                            }
                        }
                    }
                    cout << "\033[47m" << "\033[30m" << "Total : " << "\033[92m" << "$" << total << endl << endl << "\033[0m";
                    cout << "VISA ..." << cardNo[15] << cardNo[16] << cardNo[17] << cardNo[18] << endl << endl;
                    cout << "\033[47m" << "\033[92m" << "PAID" << endl << endl << "\033[0m" << endl << endl;
                    cout << "\033[0m" << "**************************************************************\n";
                    fout << '[' << user << '|' << email << '{';
                    for (int i = 0; i < cur; ++i)
                    {
                        fout << ',' << ORD[i];
                    }
                    fout << '}' << total << '|' << "VISA" << '|' << cardNo << '|' << cardDt << '|' << cardCVC << '|' << ']';
                    fout.close();
                    system("pause");
                    exit(0);
                }
            }
            else if (choice == '2')
            {
                cout << "\033[33m" << "\n\n\t    \t\t    MASTERCARD" << "\033[0m" << "\n\tt~~~~~~~~~~~~~~~~~************~~~~~~~~~~~~~~~~~";
                while (cardNo.length() != 19)
                {
                    cout << "\n\nPlease enter your MASTERCARD card number (XXXX-XXXX-XXXX-XXXX)";
                    cout << "\n\n>> ";
                    cin >> cardNo;
                }
                while (cardDt.length() != 4)
                {
                    cout << "\n\nPlease enter your card's expiry date (X/XX)";
                    cout << "\n\n>> ";
                    cin >> cardDt;
                }
                while (cardCVC.length() != 3)
                {
                    cout << "\n\nPlease enter your card's CVC (XXX)";
                    cout << "\n\n>> ";
                    cin >> cardCVC;
                }
                cout << "\n\nPlease confirm your purchase of $" << total << " with MASTERCARD ..." << cardNo[15] << cardNo[16] << cardNo[17] << cardNo[18] << "[y/n]\n>> ";
                cin >> choice2;
                if (choice2 == 'y' || choice2 == 'Y')
                {
                    cout << "\n\nThanks for confirming your purchase, your receipt will be email to " << email << endl << endl;
                    system("pause");
                    system("CLS");
                    cout << "\n\n\t    \t\t    RECEIPT\n\t~~~~~~~~~~~~~~~~~************~~~~~~~~~~~~~~~~~\n";
                    cout << "**************************************************************\n";
                    for (int i = 0; i < cur; ++i)
                    {
                        for (int x = 0; x < 7; ++x)
                        {
                            for (int y = 0; y < 4; ++y)
                            {
                                if (page[x].ID[y] == ORD[i])
                                {
                                    cout << "\033[37m" << page[x].item[y] << " : ";
                                    cout << "\033[32m" << "$" << page[x].price[y] << endl << endl;
                                }
                            }
                        }
                    }
                    cout << "\033[47m" << "\033[30m" << "Total : " << "\033[92m" << "$" << total << endl << endl << "\033[0m";
                    cout << "MASTERCARD ..." << cardNo[15] << cardNo[16] << cardNo[17] << cardNo[18] << endl << endl;
                    cout << "\033[47m" << "\033[92m" << "PAID" << endl << endl << "\033[0m" << endl << endl;
                    cout << "\033[0m" << "**************************************************************\n";
                    fout << '[' << user << '|' << email << '{';
                    for (int i = 0; i < cur; ++i)
                    {
                        fout<< ',' << ORD[i];
                    }
                    fout << '}'<< total<<'|'<<"MASTERCARD"<<'|'<<cardNo << '|' << cardDt << '|' << cardCVC << '|' <<  ']';
                    fout.close();
                    system("pause");
                    exit(0);
                }
            }
            else 
                {
                cart();
            }
                
            
            
        }
      
    }
    
    system("pause");
    menu();
}

void signup()
{
    system("CLS");
    //clear
    bool clear = false;
    //
    bool flag = false;
    //declare
    string username, password, email;
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
        cout << "enter email\n>> ";
        cin >> email;
        if (regex_match(email, regex("([a-z]+)([_.a-z0-9]*)([a-z0-9]+)(@)([a-z]+)([.a-z]+)([a-z]+)")))
        {
            flag = true;
        }
        else
        {
            cout << "\n\nInvalid email, please try again\n\n";
            system("pause");
            system("CLS");
        }
    }
    flag = false;
    while (!flag)
    {
        cout << "\nenter username\n>> ";
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
    fout << "[" << username << "|" << password << "]" << "{" << email << "}";
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
                    if (user == "admin")
                    {
                        Alogged = true;
                    }
                    else
                    {
                        logged = true;
                    }
                    build = "";
                    ++i;
                    ++i;
                    while (load[i] != '}')
                    {
                        build += load[i];
                        ++i;
                    }
                    email = build;
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
        cout << "\nsuccessfully logged in.\n";
    }
    else
    {
        cout << "\nusername or password is incorrect, please try again\n.";
    }
    //close
    fin.close();
    cout << endl;
    system("pause");
    menu();
}

void editUD()
{
    int max;
    bool flag = false;
    ofstream clr;
    fstream fout;
    ifstream fin;
    string data, build = "";
    string choice;
    string EM_NEW;
    char choice1;
    string USR, EML;
    int iUSR;
    string store1, store2;
    system("CLS");
    fin.open("user_data.txt");
    fin >> data;
    cout << "\t    \t\t     Edit User Data\n\t~~~~~~~~~~~~~~~~~~~*******************~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "***USERS***\n\n";
    for (int i = 0; i < cur1; ++i)
    {
        cout << "[" << i << "]" << TotalUsers[i] << endl << endl;
    }
    cout << "***********\n\nPlease Select a User\t[e]Exit\n\n>> ";
    cin >> choice;
    if (choice == "e" || choice == "E")
    {
        menu();
    }
    iUSR = stoi(choice);
    USR = TotalUsers[iUSR];
    system("CLS");
    while (true)
    {
        for (int i = 0; i < data.length(); ++i)
        {
            if (data[i] == '[')
            {

                ++i;
                while (data[i] != '|')
                {
                    build += data[i];
                    ++i;
                }
                if (build == USR)
                {
                    build = "";
                    while (data[i] != '{')
                    {
                        ++i;
                    }
                    ++i;
                    while (data[i] != '}')
                    {
                        build += data[i];
                        ++i;
                    }
                    EML = build;
                    cout << "Current username : " << USR << endl << endl;
                    cout << "Current email : " << EML << endl << endl;
                    cout << "Would you like to edit this email? [y/n]\n\n>> ";
                    cin >> choice1;
                    if (choice1 == 'y' || choice1 == 'Y')
                    {
                        cout << "\n************\n\nPlease enter new email\n\n>> ";
                        while (!flag)
                        {
                            cin >> EM_NEW;
                            cout << endl << endl;
                            if (regex_match(EM_NEW, regex("([a-z]+)([_.a-z0-9]*)([a-z0-9]+)(@)([a-z]+)([.a-z]+)([a-z]+)")))
                            {
                                flag = true;
                            }
                            else
                            {
                                cout << "\n\nInvalid email, please try again\n\n";
                            }
                            for (int i = 0; i < data.length(); ++i)
                            {
                                if (data[i] == '[')
                                {

                                    ++i;
                                    while (data[i] != '|')
                                    {
                                        build += data[i];
                                        ++i;
                                    }
                                    if (build == USR)
                                    {
                                        while (data[i] != '{')
                                        {
                                            ++i;
                                        }
                                        max = i;
                                        i = 0;
                                        while (i != max)
                                        {
                                            store1 += data[i];
                                            ++i;
                                        }
                                        store1 += data[i];
                                        while (data[i] != '}')
                                        {
                                            ++i;
                                        }
                                        while ((data[i] != '\0'))
                                        {
                                            store2 += data[i];
                                            ++i;
                                        }
                                        clr.open("user_data.txt", ofstream::out | ofstream::trunc);
                                        clr.close();
                                        fout.open("user_data.txt", ios::app);
                                        fout << store1 << EM_NEW << store2;
                                        fout.close();
                                        fin.close();
                                        fin.open("user_data.txt");
                                        fin >> data;
                                        cout << "email successfully updated\n\n";
                                        system("pause");
                                        editUD();
                                    }
                                    if (build != USR)
                                    {
                                        build = "";
                                        flag = true;
                                    }
                                    if (data[i] == '|')
                                    {
                                        while (data[i] != ']')
                                        {
                                            ++i;
                                        }
                                    }
                                }
                            }
                        }
                        
                    }
                    else
                    {
                        editUD();
                    }
                    
                    break;
                }
                if (build != USR)
                {
                    build = "";
                }
                if (data[i] == '|')
                {
                    while (data[i] != ']')
                    {
                        ++i;
                    }
                }
            }
        }
    }
    
    
}

void editSplash()
{
    ofstream clr;
    fstream fout;
    ifstream fin;
    string conv, curr, build;
    system("CLS");
    fout.open("splash.txt", ios::app);
    fin.open("splash.txt");
    while (!fin.eof())
    {
        fin >> curr;
        build += curr;
    }
    for (int i = 0; i < build.length(); ++i)
    {
        if (build[i] == '_')
        {
            build[i] = ' ';
        }
    }
    fin.close();
    cout << "current deal : " << build << endl << endl;
    cout << "please enter new deal\t[e]EXIT\n\n>> ";
    getline(cin >> ws, conv);
    if (conv == "e" || conv == "E")
    {
        fout.close();
        menu();
    }
    clr.open("splash.txt", ofstream::out | ofstream::trunc);
    clr.close();
    cout << "\n";
    for (int i = 0; i < conv.length(); ++i)
    {
        if (conv[i] == ' ')
        {
            conv[i] = '_';
        }
    }
    fout << conv;   
    fout.close();
    cout << "deal successfully updated.\n\n";
    system("pause");
    menu();
}

void editMENU()
{

    int P = 0, X = 0;
    char choice;
    while (true)
    {
        system("CLS");
        cout << "\t    \t\t    Edit Menu\n\t~~~~~~~~~~~~~~~~~~~************~~~~~~~~~~~~~~~~~~~\n\n   \t" << "\t~please select an item to edit~" << "\n\n";
        for (int i = 0; i < 4; ++i)
        {
            cout << "[" << i + 1 << "]\t" << page[P].item[i] << "\t$" << page[P].price[i] << endl << endl;
        }
        cout << "\t<<[b]\t\t    page " << P + 1 << "\t\t[f] >> \n\n[e] Exit\n\n >> ";
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
            system("CLS");
            cout <<"Item : " << page[P].item[0];
            cout << "\n\nPrice : $" << page[P].price[0];
            cout << "\n\nEdit Name or Price? [n] [p]\t[e]EXIT\n\n>> ";
            cin >> choice;
            if (choice == 'n' || choice == 'N')
            {
                nameEditor(P, 0);
            }
            if (choice == 'p' || choice == 'P')
            {
                priceEditor(P, 0);
            }
            else
            {
                editMENU();
            }
            system("pause");
           
        }
        else if (choice == '2')
        {
            system("CLS");
            cout << "Item : " << page[P].item[0];
            cout << "\n\nPrice : $" << page[P].price[0];
            cout << "\n\nEdit Name or Price? [n] [p]\t[e]EXIT\n\n>> ";
            cin >> choice;
            if (choice == 'n' || choice == 'N')
            {
                nameEditor(P, 1);
            }
            if (choice == 'p' || choice == 'P')
            {
                priceEditor(P, 1);
            }
            else
            {
                editMENU();
            }
            system("pause");
        }
        else if (choice == '3')
        {
            system("CLS");
            cout << "Item : " << page[P].item[0];
            cout << "\n\nPrice : $" << page[P].price[0];
            cout << "\n\nEdit Name or Price? [n] [p]\t[e]EXIT\n\n>> ";
            cin >> choice;
            if (choice == 'n' || choice == 'N')
            {
                nameEditor(P, 2);
            }
            if (choice == 'p' || choice == 'P')
            {
                priceEditor(P, 2);
            }
            else
            {
                editMENU();
            }
            system("pause");
        }
        else if (choice == '4')
        {
            system("CLS");
            cout << "Item : " << page[P].item[0];
            cout << "\n\nPrice : $" << page[P].price[0];
            cout << "\n\nEdit Name or Price? [n] [p]\t[e]EXIT\n\n>> ";
            cin >> choice;
            if (choice == 'n' || choice == 'N')
            {
                nameEditor(P, 3);
            }
            if (choice == 'p' || choice == 'P')
            {
                priceEditor(P, 3);
            }
            else
            {
                editMENU();
            }
            system("pause");
        }
    }
}

void nameEditor(int a, int b)
{
    string data,item, build,part1,part2, conv;
    int max;
    ofstream clr;
    fstream fout;
    ifstream fin;
    fin.open("menu.txt");
    fin >> data;
    item = page[a].item[b];
    
    for (int i = 0; i < item.length(); ++i)
    {
        if (item[i] == ' ')
        {
            item[i] = '_';
        }
    }
    cout << "\nInsert new item name\n\n>> ";
    getline(cin >> ws, conv);
    for (int i = 0; i < conv.length(); ++i)
    {
        if (conv[i] == ' ')
        {
            conv[i] = '_';
        }
    }
    
    for (int i = 0; i < data.length(); ++i)
    {
        build = "";
        if (data[i] == '[')
        {
            ++i;
            while (data[i] != '{')
            {
                build += data[i];
                ++i;
            }
            if (build == item)
            {
                build = "";
                while (data[i] != '[')
                {
                    --i;
                }
                max = i;
                while (data[i] != '{')
                {
                    ++i;
                }
                while (data[i] != '\0')
                {
                    part2 += data[i];
                    ++i;
                }
                i = 0;
                while (i != max)
                {
                    part1 += data[i];
                    ++i;
                }
                part1 += data[i];
                part1 += data[i];
                for (int i = 0; i < conv.length(); ++i)
                {
                    if (conv[i] == ' ')
                    {
                        conv[i] = '_';
                    }
                }
                clr.open("menu.txt", ofstream::out | ofstream::trunc);
                clr.close();
                fout.open("menu.txt", ios::app);
                fout << part1 << conv << part2;
                fout.close();
                fin.close();
                page[a].item[b] = conv;
                cout << "\nitem successfully updated\n\n";
                system("pause");
                menu();
            }
        }
    }
}

void priceEditor(int a, int b)
{
    string data, item, build, part1, part2, conv;
    int max;
    ofstream clr;
    fstream fout;
    ifstream fin;
    fin.open("menu.txt");
    fin >> data;
    item = page[a].price[b];

    for (int i = 0; i < item.length(); ++i)
    {
        if (item[i] == ' ')
        {
            item[i] = '_';
        }
    }
    cout << "\nInsert new price\n\n>> ";
    getline(cin >> ws, conv);

    for (int i = 0; i < data.length(); ++i)
    {
        build = "";
        if (data[i] == '{')
        {
            ++i;
            while (data[i] != '}')
            {
                build += data[i];
                ++i;
            }
            if (build == item)
            {
                build = "";
                while (data[i] != '{')
                {
                    --i;
                }
                
                max = i;
                while (data[i] != '}')
                {
                    ++i;
                }
                while (data[i] != '\0')
                {
                    part2 += data[i];
                    ++i;
                }
                i = 0;
                while (i != max)
                {
                    part1 += data[i];
                    ++i;
                }
                part1 += data[i];
                for (int i = 0; i < conv.length(); ++i)
                {
                    if (conv[i] == ' ')
                    {
                        conv[i] = '_';
                    }
                }
                clr.open("menu.txt", ofstream::out | ofstream::trunc);
                clr.close();
                fout.open("menu.txt", ios::app);
                fout << part1 << conv << part2;
                fout.close();
                fin.close();
                page[a].price[b] = conv;
                cout << "\nitem successfully updated\n\n";
                system("pause");
                menu();
            }
        }
    }

}

void showOrders()
{
    system("CLS");
    int a = 0;
    string data,build;
    string LIST[50];
    ifstream fin;
    fin.open("order_data.txt");
    fin >> data;
    for (int i = 0; i < data.length(); ++i)
    {
        if (data[i] == '[')
        {
            ++i;
            while (data[i] != ']')
            {
                build += data[i];
                ++i;
            }
            LIST[a] = build;
            build = "";
            ++a;

        }
    }
    cout << "\t    \t\t    Orders\n\t~~~~~~~~~~~~~~~~~~~*******~~~~~~~~~~~~~~~~~~~\n\n";
    for (int i = 0; i < a; ++i)
    {
        cout << LIST[i] << endl << endl;
    }
    cout << "[e]EXIT";
    char choice;
    cin >> choice;
    menu();
}
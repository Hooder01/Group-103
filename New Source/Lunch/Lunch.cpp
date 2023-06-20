#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int menu()// Section done by James
{
    string menuItems[10]{ "Shepherds Pie", "Mashed Potato & Cheese", "Fresh Fruit", "Loaded Wedges", "Veggie Burger", "Vegetarian Curry", "Beef Nachos with Cheese", "Sweet Slice", "Butter Chicken with Basmati Rice", "Ice cream sunday" };

    cout << "\n\n==================" << "\n\nLUNCH ORDER MENU" << "\n\n==================";

    

    return 0;
}
// Section ends...




int main()
{
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
    fout << "[" << username <<"|" << password << "]";
    //close/commit
    fout.close();
    //read
    fin.open("user_data.txt");
    while (!fin.eof())
    {
        fin >> ch;
        cout << ch << " ";
    }
    //close
    fin.close();
    if (clear == true)
    {
        clr.open("user_data.txt", std::ofstream::out | std::ofstream::trunc);
        clr.close();
    }

    //return
    return 0;
}

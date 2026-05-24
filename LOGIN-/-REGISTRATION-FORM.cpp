#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class mubi
{

    string username, email, password, mobile_number;
    string input_email, input_password, input_username;
    ifstream file;

public:
    void signup();
    void login();
    void forgot_password();
    void show();
};

int main()
{
    mubi m;

    int option;
    cout << "------Welcome to the Login and Registration Form!---" << endl;
    cout << "Please select an option:" << endl;
    cout << "1. signup" << endl;
    cout << "2. login" << endl;
    cout << "3. forgot password" << endl;
    cout << "4. read records" << endl;
    cout << "5. exit" << endl;
    cout << "\tEnter your option: ";

    cin >> option;
    cin.ignore();

    switch (option)
    {
    case 1:
        m.signup();
        break;
    case 2:
        m.login();
        break;
    case 3:
        m.forgot_password();
        break;
    case 4:
        m.show();
        break;
    case 5:
        cout << "Exiting the program. Goodbye!" << endl;
        break;
    default:
        cout << "Invalid option. Please try again." << endl;
    }
}
void mubi ::signup()
{
    cout << "Enter your username:\n ";
    getline(cin, username);
    cout << "Enter your email: \n";
    getline(cin, email);
    cout << "create your password: \n";
    getline(cin, password);
    ofstream file("record.txt", ios::app | ios::out);
    file << username << "," << email << "," << password << endl;
}

void mubi ::login()
{
    cout << "enter your email \t";
    getline(cin, input_email);
    cout << "enter your password \t";
    getline(cin, input_password);

    file.open("record.txt", ios::in);

    if (!file.is_open())
    {
        cout << "FILE NOT OPENED\n";
    }
    bool found = false;
    while (getline(file, username, ',') &&
           getline(file, email, ',') &&
           getline(file, password))

    {

        if (input_email == email && input_password == password)
        {

            cout << "\tACESS GRANTED \n";
            cout << email << "\n";
            cout << username;
            found = true;
            break;
        }
    }
    if (!found && input_email == email && input_password != password)
    {
        cout << "\tACCESS DENIED----PASSWORD INCORRECT\n";
    }

    if (!found && input_email != email && input_password == password)
    {
        cout << "\tACCESS DENIED----EMAIL INCORRECT\n";
    }
    if (!found)
    {
        cout << "\tACCESS DENIED----wrong credentials\n";
    }
    file.close();
}

void mubi ::forgot_password()
{
    cout << "enter your username \t";
    getline(cin, input_username);
    cout << "enter your email \t";
    getline(cin, input_email);

    file.open("record.txt", ios::in);

    if (!file.is_open())
    {
        cout << "FILE NOT OPENED\n";
    }

    bool found = false;

    while (getline(file, username, ',') &&
           getline(file, email, ',') &&
           getline(file, password))

    {
        if (input_username == username && input_email == email)
        {

            cout << "\tPASSWORD RETRIEVED \n";
            cout << "your password is: " << password << "\n";
            found = true;
            break;
        }
    }

    if (!found && input_username != username && input_email == email)
    {
        cout << "\tACCESS DENIED----USERNAME INCORRECT\n";
    }

    if (!found && input_email != email && input_username == username)
    {
        cout << "\tACCESS DENIED----EMAIL INCORRECT\n";
    }

    if (!found)
    {
        cout << "\t WRONG CREDENTIALS\n";
    }
    file.close();
}

void mubi::show()
{
    string data;
    if (!file.is_open())
        file.open("record.txt");
    while (getline(file, data))
        cout << data << endl;
    file.close();
}
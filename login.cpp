#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class UserAccount
{
public:
    string userName;
    string EmailId;
    string UserPassword;
    string SearchUserName;
    string SearchUserPassword;
    string SearchUserEmail;

    fstream file;

    void login()
    {
        cout << "---***--- Login Page ---***--- " << endl;
        cout << "Enter Your User Name: ";
        cin.ignore(); // Clear the input buffer before getline
        getline(cin, SearchUserName);
        cout << "Enter Your Password: ";
        getline(cin, SearchUserPassword);

        file.open("loginData.txt", ios::in);
        if (!file)
        {
            cout << "Error: Unable to open file. Please try again later." << endl;
            return;
        }

        getline(file, userName, '*');
        getline(file, EmailId, '*');
        getline(file, UserPassword);

        bool found = false;
        while (!file.eof())
        {
            if (userName == SearchUserName)
            {
                if (UserPassword == SearchUserPassword)
                {
                    cout << "Your Account Successfully Logged In!" << endl;
                    cout << "User Name: " << userName << endl;
                    cout << "Email: " << EmailId << endl;
                    found = true;
                    break;
                }
                else
                {
                    cout << "Sorry... Your Password is Wrong." << endl;
                    found = true;
                    break;
                }
            }
            getline(file, userName, '*');
            getline(file, EmailId, '*');
            getline(file, UserPassword);
        }
        if (!found)
        {
            cout << "Your Account Not Found." << endl;
        }
        file.close();
    }

    void signUp()
    {
        cout << "Enter Your User Name: ";
        getline(cin, userName);
        cout << "Enter Your Email Address: ";
        getline(cin, EmailId);
        cout << "Enter Your Password: ";
        getline(cin, UserPassword);

        file.open("loginData.txt", ios::out | ios::app);
        if (!file)
        {
            cout << "Error: Unable to open file. Please try again later." << endl;
            return;
        }
        file << userName << "*" << EmailId << "*" << UserPassword << endl;
        file.close();
        cout << "Account Created Successfully!" << endl;
    }

    void forget()
    {
        cout << "---***--- Forgot Password Page ---***---" << endl;
        cout << "Enter Your User Name: ";
        cin.ignore(); // Clear the input buffer before getline
        getline(cin, SearchUserName);
        cout << "Enter Your Email: ";
        getline(cin, SearchUserEmail);

        file.open("loginData.txt", ios::in);
        if (!file)
        {
            cout << "Error: Unable to open file. Please try again later." << endl;
            return;
        }

        getline(file, userName, '*');
        getline(file, EmailId, '*');
        getline(file, UserPassword);

        bool found = false;
        while (!file.eof())
        {
            if (userName == SearchUserName && EmailId == SearchUserEmail)
            {
                cout << "Your Account Successfully Found!" << endl;
                cout << "Your Password: " << UserPassword << endl;
                found = true;
                break;
            }
            getline(file, userName, '*');
            getline(file, EmailId, '*');
            getline(file, UserPassword);
        }
        if (!found)
        {
            cout << "Your Account Not Found." << endl;
        }
        file.close();
    }
};

int main(int argc, char const *argv[])
{
    char choice;
    UserAccount u;

    cout << "1 -> Login" << endl;
    cout << "2 -> Sign-Up" << endl;
    cout << "3 -> Forgot Password" << endl;
    cout << "4 -> Exit" << endl;
    cout << "Please Select Your Choice: ";
    cin >> choice;
    cin.ignore(); // Clear the input buffer after reading choice

    switch (choice)
    {
    case '1':
        u.login();
        break;

    case '2':
        u.signUp();
        break;

    case '3':
        u.forget();
        break;

    case '4':
        cout << "Exiting..." << endl;
        return 0;

    default:
        cout << "Invalid Choice. Please Try Again." << endl;
        break;
    }
    return 0;
}

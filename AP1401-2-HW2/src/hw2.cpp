#include "../include/hw2.h"

// User definition of constructor and deconstructor

User::User(std::string name, std::string pass, std::string mail)
{
    username = name;
    email = mail;
    password = pass;

    // std::cout << "Make User" << std::endl;
}

User::~User()
{
    // std::cout << "Remove User" << std::endl;
}

// Login function development

Login::Login()
{
}

Login::~Login()
{
    users.clear();
}

void Login::readFile(std::string path) // reads the .txt file, then register the user inside readFile using theregisterUser function
{
    std::ifstream myfile(path); // reading file via ifstream
    std::string Line; // string variable to save each line read from file
    std::string Element; // string variable to save each line element read from file
    std::string username, password, email, Loggedin;
    bool first_line_flag = true; // boolian to ignore first line
    unsigned long long int pos, index;

    while (std::getline(myfile, Line)) {

        if (first_line_flag) {
            first_line_flag = false;
            continue;
        } else {
            // Split line with space and make row

            index = 0;
            while ((pos = Line.find(" ")) != std::string::npos) {

                // save element string and rest of line
                Element = Line.substr(0, pos);
                Line = Line.substr(pos + 1, Line.size() + 1);
                if (Element.size() > 1) {
                    if (index == 0) {
                        username = Element;
                    } else if (index == 1) {
                        password = Element;
                    } else if (index == 2) {
                        email = Element;
                    } else {
                        Loggedin = Element;
                    }
                    index++;
                }
            }

            if (Line.size() > 0) {
                Loggedin = Element;
            }

            index = users.size();
            registerUser(username, password, email);

            if (Loggedin.compare("yes") == 0) {
                if (users.size() > index)
                    LoginedUsers.push_back(users.back());
                else
                    loginUser(username, password);
            }
        }
    }
}

bool Login::checkUsername(std::string& new_username) // checks if the user is already taken, if so, it returns true and the username shouldn't be created
// and prints "username already taken"
{
    bool flag { false };
    unsigned long long int i;
    for (i = 0; i < users.size() && !flag; i++)
        if (new_username.compare(users[i]->username) == 0)
            flag = true;

    if (flag)
        ;
    // std::cout << "username already taken" << std::endl;

    return flag;
}

bool Login::checkEmail(std::string& new_email) // only new emails may be pushedback to "emails" vector
{
    bool flag { false };
    unsigned long long int i;
    for (i = 0; i < users.size() && !flag; i++)
        if (new_email.compare(users[i]->email) == 0)
            flag = true;

    if (flag)
        ;
    // std::cout << "email already taken" << std::endl;

    return flag;
}

void Login::changeUsername(std::string username, std::string newUsername)
{
    if (getUser(newUsername) == nullptr) {
        getUser(username)->username = newUsername;
        // std::cout << "Usernamed changed successfully!" << std::endl;
    } else {
        // std::cout << "INVALID new Username: This new username is already exists!" << std::endl;
    }
}

void Login::changePassword(std::string username, std::string newPassword)
{
    User* myUser = getUser(username);
    if (myUser != nullptr) {
        myUser->password = newPassword;
    }
}

void Login::changeMail(std::string username, std::string newMail)
{
    User* myUser = getUser(username);
    if (myUser != nullptr) {
        myUser->email = newMail;
    }
}

void Login::registerUser(std::string username, std::string password, std::string email) // function to create a user
{
    if (!checkUsername(username) && !checkEmail(email)) {
        User* newUser { new User(username, password, email) };
        users.push_back(newUser);
        // std::cout << "New User Added Succesfully!" << std::endl;
    }
}

void Login::loginUser(std::string username, std::string password)
{
    for (unsigned long long int i = 0; i < users.size(); i++) {
        if (username.compare(users[i]->username) == 0) {
            if (password.compare(users[i]->password) == 0) {
                LoginedUsers.push_back(users[i]);
                // std::cout << "User Logged in Successfully!" << std::endl;
                return;
            } else {
                // std::cout << "Incorrect Password for User:" << username << std::endl;
                return;
            }
        }
    }

    // std::cout << "No user found for username:" << username << std::endl;
}

void Login::removeUser(std::string username)
{
    for (unsigned long long int i = 0; i < users.size(); i++)
        if (username.compare(users[i]->username) == 0) {
            for (unsigned long long int j = 0; j < LoginedUsers.size(); j++)
                if (LoginedUsers[j]->username.compare(username) == 0) {
                    LoginedUsers.erase(LoginedUsers.begin() + j);
                    break;
                }
            delete users[i];
            users.erase(users.begin() + i);
            return;
        }
}

User* Login::getUser(std::string username) // returns the usernames using the same email, returns false if that email doesnt exist
{
    for (unsigned long long int i = 0; i < users.size(); i++)
        if (username.compare(users[i]->username) == 0)
            return users[i];

    return nullptr;
}

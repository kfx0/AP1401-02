#include "../include/hw2.h"
#include "gtest/gtest.h"

#include <iostream>

int main(int argc, char* argv[])
{

    if (false) // make false to run unit tests
    {
        // std::cout << "Hello Farid" << std::endl;

        // Login l;
        // l.registerUser("Farid", "Farid123", "Farid1@g");
        // l.registerUser("Farid", "Farid456", "Farid2@g");
        // l.registerUser("Farbod", "Farbod123", "Farbod1@g");
        // l.registerUser("Farbod2", "Farbod123", "Farbod1@g");
        // l.registerUser("Shiva", "Shiva123", "Shiva1@g");

        // std::cout << "username\t|\tpassword\t|\temail\n";
        // std::cout << "----------------+-----------------------+---------------\n";

        // for (unsigned long long int i = 0; i < l.users.size(); i++)
        //     std::cout << l.users[i]->username << "\t\t|\t" << l.users[i]->password << "\t|\t" << l.users[i]->email << std::endl;

        // std::cout << l.getUser("test") << std::endl;

        // l.removeUser("Farbod");

        // std::cout << "username\t|\tpassword\t|\temail\n";
        // std::cout << "----------------+-----------------------+---------------\n";

        // for (unsigned long long int i = 0; i < l.users.size(); i++)
        //     std::cout << l.users[i]->username << "\t\t|\t" << l.users[i]->password << "\t|\t" << l.users[i]->email << std::endl;

        // std::cout << l.getUser("Farbod") << std::endl;
        // debug section
    } else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << RUN_ALL_TESTS() << std::endl;
    }
}
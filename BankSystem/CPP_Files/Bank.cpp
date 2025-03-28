#include "resources.h"
#include "management.h"


int main() {
    std::unique_ptr<Bank_Account> bankaccount;
    char letter;
    std::cout << "Welcome to Bank System !" << std::endl;
    std::cout << "Create an account: yes (y) or no (n)? " << std::endl;
    std::cin >> letter;

    switch (letter) {
    case 'y':
        short pass;
        std::cout << "You chose to create an account! Choose a password 4 numbers:" << std::endl;
        std::cin >> pass;
        bankaccount = std::make_unique<Bank_Account>(0, pass);
        break;
    case 'n':
        std::cout << "You chose not to create an account!" << std::endl;
        break;
    default:
        std::cout << "Invalid choice! Please enter 'y' or 'n'." << std::endl;
        break;
    }

    std::cout << "Login to your account, enter your password : " << std::endl;


    return 0;
}
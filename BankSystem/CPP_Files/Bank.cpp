#include "resources.h"
#include "management.h"


int main() {
    std::unique_ptr<Bank_Account> bankaccount;
    char letter;
    std::cout << "Welcome to Bank System!" << std::endl;
    std::cout << "Create an account: yes (y) or no (n)? " << std::endl;
    std::cin >> letter;

    switch (letter) {
    case 'y':
        short pass;
        std::cout << "You chose to create an account! Choose a password of 4 numbers :" << std::endl;
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

    if (!bankaccount) {
        std::cout << "No account found. Exiting..." << std::endl;
        return 0;
    }

    short passlogin;
    do {
        std::cout << "Login to your account, enter your password: " << std::endl;
        std::cin >> passlogin;

        if (passlogin != bankaccount->GetBankPassword()) {
            std::cout << "Incorrect password! Try again." << std::endl;
        }
    } while (passlogin != bankaccount->GetBankPassword());

    std::cout << "\033[32mWelcome to your Bank Account!\033[0m" << std::endl;

    return 0;
}
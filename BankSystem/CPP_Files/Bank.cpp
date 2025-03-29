// Bank File / Main File
//
// Projet créer par Abso :)

#include "resources.h"
#include "management.h"

int main() {
    std::unique_ptr<Bank_Account> bankaccount;
    char letter;
    std::cout << "\033[33mWelcome to Bank system!\033[0m" << std::endl;
    std::cout << "Create an account: yes (y) or no (n)? " << std::endl;
    std::cin >> letter;

    switch (letter) {
    case 'y':
        short pass;
        std::cout << "You chose to create an account! Choose a password of 4 numbers :" << std::endl;
        std::cin >> pass;
        bankaccount = std::make_unique<Bank_Account>(0, pass);
        bankaccount->SetUserConnectedToBankAccount(false);
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

    bankaccount->SetUserConnectedToBankAccount(true);
    if (bankaccount->IsConnected()) {
        std::cout << "\033[32mWelcome to your Bank Account!\033[0m" << std::endl;
    }
    else {
        std::cout << "\033[31mYou are not connected to your account!\033[0m" << std::endl;
    }

    choose_options:
    short choice_number;
    std::cout << "\033[33mChoose an options:\033[0m" << std::endl;
    std::cout << "1. Deposit money" << std::endl;
    std::cout << "2. Withdraw money" << std::endl;
    std::cout << "3. Get my bank password" << std::endl;
    double bank_money = bankaccount->GetBankMoney();
    std::cout << "Bank : " << bank_money << "$" << std::endl;
    std::cin >> choice_number;
    switch (choice_number) {
    case 1 :
        double deposit_money;
        std::cout << "You have chosen 1! Deposit money" << std::endl;
        std::cout << "How many $ do you want to deposit?" << std::endl;
        std::cin >> deposit_money;
        std::cout << "Do you really want to deposit : " << deposit_money << "$" << " in the bank" << std::endl;
        std::cout << "\033[33mChoose an options:\033[0m" << std::endl;
        std::cout << "Yes = y" << std::endl;
        std::cout << "No = n" << std::endl;
        char letter;
        std::cin >> letter;
        switch (letter) {
        case 'y' :
            bankaccount->Deposit(deposit_money);
            break;
        case 'n' :
            system("cls");
            goto choose_options;
            break;
        }
        break;
    case 2 :
        std::cout << "Vous avez choisi 2 ! Retirer bank" << std::endl;
        break;
    case 3 :
        std::cout << "Vous avez choisi 3 ! Get bank password" << std::endl;
        break;
    default :
        std::cout << "Vous devez choisir une option valide !" << std::endl;
        break;
    }
    return 0;
}
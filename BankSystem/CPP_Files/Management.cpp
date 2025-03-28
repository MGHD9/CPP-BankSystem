// Management File
//
// Projet créer par Abso :)

#include "resources.h"
#include "management.h"

Bank_Account::Bank_Account(double MONEY, short PASS) : m_bank_money(MONEY), m_bank_password(PASS) {};

void Bank_Account::Deposit(double cash) {
	if (cash > max_deposit_money) {
		std::cout << "Error : you cannot deposit more than $200" << std::endl;
	}
	else {
		m_bank_money + cash;
	}
}

void Bank_Account::Withdraw(double cash) {
	if (cash > max_withdraw_money) std::cout << "Error : you cannot withdraw more than $200" << std::endl;
	else m_bank_money - cash;
}

//getter
double Bank_Account::GetBankMoney() const { return m_bank_money; }
short Bank_Account::GetBankPassword() const { return m_bank_password; }
bool Bank_Account::IsConnected() const { return m_isconnected; }

//setter
void Bank_Account::SetBankPassword(short password) { m_bank_password = password; }
void Bank_Account::SetUserConnectedToBankAccount(bool status) {
	if (status = true) {
		m_isconnected = true;
	}
	else {
		m_isconnected = false;
	}
}
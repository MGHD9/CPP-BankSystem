// Management file
//
// Projet créer par Abso :)

#ifndef _MANAGEMENT_
#define _MANAGEMENT_
#endif

const double max_withdraw_money = 500;
const double max_deposit_money = 200;

class Bank_Account {
public:
	Bank_Account(double MONEY, short PASS);

	void Deposit(double cash);
	void Withdraw(double cash);

	double GetBankMoney() const;
	short GetBankPassword() const;

	void SetBankPassword(short password);

private:
	double m_bank_money;
	short m_bank_password;
};
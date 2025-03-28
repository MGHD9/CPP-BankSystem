// Management File (Header)
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

	//Bank functions
	void Deposit(double cash);
	void Withdraw(double cash);

	//getters
	double GetBankMoney() const;
	short GetBankPassword() const;

	//setter
	void SetBankPassword(short password);

	//is connected to bank account?
	bool IsConnected() const;

private:
	bool m_isconnected;
	double m_bank_money;
	short m_bank_password;
};
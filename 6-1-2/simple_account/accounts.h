#ifndef ACCOUNTS_H
# define ACCOUNTS_H

class Account {
private:
	int mId, mBalance;
public:
	Account() : mId(0), mBalance(0) {}
	Account(int _id) : mId(_id), mBalance(0) {}
	int id();
	int balance();
	void change(int amount);
};

class AccountManager {
private:
	Account accounts[10];
	int count;
public:
	AccountManager() : count(0) {}
	void create();
	void deposit(int id, int amount);
	void withdraw(int id, int amount);
	void transfer(int id1, int id2, int amount);
	void status(int id);
};

#endif

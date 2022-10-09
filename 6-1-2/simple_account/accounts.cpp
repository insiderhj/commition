#include <iostream>
#include "accounts.h"

using namespace std;

int Account::id()
{
	return mId;
}

int Account::balance()
{
	return mBalance;
}

void Account::change(int amount)
{
	mBalance += amount;
}

void AccountManager::create()
{
	if (count >= 10) return;
	cout << "Account for user " << count << " registered" << endl;
	accounts[count] = Account(count);
	status(count);
	count++;
}

void AccountManager::deposit(int id, int amount)
{
	if (count <= id) {
		cout << "Account does not exist" << endl;
		return;
	}
	if (accounts[id].balance() + amount <= 1000000) {
		accounts[id].change(amount);
		cout << "Success: ";
	} else cout << "Failure: ";
	cout << "Deposit to user " << id << ' ' << amount << endl;
	status(id);
}

void AccountManager::withdraw(int id, int amount)
{
	if (count <= id) {
		cout << "Account does not exist" << endl;
		return;
	}
	if (accounts[id].balance() >= amount) {
		accounts[id].change(-amount);
		cout << "Success: ";
	} else cout << "Failure: ";
	cout << "Withdraw from user " << id << ' ' << amount << endl;
	status(id);
}

void AccountManager::transfer(int id1, int id2, int amount)
{
	if (count < id1 - 1 || count < id2 - 1) {
		cout << "Account does not exist" << endl;
		return;
	}
	if (accounts[id1].balance() >= amount && accounts[id2].balance() + amount <= 1000000) {
		accounts[id1].change(-amount);
		accounts[id2].change(amount);
		cout << "Success: ";
	} else cout << "Failure: ";
	cout << "Transfer from user " << id1 << " to user " << id2 << ' ' << amount << endl;
	if (id1 < id2) {
		status(id1);
		status(id2);
	} else {
		status(id2);
		status(id1);
	}
}

void AccountManager::status(int id)
{
	cout << "Balance of user " << id << ": " << accounts[id].balance() << endl;
}

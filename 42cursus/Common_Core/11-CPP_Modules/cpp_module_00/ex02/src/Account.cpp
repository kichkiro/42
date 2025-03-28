/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:34:31 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/18 22:18:10 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Libraries ------------------------------------------------------------------>

#include "Account.hpp"

#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
using std::time_t;
using std::time;
using std::tm;
using std::localtime;
using std::strftime;

// Static --------------------------------------------------------------------->

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor ---------------------------------------------------------------->

Account::Account(void) {
    this->_nbAccounts += 1;
    this->_accountIndex = this->_nbAccounts - 1;
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_displayTimestamp();
    cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << \
        ";created" << endl;
}

Account::Account(int initial_deposit) {
    this->_nbAccounts += 1;
    this->_totalAmount += initial_deposit;
    this->_accountIndex = this->_nbAccounts - 1;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_displayTimestamp();
    cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << \
        ";created" << endl;
}

// Destructor ----------------------------------------------------------------->

Account::~Account(void) {
    this->_displayTimestamp();
    cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << \
        ";closed" << endl;
}

// Methods -------------------------------------------------------------------->

int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << \
        ";deposits:" << _totalNbDeposits << ";withdrawals:" << \
        _totalNbWithdrawals << endl;
}

void Account::makeDeposit(int deposit) {
    int	p_amount;

    p_amount = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    this->_totalAmount += deposit;
    this->_totalNbDeposits += 1;
    _displayTimestamp();
    cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << \
        ";deposit:" << deposit << ";amount:" << this->_amount << \
        ";nb_deposits:" << this->_nbDeposits << endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    int	p_amount;

    p_amount = this->_amount;
    if (this->_amount - withdrawal >= 0) {
        this->_amount -= withdrawal;
        this->_nbWithdrawals += 1;
        this->_totalAmount -= withdrawal;
        this->_totalNbWithdrawals += 1;
        this->_displayTimestamp();
        cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << \
            ";withdrawal:" << withdrawal << ";amount:" << this->_amount << \
            ";nb_withdrawals:" << this->_nbWithdrawals << endl;
        return true;
    }
    else {
        this->_displayTimestamp();
        cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << \
            ";withdrawal:refused" << endl;
        return false;
    }
}

int Account::checkAmount(void) const {
    return this->_amount;
}

void Account::displayStatus(void) const {
    this->_displayTimestamp();
    cout << "index:" << this->_accountIndex << ";amount:" << this->_amount \
        << ";deposits:" << this->_nbDeposits << ";withdrawals:" << \
        this->_nbWithdrawals << endl;
}

void Account::_displayTimestamp(void) {
    char buf[20];

    time_t timestamp = time(NULL);
    tm *timeinfo = localtime(&timestamp);
    strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", timeinfo);
    cout << '[' << buf << ']' << ' ';
}

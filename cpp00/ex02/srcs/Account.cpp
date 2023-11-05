/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:00:31 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/05 16:55:33 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
  return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
  return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
  return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
  return Account::_totalNbWithdrawals;
}

void    Account::_displayTimestamp(void)
{
 	time_t	t_stamp;
	char	buff[16];

	time(&t_stamp);
	strftime(buff, sizeof(buff), "%Y%m%d_%H%M%S", localtime(&t_stamp));
	std::cout << "[" << buff << "]";
}

Account::Account(int initial_deposit)
{
  	_accountIndex = Account::_nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
	Account::_totalAmount += _amount;
	Account::_nbAccounts++;
}

void Account::displayAccountsInfos(void)
{
  Account::_displayTimestamp();
  std::cout << " accounts:" << Account::_nbAccounts
    << ";total:" << Account::_totalAmount
    << ";deposits:" << Account::_totalNbDeposits
    << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << " index:" << _accountIndex << ";"
         << "amount:" << _amount << ";"
         << "deposits:" << _nbDeposits << ";"
         << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int	p_amount;

	p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposits:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
  	int	p_amount;

	p_amount = _amount;
	_amount = _amount - withdrawal;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	if (checkAmount() != 0)
	{
		_nbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		return (true);
	}
	else
	{
		std::cout << "withdrawal:refused" << ";" << std::endl;
		_amount = p_amount;
		return (false);
	}
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << ";" << std::endl;
}

int Account::checkAmount(void) const {
	if (_amount < 0)
        return 0;
    return 1;
}

Account::Account(void) {
  
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:34:29 by pedperei          #+#    #+#             */
/*   Updated: 2023/08/29 14:48:00 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <stdlib.h> 
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
    time_t rawtime;
    tm* currentime;
    char formatdate[30];

    time(&rawtime);
    currentime = localtime(&rawtime);
    strftime(formatdate, sizeof(formatdate), "[%Y%m%d_%H%M%S] ", currentime);
    std::cout << formatdate;
}


Account::Account(int initial_deposit)
{
    this->_amount = initial_deposit;
    _totalAmount += this->_amount;
    this->_accountIndex = _nbAccounts;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
    _nbAccounts++;
}
Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
    _totalAmount -= this->_amount;
    _nbAccounts--;
}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;   
}

void	Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    this->_nbDeposits++;
    this->_amount += deposit;
	_totalNbDeposits++;
    _totalAmount += deposit;
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << 
        ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

int		Account::checkAmount( void ) const
{
    if (this->_amount < 0)
    {
        return (0);
    }
    return (1);
}

bool	Account::makeWithdrawal(int withdrawal)
{
    this->_amount -= withdrawal;
    if (!checkAmount())
    {
        this->_amount += withdrawal;
        _displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
        return (0);
    }
    this->_nbWithdrawals++;
	_totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal << 
        ";deposit:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (1);
}


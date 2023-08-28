#include <iostream>
#include <cstdio>
#include <iomanip>
#include <stdlib.h> 
#include "Account.hpp"

Account::Account(int initial_deposit)
{
    this->_amount = initial_deposit;
    _totalAmount += this->_amount;
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
    this->_accountIndex++;
    _nbAccounts++;
}
Account::~Account()
{
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_totalAmount << ";closed" << std::endl;
    _totalAmount -= this->_amount;
    _nbAccounts--;
}

void	Account::displayAccountsInfos(void)
{
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus(void) const
{
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;   
}

void	Account::makeDeposit(int deposit)
{
    this->_nbDeposits++;
    this->_amount += deposit;
	_totalNbDeposits++;
    _totalAmount += deposit;
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << 
        ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}
/* [19920104_091532] index:0;p_amount:47;withdrawal:refused
[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
 */
bool	Account::makeWithdrawal(int withdrawal)
{
    this->_nbWithdrawals++;
    this->_amount -= withdrawal;
	_totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal << 
        ";deposit:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (1);
}


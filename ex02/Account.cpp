/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 20:00:54 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/11 20:05:01 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

int	Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << ";";
	std::cout << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	size_t p_amount = this->_amount;
	this->_nbDeposits++;
	this->_amount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << ";";
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	size_t p_amount = this->_amount;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	if (this->_amount < withdrawal)
	{
		std::cout << "withdrawal:refused;";
		std::cout << std::endl;
		return (false);
	}
	else
	{
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << ";";
		std::cout << std::endl;
		return (true);
	}
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << ";";
	std::cout << std::endl;
}

Account::Account( int initial_deposit )
{
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created";
	std::cout << std::endl;

	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed";
	std::cout << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(NULL);
	std::tm	*time = std::localtime(&now);
	
	time->tm_mon++;
	time->tm_year += 1900;
	std::cout << "[" << time->tm_year  << time->tm_mon << time->tm_mday;
	std::cout << "_" << time->tm_hour << time->tm_min << time->tm_sec << "] ";
}


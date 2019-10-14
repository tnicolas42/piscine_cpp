#include "Account.class.hpp"
#include <iostream>

Account::Account() :
  _accountIndex(_nbAccounts),
  _amount(0),
  _nbDeposits(0),
  _nbWithdrawals(0)
{
    _nbAccounts++;
}

Account::Account(int initial_deposit) :
  _accountIndex(_nbAccounts),
  _amount(initial_deposit),
  _nbDeposits(0),
  _nbWithdrawals(0)
{
    _nbAccounts++;
}

void    Account::makeDeposit( int deposit ) {
    _amount += deposit;
    Account::_totalAmount += deposit;
    _nbDeposits++;
    Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    _amount += withdrawal;
    Account::_totalAmount += withdrawal;
    _nbWithdrawals++;
    Account::_totalNbWithdrawals++;
}
int		Account::checkAmount( void ) const { return _amount; }
void	Account::displayStatus( void ) const {
    std::cout << "Account id: " << _accountIndex << std::endl;
    std::cout << "Amount: " << _amount << std::endl;
    std::cout << "Number of deposit: " << _nbDeposits << std::endl;
    std::cout << "Number with drawals: " << _nbWithdrawals << std::endl;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int     Account::getNbAccounts( void ) { return Account::_nbAccounts; }
int     Account::getTotalAmount( void ) { return Account::_totalAmount; }
int     Account::getNbDeposits( void ) { return Account::_totalNbDeposits; }
int     Account::getNbWithdrawals( void ) { return Account::_totalNbWithdrawals; }
void	Account::displayAccountsInfos( void ) {
    std::cout << "Number of accounts: " << _nbAccounts << std::endl;
    std::cout << "Total amount: " << _totalAmount << std::endl;
    std::cout << "Total number of deposit: " << _totalNbDeposits << std::endl;
    std::cout << "Total number of deposit with drawals: " << _totalNbWithdrawals << std::endl;
}

Account::~Account() {}
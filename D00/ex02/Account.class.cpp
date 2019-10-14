#include "Account.class.hpp"
#include <iostream>
#include <ctime>

Account::Account() :
  _accountIndex(_nbAccounts),
  _amount(0),
  _nbDeposits(0),
  _nbWithdrawals(0)
{
    _nbAccounts++;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex <<
        ";amount:" << _amount << ";created" << std::endl;
}

Account::Account(int initial_deposit) :
  _accountIndex(_nbAccounts),
  _amount(initial_deposit),
  _nbDeposits(0),
  _nbWithdrawals(0)
{
    _totalAmount += _amount;
    _nbAccounts++;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex <<
        ";amount:" << _amount << ";created" << std::endl;
}

void    Account::makeDeposit( int deposit ) {
    _amount += deposit;
    Account::_totalAmount += deposit;
    _nbDeposits++;
    Account::_totalNbDeposits++;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex <<
        ";p_amount:" << _amount - deposit <<
        ";deposit:" << deposit <<
        ";amount:" << _amount <<
        ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    if (_amount - withdrawal < 0) {
        Account::_displayTimestamp();
        std::cout << "index:" << _accountIndex <<
            ";p_amount:" << _amount <<
            ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    _nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex <<
        ";p_amount:" << _amount + withdrawal <<
        ";withdrawal:" << withdrawal <<
        ";amount:" << _amount <<
        ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}
int		Account::checkAmount( void ) const { return _amount; }
void	Account::displayStatus( void ) const {
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex <<
        ";amount:" << _amount <<
        ";deposits:" << _nbDeposits <<
        ";withdrawals:" << _nbWithdrawals << std::endl;
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
    Account::_displayTimestamp();
    std::cout << "accounts:" << _nbAccounts <<
        ";total:" << _totalAmount <<
        ";deposits:" << _totalNbDeposits <<
        ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
void	Account::_displayTimestamp( void ) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::cout << "[" << 1900 + ltm->tm_year <<
        ((ltm->tm_mon < 10) ? "0" : "") << ltm->tm_mon <<
        ltm->tm_mday << "_" <<
        ((ltm->tm_hour < 10) ? "0" : "") << ltm->tm_hour <<
        ((ltm->tm_min < 10) ? "0" : "") << ltm->tm_min <<
        ((ltm->tm_sec < 10) ? "0" : "") << ltm->tm_sec << "] ";
}

Account::~Account() {
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex <<
        ";amount:" << _amount << ";closed" << std::endl;
}
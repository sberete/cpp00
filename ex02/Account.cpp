#include "Account.hpp"
#include "iostream"
#include "ctime"

Account::Account(int initial_deposit)
{
    _nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:"<< _amount <<";created" <<  std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:"<< _amount <<";closed" <<  std::endl;
}

int	Account::getNbAccounts( void )
{
    return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
    return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() <<";deposits:"<< getNbDeposits() <<";withdrawals:"<< getNbWithdrawals() <<std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _nbDeposits++;
    _totalNbDeposits+= _nbDeposits;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:"<< _amount <<";deposit:" << deposit << ";amount:"<< _amount + deposit << ";nb_deposits:"<< _nbDeposits <<std::endl;
    _amount += deposit;
    _totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    if (withdrawal > _amount)
    {
        std::cout << "index:" << _accountIndex << ";p_amount:"<< _amount <<";withdrawal:refused" << std::endl;
        return false;
    }
    else
    {
        _nbWithdrawals++;
        _totalNbWithdrawals += _nbWithdrawals;
        std::cout << "index:" << _accountIndex << ";p_amount:"<< _amount <<";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        return true;
    }
}

int		Account::checkAmount( void ) const
{
    return _amount;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:"<< _amount <<";deposits:" << _nbDeposits << ";withdrawals:"<< _nbWithdrawals <<std::endl;
}

void	Account::_displayTimestamp( void )
{
    time_t timestamp;
    time(&timestamp);
    std::string time = ctime(&timestamp);
    std::size_t len = time.size();
    time[len - 1] = '\0';
    std::cout << "[" << time << "] ";
}


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

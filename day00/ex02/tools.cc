  #include "Account.hpp"
  
  
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

  static int GetNbAccounts(void) {
        return _nbAccounts;
    }

    static int GetTotalAmount(void) {
        return _totalAmount;
    }

    static int GetNbDeposits(void) {
        return (_totalNbDeposits);
    }

    static int GetNbWithdrawals(void) {
        return  _totalNbWithdrawals;
    }

    static void displayAccountsInfos(void) {
        _displayTimestamp();
        std::cout << "accounts:" << GetNbAccounts() << ";"
                  << "total:" << GetTotalAmount() << ";"
                  << "deposits:" << GetNbDeposits() << ";"
                  << "withdrawals:" << GetNbWithdrawals() << std::endl;
    }

    Account(initial_deposit) {
        _accountIndex = _nbAccounts;
        _amount = initial_deposit;
        _nbDeposits = 0;
        _nbWithdrawals = 0;
        _nbAccounts++;
        _totalAmount += initial_deposit;

        _displayTimestamp();
        std::cout << "Index:" << _accountIndex << ";"
                  << "amount:" << initial_deposit << ";"
                  << "created" << std::endl;
    }

    ~Account(void) {
        _displayTimestamp();
        std::cout << "Index:" << _accountIndex << ";"
                  << "amount:" << _amount << ";"
                  << "closed" << std::endl;

        _nbAccounts--;
        _totalAmount -= _amount;
    }

    void makeDeposit(int deposit) {
        _displayTimestamp();
        _amount += deposit;
        _nbDeposits++;
        _totalAmount += deposit;
        _totalNbDeposits++;

        std::cout << "Index:" << _accountIndex << ";"
                  << "p_amount:" << _amount - deposit << ";"
                  << "deposit:" << deposit << ";"
                  << "amount:" << _amount << ";"
                  << "nb_deposits:" << _nbDeposits << std::endl;
    }

    bool makeWithdrawal(int withdrawal) {
        _displayTimestamp();
        if (withdrawal <= _amount) {
            _amount -= withdrawal;
            _nbWithdrawals++;
            _totalAmount -= withdrawal;
            _totalNbWithdrawals++;

            std::cout << "Index:" << _accountIndex << ";"
                      << "p_amount:" << _amount + withdrawal << ";"
                      << "withdrawal:" << withdrawal << ";"
                      << "amount:" << _amount << ";"
                      << "nb_withdrawals:" << _nbWithdrawals << std::endl;

            return true;
        } else {
            std::cout << "Index:" << _accountIndex << ";"
                      << "p_amount:" << _amount << ";"
                      << "withdrawal:refused" << std::endl;

            return false;
        }
    }

    int checkAmount(void) const {
        return _amount;
    }

    std::string displayStatus(void) const {
        _displayTimestamp();
        std::cout << "Index:" << _accountIndex << ";"
                  << "amount:" << _amount << ";"
                  << "deposits:" << _nbDeposits << ";"
                  << "withdrawals:" << _nbWithdrawals << std::endl;
    }


Account::Account(void) {
    // ...
}

void Account::_displayTimestamp(void) {
    // ...
}
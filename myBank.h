#ifndef _MYMATH_
#define _MYMATH_
#define total_of_bank_account 50
#define row 2
extern double arr_accounts[row][total_of_bank_account];

void open_new_account_and_make_first_deposit(double amount_to_deposit);
double look_for_balance(int accountNumber);
int look_if_account_exist(int accountNumber);
void deposit_in_account(int accountNumber,double amount_to_deposit);
void withdrawal_from_account(int accountNumber,double amount_to_withdrawal);
void close_account(int accountNumber);
void add_interest(double interest);
void return_account_number_and_balance();
void close_add_accounts(); 
double fix_amount_for_only_two_after_dot(double amount_to_change);

#endif
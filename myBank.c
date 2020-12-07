#include <stdio.h>
#include "myBank.h"
double arr_accounts [row][total_of_bank_account] = {0};

double fix_amount_for_only_two_after_dot(double amount_to_change){
    amount_to_change = amount_to_change*100;
    int temp = amount_to_change;
    double temp2 = temp;
    amount_to_change = temp2/100;
    return amount_to_change;
}
void open_new_account_and_make_first_deposit(double amount_to_deposit)
{
    if (amount_to_deposit < 0)
    {
        printf("You cant deposit a negetive number\n");
        return;
    }
    int i, free_account = -1;
    for (i = 0; i < total_of_bank_account; i++)
    {
        if (arr_accounts[0][i] == 0)
        {
            free_account = i;
            break;
        }
    }
    if (free_account == -1)
    {
        printf("Sorry, all the bank accounts is occupied\n");
    }
    else
    {
        arr_accounts[0][free_account] = 1;
        arr_accounts[1][free_account] = amount_to_deposit;
        printf("Your account number is: %d\n", (free_account + 901));
    }
}
int look_if_account_exist(int account_number)
{
    int arr_account_number = account_number - 901;
    if (arr_accounts[0][arr_account_number] == 1)
        return 1;
    else
        return 0;
}
double look_for_balance(int account_number)
{
    int arr_account_number = account_number - 901;
    return arr_accounts[1][arr_account_number];
}
void deposit_in_account(int account_number, double amount_to_deposit)
{
    int arr_account_number = account_number - 901;
    arr_accounts[1][arr_account_number] += amount_to_deposit;
    printf("Your new balance is:%0.2lf\n", arr_accounts[1][arr_account_number]);
}
void withdrawal_from_account(int account_number, double amount_to_withdrawal)
{
    int arr_account_number = account_number - 901;
    double new_amount = arr_accounts[1][arr_account_number] - amount_to_withdrawal;
    if (new_amount < 0)
        printf("You dont have enough money in your account to withdrawal this amount\n");
    else
    {
        arr_accounts[1][arr_account_number] = new_amount;
        printf("Your new balance is: %0.2lf\n", new_amount);
    }
}
void close_account(int account_number)
{
    int arr_account_number = account_number - 901;
    arr_accounts[0][arr_account_number] = 0;
    arr_accounts[1][arr_account_number] = 0;
    printf("account number: %d has been close!\n", account_number);
}
void add_interest(double interest)
{
    double how_much_to_add;
    for (int i = 0; i < total_of_bank_account; i++)
    {
        if (arr_accounts[0][i] == 1)
        {
            how_much_to_add = ((arr_accounts[1][i] * interest) / 100);
            arr_accounts[1][i] += how_much_to_add;
        }
    }
    printf("Finish to add interest\n");
}
void return_account_number_and_balance()
{
    int flag_if_there_is_any_open_account = 0;
    for (int i = 0; i < total_of_bank_account; i++)
    {
        if (arr_accounts[0][i] == 1)
        {
            printf("in account number: %d the balance is: %0.2lf\n", (i + 901), arr_accounts[1][i]);
            flag_if_there_is_any_open_account = 1;
        }
    }
    if (flag_if_there_is_any_open_account == 0)
    {
        printf("There is no open accounts in the bank\n");
    }
}
void close_add_accounts()
{

    for (int i = 0; i < total_of_bank_account; i++)
    {
        if (arr_accounts[0][i] == 1)
        {
            arr_accounts[0][i] = 0;
            arr_accounts[1][i] = 0;
        }
    }
    printf("All the bank account has beed closed!\n");
}

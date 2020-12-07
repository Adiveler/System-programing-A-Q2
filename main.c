#include <stdio.h>
#include "myBank.h"
int main()
{
    char command = ' ';
    double amount_to_deposit = 0, balance = 0, amount_to_withdrawal = 0 , interest = 0;
    int accountNumber = 0;
    do
    {
        printf("Please choose one of this actions:O,B,D,W,C,I,P,E\n");
        if(scanf(" %c", &command) != 1) 
        {
            printf("Failure you enter a wrong command , please enter a real char command");
        }
        switch (command)
        {
        case 'O':
            printf("Please enter the amount of money you like to deposit\n");
            if (scanf("%lf", &amount_to_deposit) != 1 || amount_to_deposit<0)
            {
                printf("Please enter numbers only! Please try again\n");
            }
            else
            {
                amount_to_deposit = fix_amount_for_only_two_after_dot(amount_to_deposit);
                open_new_account_and_make_first_deposit(amount_to_deposit);
            }
            break;
        case 'B':
            printf("Please enter your account number\n");
            if (scanf("%d", &accountNumber) != 1)
            {
                printf("Please enter numbers only!\n");
            }
            else
            {
                if (accountNumber < 901 || accountNumber > 950)
                    printf("You pot a wrong account number, try again\n");
                else if (look_if_account_exist(accountNumber) == 0)
                    printf("Error, the account number you ask about is close\n");
                else
                {
                    balance = look_for_balance(accountNumber);
                    printf("Your balance is:%0.2lf\n", balance);
                }
            }
            break;
        case 'D':
            printf("Please enter your account number\n");
            if (scanf("%d", &accountNumber) != 1)
            {
                printf("Please enter numbers only!\n");
            }
            else
            {
                if (accountNumber < 901 || accountNumber > 950)
                    printf("You pot a wrong account number, try again\n");
                else if (look_if_account_exist(accountNumber) == 0)
                    printf("Error, the account number you ask about is close\n");
                else
                {
                    printf("Please enter the amount of deposit\n");
                    scanf("%lf", &amount_to_deposit);
                    if (amount_to_deposit < 0)
                        printf("You cant deposit a negetive amount");
                    else
                    {
                        amount_to_deposit = fix_amount_for_only_two_after_dot(amount_to_deposit);
                        deposit_in_account(accountNumber, amount_to_deposit);
                    }
                }
            }
            break;
        case 'W':
            printf("Please enter your account number\n");
            if (scanf("%d", &accountNumber) != 1)
            {
                printf("Please enter numbers only!\n");
            }
            else
            {
                if (accountNumber < 901 || accountNumber > 950)
                    printf("You pot a wrong account number, try again\n");
                else if (look_if_account_exist(accountNumber) == 0)
                    printf("Error, the account number you ask about is close\n");
                else
                {
                    printf("Please enter the amount that you like to withdrawal\n");
                    if (scanf("%lf", &amount_to_withdrawal) != 1)
                    {
                        printf("Please enter numbers only!\n");
                    }
                    else
                    {
                        if (amount_to_withdrawal < 0)
                            printf("You cant withdrawal a negetive amount\n");
                        else
                        {
                            amount_to_withdrawal = fix_amount_for_only_two_after_dot(amount_to_withdrawal);
                            withdrawal_from_account(accountNumber, amount_to_withdrawal);
                        }
                    }
                }
            }
            break;
        case 'C':
            printf("Please enter the account number you like to close\n");
            if (scanf("%d", &accountNumber) != 1)
            {
                printf("Please enter numbers only!\n");
            }
            else
            {
                if (accountNumber < 901 || accountNumber > 950)
                    printf("You pot a wrong account number, please try again\n");
                else if (look_if_account_exist(accountNumber) == 0)
                    printf("This account number is already close\n");
                else
                {
                    close_account(accountNumber);
                }
            }
            break;
        case 'I':
            printf("Please enter the amount of interesy you like to add\n");
            if (scanf("%lf", &interest) != 1)
            {
                printf("Please enter numbers only!\n");
            }
            else
            {
                add_interest(interest);
            }
            break;
        case 'P':
            return_account_number_and_balance();
            break;
        case 'E':
            close_add_accounts();
            break;
        default:
            printf("You type a wrong command, please try one of those: O,B,D,W,C,I,P,E\n");
            break;
        }
    } while (command != 'E');
    return 0;
}
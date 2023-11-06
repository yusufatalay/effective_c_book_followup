#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {Savings, Checking, MoneyMarket, CD} AccountType;

void assignInterestRate(AccountType account){
  double interest_rate;
  switch (account) {
    case Savings:
      interest_rate = 3.0;
      break;
      case Checking:
      interest_rate = 1.0;
      break;
    case MoneyMarket:
      interest_rate = 4.5;
      break;
    case CD:
      interest_rate = 7.5;
      break;
    default: abort();
  }

  printf("Interest rate = %g.\n", interest_rate);
}


int main(void){
  assignInterestRate(CD);
}

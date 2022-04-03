#include "money.h"

// This function definition provided as an example
const Money operator +(const Money& amount1, const Money& amount2) {
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Add all the cents together
  int sum_all_cents = all_cents1 + all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = abs(sum_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (sum_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

// CLASS FUNCTION DEFINITIONS GO HERE

const Money operator -(const Money& amount1, const Money& amount2) {
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Subtract cents of object 2 from cents of object 1
  int sum_all_cents = all_cents1 - all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = abs(sum_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (sum_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

bool operator ==(const Money& amount1, const Money& amount2) {
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Compare the two amounts
  if (all_cents1 == all_cents2) {
    return true;
  }
  return false;
}

const Money operator -(const Money &amount) {
  // Negate the cents_ and dollars_
  int neg_cents = -amount.cents_;
  int neg_dollars = -amount.dollars_;
  return Money(neg_dollars, neg_cents);
}

ostream& operator <<(ostream &out, const Money &amount) {
  // "Default" scenario, where dollars_ and cents_ are both >= 0 AND cents_ > 9
  if (amount.dollars_ >= 0 && amount.cents_ >= 0 && amount.cents_ > 9) {
    out << '$';
    out << amount.dollars_;
    out << '.';
    out << amount.cents_;
    return out;
  }
  // Second scenario where the above is all true EXCEPT cents_ < 10
  if (amount.dollars_ >= 0 && amount.cents_ >= 0 && amount.cents_ < 10) {
    out << '$';
    out << amount.dollars_;
    out << '.';
    out << '0';
    out << amount.cents_;
    return out;
  }
  // Third scenario where dollars_ >= 0 && cents_ < -9
  if (amount.dollars_ >= 0 && amount.cents_ < -9) {
    out << '$';
    out << '-';
    out << amount.dollars_;
    out << '.';
    out << -amount.cents_;
    return out;
  }
  // Fourth scenario where dollars_ < 0 && cents_ < 0 && cents_ > -10
  if (amount.dollars_ < 0 && amount.cents_ < 0 && amount.cents_ > -10) {
    out << '$';
    out << amount.dollars_;
    out << '.';
    out << '0';
    out << -amount.cents_;
    return out;
  }
  out << "Error: No scenarios occured.";
  return out;
}

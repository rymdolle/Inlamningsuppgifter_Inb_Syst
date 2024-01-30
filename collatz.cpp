/// Collatz conjecture
///
/// Copyright (c) 2024 Olle Mattsson <rymdolle@gmail.com>
///
/// This program asks for a number range and applies the Collatz
/// algorithm using recursion. Prints a table over distribution of
/// iterations needed to reach 1.
///
/// While number is greater than 1
///   Multiply by 3 and add 1 if number is odd
///   Divide by 2 if number is even

#include <cstdint>
#include <iomanip>
#include <iostream>

// Collatz conjecture using recursion
//
// One disadvantage of using recursion is that if the compiler does
// not optimise calls, it builds on the stack which can lead to stack
// overflow.
int collatz1(uint64_t number)
{
  if (number > 1) {
    if (number % 2 != 0) // if odd
      return 1 + collatz1(number * 3 + 1);
    else
      return 1 + collatz1(number / 2);

    // The code below does the same but is arguably more readable
    // return 1 + collatz1(number % 2 ? number * 3 + 1 : number / 2);
  }
  return 0;
}

// Collatz conjecture using loop
//
// A loop is straigt forward to understand and does not build on the
// stack.
int collatz2(uint64_t number)
{
  int n;
  for (n = 0; number > 1; ++n)
    number = number % 2 ? number * 3 + 1 : number / 2;
  return n;
}

int collatz(uint64_t number)
{
  return collatz1(number);
}

int main(int argc, char *argv[])
{
  uint64_t start, count;
  std::cout << "Enter start value: ";
  std::cin >> start;
  std::cout << "Enter amount of numbers in range: ";
  std::cin >> count;
  std::cout << "\n"
            << "The table below is the collatz algorithm for "
            << "each number in the range "
            << '[' << start << ',' << start+count << ")\n\n";

  std::cout << std::left << std::setw(8) << "Steps"
            << "Number"
            << std::endl;

  for (uint64_t number = start; number < start+count; ++number) {
    int steps = collatz(number);
    std::cout << std::left << std::setw(8) << steps
              << number
              << std::endl;
  }
  return 0;
}

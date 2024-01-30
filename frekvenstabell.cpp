/// Frequency Distribution Table
///
/// Copyright (c) 2024 Olle Mattsson <rymdolle@gmail.com>
///
/// This program displays the frequency distribution tables for a
/// fixed set of dice rolls.

#include <iostream>
#include <iomanip>
#include <ctime>

void frequency_distribution_table(int count)
{
  // Collect distribution
  constexpr int faces = 6;
  int result[faces] = {};
  for (int i = 0; i < count; i++)
    ++result[std::rand() % faces];

  std::cout << "Frequency distribution for " << count << " rolls."
              << std::endl;

  std::cout << std::left
            << std::setw(6)  << "Face"
            << std::setw(15) << "Count"
            << "Distribution"
            << std::endl;

  for (int i = 0; i < 6; i++) {
    std::cout << std::left
              << std::setw(6) << i + 1
              << std::setw(15) << result[i]
              << std::fixed << std::setprecision(5)
              << result[i] / static_cast<double>(count)
              << std::endl;
  }

  std::cout << std::left
            << std::setw(6) << "All"
            << std::setw(15) << count
            << count / count
            << std::endl
            << std::endl;
}

int main() {
  std::srand(std::time(nullptr));

  // Print tables
  for (auto& count : {10, 50, 100, 1'000, 10'000, 5'000'000})
    frequency_distribution_table(count);

  return 0;
}

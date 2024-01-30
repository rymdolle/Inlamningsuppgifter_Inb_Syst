/// Palindrome
///
/// Copyright (c) 2024 Olle Mattsson <rymdolle@gmail.com>
///
/// From Wikipedia:
///     A palindrome is a word, number, phrase, or other sequence of
///     symbols that reads the same backwards as forwards.
///
/// This program tests an ASCII-string if it is a palindrome and lets
/// the user try until one is found. If the user doesn't come up with
/// one, they can exit and are presented with some examples of strings
/// that are palindromes.

#include <iostream>
#include <string>

bool is_separator(char c)
{
  switch (c) {
  case ' ':
  case '\t':
  case '.':
  case ',':
  case ':':
  case ';':
  case '!':
  case '?':
  case '-':
  case '&':
  case '/':
  case '"':
  case '\'':
    return true;
  default:
    return false;
  }
}

bool palindrome(const char *text, size_t length) {
  // Start from ends and move towards the middle. If the first and
  // last character compares equal, move one step inward from each
  // side and repeat. If they are not equal, the string is not a
  // palindrome.

  const char *first = text;
  const char *last  = text + (length - 1);

  while (first < last) {
    // Ignore separators from start
    if (is_separator(*first)) {
      ++first;
      continue;
    }

    // Ignore separators from end
    if (is_separator(*last)) {
      --last;
      continue;
    }

    // Compare letters as uppercase
    if (std::toupper(*first) != std::toupper(*last))
      return false;

    ++first;
    --last;
  }

  return true;
}

int main(int argc, char *argv[])
{
  std::string text;
  for (;;) { // infinite loop
    std::cout << "Enter an ASCII-string to test for palindrome,\n"
              << "or an empty line to exit and see some examples.\n";
    std::getline(std::cin, text);

    if (text.empty()) {
      std::cout << "Some examples of palindromes are:\n\n"
                << "\tRats live on no evil star\n"
                << "\tA Toyota's a Toyota\n"
                << "\tStep on no pets\n"
                << "\tGo hang a salami, I'm a lasagna hog\n"
                << "\tToo bad I hid a boot\n"
                << std::endl;
      // User wants to exit
      break;
    }

    if (palindrome(text.c_str(), text.length())) {
      std::cout << "\nThe string IS a palindrome.\n"
                << std::endl;
      // The string is palindrome, exit loop
      break;
    } else {
      std::cout << "\nThe string is NOT a palindrome.\n"
                << std::endl;
    }
  }

  return 0;
}

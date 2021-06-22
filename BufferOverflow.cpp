// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <string>

int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_order
  //  varaible, and its position in the declaration. It must always be directly before the variable used for input.

  const std::string account_number = "CharlieBrown42";
  char user_input[21]; // Leaving as-is for now besides adding 1 char slot for \0 char. Ensuring C-cross-compatability. Up to the team whether this is necessary.
  std::string buffer; // string from stdlib automatically handles memory allocation, hooray for c++
  std::cout << "Enter a value: ";

  std::getline(std::cin, buffer); // reads entire line into buffer up until newline char, \0 char, or EOF
  strncpy_s(user_input, buffer.c_str(), sizeof(user_input) - 1); // if buffer.length() < sizeof(user_input) then remaining chars will become nullchars

  if (buffer.length() > sizeof(user_input) - 1) { // Must subtract 1 because the string ends with terminating char \0
	  std::cout << "Buffer overflow would have occurred.";
	  std::cout << "You entered: " << buffer << " but was shortened to " << user_input << std::endl;
  }
  else {
	  std::cout << "Overflow would not have occurred.";
	  std::cout << "You entered: " << user_input << std::endl;
  }

  std::cout << "Account Number = " << account_number << std::endl; // account_number no longer affected

  // Please note: Output was moved & modified based on overflow for demonstration purposes but order still is unchanged.
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

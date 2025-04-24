// Task 02 - Odd or Even number

// Check a number given from the user, and tell if it's odd or even


#include <iostream>
#include <iomanip>

/*
 * We need to check if the input is an integer.
 * 
*/

int main()
{
   int number = 0;

   std::cout << "Please, enter a no decimal number (whole number): \n>>> ";
   std::cin >> number;
   std::cout << std::endl;

   // Handle wrong inputs:
   while (!std::cin.good())
   {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      std::cout << "Wrong input. Please give a no decimal number: \n>>> ";
      std::cin >> number;
   }
   //std::cout << std::endl;

   // Check whether the number is odd or even:
   if (number % 2 == 0)
   {
      std::cout << "The number is even.\n";
   }
   else
   {
      std::cout << "The number is odd.\n";
   }

   std::cout << "Bye bye" << std::endl;

   return 0;
}
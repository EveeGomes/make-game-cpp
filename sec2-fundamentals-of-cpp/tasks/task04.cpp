// Task 04 - Given a sequence of numbers, find the smallest one.

#include <iostream>
#include <vector>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()

/*
 * 1st: 
 *    generate a bunch of random numbers to work with.
 * 2nd:
 *    check each number and compare with a variable that holds the latest smaller number.
*/

int main()
{
   const int MAXNUMBERS = 0;
   //int smallest = std::numeric_limits<int>::max();
   int smallest = 0;
   std::vector<int> randomNumbers;

   // Seed the random number generator
   std::srand(std::time(nullptr));

   for (int i = 0; i < MAXNUMBERS; ++i)
   {
      // Generate a number between 1 and 100
      int randomNum = std::rand() % 100 + 1;

      // Add to randomNumbers vector
      randomNumbers.push_back(randomNum);

      std::cout << randomNumbers[i] << " ";
   }
   std::cout << std::endl;
   
   // Taking care of the possibility when the vector of numbers is empty, and not using numeric_limits to set smallest
   if (!randomNumbers.empty())
   {
      smallest = randomNumbers[0];
      for (int number : randomNumbers)
      {
         if (number < smallest)
         {
            smallest = number;
         }
      }

      std::cout << "The smallest number is: " << smallest;
   }
   else
   {
      std::cout << "There are no numbers to check";
   }
   std::cout << std::endl;

   return 0;
}
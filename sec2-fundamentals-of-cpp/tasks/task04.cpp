// Task 04 - Given a sequence of numbers, find the smallest one.

#include <iostream>
#include <vector>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()

/*
 * 1st: 
 *    generate a bunch of random numbers to work with.
*/

int main()
{
   const int MAXNUMBERS = 10;

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

   return 0;
}
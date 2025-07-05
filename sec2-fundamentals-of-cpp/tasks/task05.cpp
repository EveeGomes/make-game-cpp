// Task 05 - Reorder the numbers from the smallest to the biggest

#include <iostream>
#include <vector>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()


int main()
{
   const int MAXNUMBERS = 5;
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

   // Use the bubble sort algorithm - SLOW
   for (int i = 0; i < randomNumbers.size(); ++i)
   {
      // compare the current element with i index agaisnt every element that comes next
      for (int j = i + 1; j < randomNumbers.size(); ++j)
      {
         if (randomNumbers[i] > randomNumbers[j])
         {
            std::swap(randomNumbers[i], randomNumbers[j]);
         }
      }
   }

   for (int number : randomNumbers)
   {
      std::cout << number << " ";
   }
   std::cout << std::endl;

   return 0;
}
// Task 05 - Reorder the numbers from the smallest to the biggest

#include <iostream>
#include <vector>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()

const int MAXNUMBERS = 5;

// Quick sort
// Insertion sort


// Merge sort //
// Time complexity: O(n log n) - dividing array in halves: log n divisions; each merge step takes linear time (n opetations). 
// Space complexity: O(n)

// Merge two sorted subarrays into one sorted array
void merge(std::vector<int>& numbersArray, int left, int mid, int right)
{
   int size1 = mid - left + 1;   // 2 + 0 + 1 = 3
   int size2 = right - mid;      // 5 - 2 = 3

   // Create temporary arrays to hold the two halves
   std::vector<int> leftHalf(size1);
   std::vector<int> rightHalf(size2);

   // Copy data to temporary arrays
   // Left half: left ... mid
   for (int i = 0; i < size1; ++i)
   {
      leftHalf[i] = numbersArray[left + i];
   }
   // Right half: mid + 1 ... right
   for (int j = 0; j < size2; ++j)
   {
      rightHalf[j] = numbersArray[mid + 1 + j];
   }

   // Merge the temporary arrays back into numbersArray[left ... right]
   int i = 0; // initial index of first subarray
   int j = 0; // initial index of second subarray
   int k = left; // Initial index of merged subarray

   while (i < size1 && j < size2)
   {
      if (leftHalf[i] <= rightHalf[j])
      {
         numbersArray[k] = leftHalf[i];
         i++;
      }
      else
      {
         numbersArray[k] = rightHalf[j];
         j++;
      }
      k++;
   }

   // Copy the remaining elements of leftArray, if any
   while (i < size1)
   {
      numbersArray[k] = leftHalf[i];
      i++;
      k++;
   }

   // Copy the remaining elements of rightArray, if any
   while (j < size2)
   {
      numbersArray[k] = rightHalf[j];
      j++;
      k++;
   }
}

// Main function that implements Merge Sort
void mergeSort(std::vector<int>& numbersArray, int left, int right)
{
   if (left < right)
   {
      // find the middle point
      int mid = left + (right - left) / 2;

      // Sort first and second halves
      mergeSort(numbersArray, left, mid);
      mergeSort(numbersArray, mid + 1, right);

      // Merge the sorted halves
      merge(numbersArray, left, mid, right);
   }
}
// Merge sort //

// Buble sort //
// SLOW
void bubbleSort(std::vector<int>& numbersArray)
{
   for (int i = 0; i < numbersArray.size(); ++i)
   {
      // compare the current element with i index agaisnt every element that comes next
      for (int j = i + 1; j < numbersArray.size(); ++j)
      {
         if (numbersArray[i] > numbersArray[j])
         {
            std::swap(numbersArray[i], numbersArray[j]);
         }
      }
   }
}
// Buble sort //

template<typename T>
void printArray(const std::vector<T>& vectorToPrint)
{
   for (T element : vectorToPrint)
   {
      std::cout << element << " ";
   }
   std::cout << std::endl;
}

void generateRandomNumbers(std::vector<int>& numbersArray, int amountOfNumbers)
{
   // Seed the random number generator
   std::srand(std::time(nullptr));

   for (int i = 0; i < amountOfNumbers; ++i)
   {
      // Generate a number between 1 and 100
      int randomNum = std::rand() % 100 + 1;

      // Add to randomNumbers vector
      numbersArray.push_back(randomNum);
   }
}

int main()
{
   std::vector<int> randomNumbers;
   generateRandomNumbers(randomNumbers, MAXNUMBERS);
   printArray<int>(randomNumbers);
   //std::cout << std::endl;

   //bubbleSort(randomNumbers);
   mergeSort(randomNumbers, 0, randomNumbers.size() - 1);
   printArray<int>(randomNumbers);
   std::cout << std::endl;
   printArray<std::string>(std::vector<std::string>{"mavi", "alex"});

   return 0;
}
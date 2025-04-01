// Task 01 - convert miles to kilometers

// Take input from the user, ask a distance in miles.
// Convert that distance to kilometers and cout the value.


#include <iostream>
#include <iomanip>

/*
* 1 mile = 1.6 km
* ie: 1 mile = (1.6 * 1) km
* 
* 10 miles = (1.6 * 10) km
* 100 miles = (1.6 * 100) km
*/

int main()
{
   const float mileToKm = 1.6;
   float milesInput = -1.0;

   std::cout << "Please, type in the distance in miles: ";
   std::cin >> milesInput;
   std::cout << std::endl;

   std::cout << "Here's the distance " << milesInput 
             << " miles in kilometers: " 
             << std::fixed << std::setprecision(2) << (milesInput * mileToKm) << std::endl;

   std::cout << "Bye bye" << std::endl;

   return 0;
}
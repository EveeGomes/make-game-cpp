// Task 03 - Given a text, find the repeated word and how many times it has been repeated.


#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <map>

/*
 * The red carpet is a beautiful red piece of decoration.
 * 
 * Save the text in a string. -> nope, in a string stream!
 * Save the first word before the whitespace in a string, say word. -> almost there...
 * 
 * ==============================================
 * 
 * String stream behaves almost line a cin and cout. So when adding a string into a stringstream we have a stream of strings. While cout or cin
 *  we're adding/removing input into/from the console.
*/

int main()
{
   // Save the text in a string, using R"""()""". That's used to accept everything as raw input, ie everything is gonna be taken literally
   //  even scape things like new lines. We use 3 quotation marks to mark that as a multiline and then parenthesis to wrap around everything.

   std::string text = R"""(C and C++ are both powerful programming languages with distinct characteristics. 
C is a procedural language, emphasizing step-by-step execution, while C++ is an object-oriented language, focusing on data and objects.

C is often favored for low-level programming and embedded systems due to its efficiency and direct memory manipulation capabilities. 

C++ builds upon C, adding features like classes, objects, and templates, making it suitable for complex software development. 

While C is considered simpler and easier to learn initially, C++ offers greater power and flexibility for large-scale projects.)""";

   std::stringstream ss;
   // Create another string to accept each individual string from ss. That's because ss has all the text string and we can keep on asking for input just
   //  like we do with cin (std::cin >> )
   std::string nextStr = "";
   std::map<const std::string, int> wordCount{};

   // "cout" the entire text into ss. It's a stream of strings :)
   ss << text;

   // So, in order to get the entire text, we can use a while loop. ss >> nextStr stops when that operation returns EOF signaling there's nothing in the
   //  buffer anymore, ie it's empty. That way we'll safely get out of the loop.
   while (ss >> nextStr)
   {
      // We need to get rid of any punctuation like commas and periods, and upper cases as well.
      //  We can loop through each character in nextStr and only accept what's a letter using std::isalpha()

      std::string word = "";
      int lastCharIndex = 0;
      for (char c : nextStr)
      {
         ++lastCharIndex;
         if (std::isalpha(c) || c == '+')
         {
            // but since we need to get rid of cases, we do as:
            word.push_back(std::tolower(c));
         }
         else
         {
            // This else is used for texts that ends up with a format that when transfered here the words are combined together after a punctuation,
            //  something like "word.word". So to fix that, anything that's not alphabetical (and in my case not +), ie a punctuation, means that what
            //  comes next is another word. That way we need to break.
            break;
         }
      }
      // So from the break, we have a problem: how do we get the next word?
      //  We use an index that represents the index of the current char c being processed in for each loop. Then we check: if that index isn't
      //  the last one in nextStr, means we still have things to process in nextStr, ie, we have the next word after a punctuation!
      //  We take care of that by adding that to the end of the stringstream ss. But we need to add a space before that word so the last period in
      //  the end of ss don't create yet another "word.word".
      if (lastCharIndex != nextStr.size() - 1)
      {
         std::string leftOver = nextStr.substr(lastCharIndex);
         ss << ' ' << leftOver;
      }
      // To find out which word is being repeated and how many times it's being repeated. 
      //  We can use a map, where we have the word and a count. That way every time that word appear in the text, we increment the count.

      // Add the word to the map. 
      //  If the word already exists, it'll increment the int which is the value
      ++wordCount[word];

      //// similar solution presented in the class 20 in section 2:
      //if (wordCount.find(word) == wordCount.end()) // if the word isn't found in the map, add it with the count = 1
      //{
      //   wordCount.insert({ word, 1 });
      //}
      //else // otherwise, if the word is in the map already, increment the count
      //{
      //   wordCount[word] += 1;
      //}

   }

   // Loop through the map and the words (keys) with a count (value) greater than 1, print it out
   // Range-based for loop
   for (const std::pair<std::string, int>& pair : wordCount) // const auto& pair
   {
      if (pair.second > 1)
      {
         std::cout << "\"" << pair.first << "\" repeated: " << pair.second << " times." << std::endl;
      }
   }

   //std::cout << std::endl;
   //std::cout << "Using iterator" << std::endl;
   //// Using iterator
   //for (std::map<std::string, int>::iterator it = wordCount.begin(); it != wordCount.end(); ++it) // auto it
   //{
   //   if (it->second > 1)
   //   {
   //      std::cout << "\"" << it->first << "\" repeated: " << it->second << " times." << std::endl;
   //   }
   //}

   return 0;
}
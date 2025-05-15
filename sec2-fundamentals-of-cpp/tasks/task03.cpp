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

   //std::cout << text << std::endl;

   std::stringstream ss;
   
   // "cout" the entire text into ss. It's a stream of strings :)
   ss << text;

   // Create another string to accept each individual string from ss. That's because ss has all the text string and we can keep on asking for input just
   //  like we do with cin (std::cin >> )
   std::string nextStr = "";
   /*ss >> nextStr;
   ss >> nextStr;
   std::cout << nextStr << std::endl;*/

   std::map<const std::string, int> wordCount{};

   // So, in order to get the entire text, we can use a while loop. ss >> nextStr stops when that operation returns EOF signaling there's nothing in the
   //  buffer anymore, ie it's empty. That way we'll safely get out of the loop.
   while (ss >> nextStr)
   {
      /*std::cout << nextStr << std::endl;*/

      // We need to get rid of any punctuation like commas and periods, and upper cases as well.
      //  We can loop through each character in nextStr and only accept what's a letter using std::isalpha()

      std::string word = "";
      int lastCharIndex = 0; // in the video he uses 0, but that might cause an issue as he uses lastCharIndex != nextStr.since() - 1
      for (char c : nextStr)
      {
         ++lastCharIndex;
         if (std::isalpha(c) || c == '+')
         {
            //word.push_back(c);
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

      ++wordCount[word];

      ////std::cout << word << std::endl;

      //// To find out which word is being repeated and how many times it's being repeated. 
      ////  We can use a map, where we have the word and a count. That way every time that word appear in the text, we increment the count.

      //// Add the word as the key and 1 as the count (if the word already exists in the map, it won't be added again)
      //int count = 1;
      //wordCount.insert(std::pair<std::string, int>(word, count));

      //// Now check if word already exists in wordCount. If it does, increment count and add to that key (word).
      ///*
      //* bug: it only checks one time? all count is 2 when printing them out...
      //* 
      //* eg
      //* word = c++
      //* 
      //* 
      //*/

      //if (word == "c++")
      //{
      //   std::cout << word << std::endl;
      //   //std::cout << count << std::endl;
      //}

      //if (wordCount.count(word)) // if
      //{
      //   ++count;
      //   //std::cout << count << std::endl;
      //   wordCount[word] = count;
      //}
      //std::cout << count << std::endl;

   }

   // Loop through the map and the words (keys) with a count (value) greater than 1, print it out
   // Range-based for loop
   for (const auto& pair : wordCount)
   {
      if (pair.second > 1)
      {
         std::cout << "\"" << pair.first << "\" repeated: " << pair.second << " times." << std::endl;
      }
   }

   return 0;
}
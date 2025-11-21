#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
   sf::Vector2u VectorWindow { 100,100 };
   sf::RenderWindow renderWindow{ sf::VideoMode(VectorWindow), "My Window"};

   while (renderWindow.isOpen())
   {

   }
   
   std::cout << "Hello World!" << std::endl;
}
/*
1. using sfml render 1 ball
2. drop a ball using physics
3. collide 2 balls together
*/

//?how will we check for collisions of thousands of balls??
//should we have some sort of queue thats like this ball is closest to this other ball and constantly check if they touch???

/*
1. we will have an engine that such that it drops a ball we have a set acceleration and speed for the ball and we can
calculate everything about the ball from there
2. we will call the engine and then use the values that we spit out the render the ball


*/


/*
1. for collisions we can calculate trajectories with the dot product
2. we can calculate spin with the cross product

*/



#include <iostream>
#include <optional>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


const int X_VALUE_SIZE = 1400;
const int Y_VALUE_SIZE = 900;


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({X_VALUE_SIZE, Y_VALUE_SIZE}), "SFML window");

    sf::CircleShape circle;
    circle.setRadius(10);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition({0, 0});

    // Start the game loop
    sf::Event event;
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        // Clear screen
        window.clear();

        //draw circle
        window.draw(circle);
 
        // Update the window
        window.display();
        
    }
}

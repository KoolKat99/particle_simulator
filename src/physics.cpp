//this class gets a current position and will just calculate its next position essentially

//we need to figure out where exactly the ball will hit the other ball, 
//this spots intersection and the middle of the ball form a vector and thats the new direction of the ball

#include <SFML/Graphics.hpp>
#include <cmath>


//when we add drag stuff we need to somehow variably change acceleration
const float Y_ACCELERATION = -9.8;
const float X_ACCELERATION = 0;
const sf::Vector2f ACCELERATION(X_ACCELERATION, Y_ACCELERATION);
const float RADIUS = 10;
const float FRAME_RATE_TIME_SECONDS = 0.1;


struct Particle {

    // float x_velocity;
    // float y_velocity;
    // float x_position;
    // float y_position;
    sf::Vector2f position;
    sf::Vector2f velocity; //this velocity vector can be used to figure out trajectory of something
    sf::Color color;

    Particle(float x, float y, float x_vel, float y_vel, sf::Color col) : 
        position(x, y), velocity(x_vel, y_vel), color(col) {}

};

//this needs a better name
void increment_time(Particle &ball) {
    ball.position = ball.position + ball.velocity*FRAME_RATE_TIME_SECONDS;
    ball.velocity = ball.velocity + ACCELERATION*FRAME_RATE_TIME_SECONDS;
}


//returns false if no collision
bool collision_event(Particle &ball1, Particle &ball2) {
    //do the dot product of the two balls i guess??

    
    sf::Vector2f collision_point = collision_location(ball1, ball2);
    //create a vector with a point of the ball and collision point
    //this needs to be a unit vector!!!!!!!!!!
    sf::Vector2f ball1_collision_vector = collision_point - ball1.position;
    sf::Vector2f ball2_collision_vector = collision_point - ball2.position;

    



    return false;

}


//will return the exact position where they touch
sf::Vector2f collision_location(const Particle &ball1, const Particle &ball2) {

    sf::Vector2f distance_vector = (ball2.position - ball1.position);
    float distance = temp.length();
    if(distance <= RADIUS*2) {
        //they have collided!!!!
        distance_vector.x *= 0.5;
        distance_vector.y *= 0.5;
        sf::Vector2f collision_point = ball1.position + distance_vector;
    }

}





#ifndef BOID_H
#define BOID_H

#include <cmath>

#include <SFML/Graphics.hpp>
#include <vector>

#define PI 3.14159265f
#define MAG(x,y) sqrt((abs(x*x) + abs(y*y)))
#define FRAND(x, y) (x + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(x-y))))

using namespace std;

extern unsigned screenWidth;
extern unsigned screenHeight;
extern unsigned totalBoids;
extern float cohesionFactor;
extern float alignmentFactor;
extern float separationFactor;


static float boidWidth = 10;
static float boidHeight = 20;
static float neighbourSeekLimit = 60;
static float separationDistance = 30;
static float velocityLimit = 3;
static float wallDistance = 30;
static float wallColisionVector = 20;

class Boid {
protected:
	float height;
	float width;
	sf::Vector2f position;
	sf::Vector2f velocity;
	float rotation;
	sf::ConvexShape convex;
	sf::CircleShape triangle;
	sf::Color color;
public:
	unsigned boidId;

	Boid();

	void createBoidShape(sf::ConvexShape *convex);
	void limitPosition();	
	void limitVelocity();
	void setVelocity(sf::Vector2f v);
	void setPosition(sf::Vector2f p);
	void setRotation(float r);
	void move(sf::Vector2f m);
	float distance(Boid &boid);

	sf::Vector2f bound_position();
	sf::Vector2f getVelocity();
	sf::Vector2f getPosition();
	sf::Vector2f getSeparation(vector<int>& boidIds, vector<Boid*> allBoids);
	sf::Vector2f getCohesion(vector<int>& boidIds, vector<Boid*> allBoids);
	sf::Vector2f getAlignment(vector<int>& boidIds, vector<Boid*> allBoids);
	vector<int> getNeighbourhood(vector<Boid*> allBoids, unsigned boidId);
};
#endif // BOID_H
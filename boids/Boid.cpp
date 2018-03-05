#include "Boid.h"

Boid::Boid() : height{ boidHeight }, width{ boidWidth } {
	position.x = static_cast<float> (rand() % screenWidth);
	position.y = static_cast<float> (rand() % screenHeight);
	velocity = sf::Vector2f(FRAND(-3, 3), FRAND(-3, 3));
	color = sf::Color(rand() % 256, rand() % 256, rand() % 256, 255);
}

void Boid::createBoidShape(sf::ConvexShape *convex){
	convex->setPointCount(3);
	convex->setPoint(0, sf::Vector2f(0, -boidHeight / 2));
	convex->setPoint(1, sf::Vector2f(-boidWidth / 2, boidHeight / 2));
	convex->setPoint(2, sf::Vector2f(boidWidth / 2, boidHeight / 2));
	convex->setPosition(position);
	rotation = atan2(velocity.y, velocity.x) * 180.f / PI + 90.f;
	convex->setRotation(rotation);
	convex->setFillColor(color);
}

void Boid::limitPosition(){
	if (this->position.x > screenWidth)
		this->position.x -= screenWidth;
	else if (this->position.x < 0)
		this->position.x += screenWidth;
	if (this->position.y > screenHeight)
		this->position.y -= screenHeight;
	else if (this->position.y < 0)
		this->position.y += screenHeight;
}

sf::Vector2f Boid::bound_position(){
	sf::Vector2f v;
	if (this->position.x < wallDistance) v.x = wallColisionVector;
	else if (this->position.x > screenWidth - wallDistance) v.x = -wallColisionVector;
	if (this->position.y < wallDistance) v.y = wallColisionVector;
	else if (this->position.y > screenHeight - wallDistance) v.y = -wallColisionVector;
	return v;
}

void Boid::limitVelocity(){
	float vMag;
	vMag = MAG(velocity.x, velocity.y);
	if (vMag > velocityLimit) {
		velocity *= (velocityLimit / vMag);
	}
}

float Boid::distance(Boid &boid){
	return MAG(abs(this->position.x - boid.position.x), abs(this->position.y - boid.position.y));
}

void Boid::setVelocity(sf::Vector2f v) { velocity = v; }
sf::Vector2f Boid::getVelocity() { return velocity; }

void Boid::setPosition(sf::Vector2f p) { position = p; }
sf::Vector2f Boid::getPosition() { return position; }

void Boid::setRotation(float r){
	rotation = r;
}

void Boid::move(sf::Vector2f m){
	position += m;
}

vector<int> Boid::getNeighbourhood(vector<Boid*> allBoids, unsigned boidId){
	vector<int> neighbours;
	for (unsigned i = 0; i < allBoids.size(); i++){
		if (i == boidId)
			continue;
		if (this->distance(*allBoids[i]) < neighbourSeekLimit)
			neighbours.push_back(i);
	}
	return neighbours;
}

sf::Vector2f Boid::getSeparation(vector<int>& boidIds, vector<Boid*> allBoids){
	sf::Vector2f s;
	for (int i : boidIds)
		if (this->distance(*allBoids[i]) < separationDistance)
			s += (this->position - allBoids[i]->position);
	return s * separationFactor;
}

sf::Vector2f Boid::getCohesion(vector<int>& boidIds, vector<Boid*> allBoids){
	sf::Vector2f c; float N;
	N = static_cast<float>(boidIds.size());
	for (int i : boidIds)
		c += allBoids[i]->position;
	if (N) c /= N;
	return (c - this->position) * cohesionFactor;
}

sf::Vector2f Boid::getAlignment(vector<int>& boidIds, vector<Boid*> allBoids){
	sf::Vector2f a; float N;
	N = static_cast<float>(boidIds.size());
	for (int i : boidIds)
		a += allBoids[i]->velocity;
	if (N) a /= N;
	return a * alignmentFactor;
}
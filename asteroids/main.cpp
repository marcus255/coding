#include <SFML/Graphics.hpp>

#include <cmath>

using namespace sf;

float DEGTORAD = 0.017453f;
int screen_w = 1200, screen_h = 600;

class Object 
{
public:
	Vector2f velocity;
	Vector2f position;
	ConvexShape convex;
	int rotation;
	bool accelerate;

	virtual void update(){};

	void draw(RenderWindow &app)
	{
		convex.setPosition(position);
		convex.setRotation(rotation + 90);
		app.draw(convex);
	}
	
virtual ~Object(){};	
};

class Ship : public Object
{
public:
	int size;
	float max_speed;
	
	Ship(int s, float max_sp = 30.0) : size { s }, max_speed { max_sp }
	{	
		accelerate = false;
		position.x = screen_w / 2;
		position.y = screen_h / 2;
		convex.setPointCount(3);
		convex.setPoint(0, Vector2f(0, -size));
		convex.setPoint(1, Vector2f(-size / 2, size / 2));
		convex.setPoint(2, Vector2f(size / 2, size / 2));
		convex.setFillColor(Color(0,255,0,255));
	}
	
	void update() 
	{

		if (accelerate){
			float speed = velocity.x*velocity.x+velocity.y*velocity.y;
			if (sqrt(speed) <= max_speed) {
				velocity.x += cos(rotation*DEGTORAD)*0.2;
				velocity.y += sin(rotation*DEGTORAD)*0.2;
			}
		}
		else {
			velocity.x *= 0.95;
			velocity.y *= 0.95;
		}
		
		position.x += velocity.x;
		position.y += velocity.y;
		
		if (position.x > screen_w)
			position.x = 0;
		if (position.x < 0)
			position.x = screen_w;
		if (position.y > screen_h)
			position.y = 0;
		if (position.y < 0)
			position.y = screen_h;
		
	}
};

int main()
{
	RenderWindow window(VideoMode(screen_w, screen_h), "Asteroids");
	window.setFramerateLimit(60);
	Event event;

	Ship *ship = new Ship(50);
	
	while (window.isOpen()){
		window.clear();
		ship->update();
		ship->draw(window);
		window.display();

		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed){
				switch (event.key.code){

					case Keyboard::Down:
						
						break;
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) ship->rotation+=2;
		if (Keyboard::isKeyPressed(Keyboard::Left))  ship->rotation-=2;
		if (Keyboard::isKeyPressed(Keyboard::Up)) 
			ship->accelerate=true;
		else
			ship->accelerate = false;
		
	}
	return 0;
}

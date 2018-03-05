#include "main.h"
#include "Boid.h"

int main()
{
	srand(static_cast <unsigned> (time(0)));
	activeFactor = &cohesionFactor;
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Boid simulation");
	window.setFramerateLimit(framesPerSecond);
	sf::Event event;
	vector<Boid*> allBoids;
	vector<int> neighboursIds;
	sf::Vector2f s, c, a;
	sf::ConvexShape *shape;

	// Create a graphical text to display
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")){
		cout << "Can't find font files in .exe directory" << endl; 
	}
	getParametersText();
	sf::Text text(parametersText, font, 14);
	text.setFillColor(sf::Color::White);

	for (unsigned i = 0; i < totalBoids; i++){
		allBoids.push_back((new Boid()));
	}
	
	while (window.isOpen()){
		window.clear();
		for (unsigned i = 0; i < totalBoids; i++){
			neighboursIds = allBoids[i]->getNeighbourhood(allBoids, i);
			s = allBoids[i]->getSeparation(neighboursIds, allBoids);
			c = allBoids[i]->getCohesion(neighboursIds, allBoids);
			a = allBoids[i]->getAlignment(neighboursIds, allBoids);
			allBoids[i]->setVelocity(allBoids[i]->getVelocity() + s + c + a);
			allBoids[i]->limitVelocity();
			allBoids[i]->setPosition(allBoids[i]->getPosition() + allBoids[i]->getVelocity());
			allBoids[i]->limitPosition();

			shape = new sf::ConvexShape();
			allBoids[i]->createBoidShape(shape);
			window.draw(*shape);
			delete shape;
		}
		window.draw(text);
		window.display();

		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed){
				switch (event.key.code){
					case sf::Keyboard::C:
						activeFactor = &cohesionFactor;
						break;
					case sf::Keyboard::S:
						activeFactor = &separationFactor;
						break;
					case sf::Keyboard::A:
						activeFactor = &alignmentFactor;
						break;
					case sf::Keyboard::Up:
						*(activeFactor) += 0.01f;
						getParametersText();
						text.setString(parametersText);
						break;
					case sf::Keyboard::Down:
						*(activeFactor) -= 0.01f;
						getParametersText();
						text.setString(parametersText);
						break;
					case sf::Keyboard::Left:
						if (totalBoids > 0) {
							totalBoids--;
							delete allBoids[totalBoids];
							allBoids.pop_back();
							getParametersText();
							text.setString(parametersText);
						}
						break;					
					case sf::Keyboard::Right:
						totalBoids++;
						allBoids.push_back(new Boid());
						getParametersText();
						text.setString(parametersText);
						break;
				}
			}
		}
	}
	return 0;
}

static void getParametersText(){
	string str = "";
	stringstream c, a, s, b;
	str.append("Cohesion: ");
	c << fixed << setprecision(2) << cohesionFactor;
	str.append(c.str());
	str.append("  \nAlignment: ");
	a << fixed << setprecision(2) << alignmentFactor;
	str.append(a.str());
	str.append("  \nSeparation: ");
	s << fixed << setprecision(2) << separationFactor;
	str.append(s.str());
	str.append("  \nBoids: ");
	b << fixed << totalBoids;
	str.append(b.str());
	parametersText = str;
}
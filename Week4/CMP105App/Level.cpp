#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	view = window->getView();

	texture.loadFromFile("gfx/Mushroom.png");
	enemyTexture.loadFromFile("gfx/Goomba.png");
	backTexture.loadFromFile("gfx/Level1_1.png");

	testSprite.setTexture(&texture);
	testSprite.setSize(sf::Vector2f(100, 100));
	testSprite.setPosition(100, 100);

	playerObject.setInput(input);
	playerObject.setTexture(&texture);
	playerObject.setSize(sf::Vector2f(100, 100));
	playerObject.setPosition(100, 100);

	enemyObject = Enemy(sf::Vector2f(300, 300), sf::Vector2f(1, 1), 500);
	enemyObject.setWindow(window);
	enemyObject.setTexture(&enemyTexture);
	enemyObject.setSize(sf::Vector2f(100, 100));

	enemy2 = Enemy(sf::Vector2f(400, 200), sf::Vector2f(1, -1), 500);
	enemy2.setWindow(window);
	enemy2.setTexture(&enemyTexture);
	enemy2.setSize(sf::Vector2f(100, 100));

	back.setTexture(&backTexture);
	back.setSize(sf::Vector2f(11038, 675));
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	playerObject.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	playerObject.update(dt);
	enemyObject.update(dt);
	enemy2.update(dt);
	if (playerObject.getPosition().x > view.getCenter().x + (view.getSize().x / 2) - playerObject.getSize().x)
	{
		view.move(700 * dt, 0);
		std::cout << "Right - " << view.getCenter().x << std::endl;
	}
	if (playerObject.getPosition().x < 0)
	{
		view.move(-100 * dt, 0);
		std::cout << "Left - " << view.getCenter().x << std::endl;
	}
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(back);
	window->draw(testSprite);
	window->draw(playerObject);
	window->draw(enemyObject);
	window->draw(enemy2);
	window->setView(view);

	endDraw();
}

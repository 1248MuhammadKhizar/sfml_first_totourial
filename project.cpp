#include"Animation.h"
using namespace std;
using namespace sf;


int main()
{
	bool a;
	RenderWindow window(VideoMode(1280, 720), "Hockey", Style::Close | Style::Resize);
	RectangleShape player(Vector2f(200.0f, 200.0f));
	RectangleShape ball(Vector2f(50.0f, 50.0f));
	/*ball.setFillColor(Color::Blue);*/
	ball.setPosition(20.0f,370.0f);
	RectangleShape bound(Vector2f(200.0f, 10.0f));
	bound.setPosition(640.0f - (bound.getSize().x / 2), window.getSize().y - bound.getSize().y);
	bound.setFillColor(Color::Green);
	Texture ball_text;
	//ball_text.loadFromFile("i.png");
	//ball.setTexture(&ball_text);
	Animation animation(&ball_text, Vector2u(2, 1), 0.1f);
	player.setPosition(540.0f, 360.0f);
	float delta_time = 0.0f;
	Texture background;
	background.loadFromFile("back.png");
	Sprite back_sprite;
	back_sprite.setTexture(background);
	Clock clock;
	int score = 0;

	
	Font font;
	font.loadFromFile("arial.ttf");
	
	Text animatedText(to_string(score), font, 80);
	animatedText.setFillColor(Color::Black);
	animatedText.setPosition(500, 100);
	
	bool count1 = true;
	bool count2 = false;
	bool count3 = false;
	bool count4 = false;

	while (window.isOpen())
	{
		delta_time = clock.restart().asSeconds();
		Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::Resized:
				break;

			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					window.close();
				}
			default:
				break;
			}

		}
		float bound_x = bound.getPosition().x;
		float bound_y = bound.getPosition().y;
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
		
			if(bound.getPosition().x>0)
			{
				bound.move(-0.3f, 0.0f);
			}
			
		}
		
		else if (Keyboard::isKeyPressed(Keyboard::D))
		{
			if (bound.getPosition().x < window.getSize().x - bound.getSize().x) {
				bound.move(0.3f, 0.0f);
			}
		}

		
		
		
		
		if (ball.getPosition().y <= bound.getPosition().y &&
			ball.getPosition().y + ball.getSize().y >= bound.getPosition().y &&
			ball.getPosition().x + ball.getSize().x > bound.getPosition().x &&
			ball.getPosition().x < bound.getPosition().x + bound.getSize().x) {
			
			count1 = false;
			count2 = true;
			score += 5;
			
		}
		else if (ball.getPosition().x + ball.getSize().x >= window.getSize().x) {
			count2 = false; 
			count3 = true;
					}
		else if (ball.getPosition().y <= 0) {
			count3 = false;
			count4 = true;
			
		}
		else if (ball.getPosition().x <= 0) {
			count4 = false; 
			count1 = true;
			
		}

		else if(ball.getPosition().y  > window.getSize().y - ball.getSize().y)
		{
			Font font1;
			font1.loadFromFile("arial.ttf");
			Text animated_Text("Game over! Press any key to exit the window ", font1, 30);
			animated_Text.setFillColor(Color::Red);
			animated_Text.setPosition(500, 100);
			window.draw(animated_Text);
			window.close();

		}
		animatedText.setString(std::to_string(score));
	
		
		if (count1)
		{
			ball.move(0.2f, 0.1f);
			ball.setFillColor(Color::Green);
		}
		else if (count2)
		{
			ball.move(0.2f, -0.1f);
			ball.setFillColor(Color::Red);
		}
		else if (count3)
		{
			ball.move(-0.2f,-0.1f);
			ball.setFillColor(Color::White);
		}
		else if (count4)
		{
			ball.move(-0.2f,0.1f);
			ball.setFillColor(Color::Yellow);
		}

		
		animatedText.move(0, sin(clock.getElapsedTime().asSeconds() * 2) * 2);
		/*animation.update(0, delta_time);
		ball.setTextureRect(animation.uvrect);*/
		
		
		window.clear();
		window.draw(back_sprite);
		window.draw(bound);
		window.draw(animatedText);
		window.draw(ball);
		
		window.display();
	}

}
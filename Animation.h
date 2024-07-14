#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class Animation
{
private:
	Vector2u Total_image;
	Vector2u current_image;

	float total_time;
	float switch_time;



public:
	IntRect uvrect;
	Animation(Texture* text, Vector2u tot_image, float switch_tme)
	{
		this->Total_image = tot_image;
		this->switch_time = switch_tme;
		total_time = 0.0f;
		current_image.x = 0;
		uvrect.width = text->getSize().x / float(Total_image.x);
		uvrect.height = text->getSize().y / float(Total_image.y);
	}

	void update(int rows, float delta_time)
	{
		current_image.y = rows;
		total_time += delta_time;
		if (total_time >= switch_time)
		{
			total_time -= switch_time;
			current_image.x++;
			if (current_image.x >= Total_image.x)
			{
				current_image.x = 0;

			}

		}
		uvrect.left = current_image.x * uvrect.width;
		uvrect.top = current_image.y * uvrect.height;
	}


};
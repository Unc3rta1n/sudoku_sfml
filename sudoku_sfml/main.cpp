#include <SFML/Graphics.hpp>
#include <stdio.h>
#include<conio.h>
#include <iostream>
#include "sudokusolve.hpp"

using namespace sf;
int main(void) {
	RenderWindow window(VideoMode(352,352), "Sudoku");
	int w = 32;//ширина клетки
	int counter = 0;
	Texture t;
	Text text;
	t.loadFromFile("images/tiles.jpg");
	Sprite s(t);
	int solution[9][9];
	int viewsudoku[9][9];
	int diff[9][9] = {
							  {0, 9, 0, 2, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 1, 0, 9, 0, 8},
							  {6, 0, 8, 0, 0, 0, 7, 1, 0},
							  {0, 0, 0, 0, 8, 0, 0, 7, 0},
							  {3, 8, 0, 5, 6, 0, 0, 0, 0},
							  {2, 0, 9, 1, 0, 0, 0, 0, 5},
							  {0, 0, 0, 0, 2, 3, 0, 6, 0},
							  {4, 6, 2, 0, 5, 1, 8, 0, 3},
							  {8, 1, 0, 0, 4, 9, 5, 2, 7} };
	int diff1[9][9] = {
							  {0, 9, 0, 2, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 1, 0, 9, 0, 8},
							  {6, 0, 8, 0, 0, 0, 7, 1, 0},
							  {0, 0, 0, 0, 8, 0, 0, 7, 0},
							  {3, 8, 0, 5, 6, 0, 0, 0, 0},
							  {2, 0, 9, 1, 0, 0, 0, 0, 5},
							  {0, 0, 0, 0, 2, 3, 0, 6, 0},
							  {4, 6, 2, 0, 5, 1, 8, 0, 3},
							  {8, 1, 0, 0, 4, 9, 5, 2, 7} };
	int diff2[9][9] = {
							  {0, 9, 0, 2, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 1, 0, 9, 0, 8},
							  {6, 0, 8, 0, 0, 0, 7, 1, 0},
							  {0, 0, 0, 0, 8, 0, 0, 7, 0},
							  {3, 8, 0, 5, 6, 0, 0, 0, 0},
							  {2, 0, 9, 1, 0, 0, 0, 0, 5},
							  {0, 0, 0, 0, 2, 3, 0, 6, 0},
							  {4, 6, 2, 0, 5, 1, 8, 0, 3},
							  {8, 1, 0, 0, 4, 9, 5, 2, 7} };
	(fillSudoku(diff1, 0, 0));
	Font font;
	if (!font.loadFromFile("arial.ttf"))
		return EXIT_FAILURE;

	while (window.isOpen())
	{
		Vector2i pos = Mouse::getPosition(window);
		int x = pos.x / w;
		int y = pos.y / w;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::TextEntered)
			{
				if ((event.text.unicode >= 49) && (event.text.unicode <= 57))
				{
					switch (event.text.unicode)
					{
					case '1':
					{
						diff[x][y] = 1;
						break;
					}
					case '2':
					{
						diff[x][y] = 2;
						break;
					}
					case '3':
					{
						diff[x][y] = 3;
						break;
					}
					case '4':
					{
						diff[x][y] = 4;
						break;
					}
					case '5':
					{
						diff[x][y] = 5;
						break;
					}
					case '6':
					{
						diff[x][y] = 6;
						break;
					}
					case '7':
					{
						diff[x][y] = 7;
						break;
					}
					case '8':
					{
						diff[x][y] = 8;
						break;
					}
					case '9':
					{
						diff[x][y] = 9;
						break;
					}
					default:
					{
						break;
					}

					}
					
							if (diff[x][y] != diff1[x][y])
								{
								
									diff[x][y]=diff2[x][y];
						        }
							if (diff[x][y] == diff1[x][y])
							{
								counter++;
								printf_s("counter is %d", counter);
							}
					std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
				}
					
			}
			if (event.type == sf::Event::Closed)
				window.close();
			/*if (event.type == Event::MouseButtonPressed)

				if (event.key.code == Mouse::Left)
				{
					diff[x][y] = c;
					
				}*/
		}
		window.clear(Color::White);

		

			for (int i = 0; i < 9; i++)
				for (int j = 0; j < 9; j++)
				{


					s.setTextureRect(IntRect(diff[i][j] * w, 0, w, w));//вырезаем из tiles.png нужную €чейку 
					s.setPosition(i * w, j * w);//устанавливаем €чейку, опира€сь на размер и координаты массива
					window.draw(s);
				}
		// ќтображаем всю композицию на экране
		
		window.display();
		
		if (counter == 81)
		{
			window.clear(Color::White);
			break;
		}
			
			
		
		
	}
	RenderWindow app(VideoMode(400, 400), "Sudoku");
	while (app.isOpen())
	{
		Event E;
		
		
		text.setFont(font);
		text.setString("congratz. u winner");
		text.setCharacterSize(16);
		text.setFillColor(sf::Color::Red);
		
		app.draw(text);
		window.display();
		while (app.pollEvent(E))
		{
			if (E.type == sf::Event::Closed)
				app.close();
		}
	}
	
	
}
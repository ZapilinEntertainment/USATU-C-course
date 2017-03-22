
#include <SFML/Graphics.hpp>
#include <cmath>

	using namespace sf;
	
	const int WINDOW_SIZE=640;
	
	const float MIN_HEIGHT=5; // минимальные -максимальные размеры
	const float MIN_WIDTH=5;
	const float MAX_WIDTH=300;
	const float MAX_HEIGHT=300;
	const float DISAPPEARING_SPEED=3; //скорость исчезновения





int main()
{
	int count=0; //количество прямоугольников
	printf ("enter rectangles count: ");
	scanf ("%i",&count);
	if (count<=0) //прямоугольников не может быть ноль или меньше нуля
	{
	printf ("incorrect input");
	return 1;
	}
	
	RectangleShape *rects = new RectangleShape[count];
	for (int i = 0; i<count; i++)
	{
		float xsize=rand()/RAND_MAX*(MAX_WIDTH-MIN_WIDTH)+MIN_WIDTH;
		float ysize = rand ()/RAND_MAX*(MAX_HEIGHT-MIN_HEIGHT)+MIN_HEIGHT;
		rects[i].setSize(Vector2f(xsize,ysize));
		
		float xpos=rand()/RAND_MAX*(WINDOW_SIZE-xsize);
		float ypos=rand()/RAND_MAX*(WINDOW_SIZE-ysize);
		rects[i].setPosition(Vector2f(xpos,ypos));
		
		rects[i].setFillColor(Color::White);
	}
	
	
	RenderWindow window(sf::VideoMode(WINDOW_SIZE,WINDOW_SIZE), "Variant2");
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        int disappeared=0; //количество исчезнувших
        for (int i=0;i<count;i++)
        {
        	float height=rects[i].getSize().y;
        	float width=rects[i].getSize().x;
        	if (height!=0)
        	{
        		height-=DISAPPEARING_SPEED;
        		if (height<0) height=0;
        		else
        		{
        			rects[i].setSize(Vector2f(width,height));
        			window.draw(rects[i]);
				}
			}
			else disappeared++;
		}
		if (disappeared==count) printf ("all rects disappeared");
        window.display();
       
    }
    
    

    return 0;
}

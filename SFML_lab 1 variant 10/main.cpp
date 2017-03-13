#include <SFML/Graphics.hpp>
#include <cmath>
	using namespace sf;
	
	const int WINDOW_SIZE=640;
	
	const float MIN_SIZE=50; // minimal - maximal sizes
	const float MAX_SIZE=200;
	
	const int MIN_COUNT=3;
	const int MAX_COUNT=10;
	
	const float SCALING_SPEED=1; //size changing speed

int main()
{
	int count=0; //squares count
	printf ("enter squares count: ");
	scanf ("%i",&count);
	if (count<MIN_COUNT||count>MAX_COUNT) //check
	{
	printf ("incorrect input");
	return 1;
	}
	
	RectangleShape *squares = new RectangleShape[count];
	bool *isGrowing = new bool[count]; // is square growing or decreasing
	
	srand ( time(NULL) );
	for (int i = 0; i<count; i++)
	{
		float size=rand()/((float)RAND_MAX)*(MAX_SIZE-MIN_SIZE)+MIN_SIZE;
		float xpos=rand()/((float)RAND_MAX)*(WINDOW_SIZE-size);
		float ypos=rand()/((float)RAND_MAX)*(WINDOW_SIZE-size);
		
		squares[i].setPosition(xpos,ypos);
		squares[i].setSize(Vector2f(size,size));
		squares[i].setFillColor(Color(rand()%255,rand()%255,rand()%255,255));
		isGrowing[i]=true;
	}

	RenderWindow window(sf::VideoMode(WINDOW_SIZE,WINDOW_SIZE), "Variant10");
	window.setFramerateLimit(30);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        

        for (int i=0;i<count;i++)
        {
        	Vector2f realsize=squares[i].getSize();//current size
        	if (realsize.x<=0||realsize.y<=0) continue;
        	Vector2f newSize;
        	
        	Vector2f realpos=squares[i].getPosition();// current position
        	Vector2f newPos;
        	
        	float delta;
        	if (isGrowing[i])
        	{
        		newPos=realpos-Vector2f(SCALING_SPEED/2,SCALING_SPEED/2);
        		newSize=realsize+Vector2f(SCALING_SPEED,SCALING_SPEED);
				delta=SCALING_SPEED/2;
				
	        	if (newPos.x<=0) 
				{
					delta=realpos.x;
					isGrowing[i]=false;
				}
				if (newPos.y<=0) {
					if (realpos.y<delta) delta=realpos.y;
					isGrowing[i]=false;
				}
				if (newPos.x+newSize.x>=WINDOW_SIZE)
				{
					if (WINDOW_SIZE-realpos.x-realsize.x<delta) 
					delta=WINDOW_SIZE-realpos.x-realsize.x;
					isGrowing[i]=false;
				}
					if (newPos.y+newSize.y>=WINDOW_SIZE)
				{
					if (WINDOW_SIZE-realpos.y-realsize.y<delta) delta=WINDOW_SIZE-realpos.y-realsize.y;
					isGrowing[i]=false;
				}
				for (int j=0;j<count;j++)
				{
					if (j==i) continue;
					Vector2f apos=squares[j].getPosition();
					Vector2f asize=squares[j].getSize();
					if (apos.x+asize.x<realpos.x||apos.x>realpos.x+realsize.x||apos.y+asize.y<realpos.y||apos.y>realpos.y+realsize.y) continue;
					if (realpos.x+realsize.x>=apos.x)
					{
						isGrowing[i]=false;
						isGrowing[j]=false;
					}
					if (realpos.x<=apos.x+asize.x)
					{
						isGrowing[i]=false;
						isGrowing[j]=false;
					}
						if (realpos.y+realsize.y>=apos.y)
					{
						isGrowing[i]=false;
						isGrowing[j]=false;
					}
					if (realpos.y<=apos.y+asize.y)
					{
						isGrowing[i]=false;
						isGrowing[j]=false;
					}
				}
			}
			else
			{
				delta=-SCALING_SPEED/2;
			}

			newPos=realpos-Vector2f(delta/2,delta/2);
			newSize=realsize+Vector2f(delta,delta);
				if (newSize.x<=0||newSize.y<=0) 
				{
					newSize=Vector2f(0,0);
				}
			squares[i].setPosition(newPos);
        	squares[i].setSize(newSize);
			window.draw(squares[i]);
		}
		window.display();
    }
    
    

    return 0;
}

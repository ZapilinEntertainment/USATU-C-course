
#include <SFML/Graphics.hpp>
#include <cmath>

	using namespace sf;
	
	const int WINDOW_SIZE=640;
	
	const int MIN_CIRCLES_COUNT=16;
	const int MAX_CIRCLES_COUNT=26;
	const float MIN_CIRCLE_SIZE=5; //radius
	const float MAX_CIRCLE_SIZE=10;
	float speed=0.3;
	bool paused=false;
	
	const int PINE_SPRITE_SIZE=190;
	float pineRadius=PINE_SPRITE_SIZE/4;
	Vector2f pinePos(WINDOW_SIZE/2-pineRadius,WINDOW_SIZE/2-pineRadius);
	Vector2f pineCenter(pinePos.x+pineRadius,pinePos.y+pineRadius);
	Texture pine_tx;
	

	Sprite pine;

	float angle=rand()%RAND_MAX*M_PI/180.0;

	Vector2f pineVelocity(speed*cos(angle),speed*sin(angle)); //polar coordinate system
	
	int count=(rand()%(MAX_CIRCLES_COUNT-MIN_CIRCLES_COUNT))+MIN_CIRCLES_COUNT;
	CircleShape *circles;
	bool *circleStatus; //true - free, false - connected to pine
	Vector2f *deltaPos; //ball position, relative to pine
	Vector2f *centers; //balls centers for calculation
	
	
	inline float Distance (Vector2f A, Vector2f B)
	{
		return (sqrt( (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)) );
	}

void MovePine() {

		
		for (int i=0;i<count;i++)
        {
        	if (circleStatus[i]==true) //free ball
        	{
        		if (Distance(centers[i],pineCenter)<pineRadius) 
				{
					circleStatus[i]=false;
					deltaPos[i]=circles[i].getPosition()-pinePos;
				}
			}
			else
			{
				circles[i].setPosition(pinePos+deltaPos[i]);
			}
		}
		
		float pos=pinePos.x+pineVelocity.x;
		if (pos<0) 
		{
			pineVelocity.x*=-1;
			pinePos.x=0;
		}
		else
		{
			if (pos>WINDOW_SIZE-PINE_SPRITE_SIZE)
			{
				pineVelocity.x*=-1;
				pinePos.x=WINDOW_SIZE-PINE_SPRITE_SIZE;
			}
			else pinePos.x+=pineVelocity.x;
		}
		
		pos=pinePos.y+pineVelocity.y;
		if (pos<0)
		{
			pineVelocity.y*=-1;
			pinePos.y=0;
		}
		else
		{
			if (pos>WINDOW_SIZE-PINE_SPRITE_SIZE)
			{
				pineVelocity.y*=-1;
				pinePos.y=WINDOW_SIZE-PINE_SPRITE_SIZE;
			}
			else pinePos.y+=pineVelocity.y;
		}
		pine.setPosition(pinePos);
		pineCenter=Vector2f(pinePos.x+PINE_SPRITE_SIZE/2,pinePos.y+PINE_SPRITE_SIZE/2);
		
	}


int main()
{
	pine_tx.loadFromFile("pine_tx.png");
	pine.setTexture(pine_tx);
	pine.setPosition(pinePos);
	pineCenter=Vector2f(pinePos.x+PINE_SPRITE_SIZE/2,pinePos.y+PINE_SPRITE_SIZE/2);
	pine.setScale(((float)PINE_SPRITE_SIZE)/pine_tx.getSize().x,((float)PINE_SPRITE_SIZE)/pine_tx.getSize().y);

	
	circles=new CircleShape[count];
	circleStatus=new bool[count];
	deltaPos=new Vector2f[count];
	centers=new Vector2f[count];

	for (int i=0;i<count;i++) //creating balls
	{
		circleStatus[i]=true; 
		float radius=rand()/((float)RAND_MAX)*(MAX_CIRCLE_SIZE-MIN_CIRCLE_SIZE)+MIN_CIRCLE_SIZE;
		circles[i].setRadius(radius);
		
		float xpos=rand()/((float)RAND_MAX)*(WINDOW_SIZE-2*radius)+radius; 
		float ypos=rand()/((float)RAND_MAX)*(WINDOW_SIZE-2*radius)+radius;
		circles[i].setPosition(Vector2f(xpos,ypos));	
		centers[i].x=xpos+radius; 
		centers[i].y=ypos+radius; 
		
		circles[i].setFillColor(Color(rand()%255,rand()%255,rand()%255,255));
		deltaPos[i]=Vector2f(0,0);
	}
	
	
	RenderWindow window(sf::VideoMode(WINDOW_SIZE,WINDOW_SIZE), "Variant13");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(pine);
              
        int collectedCount=0;
        for (int i=0;i<count;i++)
        {
        	window.draw(circles[i]);
        	if (circleStatus[i]==false) collectedCount++;
		}
  
		//if (!paused) {		
		MovePine();
	//	}
        window.display();
        if (collectedCount==count&&!paused) 
		{
		printf("game over");
		paused=true;
		}
    }
    
    

    return 0;
}

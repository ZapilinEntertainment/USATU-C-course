#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
	using namespace sf;
	
	const int WINDOW_SIZE=1024;
	const int MAX_RADIUS=50; // минимальные -максимальные размеры
	const int MIN_RADIUS=7;
	const float SPEED=1.5; //скорость исчезновения

class Ball 
{
	public:
	Vector2f center,velocity;	
	CircleShape base;
	
	Ball ()
	{
		float radius=20;
		base=CircleShape(radius);
		base.setFillColor(Color::Yellow);
		center=base.getPosition()+Vector2f(radius,radius);
		velocity=Vector2f(0,0);
	}
	Ball (int radius, Color ballColor,Vector2f ballPosition,Vector2f ballVelocity)
	{
		base=CircleShape(radius);
		base.setPosition(ballPosition);
		base.setFillColor(ballColor);
		center=base.getPosition()+Vector2f(radius,radius);
		velocity=ballVelocity;
	}
	~Ball() {}
};

inline float Distance (Vector2f a, Vector2f b) 
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

inline float Magnitude(Vector2f a)
{
	return (sqrt(a.x*a.x+a.y*a.y));
}

float AngleBetweenVectors(Vector2f a, Vector2f b)
{
	return (acos((a.x*b.x+a.y*b.y)/(Magnitude(a)*Magnitude(b)))*180.0);
}

int main()
{
	std::cout<<"please enter balls count: ";
	int count;
	std::cin>>count;
	Ball *balls=new Ball[count];
	srand(time(NULL));
	for (int i=0;i<count;i++)
	{
		float rad=rand()/((float)(RAND_MAX))*(MAX_RADIUS-MIN_RADIUS)+MIN_RADIUS;
		float xpos=rand()%(WINDOW_SIZE-(int)(rad*2));
		float ypos=rand()%(WINDOW_SIZE-(int)(rad*2));
		float angle=rand()%181/180.0*M_PI;
		balls[i]=Ball(rad,Color(rand()%255,rand()%255,rand()%255,255),Vector2f(xpos,ypos),Vector2f(SPEED*cos(angle),SPEED*sin(angle)));	
	}
	
	RenderWindow window(sf::VideoMode(WINDOW_SIZE,WINDOW_SIZE), "Wow, such physics");
	window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();

        for (int i=0;i<count;i++)
        {
        	Vector2f startPos=balls[i].center;
        	Vector2f endPos=startPos+balls[i].velocity;
        	float myRadius=balls[i].base.getRadius();
        	
        	int farBorder=WINDOW_SIZE-myRadius;
        	if (endPos.x<myRadius) {endPos.x=myRadius; balls[i].velocity.x*=-1;}
        	else {
        		if (endPos.x>farBorder) {endPos.x=farBorder;balls[i].velocity.x*=-1;}
        	}
        	if (endPos.y<myRadius) {endPos.y=myRadius;balls[i].velocity.y*=-1;}
        	else {
        		if (endPos.y>farBorder) {endPos.y=farBorder;balls[i].velocity.y*=-1;}
			}
        	
        	for (int j=i+1;j<count;j++)
        	{
        		
        		if (Distance(endPos,balls[j].center)<(myRadius+balls[j].base.getRadius()))
        		{
        			Vector2f hitVector=balls[j].base.getPosition()-endPos;
        			float hitAngle=AngleBetweenVectors(balls[i].velocity,balls[j].velocity);
        			Vector2f resultVector=balls[i].velocity+balls[j].velocity;
        			if (hitAngle>90) balls[i].velocity=resultVector/(Magnitude(resultVector))*SPEED;
        			else 
					{
						resultVector=balls[i].velocity-hitVector;
						balls[i].velocity=resultVector/(Magnitude(resultVector))*SPEED;						
					}
        			
        			resultVector=balls[j].velocity+hitVector;
        			balls[j].velocity=resultVector/(Magnitude(resultVector))*SPEED;
        			
        			Color x=balls[i].base.getFillColor();
        			balls[i].base.setFillColor(balls[j].base.getFillColor());
        			balls[j].base.setFillColor(x);
				}
			}
			
			balls[i].base.setPosition(endPos-Vector2f(myRadius,myRadius));
			balls[i].center=endPos;
			window.draw(balls[i].base);
		}
  

        window.display();
    }
    return 0;
}

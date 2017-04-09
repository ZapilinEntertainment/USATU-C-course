#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdio.h>
	using namespace sf;
	
	const int WINDOW_SIZE=640;
	
	const float MIN_SIZE=50; // minimal - maximal sizes of main body
	const float MAX_SIZE=200;
	
	const int MIN_COUNT=2;
	const int MAX_COUNT=7;
	

int main()
{
	float rotationSpeed;
	printf("set rotation speed (in radians): "); //0.03 recommended
	scanf("%f",&rotationSpeed);

	srand(time(NULL));
	float r=rand()/((float)(RAND_MAX))*(MAX_SIZE-MIN_SIZE)+MIN_SIZE;
	CircleShape mainBody=CircleShape(r);
	mainBody.setPosition(WINDOW_SIZE/2-r,WINDOW_SIZE/2-r);
	
	float xpos; //start position coordinates
	float ypos;
	
	
	int count=rand()%6+MIN_COUNT;
	float orbitalRadius=r;
	float orbitalRadiusDelta=(WINDOW_SIZE/2-orbitalRadius)/count; //distance between satellites

	CircleShape *satellites=new CircleShape[count];
	float *angles=new float[count]; //current angle of satellite in polar coordinate system
	for (int i=0;i<count;i++)
	{
		orbitalRadius+=orbitalRadiusDelta;
		r=rand()/((float)(RAND_MAX))*(MAX_SIZE-MIN_SIZE)+MIN_SIZE;	//radius of ball
		r/=10;
		satellites[i]=CircleShape(r);
		
		angles[i]=rand()/((float)(RAND_MAX))*M_PI*2; //set starting position  using polar coordinate system
		xpos=orbitalRadius*cos(angles[i]);
		ypos=orbitalRadius*sin(angles[i]);
		satellites[i].setPosition(WINDOW_SIZE/2+xpos,WINDOW_SIZE/2+ypos);
	}

	RenderWindow window(sf::VideoMode(WINDOW_SIZE,WINDOW_SIZE), "Variant8");
	window.setFramerateLimit(30);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        
        window.draw(mainBody);
        orbitalRadius=mainBody.getRadius();
        for (int i=0;i<count;i++)
        {
        	angles[i]+=rotationSpeed;
        	orbitalRadius+=orbitalRadiusDelta;
        	xpos=orbitalRadius*cos(angles[i])-satellites[i].getRadius();
			ypos=orbitalRadius*sin(angles[i])-satellites[i].getRadius();
			satellites[i].setPosition(WINDOW_SIZE/2+xpos,WINDOW_SIZE/2+ypos);
			
        	window.draw(satellites[i]);
		}
        
        window.display();
    }
    
    return 0;
}

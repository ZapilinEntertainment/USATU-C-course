#include <SFML/Graphics.hpp>
#include <cmath>
	using namespace sf;
	
	const int WINDOW_SIZE=640;
	
	const float MIN_HEIGHT=100; // минимальные -максимальные размеры
	const float MIN_WIDTH=100;
	const float MIN_LENGTH=100;
	const float MAX_WIDTH=300;
	const float MAX_HEIGHT=300;
	const float MAX_LENGTH=300;
	const float DISAPPEARING_SPEED=1; //скорость исчезновения
	const float VIEW_ANGLE=45; //угол, под которым мы видим трехмерную проекцию

	struct Plgramm
	{
	float width,height,length,xpos,ypos; //width-x,height- y, length- z (проецируется)
	Vertex bottomSide[3]=
	{
		Vertex(Vector2f(0,100)),
		Vertex(Vector2f(100,150)),
		Vertex (Vector2f(300,150))
	};
	Vertex upside[4]=
	{
		Vertex (Vector2f(0,0)),
		Vertex (Vector2f(200,0)),
		Vertex (Vector2f(300,50)),
		Vertex (Vector2f(100,50)),
	};
	Vertex edge1[2]= 
	{
		Vertex (Vector2f(0,0)),
		Vertex (Vector2f(0,100))
	};
		Vertex edge2[2]= 
	{
		Vertex (Vector2f(100,50)),
		Vertex (Vector2f(100,150))
	};
		Vertex edge3[2]= 
	{
		Vertex (Vector2f(300,50)),
		Vertex (Vector2f(300,150))
	};
	};




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
	
	Plgramm *plgramms = new Plgramm[count];
	for (int i = 0; i<count; i++)
	{
		plgramms[i].width=rand()/((float)RAND_MAX)*(MAX_WIDTH-MIN_WIDTH)+MIN_WIDTH;
		plgramms[i].height = rand ()/((float)RAND_MAX)*(MAX_HEIGHT-MIN_HEIGHT)+MIN_HEIGHT;
		plgramms[i].length= rand ()/((float)RAND_MAX)*(MAX_LENGTH-MIN_LENGTH)+MIN_LENGTH;
		
		plgramms[i].xpos=rand()/((float)RAND_MAX)*(WINDOW_SIZE-plgramms[i].width-plgramms[i].width*cos(VIEW_ANGLE/180*M_PI));
		plgramms[i].ypos=rand()/((float)RAND_MAX)*(WINDOW_SIZE-plgramms[i].height-plgramms[i].height*sin(VIEW_ANGLE/180*M_PI));

	}

	RenderWindow window(sf::VideoMode(WINDOW_SIZE,WINDOW_SIZE), "Variant2");
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
        

        
        int disappeared=0; //количество исчезнувших
        for (int i=0;i<count;i++)
        {
        	float newHeight=plgramms[i].height;
        	if (newHeight!=0)
        	{
        		newHeight-=DISAPPEARING_SPEED;
        		if (newHeight<0) newHeight=0;
        		else
        		{
				    plgramms[i].ypos+=(plgramms[i].height-newHeight)/2;
					plgramms[i].height=newHeight;
				
					plgramms[i].upside[0].position=Vector2f(plgramms[i].xpos,plgramms[i].ypos); //верхняя крышка, вершины сверху вниз по часовой стрелке
					plgramms[i].upside[1].position=plgramms[i].upside[0].position+Vector2f(plgramms[i].width,0);
					plgramms[i].upside[2].position=plgramms[i].upside[1].position+Vector2f(plgramms[i].length*cos(VIEW_ANGLE/180*M_PI), plgramms[i].length*sin(VIEW_ANGLE/180*M_PI));
					plgramms[i].upside[3].position=plgramms[i].upside[2].position-Vector2f(plgramms[i].width,0);
					
					plgramms[i].edge1[0].position=plgramms[i].upside[0].position;//три боковые грани
					plgramms[i].edge1[1].position=plgramms[i].edge1[0].position+Vector2f(0,plgramms[i].height);
					
					plgramms[i].edge2[0].position=plgramms[i].upside[3].position;
					plgramms[i].edge2[1].position=plgramms[i].edge2[0].position+Vector2f(0,plgramms[i].height);
					
					plgramms[i].edge3[0].position=plgramms[i].upside[2].position;
					plgramms[i].edge3[1].position=plgramms[i].edge3[0].position+Vector2f(0,plgramms[i].height);
					
					plgramms[i].bottomSide[0].position=plgramms[i].edge1[1].position; //нижняя часть
					plgramms[i].bottomSide[1].position=plgramms[i].edge2[1].position;
					plgramms[i].bottomSide[2].position=plgramms[i].edge3[1].position;
        			
        			
        			window.draw(plgramms[i].upside,4,LinesStrip);
					window.draw(plgramms[i].edge1,2,Lines);
					window.draw(plgramms[i].edge2,2,Lines);
					window.draw(plgramms[i].edge3,2,Lines);
					window.draw(plgramms[i].bottomSide,3,LinesStrip);
				}
			}
			else disappeared++;
		}
		if (disappeared==count) printf ("all rects disappeared");
        window.display();
       
    }
    
    

    return 0;
}

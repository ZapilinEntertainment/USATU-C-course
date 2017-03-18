#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	union 
    {
        unsigned char bytes;              
        struct 
        {
            unsigned b0:1;
            unsigned b1:1;
            unsigned b2:1;
            unsigned b3:1;
            unsigned b4:1;
            unsigned b5:1;
            unsigned b6:1;
            unsigned b7:1;
        } byte;
    } bu; //binary union
 
 	char s;
 	printf ("enter you symbol: ");
 	scanf("%c",&s);
 	bu.bytes=s;
 	cout<<bu.byte.b0<<bu.byte.b1<< bu.byte.b2<< bu.byte.b3<< bu.byte.b4<< bu.byte.b5<< bu.byte.b6<< bu.byte.b7<<endl;
	return 0;
}

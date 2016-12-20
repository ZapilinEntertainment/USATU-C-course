#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

//using dev-C++

double *answer; //0-площадь поверхности, 1- объем

double VectorMagnitude (double v[3])
{
return (sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]));
}

double AngleCosBetweenVectors(double v1[3],double v2[3]) 
{
	double v1_l=VectorMagnitude(v1);
	double v2_l=VectorMagnitude(v2);
	if (v1_l==0||v2_l==0) return 1;
	return ((v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2])/(v1_l*v2_l));
}

double TriangleSquare (double v1[3],double v2[3])
{
	double v1_l=VectorMagnitude(v1);
	double v2_l=VectorMagnitude(v2);
	double angle_component=AngleCosBetweenVectors(v1,v2);
	angle_component=sqrt(1-angle_component*angle_component); //превращаем в синус
	return (v1_l*v2_l*angle_component);
}

void GetSquareAndVolume (double *v1, double *v2,double *v3,double *answer) {
	double back1[3],back2[3];
	back1[0]=v1[0]-v2[0]; back1[1]=v1[1]-v2[1];back1[2]=v1[2]-v2[2];
	back2[0]=v2[0]-v3[0];back2[1]=v2[1]-v3[0];back2[2]=v2[2]-v3[2];
	answer=malloc(2*sizeof(double));
	answer[0] = TriangleSquare (v1,v2)+TriangleSquare (v2,v3)+TriangleSquare(v1,v3)+TriangleSquare(back1,back2);
	printf("%lf",answer[0]);
	answer[1]= 1.0/6.0*(v1[0]*(v2[1]*v3[2]-v2[2]*v3[1])+v1[1]*(v2[2]*v3[0]-v3[2]*v2[0])+v1[2]*(v2[0]*v3[1]-v2[1]*v3[0]));	
}

int main(int argc, char *argv[]) {
	double vo[3],va[3],vb[3],vc[3];
	printf ("enter vertices coordinates:\n vertex O:");
	scanf ("%lf%lf%lf",&vo[0],&vo[1],&vo[2]);
	printf ("\n vertex A:");
	scanf ("%lf %lf %lf",&va[0],&va[1],&va[2]);
	if (va[0]==vo[0]&&va[1]==vo[1]&&va[2]==vo[2]) {
		printf ("error: vertex overlap!");
		_getch();
		return (-1);
	}
	printf ("\n vertex B:");
	scanf ("%lf%lf%lf", &vb[0],&vb[1],&vb[2]);
	if ((vb[0]==vo[0]&&vb[1]==vo[1]&&vb[2]==vo[2])||(va[0]==vb[0]&&va[1]==vb[1]&&va[2]==vb[2])) {
		printf ("error: vertex overlap!");
		_getch();
		return (-1);
	}
	printf ("\n vertex C:");
	scanf ("%lf%lf%lf",&vc[0],&vc[1],&vc[2]);
		if ((vc[0]==vo[0]&&vc[1]==vo[1]&&vc[2]==vo[2])||(vc[0]==vb[0]&&vc[1]==vb[1]&&vc[2]==vb[2])||(va[0]==vc[0]&&va[1]==vc[1]&&va[2]==vc[2])) {
		printf ("error: vertex overlap!");
		_getch();
		return (-1);
	}
	
	//представим в виде трех векторов с началом в точке О
	
	va[0]-=vo[0]; va[1]-=vo[1]; va[2]-=vo[2];
	vb[0]-=vo[0]; vb[1]-=vo[1]; vb[2]-=vo[2];
	vc[0]-=vo[0]; vc[1]-=vo[1]; vc[2]-=vo[2];
	int oa_l=VectorMagnitude(va);
	int ob_l=VectorMagnitude(vb);
	int oc_l=VectorMagnitude(vc);
	
	//проверка на совпадение векторов с помощью косинусов углов из скалярного произведения по координатам
	float s_cos=AngleCosBetweenVectors(va,vb);
	if (s_cos==1||s_cos==-1) {
		printf ("error: pyramid not exist - zero angle!");
		_getch();
		return (-1);
	}
	s_cos=AngleCosBetweenVectors(va,vc);
	if (s_cos==1||s_cos==-1) {
		printf ("error: pyramid not exist - zero angle!");
		_getch();
		return (-1);
	}
	s_cos=AngleCosBetweenVectors(vc,vb);
	if (s_cos==1||s_cos==-1) {
		printf ("error: pyramid not exist - zero angle!");
		_getch();
		return (-1);
	}
	//получение вектора нормали плоскости oab
	double n[]={va[1]*vb[2]-va[2]*vb[1],va[2]*vb[0]-va[0]*vb[2],va[0]*vb[1]-va[1]*vb[0]};
	//нормализация вектора n
	int n_l=VectorMagnitude(n);
	n[0]/=n_l;
	n[1]/=n_l;
	n[2]/=n_l;
	//проверка, не лежит ли точка C в плоскости oab
	s_cos=AngleCosBetweenVectors(n,vc);
	if (s_cos==0) { //cos==0 -> угол равен 90 градусам, то есть лежит в плоскости
		printf ("error: pyramid not exist!");
		_getch();
		return (-1);
	}
	else 
	{
	GetSquareAndVolume(va,vb,vc,answer);
		printf ("Surface square: %lf",answer[0]);
		printf ("Volume: %lf",answer[1]);
	}
	
	_getch();
	return 0;
}

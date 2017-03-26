#include "Wizard.h"
#include <iostream>


Wizard::Wizard()
{
	NAME="No name";
	MANA=10;
	HITPOINT=10;
	LEADER=false;
}

Wizard::Wizard(std::string name, int mana, int hitpoint, bool leader)
{
	SetData(name,mana,hitpoint,leader);
}
Wizard::~Wizard() {
}

void Wizard::SetMana (int x) {if (x>=0)  MANA=x; else MANA=0;}
void Wizard::SetHP (int x) {if (x>=0) HITPOINT=x; else HITPOINT=0;}
void Wizard::SetName (std::string x) {NAME=x;}
void Wizard::SetLeadership (bool x) {LEADER=x;}
void Wizard::SetData(std::string name,int mana, int hitpoint, bool leadership) 
{
	NAME=name;
	if (mana<0) mana=0;
	MANA=mana;
	if (hitpoint<0) hitpoint=0;
	HITPOINT=hitpoint;
	LEADER=leadership;
}
	
int Wizard::GetMana() {return MANA;}
int Wizard::GetHP() {return HITPOINT;}
bool Wizard::IsLeader() {return LEADER;}
std::string Wizard::GetName() {return NAME;}
	
void Wizard::ShowInfo () 
{
	std::cout<<"\nName: "+NAME<<std::endl;
	printf("Hitpoints: %i",HITPOINT);
	printf("\nMana points: %i", MANA);
	if (LEADER==true) printf ("\nLeader");
	else printf ("\nNot leader");
}


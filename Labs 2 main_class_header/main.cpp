#include <iostream>
#include "Wizard.h"
#include <string>
using namespace std;
	void GetMostMagician(Wizard *wizards,int count) //with the largest mana reserve
	{
		if (count<=0) return;
		int maxMana=-1;
		int maxManaIndex=-1;
		for (int i=0;i<count;i++)
		{
			if (wizards[i].GetMana()>maxMana)
			{
				maxMana=wizards[i].GetMana();
				maxManaIndex=i;
			}			
		}
		if (maxManaIndex!=-1)
		wizards[maxManaIndex].ShowInfo();
	}
	void FindWizard (string name,Wizard *wizards,int count)
	{
		if (count<=0) return;
		int leaderIndex=-1;
		for (int i=0; i<count;i++)
		{
			if (wizards[i].IsLeader()) leaderIndex=i;
			if (wizards[i].GetName()==name) 
			{
				wizards[i].ShowInfo();
				return;
			}
		}
		if (leaderIndex!=-1) wizards[leaderIndex].ShowInfo();
	}

int main(int argc, char** argv) {
	printf ("enter count: ");
		int count;
		scanf("%i",&count);
		if (count<=0) 
		{
			printf ("incorrect input!");
			return(-1);
		}
		Wizard *TEAM=new Wizard[count];

		printf ("please, enter party data:\n");
		for (int i=0;i<count;i++)
		{
			string name;
			int hp,mana;
			bool leadership;
			printf ("\nWIZARD %i : \n",i+1);
			
			printf("Name: ");
			cin>>name;	
				
			printf("Mana points: ");
			scanf("%i",&mana);	
					
			printf ("Hitpoints: ");
			scanf ("%i",&hp);		
				
			printf("Is leader? (yes/no) ");	
			string x;
			cin>>x;
			if (x=="yes"||x=="true") 
			{
			leadership=true;
			}
			 else leadership=false;
			 
			 TEAM[i].SetData(name,mana,hp,leadership);
		}
		
		printf ("\nThe largest mana reserve: \n");
		GetMostMagician(TEAM,count);
		
		printf ("\n enter name for searching: ");
		string wname;
		cin>>wname;
		printf ("\n");
		FindWizard(wname,TEAM,count);
		
	return 0;
}

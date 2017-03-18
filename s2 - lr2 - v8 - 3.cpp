#include <iostream>
#include <string>
// c++ 11 standart set (compiler options - code generation -language standart) for nullptr that is not using here...
using namespace std;

class Wizard
{
	protected:
	int MANA;
	bool LEADER;
	int HITPOINT;
	string NAME;
	
	public:
	Wizard() {}
	Wizard (string name, int hp, int mana, bool leader)
	{
		NAME=name;
		MANA=mana;
		HITPOINT=hp;
		LEADER=leader;
	}
	~Wizard() { delete this;}
	
	void SetMana (int x) {if (x>=0) MANA=x; else MANA=0;}
	void SetHP (int x) {if (x>=0) HITPOINT=x; else HITPOINT=0;}
	void SetName (string x) {NAME=x;}
	void SetLeadership (bool x) {LEADER=x;}
	
	int GetMana() {return MANA;}
	int GetHP() {return HITPOINT;}
	bool IsLeader() {return LEADER;}
	string GetName() {return NAME;}
	
	void ShowInfo () 
	{
		cout<<"\nName: "+NAME<<endl;
		printf("Hitpoints: %i",HITPOINT);
		printf("\nMana points: %i", MANA);
		if (LEADER==true) printf ("\nLeader");
		else printf ("\nNot leader");
	}
	
	static void GetMostMagician(Wizard *wizards,int count) //with the largest mana reserve
	{
		if (count<=0) return;
		int maxMana=-1;
		int maxManaIndex=-1;
		for (int i=0;i<count;i++)
		{
			if (wizards[i].MANA>maxMana)
			{
				maxMana=wizards[i].MANA;
				maxManaIndex=i;
			}			
		}
		if (maxManaIndex!=-1)
		wizards[maxManaIndex].ShowInfo();
	}
	
	
	 static void FindWizard (string name,Wizard *wizards,int count)
	{
		if (count<=0) return;
		int leaderIndex=-1;
		for (int i=0; i<count;i++)
		{
			if (wizards[i].LEADER) leaderIndex=i;
			if (wizards[i].NAME==name) 
			{
				wizards[i].ShowInfo();
				return;
			}
		}
		if (leaderIndex!=-1) wizards[leaderIndex].ShowInfo();
	}
	
};

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
			printf ("\nWIZARD %i : \n",i+1);
			
			printf("Name: ");
			cin>>name;	
			TEAM[i].SetName(name);
				
			printf("Mana points: ");
			scanf("%i",&mana);	
			TEAM[i].SetMana(mana);
					
			printf ("Hitpoints: ");
			scanf ("%i",&hp);		
			TEAM[i].SetHP(hp);
				
			printf("Is leader? (yes/no) ");	
			string x;
			cin>>x;
			if (x=="yes"||x=="true") 
			{
			TEAM[i].SetLeadership(true);
			}
			 else TEAM[i].SetLeadership(false);
		}
		
		printf ("\nThe largest mana reserve: \n");
		Wizard::GetMostMagician(TEAM,count);
		
		printf ("\n enter name for searching: ");
		string wname;
		cin>>wname;
		printf ("\n");
		Wizard::FindWizard(wname,TEAM,count);
		
	return 0;
}

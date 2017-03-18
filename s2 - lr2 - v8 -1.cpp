#include <iostream>
#include <string>

using namespace std;

const int WIZARD_COUNT=3;
		int leaderIndex=-1;
		
		struct WIZARD {
		public:
			int MANA;
			bool LEADER;
			int HITPOINT;
			string NAME;
		};
		WIZARD *TEAM;
		
inline void ShowWizardInfo (int index)
{
	cout<<"\nName: "+TEAM[index].NAME<<endl;
	printf ("Mana points: %i",TEAM[index].MANA);
	printf ("\nHitpoints: %i",TEAM[index].HITPOINT);
	if (TEAM[index].LEADER==true) printf ("\nLeader");
	else printf ("\nNot leader");
}

int main(int argc, char** argv) {

		
		TEAM=new WIZARD[WIZARD_COUNT];
		int maxMana=-1; int maxManaIndex=-1;
		
		//check incorrect data?
		printf ("please, enter party data:\n");
		for (int i=0;i<WIZARD_COUNT;i++)
		{
			printf ("\nWIZARD %i : \n",i+1);
			
			printf("Name: ");
			cin>>TEAM[i].NAME;
			
			printf("Mana points: ");
			int mp=0;
			scanf("%i",&mp);
			if (mp<=0) TEAM[i].MANA=0;
			else TEAM[i].MANA=mp;
			if (mp>maxMana) 
			{
				maxMana=mp;
				maxManaIndex=i;
			}
			
			printf ("Hitpoints: ");
			scanf ("%i",&TEAM[i].HITPOINT);
			
			printf("Is leader? (yes/no) ");	
			string x;
			cin>>x;
			if (x=="yes"||x=="true") 
			{
			TEAM[i].LEADER=true;
			leaderIndex=i;
			}
			 else TEAM[i].LEADER=false;
		}
		
		if (maxManaIndex!=-1)
		{
			printf ("\nWizard %i have largest reserve of mana: %i points", maxManaIndex+1, maxMana);
		}	
		
		printf ("\nEnter name for searching: ");
		string nm;
		cin>>nm;
		int searchingIndex=-1;
		for (int i=0; i<WIZARD_COUNT;i++)
		{
			if (TEAM[i].NAME.compare(nm)==0)
			{
				searchingIndex=i;
				break;
			}
		}
		if (searchingIndex!=-1)
		{
			ShowWizardInfo(searchingIndex);
		}
		else
		{
			printf ("Wizard not found. Showing party leader info...");
			if (leaderIndex!=-1)
			{
				ShowWizardInfo(leaderIndex);
			}
			else
			{
				printf("Leader not found.");
			}
		}
	return 0;
}

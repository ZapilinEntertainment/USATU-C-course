#ifndef WIZARD_H
#define WIZARD_H
#include <string>
class Wizard
{
	public:
		Wizard ();
		Wizard (std::string name, int mana, int hitpoint, bool leader);
		void ShowInfo();
		~Wizard();
		
	void SetMana (int);
	void SetHP (int);
	void SetName (std::string);
	void SetLeadership (bool);
	void SetData(std::string,int,int,bool);
	
	int GetMana() ;
	int GetHP();
	bool IsLeader();
	std::string GetName() ;
		
	protected:
	std::string NAME;
	int MANA;
	int HITPOINT;
	bool LEADER;
};

#endif

/*
#include <iostream>
#include <string>
#include "Noble.h"
#include "Warrior.h"
using namespace std;
namespace WarriorCraft {
	Warrior::Warrior(const string& name, int strength) : warrior_name(name), warrior_strength(strength) {}
	//get strength
	int Warrior::get_strength()const {
			return warrior_strength;
		}
	//get name
	string Warrior::get_name()const  {
			return warrior_name;
		}
	//change the strength
	void Warrior::change_strength(int ratio) {
			warrior_strength -= ratio;
		}
	//assign a noble
	void Warrior::assign(Noble* mynoble) {
		my_noble = mynoble;
	}
	//kill warrior
	void Warrior::dead_warrior() {
			warrior_strength = 0;
		}
	//Warrior runs
	void Warrior::runaway() {
		my_noble->warrior_ran(*this);
		my_noble = nullptr;
	}
	ostream& operator<<(ostream& os, const Warrior& rhs) {
		os << rhs.warrior_name << ": " << rhs.warrior_strength << endl;
		return os;
	}
}
*/
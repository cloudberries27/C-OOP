/*#include <iostream>
#include <string>
#include <vector>
#include "Warrior.h"
#include "Noble.h"
using namespace std;

namespace WarriorCraft {
		//with name and army of warriors and status of life
		Noble::Noble(const string& _name) : name(_name) {}
		//check if dead?
		bool Noble::is_dead() {
			return dead_or_alive;
		}
		//add warriors to vector
		bool Noble::hire(Warrior& warrior) {
			vector_of_warriors.push_back(&warrior);
			warrior.assign(this);
			return true;
		}
		//Warrior ran away
		void Noble::warrior_ran(Warrior& warrior) {
			std::cout << warrior.get_name() << " runs away.\n";
			for (size_t i = 0; i < vector_of_warriors.size(); i++) {
				if (vector_of_warriors[i]->get_name() == warrior.get_name()) {
					//tried to move pointer over
					vector_of_warriors[i] = vector_of_warriors.back();
					vector_of_warriors.pop_back();
				}
			}
		}
		//finds and removes them from the vector
		bool Noble::fire(Warrior& warrior) {
			if (!is_dead()) {
				cout << warrior.get_name() << " you're fired!" << endl;
				for (size_t i = 0; i < vector_of_warriors.size(); i++) {
					if (vector_of_warriors[i]->get_name() == warrior.get_name()) {
						//tried to move pointer over
						vector_of_warriors[i] = vector_of_warriors.back();
						vector_of_warriors.pop_back();
					}
				}
				return true;
			}
			return false;
		}
		//adds the strength of all warriors
		int Noble::warriors_strength_combined() {
			int combined = 0;
			for (size_t i = 0; i < vector_of_warriors.size(); i++) {
				combined += vector_of_warriors[i]->get_strength();
			}
			return combined;
		}
		//nobles battle
		void Noble::battle(Noble& noble) {
			cout << name << " battles " << noble.name << endl;
			//if neither one is dead...
			if (warriors_strength_combined() != 0 && noble.warriors_strength_combined() != 0) {
				//is this noble has greater strength...
				if (warriors_strength_combined() > noble.warriors_strength_combined()) {
					cout << name << " defeats " << noble.name << endl;
					//find ratio
					int ratio = (warriors_strength_combined() / noble.warriors_strength_combined());
					//kill all of that nobles warriors
					for (size_t i = 0; i < noble.vector_of_warriors.size(); i++) {
						noble.vector_of_warriors[i]->dead_warrior();
					}
					//and subtract ratio from strength of this noble
					for (size_t i = 0; i < vector_of_warriors.size(); i++) {
						vector_of_warriors[i]->change_strength(ratio);
					}
					//that noble is dead
					noble.dead_or_alive = false;
				}
				//if that noble has greater strength...
				else if (warriors_strength_combined() < noble.warriors_strength_combined()) {
					cout << noble.name << " defeats " << name << endl;
					//find ratio
					int ratio = (noble.warriors_strength_combined() / warriors_strength_combined());
					//kill all of this nobles warriors
					for (size_t i = 0; i < vector_of_warriors.size(); i++) {
						vector_of_warriors[i]->dead_warrior();
					}
					//subtract that nobles warrior's strength
					for (size_t i = 0; i < noble.vector_of_warriors.size(); i++) {
						noble.vector_of_warriors[i]->change_strength(ratio);
					}
					//this noble is dead
					dead_or_alive = false;
				}
				//if they have the same strength...
				else if (warriors_strength_combined() == noble.warriors_strength_combined()) {
					cout << "Mutual Annihilation: " << name << " and " << noble.name << " dies at each other's hands" << endl;
					//they both die
					noble.dead_or_alive = false;
					dead_or_alive = false;
				}
			}
			//this noble is dead
			else if (warriors_strength_combined() == 0) {
				cout << "He's dead " << noble.name << endl;
			}
			//that noble is dead
			else if (noble.warriors_strength_combined() == 0) {
				cout << "He's dead " << name << endl;
			}
			//they are both dead...
			else {
				cout << "Oh, NO! They're both dead! Yuck!" << endl;
			}

		}

	ostream& operator<<(ostream& os, const Noble& rhs) {
		os << rhs.name << " has an army of " << rhs.vector_of_warriors.size() << endl;
		//prints out the warriors in army
		for (size_t i = 0; i < rhs.vector_of_warriors.size(); i++) {
			os << *(rhs.vector_of_warriors[i]) << endl;
		}
		return os;
	}
}
*/
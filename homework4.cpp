/*Claudia Rodriguez
HW 4: Nobles have Warriors

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Warrior {
public:
	Warrior(const string& name, int strength) : name(name), strength(strength), status(false) {}
	void display() const {
		cout << "\t" << name << " : " << strength << endl;
	}
	bool getStatus() const { return status; }
	int getStrength() const { return strength; }
	string getName() const { return name; }
	void changeStatus(bool tr) { status = tr; }
	void deadWarrior() { strength = 0; }
	void changeStrength(int ratio) { strength -= ratio; }
private:
	const string name;
	int strength;
	bool status;
};

class Noble {
public:
	Noble(const string& name) : name(name), status(true) {}
	bool hire(Warrior& warrior) {
		//if warrior unemployed and noble alive...
		if (!warrior.getStatus() && status) {
			Warrior* owarrior = &warrior;
			vWarrior.push_back(owarrior);
			owarrior->changeStatus(true);
			return true;
		}
		return false;
	}
	void display() const {
		cout << name << " has an army of " << vWarrior.size() << endl;
		//prints out the warriors in army
		for (size_t i = 0; i < vWarrior.size(); i++) { vWarrior[i]->display(); }
	}
	bool fire(Warrior& warrior) {
		if (status) {
			cout << warrior.getName() << ", you're fired! -- " << name << endl;
			int index = 0;
			//loops over vector to find warrior
			for (size_t i = 0; i < vWarrior.size(); i++) {
				if (vWarrior[i]->getName() == warrior.getName()) {
					index = i;
					vWarrior[i]->changeStatus(false);
					break;
				}
			}
			//loops over the vector starting at the index
			while (index < vWarrior.size()) {
				if (index == vWarrior.size() - 1) {
					vWarrior.pop_back();
				}
				else { vWarrior[index] = vWarrior[index + 1]; }
				index++;
			}
			return true;
		}
		return false;
	}
	void battle(Noble& anoble) {
		cout << name << " battles " << anoble.name << endl;
		//if neither one is dead...
		if (status == true && anoble.status == true) {
			//this noble is stronger
			if (combined() > anoble.combined()) {
				cout << name << " defeats " << anoble.name << endl;
				//find ratio
				int ratio = (combined() / anoble.combined());
				//kill all of that nobles warriors
				for (size_t i = 0; i < anoble.vWarrior.size(); i++) {
					anoble.vWarrior[i]->deadWarrior();
				}
				//and subtract ratio from strength of this noble
				for (size_t i = 0; i < vWarrior.size(); i++) {
					vWarrior[i]->changeStrength(ratio);
				}
				anoble.status = false;
			}
			//that noble is stronger
			else if (combined() < anoble.combined()) {
				cout << anoble.name << " defeats " << name << endl;
				//find ratio
				int ratio = (anoble.combined() / combined());
				//kill all of that nobles warriors
				for (size_t i = 0; i < vWarrior.size(); i++) {
					vWarrior[i]->deadWarrior();
				}
				//and subtract ratio from strength of this noble
				for (size_t i = 0; i < anoble.vWarrior.size(); i++) {
					anoble.vWarrior[i]->changeStrength(ratio);
				}
				status = false;
			}
			//if they have the same strength...
			else if (combined() == anoble.combined()) {
				cout << "Mutual Annihilation: " << name << " and " << anoble.name << " die at each other's hands" << endl;
				//they both die
				anoble.status = false;
				status = false;
				//warriors die
				for (size_t i = 0; i < anoble.vWarrior.size(); i++) {
					anoble.vWarrior[i]->deadWarrior();
				}
				for (size_t i = 0; i < vWarrior.size(); i++) {
					vWarrior[i]->deadWarrior();
				}
			}
		}
		else if (status == false && anoble.status == false) { cout << "Oh, NO! They're both dead! Yuck!" << endl; }
		else if (status == false) { cout << "He's dead " << anoble.name << endl; }
		else if (anoble.status == false) { cout << "He's dead " << name << endl; }
	}
	//adds the strength to find the ratio
	int combined() const {
		int combined = 0;
		for (size_t i = 0; i < vWarrior.size(); i++) {
			combined += vWarrior[i]->getStrength();
		}
		return combined;
	}
private:
	const string name;
	vector <Warrior*> vWarrior;
	bool status;
};

int main() {
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);
}*/
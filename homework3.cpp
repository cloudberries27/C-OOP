/*Claudia Rodriguez
HW 3: Warriors with Weapons

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Warrior {
	class Weapon {
	public:
		Weapon(const string& wname, int strength) : name(wname), strength(strength) {}
		void display() const {
			cout << ", Weapon: " << name << ", " << strength << endl;
		}
		int getStrength() const { return strength; }
		void changeStrength(int num) { strength -= num; }
		void killWeapon() { strength = 0; }
	private:
		const string name;
		int strength;
	};
public:
	Warrior(const string& name, const string& wname, int strength) : name(name), weapon(wname, strength) {}
	string getName() const { return name; }
	void display() const {
		cout << "Warrior: " << name;
		weapon.display();
	}
	void battle(Warrior& oWarrior) {
		cout << name << " battles " << oWarrior.getName() << endl;
		//if warrior1 is stronger
		if (weapon.getStrength() > oWarrior.weapon.getStrength()) {
			if (oWarrior.weapon.getStrength() != 0) {
				cout << name << " defeats " << oWarrior.getName() << endl;
				weapon.changeStrength(oWarrior.weapon.getStrength());
				oWarrior.weapon.killWeapon();
			}
			else {
				cout << "He's dead, " << name << endl;
			}
		}
		//if warrior 2 is stronger
		else if (weapon.getStrength() < oWarrior.weapon.getStrength()) {
			if (weapon.getStrength() != 0) {
				cout << oWarrior.getName() << " defeats " << name << endl;
				oWarrior.weapon.changeStrength(weapon.getStrength());
				weapon.killWeapon();
			}
			else {
				cout << "He's dead, " << oWarrior.getName() << endl;
			}
		}
		//If they are both of equal strength
		else if (weapon.getStrength() == oWarrior.weapon.getStrength()) {
			if (weapon.getStrength() != 0 &&  oWarrior.weapon.getStrength() != 0) {
				cout << "Mutual Annihilation: " << oWarrior.getName() << " and " << name << " die at each other's hands" << endl;
				weapon.killWeapon();
				oWarrior.weapon.killWeapon();
			}
			else {
				cout << "Oh, NO! They're both dead! Yuck!" << endl;
			}
		}
	}
private:
	const string name;
	Weapon weapon;
};

int main() {
	ifstream wartxt("warriors2.txt");
	if (!wartxt) {
		cerr << "Can't load from warriors.txt" << endl;
		exit(1);
	}
	vector <Warrior> vwarriors;
	string command, name, wname;
	int strength;
	while (wartxt >> command) {
		if (command == "Warrior") {
			wartxt >> name >> wname >> strength;
			Warrior wblock(name, wname, strength);
			vwarriors.push_back(wblock);
		}
		else if (command == "Status") {
			cout << "There are " << vwarriors.size() << " warriors" << endl;
			for (int i = 0; i < vwarriors.size(); i++) {
				vwarriors[i].display();
			}
		}
		else if (command == "Battle") {
			string name1, name2;
			wartxt >> name1 >> name2;
			int index1, index2;
			//finds warriors and stores the index
			for (int x = 0; x < vwarriors.size(); x++) {
				if (vwarriors[x].getName() == name1) { index1 = x; }
				else if (vwarriors[x].getName() == name2) { index2 = x; }
			}
			//sends them to battle
			vwarriors[index1].battle(vwarriors[index2]);
		}
	}
	wartxt.close();
	string done;
	cin >> done;
}
*/

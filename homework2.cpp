/* Claudia Rodriguez
HW 2: read a file of warriors and have them battle

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Warrior {
	string name;
	int strength;
};

void printWarriors(const vector <Warrior>& vWarriors) {
	cout << "There are: " << vWarriors.size() << " warriors" << endl;
	for (Warrior wblock : vWarriors) {
		cout << "Warrior: " << wblock.name << ", strength: " << wblock.strength << endl;

	}
}

void warriorsBattle(Warrior& warrior1, Warrior& warrior2) {
	cout << warrior1.name << " battles " << warrior2.name << endl;
	if (warrior1.strength == 0 && warrior2.strength == 0) {
		cout << "Oh, NO! They're both dead! Yuck!" << endl;
	}
	else if (warrior1.strength == warrior2.strength) {
		warrior1.strength = 0;
		warrior2.strength = 0;
		cout << "Mutual Annihalation: " << warrior1.name << " and " 
			<< warrior2.name << " die at each other's hands" << endl;
	}
	else if (warrior1.strength == 0) { cout << "He's dead, " << warrior2.name << endl; }
	else if (warrior2.strength == 0) { cout << "He's dead, " << warrior1.name << endl; }
	else if (warrior1.strength > warrior2.strength){
		warrior1.strength -= warrior2.strength;
		warrior2.strength = 0;
		cout << warrior1.name << " defeats " << warrior2.name << endl;
	}
	else if (warrior1.strength < warrior2.strength) {
		warrior2.strength -= warrior1.strength;
		warrior1.strength = 0;
		cout << warrior2.name << " defeats " << warrior1.name << endl;
	}
}

int main() {
	ifstream wartxt("warriors.txt");
	if (!wartxt) {
		cerr << "Could not open file\n";
		exit(1);
	}
	string command;
	vector <Warrior> vWarriors;
	while (wartxt >> command) {
		if (command == "Warrior"){
			Warrior nWarrior;
			wartxt >> nWarrior.name;
			wartxt >> nWarrior.strength;
			vWarriors.push_back(nWarrior);
		}
		else if (command == "Battle") {
			string name1, name2;
			int index1, index2;
			wartxt >> name1 >> name2;
			for (int x = 0; x < vWarriors.size(); x++) {
				if (vWarriors[x].name == name1) { index1 = x; }
				else if (vWarriors[x].name == name2) { index2 = x; }
			}
			warriorsBattle(vWarriors[index1], vWarriors[index2]);
		}
		else if (command == "Status") { printWarriors(vWarriors);}
	}
	wartxt.close();
}*/

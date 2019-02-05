/*#ifndef NOBLE_H
#define NOBLE_H
#include <string>
#include <vector>

//DEFINITION
namespace WarriorCraft {

	class Warrior;

	class Noble {
		friend std::ostream& operator<<(std::ostream& os, const Noble& rhs);
	public:
		Noble(const std::string& name);
		bool is_dead();
		bool hire(Warrior& warrior);
		void warrior_ran(Warrior& warrior);
		bool fire(Warrior& warrior);
		int warriors_strength_combined();
		void battle(Noble& noble);

	private:
		std::string name;
		std::vector <Warrior*> vector_of_warriors;
		bool dead_or_alive = true;
	};
}
#endif
*/
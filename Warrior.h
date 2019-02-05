/*#ifndef WARRIOR_H
#define WARRIOR_H
#include <string>

//DEFINITION
namespace WarriorCraft {
	class Noble;

	class Warrior {
		friend std::ostream& operator<<(std::ostream& os, const Warrior& rhs);
	public:
		Warrior(const std::string& name, int strength);
		int get_strength() const;
		std::string get_name() const;
		void change_strength(int ratio);
		void dead_warrior();
		void assign(Noble* mynoble);
		void runaway();
	private:
		std::string warrior_name;
		int warrior_strength;
		Noble* my_noble;
	};
}
#endif
*/
#include <string>
#include <set>

using namespace std;

class Player
{
private:
	int jersey_number;
	string name;
	set<string> positions;

public:
	Player();
	Player(int number, string name);

	int get_number() { return jersey_number; }
	string get_name() { return name; }
	bool is_empty();
	void set_number();
	bool check_number(int);
	void set_name();
	void add_positions();
	void change_positions();
	void empty_data();
	void display_positions();
	void display_player();
};
#include "Player.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <set>

Player::Player()
{
	jersey_number = 0;
	name = "";
}

/*
* 
* This constructor is commented out because it's not called anywhere.  The reason
* I still have it is because I was using it to run some test cases.
* 
Player::Player(int number, string name)
{
	jersey_number = number;
	this->name = name;
}
*/

bool Player::is_empty()
{
	if (jersey_number == 0 && name == "")
	{
		return true;
	}

	return false;
}

//This function will only give the player a jersey number that is between
//1-99.  Anything outside of that will return a false and we have to go
//through the process again.

void Player::set_number()
{
	int number;
	bool invalid = true;
	while (invalid)
	{
		cout << "Enter the jersey number: ";
		cin >> number;

		if (check_number(number))
		{
			invalid = false;
		}
	}

	jersey_number = number;
}

bool Player::check_number(int number)
{
	if (0 < number < 100)
	{
		return true;
	}

	cout << "That isn't a valid jersey number.\n";
	return false;
}

void Player::set_name()
{
	cout << "Enter name of player: ";
	cin.ignore();
	getline(cin, name);
}

void Player::add_positions()
{
	int position_number;
	cout << "Here are the positions you can add.\n";
	cout << "1 - Quarterback\n";
	cout << "2 - Running Back\n";
	cout << "3 - Wide Receiver\n";
	cout << "4 - Tight End\n";
	cout << "5 - Linebacker\n";
	cout << "6 - Defensive Back\n";
	cout << "7 - Offensive Lineman\n";
	cout << "8 - Defensive Lineman\n";
	cout << "9 - Special Teams\n";

	cout << "Enter a number: ";
	cin >> position_number;

	switch (position_number)
	{
		case 1:
			positions.insert("QB");
			cout << "QB added!";
			break;

		case 2:
			positions.insert("RB");
			cout << "RB added!";
			break;

		case 3:
			positions.insert("WR");
			cout << "WR added!";
			break;

		case 4:
			positions.insert("TE");
			cout << "TE added!";
			break;

		case 5:
			positions.insert("LB");
			cout << "LB added!";
			break;

		case 6:
			positions.insert("DB");
			cout << "DB added!";
			break;

		case 7:
			positions.insert("OL");
			cout << "OL added!";
			break;

		case 8:
			positions.insert("DL");
			cout << "DL added!";
			break;

		case 9:
			positions.insert("K");
			cout << "K added!";
			break;

		default:
			cout << "That response doesn't work.\n\n";
			break;
	}

	cout << endl;
}

//This will either add or remove a player's position from their
//"positions" set.

void Player::change_positions()
{
	int choice;
	cout << "Would you like to add or remove positions?\n";
	cout << "1 - Add\n";
	cout << "2 - Remove\n";
	cout << "0 - Cancel\n";

	cout << "Choose an option: ";
	cin >> choice;

	switch (choice)
	{
		case 1:
			add_positions();
			break;

		case 2:
		{
			string pos;
			cout << "These are the player's positions: ";
			display_positions();

			cout << "Which one would you like to remove? ";
			cin >> pos;

			positions.erase(pos);
			break;
		}

		case 0:
			break;

		default:
			cout << "Invalid input\n";
			break;
	}
}

void Player::empty_data()
{
	jersey_number = 0;
	name = "";
	positions.clear();
}

void Player::display_positions()
{
	bool first_one = true;
	for (string pos : positions)
	{
		if (!first_one)
		{
			cout << " / ";
		}
		cout << pos;

		first_one = false;
	}

	cout << endl;
}

void Player::display_player()
{
	cout << "# " << setw(2) << right << jersey_number;
	cout << " | " << setw(30) << left << name << " | ";
	display_positions();
}
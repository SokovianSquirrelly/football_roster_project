// FootballRosterProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "Player.h"

using namespace std;

int main()
{
    Player players[100];
    bool done = false;

    cout << "Welcome to the team tracker!\n\n";

    do
    {
        int choice;

        cout << "Please pick an option.\n";
        cout << "1 - Add a Player\n";
        cout << "2 - Edit a Player\n";
        cout << "3 - Remove a Player\n";
        cout << "4 - Display Team Roster\n";
        cout << "0 - Quit\n";

        cout << "Enter your option: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Add a Player
        {
            Player player = Player();
            player.set_number();

            //Each player must have their own unique jersey.  This checks to
            //make sure we don't get a duplicate jersey.

            if (!players[player.get_number()].is_empty())
            {
                cout << "That jersey number is already taken.\n";
            }
            else
            {
                //This checks to make sure the player's name hasn't already
                //been put in the system with another jersey.  If there are
                //no duplicates, we put in one of the player's positions
                //and add them to the array.

                bool duplicate = false;
                player.set_name();

                for (Player teammate : players)
                {
                    if (player.get_name() == teammate.get_name())
                    {
                        cout << "That player is already on the roster.\n";
                        duplicate = true;
                    }
                }

                if (!duplicate)
                {
                    cout << endl;
                    player.add_positions();
                    int j_number = player.get_number();
                    players[j_number] = player;
                }
            }

            cout << endl;

            break;
        }

        case 2: //Edit a Player
        {
            int number = 0;
            cout << "Enter the jersey number of the player you'd like to edit: ";
            cin >> number;

            if (players[number].is_empty())
            {
                cout << "There's no player with that jersey number.\n";
            }

            else
            {
                int edit_choice = 0;
                Player edited_player = players[number];

                cout << "\nSelect what info you'd like to edit.\n";
                cout << "1 - Jersey Number\n";
                cout << "2 - Name of Player\n";
                cout << "3 - Positions\n";

                cout << ">> ";
                cin >> edit_choice;

                switch (edit_choice)
                {
                case 1:  //Jersey Number

                    //When a jersey number is successfully changed, the player's
                    //info will actually be moved to another index in players.
                    //That index corresponds with the player's jersey number.

                    edited_player.set_number();

                    if (players[edited_player.get_number()].is_empty())
                    {
                        players[edited_player.get_number()] = edited_player;
                        players[number].empty_data();
                        cout << "Jersey number successfully edited.\n";
                    }
                    else
                    {
                        cout << "That jersey is already taken.\n";
                    }

                    break;

                case 2:  //Name of Player
                {
                    bool duplicate = false;
                    edited_player.set_name();

                    for (Player teammate : players)
                    {
                        if (teammate.get_number() != edited_player.get_number())
                        {
                            if (teammate.get_name() == edited_player.get_name())
                            {
                                duplicate = true;
                            }
                        }
                    }

                    if (duplicate)
                    {
                        cout << "That player already has their own jersey.\n";
                    }
                    else
                    {
                        players[number] = edited_player;
                    }

                    break;
                }

                case 3:  //Positions
                    players[number].change_positions();
                    break;

                default:
                    cout << "Invalid input\n";
                    break;
                }
            }

            cout << endl;

            break;
        }

        case 3: //Remove a Player
        {
            int number;
            cout << "Enter the jersey number of the player you'd like to remove: ";
            cin >> number;

            if (!players[number].is_empty())
            {
                cout << players[number].get_name() << " (#"
                    << players[number].get_number() << ") has been removed.\n\n";

                players[number].empty_data();
            }
            else
            {
                cout << "There are no players with that jersey number.\n\n";
            }

            break;
        }

        case 4:  //Display Entire Roster
            cout << "\n                     Name              Positions\n";
            for (Player teammate : players)
            {
                if (!teammate.is_empty())
                {
                    teammate.display_player();
                }
            }

            cout << endl;

            break;

        case 0:
            done = true;
            break;

        default:
            cout << "Invalid response.\n\n";
            break;
        }

    } while (!done);

    return 0;
}
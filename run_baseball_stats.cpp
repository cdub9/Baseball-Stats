/*
Coleman Warren, Section 8, CS 142 Fall 2016 Midterm 2
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "team.h"

using namespace std;

const int TEAM1 = 1;
const int TEAM2 = 2;
const int BATTING_ORDER_SIZE = 9;

// Menu selection options
const int RUN = 1;
const int HIT = 2;
const int AT_BAT = 3;
const int ADVANCE_BATTER = 4;
const int SUBSTITUTION = 5;
const int SWITCH_TEAM = 6;
const int QUIT = 7;


string get_team_name(int team_number) {
	string team_name;
	cout << "Enter Team " << team_number << "'s name: ";
	getline(cin, team_name);

	return team_name;
}

void get_batting_order(vector<string>& batters, string team_name) {
	for (int i = 1; i <= BATTING_ORDER_SIZE; i++) {
		string batter;
		cout << "Enter " << team_name << " batter " << i << ": ";
		getline(cin, batter);
		batters.push_back(batter);
	}
}

int get_menu_selection() {
	int selection = -1;
	bool valid_input = false;

	while (!valid_input) {
		cout << "* * * MENU * * *" << endl;
		cout << "1 - Add a run" << endl;
		cout << "2 - Add a hit" << endl;
		cout << "3 - Add an at-bat" << endl;
		cout << "4 - Advance the batting order" << endl;
		cout << "5 - Make a substitution in the batting order" << endl;
		cout << "6 - Switch batting team" << endl;
		cout << "7 - Exit and print final stats" << endl;

		cin >> selection;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input, please try again" << endl;
		}
		else if (selection < 1 || selection > 7) {
			cout << "Please enter a number between 1 and 7." << endl;
		}
		else {
			valid_input = true;
		}
	}
	return selection;
}

void make_substitution(Team& current_team) {
	string previous_player;
	string current_player;

	cout << "Who would you like to replace? ";
	cin >> previous_player;

	cout << "Who will take their place? ";
	cin >> current_player;

	current_team.make_batting_substitution(previous_player, current_player);
}

void run_baseball_stats(Team team1, Team team2) {
	int current_team = TEAM1;
	int menu_selection = -1;

	while (menu_selection != QUIT) {

		cout << "Current team: " << (current_team == TEAM1 ? team1.get_name() : team2.get_name()) << endl;
		menu_selection = get_menu_selection();

		if (menu_selection == RUN) {
			current_team == TEAM1 ? team1.add_run() : team2.add_run();
		}
		else if (menu_selection == HIT) {
			current_team == TEAM1 ? team1.add_hit() : team2.add_hit();
		}
		else if (menu_selection == AT_BAT) {
			current_team == TEAM1 ? team1.add_at_bat() : team2.add_at_bat();
		}
		else if (menu_selection == ADVANCE_BATTER) {
			current_team == TEAM1 ? team1.advance_batter() : team2.advance_batter();
		}
		else if (menu_selection == SUBSTITUTION) {
			current_team == TEAM1 ? make_substitution(team1) : make_substitution(team2);
		}
		else if (menu_selection == SWITCH_TEAM) {
			current_team = current_team == TEAM1 ? TEAM2 : TEAM1;
		}

		cout << endl;
		current_team == TEAM1 ? team1.print_stats() : team2.print_stats();
		cout << endl;
	}
	current_team == TEAM1 ? team2.print_stats() : team1.print_stats();
}


int main() {
	string team1_name; // name of team 1
	string team2_name; // name of team 2
	vector<string> team1_order; // batting order for team 1
	vector<string> team2_order; // batting order for team 2

	cout << "Welcome to Baseball Stats!" << endl;

	team1_name = get_team_name(TEAM1);
	get_batting_order(team1_order, team1_name);

	team2_name = get_team_name(TEAM2);
	get_batting_order(team2_order, team2_name);
	
	Team team1(team1_name, team1_order);
	Team team2(team2_name, team2_order);

	run_baseball_stats(team1, team2);

	system("pause");
	return 0;
}
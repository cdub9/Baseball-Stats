/*
	This file shows the implementation of the member functions for the Team class
*/
#include "team.h"
#include <iostream>

using namespace std;

Team::Team(string name, vector<string> batting_order)
{
	this->batting_order = BattingOrder(batting_order);
	team_name = name;
}

void Team::add_run()
{
	runs++;
}

void Team::add_hit()
{
	hits++;
}

void Team::add_at_bat()
{
	at_bats++;
}

void Team::advance_batter()
{
	batting_order.advance_batter();
}

void Team::make_batting_substitution(string previous_player, string new_player)
{
	batting_order.make_substitution(previous_player, new_player);
}

string Team::get_name() const
{
	return team_name;
}

double batting_average(int hits, double at_bats)
{
	if (at_bats > 0) {
		cout << fixed << setprecision(3);
		double team_batting_average = hits / at_bats;
		return team_batting_average;
	}
	else {
		return 0;
	}
}

void Team::print_stats()
{
	cout << "Team: " << team_name << endl;
	cout << "Runs: " << runs << endl;
	cout << "Hits: " << hits << endl;
	cout << "At-bats: " << at_bats << endl;
	cout << "Batting Average: " << batting_average(hits, at_bats) << endl;
    cout << "Batting Order: ";
    batting_order.print_batting_order();
    cout << endl;
    current_batter = batting_order.get_current_batter();
	cout << "Up to Bat: " << current_batter << endl;
}
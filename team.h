/*
    This file shows the member functions available through the Team class, as well as defines the data members to be used privately within its member functions.
*/
#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "BattingOrder.h"
using namespace std;

/**
	A baseball team roster
*/

class Team
{
public:
	/*
		Constructs a team with the given name and batting order
	*/
	Team(string name, vector<string> batting_order);

	/*
		Increments the number of runds for a team by 1
	*/
	void add_run();

	/*
		Increments the number of hits for a team by 1
	*/
	void add_hit();

	/*
		Increments the number of at-bats for a team by 1
	*/
	void add_at_bat();

	/*
		Changes the player up to bat to the next player in the batting order
	*/
	void advance_batter();

	/*
		Removes "previous_player" from the batting order and adds "new_player" in that spot
	*/
	void make_batting_substitution(string previous_player, string new_player);

	/*
		Returns the name of the team
	*/
	string get_name() const;

	/*
	Calculates batting average
	*/
	//double batting_average(int hits, int at_bats);

	/*
		Prints the team stats to the console
	*/
	void print_stats();

private:
	string team_name;
	BattingOrder batting_order;
	int runs;
	int hits;
	double at_bats;
	string previous_player;
	string new_player;
    string current_batter;
	double team_batting_average;
};
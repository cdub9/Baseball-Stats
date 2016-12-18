/*
    This file shows the member functions available through the BattingOrder class, as well as defines the data members to be used privately within its member functions.
*/
#pragma once
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/**
	The batting order for the teams
*/

class BattingOrder
{
public:
	/*
		Sets the batting order
	*/
	BattingOrder(vector<string> batting_order);

	/*
		Default constructor
	*/
	BattingOrder();

	/*
		Removes "previous_player" from the batting order and adds "new_player" in that spot
	*/
	void make_substitution(string previous_player, string new_player);

	/*
		Changes the player up to bat to the next player in the batting order
	*/
	void advance_batter();

	/*
		Returns the name of the player who is up to bat
	*/
	string get_current_batter();

	/*
		Prints the batting order
	*/
	void print_batting_order();

private:
	vector<string> batting_order;
	string previous_player;
	string new_player;
	int up_to_bat;
};
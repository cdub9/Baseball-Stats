/*
    This file shows the implementation of the member functions of the BattingOrder class
*/
#include <iostream>
#include "BattingOrder.h"

using namespace std;

BattingOrder::BattingOrder(vector<string> batting_order)
{
    up_to_bat = 0;
	this->batting_order = batting_order;
}

BattingOrder::BattingOrder()
{

}

void BattingOrder::make_substitution(string previous_player, string new_player)
{
    for (int i = 0; i < batting_order.size(); i++) {
        if (previous_player == batting_order[i]) {
            batting_order[i] = new_player;
        }
    }
}

void BattingOrder::advance_batter()
{
    if (up_to_bat == batting_order.size()) {
        up_to_bat = 0;
    }
    else {
        up_to_bat++;
    }
}

string BattingOrder::get_current_batter()
{
    return batting_order[up_to_bat];
}

void BattingOrder::print_batting_order()
{
    for (int i = 0; i < batting_order.size(); i++) {
        if (i > 0) {
            cout << ", " << batting_order[i];
        }
        else {
            cout << batting_order[i];
        }
    }
}
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "bag.h"

using namespace std;

void Print_Vector(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}

int main(){
    cout << "What are the initial hand sizes? ";
    int hand_size;
    cin >> hand_size;

    srand(time(0));

    
    Bag<int> Hand_P1; // Player 1 - Initial Hand 

    for(int i = 0; i < hand_size; i++){
        int element = rand() % 13 + 1;
        Hand_P1.insert(element);
    }

    
    Bag<int> Hand_P2; // Player 2 - Initial Hand

    for(int i = 0; i < hand_size; i++){
        int element = rand() % 13 + 1;
        Hand_P2.insert(element);
    }

    Bag<int> reward_pile; // Reward Pile

    int n = 0; // Round number

    while(!Hand_P1.is_empty() && !Hand_P2.is_empty()){ // Both players have cards in hand
        n = n + 1;
        cout << "Round " << n << endl;

        cout << "Player 1 hand: "; // Player 1 : Current hand
        Print_Vector(Hand_P1.toVector());

        cout << endl << "Player 2 hand: "; // Player 2 : Current hand
        Print_Vector(Hand_P2.toVector());

        // Choosing one card each from both player's current hand, adding them to reward pile, and removing them from the current hand
        int card_P1;
        Hand_P1.choose(card_P1);
        reward_pile.insert(card_P1);
        Hand_P1.remove(card_P1);

        int card_P2;
        Hand_P2.choose(card_P2);
        reward_pile.insert(card_P2);
        Hand_P2.remove(card_P2);

        if(card_P1 > card_P2){ // Player 1 wins
            cout << endl << "Player 1 wins " << card_P1 << " to " << card_P2 << endl;
            // Emptying all elements of the reward pile to Player 1's current hand
            while(!reward_pile.is_empty()){
                int reward;
                reward_pile.choose(reward);
                Hand_P1.insert(reward);
                reward_pile.remove(reward);
            }
        }
        else if(card_P1 < card_P2){ // Player 2 wins
            cout << endl << "Player 2 wins " << card_P2 << " to " << card_P1 << endl;
            // Emptying all elements of the reward pile to Player 2's current hand
            while(!reward_pile.is_empty()){
                int reward;
                reward_pile.choose(reward);
                Hand_P2.insert(reward);
                reward_pile.remove(reward);
            }
        }
        else{ // Both players have the same card so it is a tie
            cout << endl <<  "WAR!!! Both players have " << card_P1 << endl;

            // Choosing one penalty card each from both player's current hand, adding them to reward pile, and removing them from the current hand
            cout << "P1's penalty card: ";
            int pc1 = Hand_P1.choose(card_P1); 
            cout << card_P1 << endl;
            reward_pile.insert(card_P1);
            Hand_P1.remove(card_P1);

            cout << "P2's penalty card: ";
            int pc2 = Hand_P2.choose(card_P2); 
            cout << card_P2 << endl;
            reward_pile.insert(card_P2);
            Hand_P2.remove(card_P2);
        }
    }

    cout << endl << "Game over!";

    if(!Hand_P1.is_empty()){ // Player 1 still has some cards in hand but not Player 2
        cout << endl << "Player 1 has won!";
    }
    else{ // Player 2 still has some cards in hand but not Player 1
        cout << endl << "Player 2 has won!";
    }

  return 0;
}

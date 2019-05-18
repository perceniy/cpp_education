//
// Created by Арсений Сысоев on 2019-05-17.
//

#ifndef OOP_BLACKJACK_GAME_H
#define OOP_BLACKJACK_GAME_H

#include <vector>
#include "card.h"
#include "player.h"

class Game
{
public:
    Game(const vector<string>& names);

    ~Game();

    // проводит игру в Blackjack
    void Play();

private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;
};

#endif //OOP_BLACKJACK_GAME_H

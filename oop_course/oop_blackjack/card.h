//
// Created by Арсений Сысоев on 2019-05-17.
//

#ifndef OOP_BLACKJACK_CARD_H
#define OOP_BLACKJACK_CARD_H

#include <vector>

using namespace std;

class Card
{
public:
    enum rank {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING
    };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

    // перегружаем оператор<<, чтобы можно было отправить объект
    // типа Card в стандартный поток вывода
    friend ostream& operator<<(ostream& os, const Card& aCard);

    Card(rank r = ACE, suit s = SPADES, bool ifu = true);

    // возвращает значение карты от 1 до 11
    int GetValue() const;

    //переворачивает карту: карта, лежащая лицом вверх,
    // переворачивается лицом вниз и наоборот
    void Flip();

private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};


class Hand
{
public:
    Hand();
    // виртуальный деструктор
    virtual ~Hand();

    // добавляет карту в руку
    void Add(Card* pCard);

    // очищает руку от карт
    void Clear();

    //получает сумму очков карт в руке, присваивая тузу
    // значение 1 или 11 в зависимости от ситуации
    int GetTotal() const;

protected:
    vector<Card*> m_Cards;
};



#endif //OOP_BLACKJACK_CARD_H

//
// Created by Арсений Сысоев on 2019-05-17.
//
#include "card.h"

Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}

int Card::GetValue() const
{
    //если карта перевернута лицом вниз ее значение равно О
    int value = 0;
    if (m_IsFaceUp)
    {
        // значение - это число, указанное на карте
        value = m_Rank;
        // значение равно 10 для JACK, QUEEN и KING
        if (value > 10)
        {
            value = 10;
        }
    }
    return value;
}

void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}

// перегружает оператор<<, чтобы получить возможность отправить
// объект типа Card в поток cout
ostream& operator<<(ostream& os, const Card& aCard)
{
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
                             "10", "J", "Q", "K" };
    const string SUITS[] = { "c", "d", "h", "s" };

    if (aCard.m_IsFaceUp)
    {
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    }
    else
    {
        os << "XX";
    }

    return os;
}

Hand::Hand()
{
    m_Cards.reserve(7);
}
// деструктор по-прежнему виртуальный
// это уже можно не обозначать
Hand::~Hand()
{
    Clear();
}

void Hand::Add(Card* pCard)
{
    m_Cards.push_back(pCard);
}

void Hand::Clear()
{
    // проходит по вектору, освобождая всю память в куче
    vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    // очищает вектор указателей
    m_Cards.clear();
}

int Hand::GetTotal() const
{
    // если карт в руке нет, возвращает значение 0
    if (m_Cards.empty())
    {
        return 0;
    }

    //если первая карта имеет значение 0, то она лежит рубашкой вверх:
    // вернуть значение 0
    if (m_Cards[0]->GetValue() == 0)
    {
        return 0;
    }

    // находит сумму очков всех карт, каждый туз дает 1 очко

    int total = 0;
    vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        total += (*iter)->GetValue();
    }

    // определяет, держит ли рука туз
    bool containsAce = false;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        if ((*iter)->GetValue() == Card::ACE)
        {
            containsAce = true;
        }
    }

    // если рука держит туз и сумма довольно маленькая, туз дает 11 очков
    if (containsAce && total <= 11)
    {
        // добавляем только 10 очков, поскольку мы уже добавили
        // за каждый туз по одному очку
        total += 10;
    }

    return total;
}

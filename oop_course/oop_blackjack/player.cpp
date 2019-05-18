//
// Created by Арсений Сысоев on 2019-05-17.
//

#include "player.h"
#include "card.h"
#include <iostream>

using namespace std;

GenericPlayer::GenericPlayer(const string& name) :
        m_Name(name)
{}

GenericPlayer::~GenericPlayer()
{}

bool GenericPlayer::IsBusted() const
{
    return (GetTotal() > 21);
}

void GenericPlayer::Bust() const {
    cout << m_Name << " busts.\n";
}

// перегружает оператор<<, чтобы получить возможность отправить
// объект типа GenericPlayer в поток cout
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << aGenericPlayer.m_Name << ":\t";

    vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.m_Cards.empty())
    {
        for (pCard = aGenericPlayer.m_Cards.begin();
             pCard != aGenericPlayer.m_Cards.end();
             ++pCard)
        {
            os << *(*pCard) << "\t";
        }


        if (aGenericPlayer.GetTotal() != 0)
        {
            cout << "(" << aGenericPlayer.GetTotal() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }
    return os;
}

Player::Player(const string& name) :
        GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::IsHitting() const {
    cout << m_Name << ", do you want a hit? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::Win() const {
    cout << m_Name << " wins.\n";
}

void Player::Lose() const {
    cout << m_Name << " loses.\n";
}

void Player::Push() const {
    cout << m_Name << " pushes.\n";
}

House::House(const string& name) :
        GenericPlayer(name)
{}

House::~House()
{}

// возвращает TRUE, если количество очков меньше или равно 16,
// и FALSE, если больше 16
bool House::IsHitting() const
{
    return (GetTotal() <= 16);
}

void House::FlipFirstCard()
{
    if (!(m_Cards.empty()))
    {
        m_Cards[0]->Flip();
    }
    else
    {
        cout << "No card to flip!\n";
    }
}

Deck::Deck()
{
    m_Cards.reserve(52);
    Populate();
}

Deck::~Deck()
{}

void Deck::Populate()
{
    Clear();
    // создает стандартную колоду
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
    {
        for (int r = Card::ACE; r <= Card::KING; ++r)
        {
            Add(new Card(static_cast<Card::rank>(r),
                         static_cast<Card::suit>(s)));
        }
    }
}
// функция переставляет указатели, расположенные в векторе m_Cards
// с помощью функции random_shuffle() стандартной библиотеки шаблонов
// Для использования данной библиотеки необходим файл <algorithm>
void Deck::Shuffle()
{
    random_shuffle(m_Cards.begin(), m_Cards.end());
}
// функция добавляет в конец вектора m_Cards копию указателя
// с помощью функции-члена Add().
// данная функция может работать с объектами классов Player и House
void Deck::Deal(Hand& aHand)
{
    if (!m_Cards.empty())
    {
        aHand.Add(m_Cards.back());
        m_Cards.pop_back();
    }
    else
    {
        cout << "Out of cards. Unable to deal.";
    }
}

// функция может работать как с объектами типа Player, так и House
void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
    cout << endl;
    //продолжает раздавать карты до тех пор, пока у игрока не случается
    // перебор или пока он хочет взять еще одну карту
    while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting())
    {
        Deal(aGenericPlayer);
        cout << aGenericPlayer << endl;

        if (aGenericPlayer.IsBusted())
        {
            aGenericPlayer.Bust();
        }
    }
}

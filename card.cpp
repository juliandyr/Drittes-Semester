#include "card.h"

Card::Card() {
    score = 0;
}

int Card::getScore() const
{
    return score;
}

void Card::setScore(int s)
{
    score = s;
}

bool Card::operator<(const Card &rhs) const
{
    return this->score < rhs.score;
}

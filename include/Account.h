/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-28
 */

#ifndef Blackjack_Account_h
#define Blackjack_Account_h

class Account
{
    double PlayerChips; // chips can be fractional
    friend class Text;
public:
    int initialBet; //bet cannot be fractional
    void initialize(double c, int b)
    {
        PlayerChips = c;
    }
};


#endif
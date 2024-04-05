/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-28
 */

#ifndef Blackjack_BLACKJACK_h
#define Blackjack_BLACKJACK_h

using namespace std;
class Player
{
    int Id;
    bool isSplit;
    string SplitId;
    vector<int> Card;
    int playerBet;
    friend class Text;
    friend class Board;
public:
    Player(){}
    Player(int id, bool split, string spid):Id(id), isSplit(split), SplitId(spid){}
    void initialize(int id, bool split, string spid)
    {
        Id = id;
        isSplit = split;
        SplitId=spid;
    }
};


#endif
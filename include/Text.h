/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-28
 */

#include <vector>
#include <limits>   

using namespace std;

#ifndef Blackjack_Text_h
#define Blackjack_Text_h

#include "Account.h"
#include "blackjack.h"

class Text
{
    int NumPlayer;
    int InitialAccountValue;
    bool useTextSymbol;
public:
    vector<bool> playerStatus;
    vector<Account> myA;
    
    Text(int n, int m, bool useTS):NumPlayer(n),InitialAccountValue(m), useTextSymbol(useTS){}
    
    void printWelcomeMessage(); // print welcome message
    void accountSetup(); // set player status and initial account value; run once
    void printAccount(); // print account information for each player
    PlayerAction playerInput(Player&, bool, bool); // takes input from each player
    void printResult(Outcome result); // print result of the play
    void printCard(int); // print a single card in human readable format
    void printDealerCard(const vector<int>& DealerCard, const bool cardHide); //print card of a dealer, with/without hide
    void printPlayerCard(Player& myP); //print all cards of a single player
    bool playerBetInput(); // get input bets from players. also check for play/exit
    void updateAccounting(int, int, Outcome); // update account information for each player based on Outcome
    void addBlankLine(int n); // add blank line
    void printLine(string s, bool newline);
};


void Text::printWelcomeMessage()
{
    cout<<"\nYou sat down at a Blackjack table with 5 other players.\nMinimum bet at the table is 50."<<endl;
}



void Text::accountSetup()
{
    playerStatus.resize(NumPlayer,true);
    myA.resize(NumPlayer);
    for (int i=0;i<NumPlayer;i++)
        myA[i].initialize(InitialAccountValue,0);
    
}

void Text::printAccount()
{
    cout<<"_____________________________________________________________"<<endl;
    for (int i=0;i<NumPlayer;i++)
        cout<<"Your Chips: "<<myA[i].PlayerChips<<"\t";
    cout<<endl;
}

PlayerAction Text::playerInput(Player& myP, bool isFirstTurn, bool isSplitPossible)
{
    bool isS, isH, isD, isSp;
    isS = isH = isD = isSp = false;
    bool isDoublePossible = isFirstTurn && (myA[myP.Id].PlayerChips >= myP.playerBet);
    isSplitPossible = isSplitPossible && (myA[myP.Id].PlayerChips >= myP.playerBet);
    
    if (!playerStatus[myP.Id])
    {
        cout<<"You have no more Chips."<<endl;
        return NO;
    }
    
    char choice = 'A';
    cout<<" Your choices are:"<<endl;
    cout<<" H : Hit"<<endl;
    cout<<" S : Stand"<<endl;
    if (isDoublePossible)   cout<<" D : Double Down"<<endl;
    if (isSplitPossible)  cout<<" T : Split into two bet"<<endl;
    
    while (!isS && !isH && !isD && !isSp)
    {
        cout<<"Your choice : ";
        cin>>choice;
        if (!cin)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        }
        
        isS = (choice=='S' || choice=='s');
        isH = (choice=='H' || choice=='h');
        isD = (choice=='D' || choice=='d') && (isDoublePossible) ;
        isSp = (choice=='T' || choice=='t') && (isSplitPossible) ;
        
    }
    
    if (isD)
    {
        myA[myP.Id].PlayerChips -= myP.playerBet; //update player chips
        myP.playerBet *= 2; // update player bet
        cout<<"Your updated bet(total) : "<<myP.playerBet<<endl;
        
    }
    if (isSp)
    {
        myA[myP.Id].PlayerChips -= myP.playerBet; //update player chips
        // we will not update playerBet, it will be updated individually
        cout<<"Your additional bet : "<<myP.playerBet<<endl;
    }
    
    if (isS)
        return STAND;
    else if (isH)
        return HIT;
    else if (isD)
        return DOUBLE;
    else
        return SPLIT;
}


void Text::printResult(Outcome result)
{
    switch(result)
    {
        case PUSH:
            cout<<"Results : Push!!"<<endl;
            break;
        case DEALER_WIN:
            cout<<"Results : Dealer Won!!"<<endl;
            break;
        case PLAYER_BUST:
            cout<<"Results : Dealer Won!! (You Bust)"<<endl;
        case PLAYER_WIN:
            cout<<"Results : You Won!!"<<endl;
            break;
        case DEALER_BUST:
            cout<<"Results : You Won!! (Dealer Bust)"<<endl;
            break;
        case PLAYER_BJ:
            cout<<"Results : Player Blackjack!! "<<endl;
            break;
        case DEALER_BJ:
            cout<<"Results : Dealer Blackjack!!"<<endl;
            break;
        default:
            break;
    }
}

void Text::printCard(int cardId)
{
    int cardInDeck = cardId%NUM_CARD_DECK;
    int rank = cardInDeck%NUM_CARD_SUIT;
    int suit = cardInDeck/NUM_CARD_SUIT;
    if (useTextSymbol)
        cout<<RANK[rank]<<" "<<SUITS_text[suit];
    else
        cout<<RANK[rank]<<SUITS[suit];
}


void Text::printDealerCard(const vector<int>& DealerCard, const bool cardHide)
{
    // print dealer cards
    if (cardHide)
    {
        if (DealerCard.size()!=2)
            cout<<"error";
        else
        {
            cout<<"Dealer Cards : ";
            printCard(DealerCard[0]);
            cout<<", ";
            cout<<"***"<<endl;
        }
    }
    else
    {
        cout<<endl<<endl<<"Dealer Cards : ";
        for(int i=0;i<DealerCard.size();i++)
        {
            printCard(DealerCard[i]);
            cout<<", ";
        }
        cout<<endl;
    }
}


void Text::printPlayerCard(Player& myP)
{
    if (!myP.isSplit)
        cout<<"Your Cards : "<<flush;
    else
        cout<<"Your Split# "<<myP.SplitId<<" Card : "<<flush;
    
    // print player cards
    for(int j=0;j<myP.Card.size();j++)
    {
        printCard(myP.Card[j]);
        cout<<", ";
    }
    cout<<endl;
}


bool Text::playerBetInput()
{
    int choice=0;
    cout<<"\t 1. Play"<<endl;
    cout<<"\t 2. Leave Table"<<endl;
    while(choice!= 1 && choice!=2)
    {
        cout<<"Your input : "<<flush;
        cin>>choice;
        if (!cin)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        }
    }
    cout<<endl;
    if (choice == 2) //exit
    {
        printAccount();
        cout<<"You have left the Blackjack table..."<<endl;
        return false;
    }
    else //play
    {
        cout<<"Collecting bets from all players..."<<endl;
        for (int i=0;i<NumPlayer;i++)
        {
            if (myA[i].PlayerChips == 0)
            {
                cout<<"You have 0 chips."<<endl;
                cout<<"You cannot play anymore..."<<endl;
                playerStatus[i] = false;
            }
            else
            {
                int tempBet = 0;
                while(tempBet> myA[i].PlayerChips || tempBet<50)
                {
                    cout<<"Your Bet (min 50) : ";
                    cin>>tempBet;
                    if (!cin)
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                    }
                }
                myA[i].initialBet = tempBet;
                myA[i].PlayerChips-=tempBet; // update players chips
            }
        }
    }
    cout<<endl;
    return true;
}

void Text::updateAccounting(int Id, int playerBet, Outcome r)
{
    switch(r)
    {
        case PUSH:
            myA[Id].PlayerChips += playerBet; // return bet
            break;
        case DEALER_WIN:
        case PLAYER_BUST:
        case DEALER_BJ:
            // player lose 1:1
            // do nothing
            break;
        case PLAYER_WIN:
        case DEALER_BUST:
            // player win 1:1
            myA[Id].PlayerChips += 2*playerBet;
            break;
        case PLAYER_BJ:
            // player win 3:2
            myA[Id].PlayerChips += 2.5*playerBet;
            break;
        default:
            break;// do nothing
            
    }
}

void Text::addBlankLine(int n) // add blank line
{
    for(int i=0;i<n;i++)
        cout<<endl;
}

void Text::printLine(string s, bool newline)
{
    cout<<s;
    if(newline)
        cout<<endl;
}



#endif
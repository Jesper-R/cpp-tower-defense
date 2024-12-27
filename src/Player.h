//
// Created by Jesper Rudegran on 2024-12-27.
//

#ifndef PLAYER_H
#define PLAYER_H



class Player {
    int lives;
    int money;
public:
    Player();
    int getLives();
    int getMoney();
    void setLives(int lives);
    void setMoney(int money);
    void addMoney(int money);
    void removeMoney(int money);
    void removeLife();
    void addLife();
};



#endif //PLAYER_H

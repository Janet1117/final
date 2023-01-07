#ifndef  SETUPPLAYER_H
#define SETUPPLAYER_H
#include<time.h>
#include"node.h"
#include"stack.h"




// void InitializeThreePlayerCard();
// void InitializeFourPlayerCard();




void ShuffleOrder(int *player_order, size_t amount);

int i;

node *player1 = NULL;//真人玩家手中的牌
node *player2 = NULL;//電腦玩家手中的牌
node *player3 = NULL;//電腦玩家手中的牌
node *player4 = NULL;//電腦玩家手中的牌
//node *players[4] = {player1, player2, player3, player4};


node *makelist(node *list){
    if(list == NULL){
        list = (node *) malloc (sizeof(node));
    }
    return list;
}

// //初始化3人模式玩家手中的牌
// void InitializeThreePlayerCard(){
//     //每位玩家手中的牌，player1固定為真人玩家
//     node *player1 = NULL;//真人玩家手中的牌
//     node *player2 = NULL;//電腦玩家手中的牌
//     node *player3 = NULL;//電腦玩家手中的牌
// }

// //初始化4人模式玩家手中的牌
// void InitializeFourPlayerCard(){
//     //每位玩家手中的牌，player1固定為真人玩家
//     node *player1 = NULL;//真人玩家手中的牌
//     node *player2 = NULL;//電腦玩家手中的牌
//     node *player3 = NULL;//電腦玩家手中的牌
//     node *player4 = NULL;//電腦玩家手中的牌
// }




//隨機出排順序
void ShuffleOrder(int *player_order, size_t amount){
    //亂數前置
    srand(time(NULL));
    if(amount > 1){
        size_t x;
        for(x = 0; x < amount; x++){
            size_t y = rand() / (RAND_MAX / (amount));
            int t = player_order[y];
            player_order[y] = player_order[x];
            player_order[x] = t;
        }
    }
}



#endif
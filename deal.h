#ifndef DEAL_H
#define DEAL_H

#include"node.h"
#include"setupplayer.h"
#include<time.h>
#define STACKSIZE 108

node *UsedCard = NULL;
node *cardpool = NULL;


node *dealt(node *player);
node deal();

int i, j;
int top = -1;

Card stack[STACKSIZE];

void setupdeck();
void empty(node *pool);
int full();
Card pop();
void push(Card card);
void ShuffleDeck(Card *deck, size_t amount);


//設置排組
void setupdeck(){
    Card data;
    for(i = 1; i < 5; i++){
        //每個顏色的0
        j = 0;
        data.color = i;
        data.name = j;
        push(data);
        
        //每個顏色(黑以外)除0以外各2張
        for(j = 1; j < 13; j++){
            data.color = i;
            data.name = j;
            push(data);
            push(data);
        }
    }
    for(i = 0, j = 13; j < 15; j++){
        data.color = i;
        data.name = j;
        push(data);
        push(data);
        push(data);
        push(data);
    }
}

void empty(node *pool){
    node *tmp;
    if(top == -1){
        setupdeck();
        ShuffleDeck(stack, 108);
        while((pool != NULL) || (pool->next != NULL)){
            tmp = UsedCard->next;
            UsedCard->next = tmp->next;
            free(tmp);
        }
    }
}

int full(){
    if(top == 107){
        return 1;
    }else{
        return 0;
    }
}

Card pop(){
    Card data;
    empty(UsedCard);
    data = stack[top];
    top--;
    return data;
}

void push(Card card){
    if(full() == 0){
        top++;
        stack[top] = card;
    }
}



//發牌
node *dealt(node *player){






    
    if(player == NULL){
        player = (node *) malloc (sizeof(node));
        Card data = pop();
        player->color = data.color;
        player->name = data.name;
        player->next = NULL;
        return player;
    }else{
        node *newnode;
        newnode = (node *) malloc (sizeof(node));
        Card data = pop();
        newnode->color = data.color;
        newnode->name = data.name;
        newnode->next = player;
        return newnode;   
    }
}

node deal(){
    Card data = pop();
    node newnode;
    newnode.color = data.color;
    newnode.name = data.name;
    newnode.next = NULL;
    return newnode;
}

//洗牌
void ShuffleDeck(Card *deck, size_t amount){
    //亂數前置
    srand(time(NULL));
    if(amount > 1){
        size_t x;
        for(x = 0; x < amount; x++){
            size_t y = rand() / (RAND_MAX / (amount));
            Card t = deck[y];
            deck[y] = deck[x];
            deck[x] = t;
        }
    }
}

#endif
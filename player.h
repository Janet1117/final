#ifndef PLAYER_H
#define PLAYER_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"node.h"
#include"setupplayer.h"
#include"function.h"
#include"gamerule.h"
#include"deal.h"

#define R(card) "\033[1;31m"#card"\033[m" //紅色的牌
#define Y(card) "\033[1;33m"#card"\033[m" //黃色的牌
#define G(card) "\033[1;32m"#card"\033[m" //綠色的牌
#define B(card) "\033[1;34m"#card"\033[m" //藍色的牌

int i;
int drawNumber;

void PlayerInput();
node *InputToNode();
void PrintCard(node *tmp);
void PlayerCurrentCard();
char InputColor[10];
char InputName[10];
char YorN[2];
node *input = NULL;
char *pass = "pass";


void PlayerInput(){
    input = makelist(input);
    PlayerCurrentCard();
    printf("先輸入顏色再輸入牌\n");
    printf("請輸入您想出的牌(如無可出的牌請輸入pass):");
    scanf("%s", InputColor);
    printf("yyyy\n");
    printf("InputColor = %s\n", InputColor);
    if(strcmp(InputColor, pass) == 0){
        printf("hi\n");
        player1 = dealt(player1);
        printf("您抽到: ");
        PrintCard(player1);
        printf("\n");
    }else{
        printf("lalalalala\n");
        scanf("%s", InputName);
        printf("InputName = %s\n", InputName);
        input = InputToNode(InputColor, InputName);
        printf("您要出的是");
        PrintCard(input);
        printf("這張牌嗎?[y/n]:");
        scanf("%s", YorN);
        while (YorN[0] != 'y'){
            printf("先輸入顏色再輸入牌\n");
            printf("請輸入您想出的牌:(如無可出的牌請輸入pass)");
            scanf("%s", InputColor);
            scanf("%s", InputName);
            input = InputToNode(InputColor, InputName);
            printf("您要出的是");
            PrintCard(input);
            printf("這張牌嗎?[y/n]:");
            scanf("%s", YorN);
        }
        cardpool = ruleandrenewpokerpile(UsedCard, input, &drawNumber);
        while (UsedCard == cardpool){
            printf("\033[1;33m輸入不正確!請重新輸入!\n\033[m");
            printf("請輸入您想出的牌:");
            scanf("%s", InputColor);
            scanf("%s", InputName);
            input = InputToNode(InputColor, InputName);
            cardpool = ruleandrenewpokerpile(UsedCard, input, &drawNumber);
        }
        UsedCard = cardpool;
    }
    printf("hi\n");

}

node *InputToNode(char Color[], char Name[]){
    node *card;
    card->next = NULL;

    if(strcmp(Color, "黑")){
        card->color = black;
    }else if(strcmp(Color, "紅")){
        card->color = red;
    }else if(strcmp(Color, "黃")){
        card->color = yellow;
    }else if(strcmp(Color, "綠")){
        card->color= green;
    }else if(strcmp(Color, "藍")){
        card->color = blue;
    }else{
        card->color = -1;
    }

    if(strcmp(Name, "0")){
        card->name = zero;
    }else if(strcmp(Name, "1")){
        card->name = one;
    }else if(strcmp(Name, "2")){
        card->name = two;
    }else if(strcmp(Name, "3")){
        card->name = three;
    }else if(strcmp(Name, "4")){
        card->name = four;
    }else if(strcmp(Name, "5")){
        card->name = five;
    }else if(strcmp(Name, "6")){
        card->name = six;
    }else if(strcmp(Name, "7")){
        card->name = seven;
    }else if(strcmp(Name, "8")){
        card->name = eight;
    }else if(strcmp(Name, "9")){
        card->name = nine;
    }else if(strcmp(Name, "禁止")){
        card->name = skip;
    }else if(strcmp(Name, "迴轉")){
        card->name = reverse;
    }else if(strcmp(Name, "+2")){
        card->name = drawtwo;
    }else if(strcmp(Name, "萬用")){
        card->name = wild;
    }else if(strcmp(Name, "+4")){
        card->name = wild_draw_four;
    }else{
        card->name = -1;
    }
    return card;
}

void PrintCard(node *tmp){
    if(tmp != NULL){
        if(tmp->color == black){
                if(tmp->name == wild){
                    printf("%s", "萬用");
                }else if(tmp->name == wild_draw_four){
                    printf("%s", "+4");
                }
            }else if(tmp->color == red){
                for(i = 0; i < 13; i++){
                    if(tmp->name == i){
                        if(i == 10){
                            printf("%s", R(禁止));
                        }else if(i == 11){
                            printf("%s", R(迴轉));
                        }else if(i == 12){
                            printf("%s", R(+2));
                        }else{
                            printf("\033[1;31m%d\033[m", i);
                        }
                    }
                }
            }else if(tmp->color == yellow){
                for(i = 0; i < 13; i++){
                    if(tmp->name == i){
                        if(i == 10){
                            printf("%s", Y(禁止));
                        }else if(i == 11){
                            printf("%s", Y(迴轉));
                        }else if(i == 12){
                            printf("%s", Y(+2));
                        }else{
                            printf("\033[1;33m%d\033[m", i);
                        }
                    }
                }
            }else if(tmp->color == green){
                for(i = 0; i < 13; i++){
                    if(tmp->name == i){
                        if(i == 10){
                            printf("%s", G(禁止));
                        }else if(i == 11){
                            printf("%s", G(迴轉));
                        }else if(i == 12){
                            printf("%s", G(+2));
                        }else{
                            printf("\033[1;32m%d\033[m", i);
                        }
                    }
                }
            }else if(tmp->color == blue){
                for(i = 0; i < 13; i++){
                    if(tmp->name == i){
                        if(i == 10){
                            printf("%s", B(禁止));
                        }else if(i == 11){
                            printf("%s", B(迴轉));
                        }else if(i == 12){
                            printf("%s", B(+2));
                        }else{
                            printf("\033[1;34m%d\033[m", i);
                        }
                    }
                }
            }
            printf(" ");
    }
    
}

void PlayerCurrentCard(){
    printf("您有:");
    node *tmp;
    tmp = player1;
    while (tmp != NULL){
        PrintCard(tmp);
        //printf("  ");
        tmp = tmp->next;
    }
    printf("\n");
}

#endif
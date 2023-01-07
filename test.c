#include<stdio.h>
#include<string.h>

#include"mode.h"
#include"cardfunction.h"
#include"stack.h"
#include"player.h"
//#include"setupplayer.h"
//#include"linkedlist.h"
#include"player.h"
int main(){
    
    // int three_player_order[3] = {0, 1, 2};
    // int four_player_order[4] = {0, 1, 2, 3};

    //ThreePlayer();
    //PlayerInput();
    printf("%ld\n", sizeof(player1));
    initialize();
    printf("hi\n");
    printf("%p\n", player1);
    printf("%ld\n", sizeof(player1));
    player1 = deal(player1);
    printf("color = %d\nname = %d\nnext = %p\n", player1->color, player1->name, player1->next);
    // node *tmp;
    // tmp = player1;
    // while(tmp != NULL){
    //     printf("tmp = %p\n", tmp);
    //     printf("color : %d\nname : %d\n", tmp->color, tmp->name);
    //     printf("----------------------------------\n");
    //     tmp = tmp->next;
    // }

    return 0;
}
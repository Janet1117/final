#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

#include "../inc/store.h"
#include "../inc/mode.h"
//getopt使用
#include<ctype.h>
#include<unistd.h>
extern char *ptarg;
extern int optind;
extern int optopt;
extern int opterr;
extern int optreset;
int getopt(int argc,char *const *argv,const char *optstring);

int ch;
bool store = false;
bool load = false;

FILE *fptr;
//開新局為0,載入歷史紀錄為1  
int NeworOld;


//store
int players;
extern node StartCard;
extern int RealPlayer[14]; 

//指標
extern Record *head;
extern Record *current;



int main(int argc,char *argv[]){

	//getopt
	opterr=0;
	while((ch=getopt(argc,argv,"ns:l:"))!=-1){
		switch(ch){
			case 'n':
				NeworOld=0;
				break;

			case 's':
				store = true;
				if((fptr=fopen(optarg,"w"))==NULL){
					printf("File can not be opened.\n");
					return 0;
				}
				NeworOld=0;
				break;
			case 'l':
				load = true;
				if((fptr=fopen(optarg,"r"))==NULL){
					printf("File can not be opened.\n");
					return 0;
				}
				NeworOld =1;
				break;
		}
	}
	//開始新局
	if(NeworOld==0){
		printf("請選擇三人局或四人局\n");
		printf("三人局請輸入3，四人局請輸入4\n");
		
		scanf("%d",&players);
		
		if(players==3){
			ThreePlayer();
		}
		else if(players==4){
			FourPlayer();
		}
	}
	//store
	//store number of pepoleV
	//底牌V
	//起始牌V
	//玩家順序V
	//IFpassV
	//抽到/顏色+數字 V
	//電腦->電腦->電腦 
	
	if(store){
		printf("儲存中...\n");
		fprintf(fptr,"%d\n", players);
		fprintf(fptr,"%d %d\n", StartCard.color, StartCard.name);
		//only store player
		for(int i = 0; i < 7; ++i)
			fprintf(fptr,"%d %d ", RealPlayer[i*2],RealPlayer[i*2+1]);
		fprintf(fptr,"\n");
		
		while (head != NULL)
		{
			fprintf(fptr,"%d %d %d %d\n", head->order, head->IFpass, head->card->color, head->card->name);
			printf("%d %d %d %d\n", head->order, head->IFpass, head->card->color, head->card->name);
			head = head->next;
		}
		
	}

	//load
	if(load){
		char data[50];
		char color[50], name[50];
		fseek(fptr, SEEK_SET, 0);
		printf("載入紀錄\n");
		fscanf(fptr,"%s\n", data);
		if(atoi(data)== 3){
			printf("三人局\n");
		}
		else if(data[0] == '4'){
			printf("四人局\n");
		}
		fscanf(fptr,"%s %s\n",color, name);
		node tmp;
		tmp.color = atoi(color);
		tmp.name = atoi(name);
		printf("底牌是: ");
		PrintCard(&tmp);
		printf("\n");
		node *current = NULL;
		for(int i = 0; i < 7; ++i){
			fscanf(fptr,"%s %s\n",color, name);
			node *newnode;
        	newnode = (node *) malloc (sizeof(node));
        	newnode->color = atoi(color);
        	newnode->name = atoi(name);
			if(current == NULL) {
				player1 = newnode;
				current = newnode;
        		newnode->next = newnode->prev = NULL;
    		}else{
        		current -> next = newnode;

				newnode->prev = current;
				newnode->next = NULL;
		
				current = newnode;
   			}
		}
		PlayerCurrentCard();
		char ifpass[50];
		int ID;
		while(fscanf(fptr,"%s %s %s %s", data, ifpass,color, name) != EOF){
			printf("現在是玩家 %s\n", data);
			ID = atoi(data);
			int flag = ifpass[0]; // '1' 
			//fscanf(fptr,"%s %s\n", color, name);
			//printf("%s %s %s %s\n",data, ifpass, color, name );
			if(ID == 1){
			if( flag > 48 && flag < 51 ){
				if(flag == 49)
					printf("pass :");
				else
					printf("抽到 :");
				node *newnode;
        		newnode = (node *) malloc (sizeof(node));
        		newnode->color = atoi(color);
        		newnode->name = atoi(name);
				newnode->next = player1->next;
        		newnode->prev = player1;
				if(player1->next != NULL){
            		player1->next->prev = newnode;
       			}
        		player1->next = newnode; 
				PrintCard(newnode);   
				printf("\n");
			}
			else{
				printf("usedCard :");
				if(flag == 51 /*black*/){
				
					tmp.color = 0;
				}
				else{
					tmp.color = atoi(color);
					//printf("%d", atoi(color));
				}
					tmp.name = atoi(name);
					PrintCard(&tmp);
					printf("\n");
					player1 = deletecard(player1, tmp);
					if(flag == 51 /*black*/){
						printf("玩家選擇顏色:");
						if(atoi(color) == yellow){
							printf("黃\n");
						}
						else if(atoi(color) == red){
							printf("紅\n");
						}
						else if(atoi(color) == green){
							printf("綠\n");
						}
						else if(atoi(color) == blue){
							printf("藍\n");
						}

				}
			}
			if(player1 != NULL){
				PlayerCurrentCard();
			}
			else{
				printf("你贏了\n");
			}
			
			}
			else if(ID == 2){
				if( flag == 49 )
					printf("玩家2抽了一張牌\n");
				else{
					printf("usedCard :");
					tmp.color = atoi(color);
					tmp.name = atoi(name);
					PrintCard(&tmp);
					printf("\n");
				}
			}
			else if(ID == 3){
				if( flag == 49 )
					printf("玩家3抽了一張牌\n");
				else{
					printf("usedCard :");
					tmp.color = atoi(color);
					tmp.name = atoi(name);
					PrintCard(&tmp);
					printf("\n");
				}
			}
			else if(ID == 4){
				if( flag == 49 )
					printf("玩家4抽了一張牌\n");
				else{
					printf("usedCard :");
					tmp.color = atoi(color);
					tmp.name = atoi(name);
					PrintCard(&tmp);
					printf("\n");
				}
			}
		}
		printf("遊戲結束！\n");
	}
	fclose(fptr);
	return 0;
}
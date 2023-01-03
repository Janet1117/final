#include "function.h"

int top=-1;//發牌堆空

//放入資料
void push(int color,int name){
	top++;
}

node deal()
{
    if(Empty==0){
        pop();   
    }
}
//判斷是否為空堆疊
int Empty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}

//拿出資料
node pop(){
	node data;
    data=stack[top];
    top--;
    return data;
}
#include"head.h"
/*本程序存在不少的函数，可以先看看else.c文件，或者head.h*/ 
int sa=1,em=1;
int main(){
	struct student *head=NULL;					//建立头指针 
	int n=0;									//进行选择时的变量 
	while(1){
		n=main_menu();							//主菜单的呈现，并得到选择 
		switch(n){
			case 1:head=create(head);break;		//建立链表 
			case 2:search(head);break;			//查找数据 
			case 3:update(head);break;			//更新数据 （增、删、改） 
			case 4:sort(head);break;			//对数据进行排序 
			case 5:statistic(head);break;		//对于数据进行统计 
			case 6:save(head);break;			//保存数据 
			case 7:print(head);break;			//打印数据 
			case 8:quit(head);					//退出程序 
		}
		if(em==0)head=NULL;						//判断学生信息是否全部删除 
	}
	return 0; 
}

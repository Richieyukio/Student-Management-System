#include"head.h"

int main_menu(){
	char  a[20];								//通过字符串得到用户的输入 
	int i;										//得到的字符串转化成的整型变量 
	do{	
		print_menu();							//仅仅是一个菜单的打印 
		fflush(stdin);
		gets(a);								
		if(strlen(a)>1){						//判断长度，毕竟只需要一个字符 
			error();							//报错 
			continue;
		}
		i=atoi(a);								//字符变整型 
		if(i<1||i>8)error();					//整型的又一次判断，是否在范围内 
		else return i;
	}while(1);
}
void print_menu(){								//专门打印菜单 
	int i;
	char *sentence[]={"创建学生数据","查找学生数据",
					  "更新学生数据","排序学生数据",
					  "统计学生数据","保存学生数据", 
					  "输出学生数据","退出管理系统"};
	system("cls");
	system("color F0");				  
	printf("\n\n\t\t\t\t\t\t 学生信息管理系统\n\n\t\t\t"); 
	for(i=0;i<30;i++)printf("*");
	printf("主菜单");
	for(i=0;i<30;i++)printf("*");
	printf("\n\t\t\t*\t\t\t\t\t\t\t\t *\n");
	for(i=1;i<9;i+=2){
		printf("\t\t\t*\t%d、%s\t\t\t   %d、%s\t *\n",i,sentence[i-1],i+1,sentence[i]);
		printf("\t\t\t*\t\t\t\t\t\t\t\t *\n");
	} 
	printf("\t\t\t");
	for(i=0;i<66;i++)printf("*");
	printf("\n\t\t\t请输入你的选择:");
} 

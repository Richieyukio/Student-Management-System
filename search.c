#include"head.h"

void search(struct student *head){				//查询 
	int n;
	if(head==NULL){
		system("color F4");
		printf("\t\t\t没有数据可以查询.\n\t\t\t按任意键返回主菜单.");
		getch();
	}
	else{
		while(1){
			n=search_menu();					//打印查询菜单，并返回值 
			switch(n){
				case 1:search_num(head);break;	//查询学号 
				case 2:search_name(head);break;	//查询姓名 
				case 3:break;					//退出 
			}
			if(n==3)break;	
		}		
	} 
} 
int search_menu(){								//这是个查询菜单 
	int i;
	char *sentence[]={"按照学号查询","按照姓名查询","退出查询"};
	do{
		system("cls");
		system("color F0");			
		printf("\n\n\t\t\t\t\t\t 学生信息管理系统\n\n\t\t\t");	  
		for(i=0;i<29;i++)printf("*");
		printf("查询菜单");
		for(i=0;i<29;i++)printf("*");
		printf("\n\t\t\t*\t\t\t\t\t\t\t\t *\n");
		for(i=0;i<3;i++){
			printf("\t\t\t*\t\t\t%d、%s\t\t\t\t *\n",i+1,sentence[i]);
			printf("\t\t\t*\t\t\t\t\t\t\t\t *\n");
		} 
		printf("\t\t\t");
		for(i=0;i<66;i++)printf("*");
		printf("\n\t\t\t请输入你的选择:");
		i=get();
		if(i<1||i>3)error();					
		else return i;							//最后得到用户的选择 
	}while(1);
}
void search_num(struct student *head){			//查找相对应的学号 
	struct student *p=head->next;
	char a[20];	
	int flag=0;
	
	printf("\t\t\t输入你所需要查询学生的学号(以换行作为输入结束):");
	get_num(a);
	while (p){
		if(strcmp(a,p->number)==0)break;
		p = p->next;
	} 
	if(p==NULL){
		printf("\n\t\t\t不存在该学生的学号!\n\t\t\t按任意键返回菜单.");
		getch();
	}
	else{
		print_student(p);
		printf("\n\t\t\t输出结束！按任意键返回菜单！");
		getch();
	}
}
void search_name(struct student *head){			//查找相对应的姓名 
	struct student *p=head->next;
	char a[20];	
	int flag=0; 
	printf("\t\t\t输入你所需要查询学生的姓名(以换行作为输入结束):");
	gets(a);
	while (p){
		if(strcmp(a,p->name)==0){
			print_student(p);
			flag=1;
		}
		p = p->next;
	}
	if(flag==0){
		printf("\n\t\t\t系统中不存在该学生的姓名!\n\t\t\t按任意键返回菜单.");
		getch();
	}
	else{
		printf("\n\t\t\t输出结束！按任意键返回菜单！");
		getch();
	}
}


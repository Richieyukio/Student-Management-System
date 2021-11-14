#include"head.h"

void error(){									//问题报错			
	system("color F4");
	printf("\n\t\t\t输入错误!请重新输入！按任意键返回菜单！");
	getch();
}
struct student *node(struct student *head){		//结点的建立 
	head=(struct student*)malloc(sizeof(struct student));
	head->next=NULL;
	return head;
}
void get_num(char *a){							//读取学号 
	int i=0,flag;
	do{	
		flag=1;									//最后判断的变量 
		fflush(stdin);
		fgets(a,15,stdin);
		a[strlen(a)-1]='\0';
		if(strlen(a)==0)printf("\t\t\t输入不能为空!请重新输入:");
		else{
			for(i=0;a[i]!='\0';i++){
				if(isdigit(a[i])==0){			//判断数字以外的数不行，除了Z 
					if(a[i]!='Z')flag=0;
				}
			}
			if(strcmp(a,"-1")==0)flag=1;
			if(flag==1)break;
			else printf("\t\t\t输入错误!请重新输入:");
		}
	}while(1);
}
int get(){										//整型数据的输入 
	char a[20],ch;
	int i,flag,n;
	do{
		do{
			i=0;
			while((ch=getchar())!='\n'){		//不能为空 
				a[i++]=ch;
			}
			a[i]='\0';
			n=strlen(a);
			if(n==0)printf("\t\t\t输入不能为空!请重新输入:");
		}while(n==0);
		flag=1;
		for(i=0;i<n;i++){						//只能为数字 
			if(isdigit(a[i])==0)flag=0;
		}
		if(flag){
			i=atoi(a);
			fflush(stdin);
			return i;
		}
		else printf("\t\t\t输入错误!请重新输入:");
		fflush(stdin); 
	}while(1);
}
void print_student(struct student *p){			//输出单个学生的信息 
	printf("\n\t\t\t学号:%s  姓名:%s   年龄:%d\n\t\t\t语文成绩:%d  数学成绩:%d  英语成绩:%d  总分:%d   平均分:%.2f\n"
			,p->number,p->name,p->year,p->grade_chinese,p->grade_math,p->grade_english,p->Total_score,p->average);	
}
void print(struct student *head){				//输出所有学生数据 
	struct student *p; 
	if(head==NULL){
		system("color F4");
		printf("\t\t\t数据还未创建.\n\t\t\t按任意键返回菜单");
		getch();
	}
	else {
		p=head->next;
		printf("\t\t\t学号\t\t姓名\t  年龄\t  语文成绩\t数学成绩\t英语成绩\t总分\t平均分\n");
		while(p!=NULL){
			printf("\t\t\t%-12s\t%-8s   %d\t     %d\t\t    %d\t\t  %d\t\t%d\t %.2f\n",p->number,p->name,p->year,p->grade_chinese,p->grade_math,p->grade_english,p->Total_score,p->average);
			p=p->next;
		}
		printf("\n\t\t\t输出成功!\n");
		printf("\t\t\t按任意键返回主菜单.");
		getch();
	}
}

void judge(char *num,struct student *head){		//判断学号输入是否重复 
	struct student*p;
	int flag=0;
	while(1){
		p=head->next;
		while(p){
			if(strcmp(num,p->number)==0){
				flag=1;
				break;
			}
			p=p->next;
		}
		if(flag==0)break;
		else {
			printf("\n\t\t\t输入错误!已存在相同学号!\n\t\t\t请重新输入:");
			get_num(num);
			flag=0;
		}
	}
}
int len(struct student *head){					//链表长度 
	int num=0;
	struct student *p=head->next;
	while(p){
		num++;
		p=p->next;
	}
	return num;
}
float fun(char *a){
	float b;
	int flag=1; 
	while(1){
		printf("输入:");
		fflush(stdin);
		fgets(a,15,stdin);
		a[strlen(a)-1]='\0';
		
		b=atof(a);
		if(b<0||b>100)flag=0;
		else if(a[0]=='0'&&strlen(a)==1)flag=1;
		if(flag==1){
			return b; 
		}
	}
} 

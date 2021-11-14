#include"head.h"

void update(struct student *head){				//更新 
	int n=0;
	if(head==NULL){
		system("color F4");
		printf("\t\t\t没有数据可以更新.\n\t\t\t按任意键返回主菜单.");
		getch();
	}
	else{
		while(1){
			n=update_menu();					//菜单，并得到选择 
			switch(n){
				case 1:increase(head);break;	//增加一个学生信息 
				case 2:release(head);break;		//删除一个学生信息 
				case 3:cancel(head);break;		//删除所有 
				case 4:modefy(head);break;		//修改一个学生信息 
				case 5:break;					//退出 
			}
			if(n==5)break;
		}				
	} 
}
int update_menu(){								//仅仅是一个更新菜单 
	int i;
	char *sentence[]={"增加一个学生信息","删除一个学生信息","删除全部学生信息","修改一名学生信息","退出更新学生界面"};
	do{
		system("cls");
		system("color F0");			
		printf("\n\n\t\t\t\t\t\t 学生信息管理系统\n\n\t\t\t");	  
		for(i=0;i<29;i++)printf("*");
		printf("更新菜单");
		for(i=0;i<29;i++)printf("*");
		printf("\n\t\t\t*\t\t\t\t\t\t\t\t *\n");
		for(i=0;i<5;i++){
			printf("\t\t\t*\t\t\t%d、%s\t\t\t *\n",i+1,sentence[i]);
			printf("\t\t\t*\t\t\t\t\t\t\t\t *\n");
		} 
		printf("\t\t\t");
		for(i=0;i<66;i++)printf("*");
		printf("\n\t\t\t请输入你的选择:");
		i=get();
		if(i<1||i>5)error();
		else return i;		
	}while(1);
}
void increase(struct student *head){			//增加一个学生信息 
	struct student *s,*p=head;
	int a,k=0;
	sa=0;										//待会要保存 
	printf("\t\t\t输入你将要插入的位置(1-%d):",len(head)+1);//判断，长度提示
	do{
		a=get();
		if(a<1||a>len(head)+1)printf("\t\t\t输入错误!请重新输入:");
		else break; 
	} while(1);
	s=node(s);
	printf("\t\t\t请输入该学生的学号:"); 
	get_num(s->number);
	judge(s->number,head);						//判断输入是否是重复学号 
	assign(s);
	while(p!=NULL&&k<a-1){
		p=p->next;
		k++;
	}
	s->next = p->next;
	p->next = s;
	printf("\n\t\t\t插入成功!按任意键返回菜单.");
	getch();		
}
void release(struct student *head){				//删除一个学生信息 
	struct student *p=head->next,*q=NULL;
	char a[20],b[20];
	sa=0;										//待会要保存
	printf("\t\t\t请依次输入该学生的学号和姓名:\n");
	printf("\t\t\t学号(以换行作为输入结束):");
	get_num(a);
	printf("\t\t\t姓名(以换行作为输入结束):"); 
	gets(b);
	while(p){
		if(strcmp(a,p->number)==0&&strcmp(b,p->name)==0)break;
		q=p;
		p=p->next;
	}
	if(p==NULL){
		printf("\t\t\t数据中不存在该学生所对应的学号和姓名!\n\t\t\t按任意键返回菜单.");
		getch();
	}
	else{
		printf("\t\t\t该学生信息为:\n");
		print_student(p);
		if(p==head->next)head->next=p->next;
		else q->next=p->next;
		free(p); 
		printf("\n\t\t\t删除成功!\n\t\t\t按任意键返回菜单.");
		getch(); 
	}
}
void cancel(struct student *head){				//释放链表 
	struct student *p,*q;
	p=head;
	while(p!=NULL){
		q=p;
		p=p->next;
		free(q);
	}
	printf("\n\t\t\t删除成功!\n\t\t\t但学生信息.csv文件中还存在上一次保存的文件，若需全部删除请手动删除.\n\t\t\t按任意键返回菜单.");
	getch();
	em=0;
	sa=0;										//待会要保存
}
void modefy(struct student *head){				//更新学生信息 
	struct student *p=head->next;
	char a[20];	
	int n;	
	sa=0;										//待会要保存
	printf("\n\t\t\t1、按照学号查询后修改");
	printf("\n\t\t\t2、按照姓名查询后修改\n\t\t\t请输入你的选择:");
	while(1){
		n=get();
		if(n<1||n>2)printf("\t\t\t只能输入1或2哦!");
		else break; 
	}
	if(n==1){
		printf("\t\t\t请输入该学生的学号(-1结束此次修改):"); 
		get_num(a);
		if(strcmp(a,"-1")==0)printf("\n\t\t\t按任意键返回菜单.");//不想做就-1跳到菜单 
		else{
			while (p){
				if(strcmp(a,p->number)==0){
					print_student(p);
					break;
				} 
				p = p->next;
			}
			if(p==NULL)printf("\n\t\t\t不存在该生信息.\n\t\t\t按任意键返回菜单.");
			else{
				printf("\n\t\t\t请输入该学生的学号(换行结束输入):"); 
				get_num(p->number);
				assign(p);
				printf("\n\t\t\t修改成功!按任意键返回菜单.");
			}
		}
		getch();
	}
	else if(n==2){
		printf("\t\t\t请输入该学生的姓名(-1结束此次修改):"); 
		gets(a);
		if(strcmp(a,"-1")==0)printf("\n\t\t\t按任意键返回菜单.");
		else{
			while (p){
				if(strcmp(a,p->name)==0){
					print_student(p);
					break;
				} 
				p = p->next;
			}
			if(p==NULL)printf("\n\t\t\t不存在该生信息.\n\t\t\t按任意键返回菜单.");
			else{
				printf("\n\t\t\t请输入该学生的学号(换行结束输入):"); 
				get_num(p->number);
				assign(p);
				printf("\n\t\t\t修改成功!按任意键返回菜单.");
			}
		}
		getch();
	}
}
void assign(struct student *s){					//对于学生信息的输入函数 
	int n;	
	time_t t;									//对于出生年输入的时候，自行以年龄进行保存 
	struct tm *p;
	time(&t);
	
	p=localtime(&t);							//或许当地时间以便计算年龄 
	printf("\t\t\t现在输入该学生的姓名(长度小于10):");
	gets(s->name);
	printf("\t\t\t请输入该学生的出生年(int):");
	while(1){
		n=get();
		if(n<1900||n>2100)printf("\t\t\t输入有误!出生年应1900~2100之间！请重新输入:");
		else break;
	}
	s->year=1900+p->tm_year-n;
	printf("\t\t\t请输入该学生的语文成绩(int):");
	s->grade_chinese=get();
	printf("\t\t\t请输入该学生的数学成绩(int):");
	s->grade_math=get();
	printf("\t\t\t请输入该学生的英语成绩(int):");	
	s->grade_english=get();
	s->Total_score=s->grade_chinese+s->grade_math+s->grade_english;
	s->average=s->Total_score/3.0;
}	

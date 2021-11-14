#include"head.h"

void sort(struct student *head){				//排序 
	int n=0;
	if(head==NULL){
		system("color F4");
		printf("\t\t\t没有数据可以排序.\n\t\t\t按任意键返回主菜单.");
		getch();
	}
	else{
		while(1){
			n=sort_menu();						//菜单，并得到选择 
			switch(n){
				case 1:sort_number(head);break;	//按照学号		
				case 2:sort_name(head);break;	//按照姓名	
				case 3:sort_chinese(head);break;//语文成绩		
				case 4:sort_math(head);break;	//数学成绩	
				case 5:sort_english(head);break;//英语成绩 
				case 6:sort_total(head);break;	//总分 
				case 7:sort_year(head);break;	//年龄 
				case 8:break;					//退出 
			}
			if(n==8)break;
		}				
	}
}
void sort_number(struct student *head){			//按照学号排序 
	int n=1; 
	struct student*pre,*p,*tail=NULL;
	sa=0;
	while(head->next!=tail){					//冒泡，接下来都是一个模子 
		pre=head;
		p=head->next;
		while(p->next!=tail){
			if(strcmp(p->number,p->next->number)>0){
		     	pre->next=p->next;				//通过交换节点 
		     	p->next=pre->next->next;
		     	pre->next->next=p;
		    }
		    else p=p->next;
			pre=pre->next;
		}
		tail=p;
	}
	p=head->next;
	while(p){
			printf("\n\t\t\t第%d名   学号:%-12s 姓名:%-8s\t语文成绩:%d  数学成绩:%d  英语成绩:%d  总分:%d   平均分:%.2f\n"
			,n++,p->number,p->name,p->grade_chinese,p->grade_math,p->grade_english,p->Total_score,p->average);
		p=p->next;
	}
	printf("\n\t\t\t输入结束!按任意值返回菜单!");
	getch();
}
void sort_name(struct student *head){			//按照姓名的字典序排列 
	struct student*pre,*p,*tail=NULL;
	int n=1;
	sa=0;
	while(head->next!=tail){
		pre=head;
		p=head->next;
		while(p->next!=tail){
			if(strcmp(p->name,p->next->name)>0){
		     	pre->next=p->next;
		     	p->next=pre->next->next;
		     	pre->next->next=p;
		    }
		    else p=p->next;
			pre=pre->next;
		}
		tail=p;
	}
	p=head->next;
	while(p){
			printf("\n\t\t\t第%d名  姓名:%s \t学号:%s\t语文成绩:%d  数学成绩:%d  英语成绩:%d  总分:%d   平均分:%.2f\n"
			,n++,p->name,p->number,p->grade_chinese,p->grade_math,p->grade_english,p->Total_score,p->average);
		p=p->next;
	}
	printf("\n\t\t\t输入结束!按任意值返回菜单!");
	getch();
}
void sort_chinese(struct student *head){		//语文成绩的排列 
	struct student*pre,*p,*tail=NULL;
	int n=1;
	sa=0;
	while(head->next!=tail){
		pre=head;
		p=head->next;
		while(p->next!=tail){
			if(p->grade_chinese<p->next->grade_chinese){
		     	pre->next=p->next;
		     	p->next=pre->next->next;
		     	pre->next->next=p;
		    }
		    else p=p->next;
			pre=pre->next;
		}
		tail=p;
	}
	p=head->next;
	while(p){
			printf("\n\t\t\t第%d名  语文成绩:%d\t学号:%s\t姓名:%s\t数学成绩:%d  英语成绩:%d  总分:%d   平均分:%.2f\n"
			,n++,p->grade_chinese,p->number,p->name,p->grade_math,p->grade_english,p->Total_score,p->average);
		p=p->next;
	}
	printf("\n\t\t\t输入结束!按任意值返回菜单!");
	getch();
}		
void sort_math(struct student *head){			//数学成绩的排序 
	struct student*pre,*p,*tail=NULL;
	int n=1;
	sa=0;
	while(head->next!=tail){
		pre=head;
		p=head->next;
		while(p->next!=tail){
			if(p->grade_math<p->next->grade_math){
		     	pre->next=p->next;
		     	p->next=pre->next->next;
		     	pre->next->next=p;
		    }
		    else p=p->next;
			pre=pre->next;
		}
		tail=p;
	}
	p=head->next;
	while(p){
			printf("\n\t\t\t第%d名  数学成绩:%d\t学号:%s\t姓名:%s\t语文成绩:%d  英语成绩:%d  总分:%d   平均分:%.2f\n"
			,n++,p->grade_math,p->number,p->name,p->grade_chinese,p->grade_english,p->Total_score,p->average);
		p=p->next;
	}
	printf("\n\t\t\t输入结束!按任意值返回菜单!");
	getch();
}
void sort_english(struct student *head){		//英语成绩的排列 
	struct student*pre,*p,*tail=NULL;
	int n=1;
	sa=0;
	while(head->next!=tail){
		pre=head;
		p=head->next;
		while(p->next!=tail){
			if(p->grade_english<p->next->grade_english){
		     	pre->next=p->next;
		     	p->next=pre->next->next;
		     	pre->next->next=p;
		    }
		    else p=p->next;
			pre=pre->next;
		}
		tail=p;
	}
	p=head->next;
	while(p){
			printf("\n\t\t\t第%d名  英语成绩:%d\t学号:%s\t姓名:%s\t数学成绩:%d  语文成绩:%d  总分:%d   平均分:%.2f\n"
			,n++,p->grade_english,p->number,p->name,p->grade_math,p->grade_chinese,p->Total_score,p->average);
		p=p->next;
	}
	printf("\n\t\t\t输入结束!按任意值返回菜单!");
	getch();
}
void sort_total(struct student *head){			//总分的排列 
	struct student*pre,*p,*tail=NULL;
	int n=1;
	sa=0;
	while(head->next!=tail){
		pre=head;
		p=head->next;
		while(p->next!=tail){
			if(p->Total_score<p->next->Total_score){
		     	pre->next=p->next;
		     	p->next=pre->next->next;
		     	pre->next->next=p;
		    }
		    else p=p->next;
			pre=pre->next;
		}
		tail=p;
	}
	p=head->next;
	while(p){
			printf("\n\t\t\t第%d名  总分:%d\t学号:%s\t姓名:%s\t语文成绩:%d  数学成绩:%d  英语成绩:%d   平均分:%.2f\n"
			,n++,p->Total_score,p->number,p->name,p->grade_chinese,p->grade_math,p->grade_english,p->average);
		p=p->next;
	}
	printf("\n\t\t\t输入结束!按任意值返回菜单!");
	getch();
}
void sort_year(struct student *head){			//年龄的排列 
	struct student*pre,*p,*tail=NULL;
	int n=1;
	sa=0;
	while(head->next!=tail){
		pre=head;
		p=head->next;
		while(p->next!=tail){
			if(p->year<p->next->year){
		     	pre->next=p->next;
		     	p->next=pre->next->next;
		     	pre->next->next=p;
		    }
		    else p=p->next;
			pre=pre->next;
		}
		tail=p;
	}
	p=head->next;
	while(p){
			printf("\n\t\t\t第%d名  年龄:%d\t学号:%s\t姓名:%s\t数学成绩:%d  语文成绩:%d  英语成绩:%d  总分:%d   平均分:%.2f\n"
			,n++,p->year,p->number,p->name,p->grade_math,p->grade_chinese,p->grade_english,p->Total_score,p->average);
		p=p->next;
	}
	printf("\n\t\t\t输入结束!按任意值返回菜单!");
	getch();
}
int sort_menu(){								//排序菜单 
	int i;
	char *sentence[]={"学生学号(低->高)","学生姓名(低->高)","语文成绩(高->低)","数学成绩(高->低)","英语成绩(高->低)","总分、平均分(高->低)","按照年龄(高->低)","退出学生排序菜单"};
	do{
		system("cls");
		system("color F0");			
		printf("\n\n\t\t\t\t\t\t 学生信息管理系统\n\n\t\t\t");	  
		for(i=0;i<29;i++)printf("*");
		printf("排序菜单");
		for(i=0;i<29;i++)printf("*");
		printf("\n\t\t\t*\t\t\t\t\t\t\t\t *\n");
		for(i=0;i<8;i++){
			printf("\t\t\t*\t\t\t%d、%s\t\t\t *\n",i+1,sentence[i]);
			printf("\t\t\t*\t\t\t\t\t\t\t\t *\n");
		} 
		printf("\t\t\t");
		for(i=0;i<66;i++)printf("*");
		printf("\n\t\t\t请输入你的选择:");
		i=get();
		if(i<1||i>8)error();
		else return i;		
	}while(1);
}

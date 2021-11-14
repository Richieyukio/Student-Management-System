#include"head.h"

void statistic(struct student *head){			//统计 
	int n=0;
	if(head==NULL){
		system("color F4");
		printf("\t\t\t没有数据可以统计.\n\t\t\t按任意键返回主菜单.");
		getch();
	}
	else{
		while(1){
			n=statistic_menu();						//菜单，并得到选择 
			switch(n){
				case 1:statistic_number(head);break;	
				case 2:statistic_situation(head);break;
				case 3:break;
			}
			if(n==3)break;
		}				
	}
}
int statistic_menu(){							//统计菜单 
	int i;
	char *sentence[]={"各科成绩情况\t","各个学生各科情况","退出学生统计菜单"};
	do{
		system("cls");
		system("color F0");			
		printf("\n\n\t\t\t\t\t\t 学生信息管理系统\n\n\t\t\t");	  
		for(i=0;i<29;i++)printf("*");
		printf("统计菜单");
		for(i=0;i<29;i++)printf("*");
		printf("\n\t\t\t*\t\t\t\t\t\t\t\t *\n");
		for(i=0;i<3;i++){
			printf("\t\t\t*\t\t\t%d、%s\t\t\t *\n",i+1,sentence[i]);
			printf("\t\t\t*\t\t\t\t\t\t\t\t *\n");
		} 
		printf("\t\t\t");
		for(i=0;i<66;i++)printf("*");
		printf("\n\t\t\t请输入你的选择:");
		i=get();
		if(i<1||i>3)error();
		else return i;		
	}while(1);
}
void statistic_number(struct student *head){	//各个成绩情况统计 
	struct student *p=head->next;
	float x=0,y=0,z=0;							//各科平均分 
	double l=0,m=0,v=0,i=0,j=0,k=0;
	int a,b,c,n;								//各科及格线 
	int num1=0,num2=0,num3=0,max,min; 
	printf("\t\t\t请输入各科成绩的及格线！\n");
	printf("\t\t\t语文:");
	a=get();
	printf("\t\t\t数学:");
	b=get();
	printf("\t\t\t英语:"); 
	c=get();
	printf("\n\t\t\t\t\t语文\t\t数学\t\t英语\n");
	while(p){
		if(p->grade_chinese<a)num1++;
		if(p->grade_math<b)num2++;
		if(p->grade_english<c)num3++;
		x+=p->grade_chinese;
		y+=p->grade_math;
		z+=p->grade_english;
		p=p->next;
	}
	n=len(head);
	x/=n;
	y/=n;
	z/=n;
	p=head->next;
	printf("\t\t\t平均分\t\t%.2f\t\t%.2f\t\t%.2f\n",x,y,z);
	while(p){
		i=p->grade_chinese-x;
		j=p->grade_math-y;
		k=p->grade_english-z;
		l+=pow(i,2);
		m+=pow(j,2);
		v+=pow(k,2);
		p=p->next;
	}
	printf("\t\t\t方差\t\t%.2lf\t\t%.2lf\t\t%.2lf\n",l/n,m/n,v/n);
	printf("\t\t\t标准差\t\t%.2lf\t\t%.2lf\t\t%.2lf\n",sqrt(l/n),sqrt(m/n),sqrt(v/n));
	p=head->next;
	a=p->grade_chinese,b=p->grade_math,c=p->grade_english;
	while(p){
		if(p->grade_chinese>a)a=p->grade_chinese;
		if(p->grade_math>b)b=p->grade_math;
		if(p->grade_english>c)c=p->grade_english;
		p=p->next;
	}
	printf("\t\t\t最高分\t\t%d\t\t%d\t\t%d\n",a,b,c);
	p=head->next;
	x=p->grade_chinese,y=p->grade_math,z=p->grade_english;
	while(p){
		if(p->grade_chinese<a)a=p->grade_chinese;
		if(p->grade_math<b)b=p->grade_math;
		if(p->grade_english<c)c=p->grade_english;
		p=p->next;
	}
	printf("\t\t\t最低分\t\t%d\t\t%d\t\t%d\n",a,b,c);
	printf("\t\t\t不及格人数\t%d\t\t%d\t\t%d\n",num1,num2,num3);
	printf("\t\t\t不及格率\t%.2f\t\t%.2f\t\t%.2f\n\n",1.0*num1/n,1.0*num2/n,1.0*num3/n);
	printf("\n\t\t\t输出结束!\n\t\t\t按任意键返回菜单.");
	getch();
}	
void statistic_situation(struct student *head){	//学生成绩情况统计 
	struct student *p=head->next;
	float x=0,y=0,z=0,n;
	while(p){
		x+=p->grade_chinese;
		y+=p->grade_math;
		z+=p->grade_english;
		p=p->next;
	}
	n=len(head);
	x/=n;
	y/=n;
	z/=n;
	p=head->next;
	printf("\n\t\t\t学号\t\t姓名\t\t语文\t\t数学\t\t英语\n");
	printf("\t\t\t平均分\t\t\t\t%.2f\t\t%.2f\t\t%.2f\n",x,y,z);
	while(p){
		printf("\t\t\t%-12s\t%-8s\t",p->number,p->name);
		if(p->grade_chinese>=x+20)printf("++\t\t");
		else if(p->grade_chinese<=x-20)printf("--\t\t");
		else if(p->grade_chinese>x+5)printf("+\t\t");
		else if(p->grade_chinese<x-5)printf("-\t\t");
		else printf("=\t\t");
		
		if(p->grade_math>=y+20)printf("++\t\t");
		else if(p->grade_math<=y-20)printf("--\t\t");
		else if(p->grade_math>y+5)printf("+\t\t");
		else if(p->grade_math<y-5)printf("-\t\t");
		else printf("=\t\t");
		
		if(p->grade_english>=z+20)printf("++\t\t");
		else if(p->grade_english<=z-20)printf("--\t\t");
		else if(p->grade_english>z+5)printf("+\t\t");
		else if(p->grade_english<z-5)printf("-\t\t");
		else printf("=\t\t");
		printf("\n");
		
		p=p->next;
	}
	printf("\n\t\t\t说明：++ 大于等于平均分20分， + 大于平均分5分， = 在平均分左右5分之内\n");
	printf("\t\t\t\t-- 小于等于平均分20分， - 小于平均分5分\n");
	printf("\n\t\t\t输出结束!\n\t\t\t按任意键返回菜单.");
	getch();
}

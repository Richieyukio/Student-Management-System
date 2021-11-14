#include"head.h"

void save(struct student *head){				//保存 
	FILE *fp;
	struct student *p;
	if(head==NULL){								//是否被创建过 
		system("color F4");
		printf("\t\t\t数据还未创建.\n\t\t\t按任意键返回主菜单.");
		getch();
	}
	else{
		p=head->next; 
		if((fp=fopen("学生成绩.csv","w"))==NULL){//文件是否打开成功 
			printf("\n\t\t\t学生成绩管理系统.txt文件打开失败!");
			getch();
		}
		else{
			sa=1;
			fprintf(fp,"学号,姓名,年龄,语文成绩,数学成绩,英语成绩,总分,平均分\n");
			while(p){
				fprintf(fp,"'%s,%s,%d,%d,%d,%d,%d,%.2f\n",p->number,p->name,p->year,p->grade_chinese,p->grade_math,p->grade_english,p->Total_score,p->average);
				p=p->next;
			}
			fclose(fp);
			printf("\n\t\t\t文件保存成功!保存在当前文件夹之内，为学生成绩管理系统.csv");
			printf("\n\t\t\t按任意键返回菜单."); 
			sa=1;
			getch();
		}		
	}
}

#include"head.h"

void quit(struct student *head){				//退出程序 
	struct student *p,*q;
	char flag[20]; 
	int i;
	if(sa==0){									//是否需要保存 
		printf("\n\t\t\t学生信息是否需要保存!\n");
		printf("\t\t\t1、是\n\t\t\t2、否\n\t\t\t"); 
		do{
			fflush(stdin);
			printf("请输入你的选择:");
			gets(flag);
			if(strlen(flag)>1){
				printf("\n\t\t\t输入错误!请重新输入(1或2):");
				continue;
			}
			i=atoi(flag);
			if(i==1||i==2)break;
			else printf("\n\t\t\t输入错误!请重新输入(1或2):");
		}while(1);
		if(i==1){
			save(head);							//保存和释放 
			p=head;
			while(p!=NULL){
				q=p;
				p=p->next;
				free(q);
			}
		}
	}
	printf("\n\n\t\t\t谢谢你的使用!");
	Sleep(1000);
	exit(0);
}

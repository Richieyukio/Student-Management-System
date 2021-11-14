#include"head.h"

struct student *create(struct student *head){	//创建学生数据 
	struct student *p,*tail=NULL;
	char num[100];								//临时存放学生信息的变量 
	FILE *fp;									
	p=node(p);									//为临时p申请空间		
	
	if(head==NULL){								//判断头指针是否为空 
		em=1;
		head=node(head);						//创建头结点 
		if((fp=fopen("学生成绩管理系统.csv","r"))!=NULL&&fgets(num,100,fp)!=NULL){	//判断是否有读取文件的存在，以及文件是否为空 
			while(1){
				if(fgets(num,100,fp)==NULL)break;
				char *buf=num;					//为.csv读取文件是用%s得到一行，并用判断“，”的方式达到赋值的目的 
				char *token=strtok(num,",");
				int index=0;
				while(token!=NULL){
					switch(index){
						case 0:strcpy(p->number,token+1);break;
						case 1:strcpy(p->name,token);break;
						case 2:p->year=atoi(token);break;
						case 3:p->grade_chinese=atoi(token);break;
						case 4:p->grade_math=atoi(token);break;
						case 5:p->grade_english=atoi(token);break;
						case 6:p->Total_score=atoi(token);break;
						case 7:p->average=atof(token);break;
					}
					index++;
					token=strtok(NULL,",");
				}
				if(head->next==NULL)head->next=p;
				else tail->next=p;				
				tail=p;
				p=node(p);
			}
			free(p);
			printf("\n\t\t\t读取学生成绩管理系统.csv文件成功!\n\t\t\t按任意键返回主菜单!");
			getch();
			return head; 
		} 
		else{									//手动输入数据 
			printf("\t\t\t让我们来创建填写学生信息吧!\n");
			printf("\t\t\t我们需要输入学生的学号、姓名、出生年、语文成绩、数学成绩、英语成绩.\n");
			printf("\t\t\t请输入第一个学生的学号(字符只能含有Z):");
			get_num(num); 
			while(strcmp(num,"-1")!=0){			//判断输入是否为-1 
				if(head!=NULL)judge(num,head);
				strcpy(p->number,num);
				assign(p);						//赋值
				
				if(head->next==NULL)head->next=p;//定位 
				else tail->next=p;
				tail=p;
				printf("\n\t\t\t输入-1结束信息填写或者输入下一名学生的学号(int):");
				get_num(num);
				p=node(p);
			}
			free(p);							//最后一个多余的节点释放 
			sa=0;								//判断文件是否需要保存 
			printf("\n\t\t\t学生信息已经创建成功!\n\t\t\t按任意键返回主菜单.");
			getch();
			return head;
		}	
	}
	else{
		system("color F4");
		printf("\t\t\t学生信息数据已经创建.\n\t\t\t按任意键返回主菜单.");
		getch();
		return head;
	}		
}

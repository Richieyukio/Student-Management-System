#include"head.h"

struct student *create(struct student *head){	//����ѧ������ 
	struct student *p,*tail=NULL;
	char num[100];								//��ʱ���ѧ����Ϣ�ı��� 
	FILE *fp;									
	p=node(p);									//Ϊ��ʱp����ռ�		
	
	if(head==NULL){								//�ж�ͷָ���Ƿ�Ϊ�� 
		em=1;
		head=node(head);						//����ͷ��� 
		if((fp=fopen("ѧ���ɼ�����ϵͳ.csv","r"))!=NULL&&fgets(num,100,fp)!=NULL){	//�ж��Ƿ��ж�ȡ�ļ��Ĵ��ڣ��Լ��ļ��Ƿ�Ϊ�� 
			while(1){
				if(fgets(num,100,fp)==NULL)break;
				char *buf=num;					//Ϊ.csv��ȡ�ļ�����%s�õ�һ�У������жϡ������ķ�ʽ�ﵽ��ֵ��Ŀ�� 
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
			printf("\n\t\t\t��ȡѧ���ɼ�����ϵͳ.csv�ļ��ɹ�!\n\t\t\t��������������˵�!");
			getch();
			return head; 
		} 
		else{									//�ֶ��������� 
			printf("\t\t\t��������������дѧ����Ϣ��!\n");
			printf("\t\t\t������Ҫ����ѧ����ѧ�š������������ꡢ���ĳɼ�����ѧ�ɼ���Ӣ��ɼ�.\n");
			printf("\t\t\t�������һ��ѧ����ѧ��(�ַ�ֻ�ܺ���Z):");
			get_num(num); 
			while(strcmp(num,"-1")!=0){			//�ж������Ƿ�Ϊ-1 
				if(head!=NULL)judge(num,head);
				strcpy(p->number,num);
				assign(p);						//��ֵ
				
				if(head->next==NULL)head->next=p;//��λ 
				else tail->next=p;
				tail=p;
				printf("\n\t\t\t����-1������Ϣ��д����������һ��ѧ����ѧ��(int):");
				get_num(num);
				p=node(p);
			}
			free(p);							//���һ������Ľڵ��ͷ� 
			sa=0;								//�ж��ļ��Ƿ���Ҫ���� 
			printf("\n\t\t\tѧ����Ϣ�Ѿ������ɹ�!\n\t\t\t��������������˵�.");
			getch();
			return head;
		}	
	}
	else{
		system("color F4");
		printf("\t\t\tѧ����Ϣ�����Ѿ�����.\n\t\t\t��������������˵�.");
		getch();
		return head;
	}		
}

#include"head.h"

void update(struct student *head){				//���� 
	int n=0;
	if(head==NULL){
		system("color F4");
		printf("\t\t\tû�����ݿ��Ը���.\n\t\t\t��������������˵�.");
		getch();
	}
	else{
		while(1){
			n=update_menu();					//�˵������õ�ѡ�� 
			switch(n){
				case 1:increase(head);break;	//����һ��ѧ����Ϣ 
				case 2:release(head);break;		//ɾ��һ��ѧ����Ϣ 
				case 3:cancel(head);break;		//ɾ������ 
				case 4:modefy(head);break;		//�޸�һ��ѧ����Ϣ 
				case 5:break;					//�˳� 
			}
			if(n==5)break;
		}				
	} 
}
int update_menu(){								//������һ�����²˵� 
	int i;
	char *sentence[]={"����һ��ѧ����Ϣ","ɾ��һ��ѧ����Ϣ","ɾ��ȫ��ѧ����Ϣ","�޸�һ��ѧ����Ϣ","�˳�����ѧ������"};
	do{
		system("cls");
		system("color F0");			
		printf("\n\n\t\t\t\t\t\t ѧ����Ϣ����ϵͳ\n\n\t\t\t");	  
		for(i=0;i<29;i++)printf("*");
		printf("���²˵�");
		for(i=0;i<29;i++)printf("*");
		printf("\n\t\t\t*\t\t\t\t\t\t\t\t *\n");
		for(i=0;i<5;i++){
			printf("\t\t\t*\t\t\t%d��%s\t\t\t *\n",i+1,sentence[i]);
			printf("\t\t\t*\t\t\t\t\t\t\t\t *\n");
		} 
		printf("\t\t\t");
		for(i=0;i<66;i++)printf("*");
		printf("\n\t\t\t���������ѡ��:");
		i=get();
		if(i<1||i>5)error();
		else return i;		
	}while(1);
}
void increase(struct student *head){			//����һ��ѧ����Ϣ 
	struct student *s,*p=head;
	int a,k=0;
	sa=0;										//����Ҫ���� 
	printf("\t\t\t�����㽫Ҫ�����λ��(1-%d):",len(head)+1);//�жϣ�������ʾ
	do{
		a=get();
		if(a<1||a>len(head)+1)printf("\t\t\t�������!����������:");
		else break; 
	} while(1);
	s=node(s);
	printf("\t\t\t�������ѧ����ѧ��:"); 
	get_num(s->number);
	judge(s->number,head);						//�ж������Ƿ����ظ�ѧ�� 
	assign(s);
	while(p!=NULL&&k<a-1){
		p=p->next;
		k++;
	}
	s->next = p->next;
	p->next = s;
	printf("\n\t\t\t����ɹ�!����������ز˵�.");
	getch();		
}
void release(struct student *head){				//ɾ��һ��ѧ����Ϣ 
	struct student *p=head->next,*q=NULL;
	char a[20],b[20];
	sa=0;										//����Ҫ����
	printf("\t\t\t�����������ѧ����ѧ�ź�����:\n");
	printf("\t\t\tѧ��(�Ի�����Ϊ�������):");
	get_num(a);
	printf("\t\t\t����(�Ի�����Ϊ�������):"); 
	gets(b);
	while(p){
		if(strcmp(a,p->number)==0&&strcmp(b,p->name)==0)break;
		q=p;
		p=p->next;
	}
	if(p==NULL){
		printf("\t\t\t�����в����ڸ�ѧ������Ӧ��ѧ�ź�����!\n\t\t\t����������ز˵�.");
		getch();
	}
	else{
		printf("\t\t\t��ѧ����ϢΪ:\n");
		print_student(p);
		if(p==head->next)head->next=p->next;
		else q->next=p->next;
		free(p); 
		printf("\n\t\t\tɾ���ɹ�!\n\t\t\t����������ز˵�.");
		getch(); 
	}
}
void cancel(struct student *head){				//�ͷ����� 
	struct student *p,*q;
	p=head;
	while(p!=NULL){
		q=p;
		p=p->next;
		free(q);
	}
	printf("\n\t\t\tɾ���ɹ�!\n\t\t\t��ѧ����Ϣ.csv�ļ��л�������һ�α�����ļ�������ȫ��ɾ�����ֶ�ɾ��.\n\t\t\t����������ز˵�.");
	getch();
	em=0;
	sa=0;										//����Ҫ����
}
void modefy(struct student *head){				//����ѧ����Ϣ 
	struct student *p=head->next;
	char a[20];	
	int n;	
	sa=0;										//����Ҫ����
	printf("\n\t\t\t1������ѧ�Ų�ѯ���޸�");
	printf("\n\t\t\t2������������ѯ���޸�\n\t\t\t���������ѡ��:");
	while(1){
		n=get();
		if(n<1||n>2)printf("\t\t\tֻ������1��2Ŷ!");
		else break; 
	}
	if(n==1){
		printf("\t\t\t�������ѧ����ѧ��(-1�����˴��޸�):"); 
		get_num(a);
		if(strcmp(a,"-1")==0)printf("\n\t\t\t����������ز˵�.");//��������-1�����˵� 
		else{
			while (p){
				if(strcmp(a,p->number)==0){
					print_student(p);
					break;
				} 
				p = p->next;
			}
			if(p==NULL)printf("\n\t\t\t�����ڸ�����Ϣ.\n\t\t\t����������ز˵�.");
			else{
				printf("\n\t\t\t�������ѧ����ѧ��(���н�������):"); 
				get_num(p->number);
				assign(p);
				printf("\n\t\t\t�޸ĳɹ�!����������ز˵�.");
			}
		}
		getch();
	}
	else if(n==2){
		printf("\t\t\t�������ѧ��������(-1�����˴��޸�):"); 
		gets(a);
		if(strcmp(a,"-1")==0)printf("\n\t\t\t����������ز˵�.");
		else{
			while (p){
				if(strcmp(a,p->name)==0){
					print_student(p);
					break;
				} 
				p = p->next;
			}
			if(p==NULL)printf("\n\t\t\t�����ڸ�����Ϣ.\n\t\t\t����������ز˵�.");
			else{
				printf("\n\t\t\t�������ѧ����ѧ��(���н�������):"); 
				get_num(p->number);
				assign(p);
				printf("\n\t\t\t�޸ĳɹ�!����������ز˵�.");
			}
		}
		getch();
	}
}
void assign(struct student *s){					//����ѧ����Ϣ�����뺯�� 
	int n;	
	time_t t;									//���ڳ����������ʱ��������������б��� 
	struct tm *p;
	time(&t);
	
	p=localtime(&t);							//������ʱ���Ա�������� 
	printf("\t\t\t���������ѧ��������(����С��10):");
	gets(s->name);
	printf("\t\t\t�������ѧ���ĳ�����(int):");
	while(1){
		n=get();
		if(n<1900||n>2100)printf("\t\t\t��������!������Ӧ1900~2100֮�䣡����������:");
		else break;
	}
	s->year=1900+p->tm_year-n;
	printf("\t\t\t�������ѧ�������ĳɼ�(int):");
	s->grade_chinese=get();
	printf("\t\t\t�������ѧ������ѧ�ɼ�(int):");
	s->grade_math=get();
	printf("\t\t\t�������ѧ����Ӣ��ɼ�(int):");	
	s->grade_english=get();
	s->Total_score=s->grade_chinese+s->grade_math+s->grade_english;
	s->average=s->Total_score/3.0;
}	

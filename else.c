#include"head.h"

void error(){									//���ⱨ��			
	system("color F4");
	printf("\n\t\t\t�������!���������룡����������ز˵���");
	getch();
}
struct student *node(struct student *head){		//���Ľ��� 
	head=(struct student*)malloc(sizeof(struct student));
	head->next=NULL;
	return head;
}
void get_num(char *a){							//��ȡѧ�� 
	int i=0,flag;
	do{	
		flag=1;									//����жϵı��� 
		fflush(stdin);
		fgets(a,15,stdin);
		a[strlen(a)-1]='\0';
		if(strlen(a)==0)printf("\t\t\t���벻��Ϊ��!����������:");
		else{
			for(i=0;a[i]!='\0';i++){
				if(isdigit(a[i])==0){			//�ж���������������У�����Z 
					if(a[i]!='Z')flag=0;
				}
			}
			if(strcmp(a,"-1")==0)flag=1;
			if(flag==1)break;
			else printf("\t\t\t�������!����������:");
		}
	}while(1);
}
int get(){										//�������ݵ����� 
	char a[20],ch;
	int i,flag,n;
	do{
		do{
			i=0;
			while((ch=getchar())!='\n'){		//����Ϊ�� 
				a[i++]=ch;
			}
			a[i]='\0';
			n=strlen(a);
			if(n==0)printf("\t\t\t���벻��Ϊ��!����������:");
		}while(n==0);
		flag=1;
		for(i=0;i<n;i++){						//ֻ��Ϊ���� 
			if(isdigit(a[i])==0)flag=0;
		}
		if(flag){
			i=atoi(a);
			fflush(stdin);
			return i;
		}
		else printf("\t\t\t�������!����������:");
		fflush(stdin); 
	}while(1);
}
void print_student(struct student *p){			//�������ѧ������Ϣ 
	printf("\n\t\t\tѧ��:%s  ����:%s   ����:%d\n\t\t\t���ĳɼ�:%d  ��ѧ�ɼ�:%d  Ӣ��ɼ�:%d  �ܷ�:%d   ƽ����:%.2f\n"
			,p->number,p->name,p->year,p->grade_chinese,p->grade_math,p->grade_english,p->Total_score,p->average);	
}
void print(struct student *head){				//�������ѧ������ 
	struct student *p; 
	if(head==NULL){
		system("color F4");
		printf("\t\t\t���ݻ�δ����.\n\t\t\t����������ز˵�");
		getch();
	}
	else {
		p=head->next;
		printf("\t\t\tѧ��\t\t����\t  ����\t  ���ĳɼ�\t��ѧ�ɼ�\tӢ��ɼ�\t�ܷ�\tƽ����\n");
		while(p!=NULL){
			printf("\t\t\t%-12s\t%-8s   %d\t     %d\t\t    %d\t\t  %d\t\t%d\t %.2f\n",p->number,p->name,p->year,p->grade_chinese,p->grade_math,p->grade_english,p->Total_score,p->average);
			p=p->next;
		}
		printf("\n\t\t\t����ɹ�!\n");
		printf("\t\t\t��������������˵�.");
		getch();
	}
}

void judge(char *num,struct student *head){		//�ж�ѧ�������Ƿ��ظ� 
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
			printf("\n\t\t\t�������!�Ѵ�����ͬѧ��!\n\t\t\t����������:");
			get_num(num);
			flag=0;
		}
	}
}
int len(struct student *head){					//������ 
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
		printf("����:");
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

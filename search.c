#include"head.h"

void search(struct student *head){				//��ѯ 
	int n;
	if(head==NULL){
		system("color F4");
		printf("\t\t\tû�����ݿ��Բ�ѯ.\n\t\t\t��������������˵�.");
		getch();
	}
	else{
		while(1){
			n=search_menu();					//��ӡ��ѯ�˵���������ֵ 
			switch(n){
				case 1:search_num(head);break;	//��ѯѧ�� 
				case 2:search_name(head);break;	//��ѯ���� 
				case 3:break;					//�˳� 
			}
			if(n==3)break;	
		}		
	} 
} 
int search_menu(){								//���Ǹ���ѯ�˵� 
	int i;
	char *sentence[]={"����ѧ�Ų�ѯ","����������ѯ","�˳���ѯ"};
	do{
		system("cls");
		system("color F0");			
		printf("\n\n\t\t\t\t\t\t ѧ����Ϣ����ϵͳ\n\n\t\t\t");	  
		for(i=0;i<29;i++)printf("*");
		printf("��ѯ�˵�");
		for(i=0;i<29;i++)printf("*");
		printf("\n\t\t\t*\t\t\t\t\t\t\t\t *\n");
		for(i=0;i<3;i++){
			printf("\t\t\t*\t\t\t%d��%s\t\t\t\t *\n",i+1,sentence[i]);
			printf("\t\t\t*\t\t\t\t\t\t\t\t *\n");
		} 
		printf("\t\t\t");
		for(i=0;i<66;i++)printf("*");
		printf("\n\t\t\t���������ѡ��:");
		i=get();
		if(i<1||i>3)error();					
		else return i;							//���õ��û���ѡ�� 
	}while(1);
}
void search_num(struct student *head){			//�������Ӧ��ѧ�� 
	struct student *p=head->next;
	char a[20];	
	int flag=0;
	
	printf("\t\t\t����������Ҫ��ѯѧ����ѧ��(�Ի�����Ϊ�������):");
	get_num(a);
	while (p){
		if(strcmp(a,p->number)==0)break;
		p = p->next;
	} 
	if(p==NULL){
		printf("\n\t\t\t�����ڸ�ѧ����ѧ��!\n\t\t\t����������ز˵�.");
		getch();
	}
	else{
		print_student(p);
		printf("\n\t\t\t�������������������ز˵���");
		getch();
	}
}
void search_name(struct student *head){			//�������Ӧ������ 
	struct student *p=head->next;
	char a[20];	
	int flag=0; 
	printf("\t\t\t����������Ҫ��ѯѧ��������(�Ի�����Ϊ�������):");
	gets(a);
	while (p){
		if(strcmp(a,p->name)==0){
			print_student(p);
			flag=1;
		}
		p = p->next;
	}
	if(flag==0){
		printf("\n\t\t\tϵͳ�в����ڸ�ѧ��������!\n\t\t\t����������ز˵�.");
		getch();
	}
	else{
		printf("\n\t\t\t�������������������ز˵���");
		getch();
	}
}


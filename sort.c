#include"head.h"

void sort(struct student *head){				//���� 
	int n=0;
	if(head==NULL){
		system("color F4");
		printf("\t\t\tû�����ݿ�������.\n\t\t\t��������������˵�.");
		getch();
	}
	else{
		while(1){
			n=sort_menu();						//�˵������õ�ѡ�� 
			switch(n){
				case 1:sort_number(head);break;	//����ѧ��		
				case 2:sort_name(head);break;	//��������	
				case 3:sort_chinese(head);break;//���ĳɼ�		
				case 4:sort_math(head);break;	//��ѧ�ɼ�	
				case 5:sort_english(head);break;//Ӣ��ɼ� 
				case 6:sort_total(head);break;	//�ܷ� 
				case 7:sort_year(head);break;	//���� 
				case 8:break;					//�˳� 
			}
			if(n==8)break;
		}				
	}
}
void sort_number(struct student *head){			//����ѧ������ 
	int n=1; 
	struct student*pre,*p,*tail=NULL;
	sa=0;
	while(head->next!=tail){					//ð�ݣ�����������һ��ģ�� 
		pre=head;
		p=head->next;
		while(p->next!=tail){
			if(strcmp(p->number,p->next->number)>0){
		     	pre->next=p->next;				//ͨ�������ڵ� 
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
			printf("\n\t\t\t��%d��   ѧ��:%-12s ����:%-8s\t���ĳɼ�:%d  ��ѧ�ɼ�:%d  Ӣ��ɼ�:%d  �ܷ�:%d   ƽ����:%.2f\n"
			,n++,p->number,p->name,p->grade_chinese,p->grade_math,p->grade_english,p->Total_score,p->average);
		p=p->next;
	}
	printf("\n\t\t\t�������!������ֵ���ز˵�!");
	getch();
}
void sort_name(struct student *head){			//�����������ֵ������� 
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
			printf("\n\t\t\t��%d��  ����:%s \tѧ��:%s\t���ĳɼ�:%d  ��ѧ�ɼ�:%d  Ӣ��ɼ�:%d  �ܷ�:%d   ƽ����:%.2f\n"
			,n++,p->name,p->number,p->grade_chinese,p->grade_math,p->grade_english,p->Total_score,p->average);
		p=p->next;
	}
	printf("\n\t\t\t�������!������ֵ���ز˵�!");
	getch();
}
void sort_chinese(struct student *head){		//���ĳɼ������� 
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
			printf("\n\t\t\t��%d��  ���ĳɼ�:%d\tѧ��:%s\t����:%s\t��ѧ�ɼ�:%d  Ӣ��ɼ�:%d  �ܷ�:%d   ƽ����:%.2f\n"
			,n++,p->grade_chinese,p->number,p->name,p->grade_math,p->grade_english,p->Total_score,p->average);
		p=p->next;
	}
	printf("\n\t\t\t�������!������ֵ���ز˵�!");
	getch();
}		
void sort_math(struct student *head){			//��ѧ�ɼ������� 
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
			printf("\n\t\t\t��%d��  ��ѧ�ɼ�:%d\tѧ��:%s\t����:%s\t���ĳɼ�:%d  Ӣ��ɼ�:%d  �ܷ�:%d   ƽ����:%.2f\n"
			,n++,p->grade_math,p->number,p->name,p->grade_chinese,p->grade_english,p->Total_score,p->average);
		p=p->next;
	}
	printf("\n\t\t\t�������!������ֵ���ز˵�!");
	getch();
}
void sort_english(struct student *head){		//Ӣ��ɼ������� 
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
			printf("\n\t\t\t��%d��  Ӣ��ɼ�:%d\tѧ��:%s\t����:%s\t��ѧ�ɼ�:%d  ���ĳɼ�:%d  �ܷ�:%d   ƽ����:%.2f\n"
			,n++,p->grade_english,p->number,p->name,p->grade_math,p->grade_chinese,p->Total_score,p->average);
		p=p->next;
	}
	printf("\n\t\t\t�������!������ֵ���ز˵�!");
	getch();
}
void sort_total(struct student *head){			//�ֵܷ����� 
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
			printf("\n\t\t\t��%d��  �ܷ�:%d\tѧ��:%s\t����:%s\t���ĳɼ�:%d  ��ѧ�ɼ�:%d  Ӣ��ɼ�:%d   ƽ����:%.2f\n"
			,n++,p->Total_score,p->number,p->name,p->grade_chinese,p->grade_math,p->grade_english,p->average);
		p=p->next;
	}
	printf("\n\t\t\t�������!������ֵ���ز˵�!");
	getch();
}
void sort_year(struct student *head){			//��������� 
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
			printf("\n\t\t\t��%d��  ����:%d\tѧ��:%s\t����:%s\t��ѧ�ɼ�:%d  ���ĳɼ�:%d  Ӣ��ɼ�:%d  �ܷ�:%d   ƽ����:%.2f\n"
			,n++,p->year,p->number,p->name,p->grade_math,p->grade_chinese,p->grade_english,p->Total_score,p->average);
		p=p->next;
	}
	printf("\n\t\t\t�������!������ֵ���ز˵�!");
	getch();
}
int sort_menu(){								//����˵� 
	int i;
	char *sentence[]={"ѧ��ѧ��(��->��)","ѧ������(��->��)","���ĳɼ�(��->��)","��ѧ�ɼ�(��->��)","Ӣ��ɼ�(��->��)","�ܷ֡�ƽ����(��->��)","��������(��->��)","�˳�ѧ������˵�"};
	do{
		system("cls");
		system("color F0");			
		printf("\n\n\t\t\t\t\t\t ѧ����Ϣ����ϵͳ\n\n\t\t\t");	  
		for(i=0;i<29;i++)printf("*");
		printf("����˵�");
		for(i=0;i<29;i++)printf("*");
		printf("\n\t\t\t*\t\t\t\t\t\t\t\t *\n");
		for(i=0;i<8;i++){
			printf("\t\t\t*\t\t\t%d��%s\t\t\t *\n",i+1,sentence[i]);
			printf("\t\t\t*\t\t\t\t\t\t\t\t *\n");
		} 
		printf("\t\t\t");
		for(i=0;i<66;i++)printf("*");
		printf("\n\t\t\t���������ѡ��:");
		i=get();
		if(i<1||i>8)error();
		else return i;		
	}while(1);
}

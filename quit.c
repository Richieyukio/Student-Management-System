#include"head.h"

void quit(struct student *head){				//�˳����� 
	struct student *p,*q;
	char flag[20]; 
	int i;
	if(sa==0){									//�Ƿ���Ҫ���� 
		printf("\n\t\t\tѧ����Ϣ�Ƿ���Ҫ����!\n");
		printf("\t\t\t1����\n\t\t\t2����\n\t\t\t"); 
		do{
			fflush(stdin);
			printf("���������ѡ��:");
			gets(flag);
			if(strlen(flag)>1){
				printf("\n\t\t\t�������!����������(1��2):");
				continue;
			}
			i=atoi(flag);
			if(i==1||i==2)break;
			else printf("\n\t\t\t�������!����������(1��2):");
		}while(1);
		if(i==1){
			save(head);							//������ͷ� 
			p=head;
			while(p!=NULL){
				q=p;
				p=p->next;
				free(q);
			}
		}
	}
	printf("\n\n\t\t\tлл���ʹ��!");
	Sleep(1000);
	exit(0);
}

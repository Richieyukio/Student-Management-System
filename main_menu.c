#include"head.h"

int main_menu(){
	char  a[20];								//ͨ���ַ����õ��û������� 
	int i;										//�õ����ַ���ת���ɵ����ͱ��� 
	do{	
		print_menu();							//������һ���˵��Ĵ�ӡ 
		fflush(stdin);
		gets(a);								
		if(strlen(a)>1){						//�жϳ��ȣ��Ͼ�ֻ��Ҫһ���ַ� 
			error();							//���� 
			continue;
		}
		i=atoi(a);								//�ַ������� 
		if(i<1||i>8)error();					//���͵���һ���жϣ��Ƿ��ڷ�Χ�� 
		else return i;
	}while(1);
}
void print_menu(){								//ר�Ŵ�ӡ�˵� 
	int i;
	char *sentence[]={"����ѧ������","����ѧ������",
					  "����ѧ������","����ѧ������",
					  "ͳ��ѧ������","����ѧ������", 
					  "���ѧ������","�˳�����ϵͳ"};
	system("cls");
	system("color F0");				  
	printf("\n\n\t\t\t\t\t\t ѧ����Ϣ����ϵͳ\n\n\t\t\t"); 
	for(i=0;i<30;i++)printf("*");
	printf("���˵�");
	for(i=0;i<30;i++)printf("*");
	printf("\n\t\t\t*\t\t\t\t\t\t\t\t *\n");
	for(i=1;i<9;i+=2){
		printf("\t\t\t*\t%d��%s\t\t\t   %d��%s\t *\n",i,sentence[i-1],i+1,sentence[i]);
		printf("\t\t\t*\t\t\t\t\t\t\t\t *\n");
	} 
	printf("\t\t\t");
	for(i=0;i<66;i++)printf("*");
	printf("\n\t\t\t���������ѡ��:");
} 

#include"head.h"
/*��������ڲ��ٵĺ����������ȿ���else.c�ļ�������head.h*/ 
int sa=1,em=1;
int main(){
	struct student *head=NULL;					//����ͷָ�� 
	int n=0;									//����ѡ��ʱ�ı��� 
	while(1){
		n=main_menu();							//���˵��ĳ��֣����õ�ѡ�� 
		switch(n){
			case 1:head=create(head);break;		//�������� 
			case 2:search(head);break;			//�������� 
			case 3:update(head);break;			//�������� ������ɾ���ģ� 
			case 4:sort(head);break;			//�����ݽ������� 
			case 5:statistic(head);break;		//�������ݽ���ͳ�� 
			case 6:save(head);break;			//�������� 
			case 7:print(head);break;			//��ӡ���� 
			case 8:quit(head);					//�˳����� 
		}
		if(em==0)head=NULL;						//�ж�ѧ����Ϣ�Ƿ�ȫ��ɾ�� 
	}
	return 0; 
}

#include"head.h"

void save(struct student *head){				//���� 
	FILE *fp;
	struct student *p;
	if(head==NULL){								//�Ƿ񱻴����� 
		system("color F4");
		printf("\t\t\t���ݻ�δ����.\n\t\t\t��������������˵�.");
		getch();
	}
	else{
		p=head->next; 
		if((fp=fopen("ѧ���ɼ�.csv","w"))==NULL){//�ļ��Ƿ�򿪳ɹ� 
			printf("\n\t\t\tѧ���ɼ�����ϵͳ.txt�ļ���ʧ��!");
			getch();
		}
		else{
			sa=1;
			fprintf(fp,"ѧ��,����,����,���ĳɼ�,��ѧ�ɼ�,Ӣ��ɼ�,�ܷ�,ƽ����\n");
			while(p){
				fprintf(fp,"'%s,%s,%d,%d,%d,%d,%d,%.2f\n",p->number,p->name,p->year,p->grade_chinese,p->grade_math,p->grade_english,p->Total_score,p->average);
				p=p->next;
			}
			fclose(fp);
			printf("\n\t\t\t�ļ�����ɹ�!�����ڵ�ǰ�ļ���֮�ڣ�Ϊѧ���ɼ�����ϵͳ.csv");
			printf("\n\t\t\t����������ز˵�."); 
			sa=1;
			getch();
		}		
	}
}

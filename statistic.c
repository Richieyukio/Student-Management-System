#include"head.h"

void statistic(struct student *head){			//ͳ�� 
	int n=0;
	if(head==NULL){
		system("color F4");
		printf("\t\t\tû�����ݿ���ͳ��.\n\t\t\t��������������˵�.");
		getch();
	}
	else{
		while(1){
			n=statistic_menu();						//�˵������õ�ѡ�� 
			switch(n){
				case 1:statistic_number(head);break;	
				case 2:statistic_situation(head);break;
				case 3:break;
			}
			if(n==3)break;
		}				
	}
}
int statistic_menu(){							//ͳ�Ʋ˵� 
	int i;
	char *sentence[]={"���Ƴɼ����\t","����ѧ���������","�˳�ѧ��ͳ�Ʋ˵�"};
	do{
		system("cls");
		system("color F0");			
		printf("\n\n\t\t\t\t\t\t ѧ����Ϣ����ϵͳ\n\n\t\t\t");	  
		for(i=0;i<29;i++)printf("*");
		printf("ͳ�Ʋ˵�");
		for(i=0;i<29;i++)printf("*");
		printf("\n\t\t\t*\t\t\t\t\t\t\t\t *\n");
		for(i=0;i<3;i++){
			printf("\t\t\t*\t\t\t%d��%s\t\t\t *\n",i+1,sentence[i]);
			printf("\t\t\t*\t\t\t\t\t\t\t\t *\n");
		} 
		printf("\t\t\t");
		for(i=0;i<66;i++)printf("*");
		printf("\n\t\t\t���������ѡ��:");
		i=get();
		if(i<1||i>3)error();
		else return i;		
	}while(1);
}
void statistic_number(struct student *head){	//�����ɼ����ͳ�� 
	struct student *p=head->next;
	float x=0,y=0,z=0;							//����ƽ���� 
	double l=0,m=0,v=0,i=0,j=0,k=0;
	int a,b,c,n;								//���Ƽ����� 
	int num1=0,num2=0,num3=0,max,min; 
	printf("\t\t\t��������Ƴɼ��ļ����ߣ�\n");
	printf("\t\t\t����:");
	a=get();
	printf("\t\t\t��ѧ:");
	b=get();
	printf("\t\t\tӢ��:"); 
	c=get();
	printf("\n\t\t\t\t\t����\t\t��ѧ\t\tӢ��\n");
	while(p){
		if(p->grade_chinese<a)num1++;
		if(p->grade_math<b)num2++;
		if(p->grade_english<c)num3++;
		x+=p->grade_chinese;
		y+=p->grade_math;
		z+=p->grade_english;
		p=p->next;
	}
	n=len(head);
	x/=n;
	y/=n;
	z/=n;
	p=head->next;
	printf("\t\t\tƽ����\t\t%.2f\t\t%.2f\t\t%.2f\n",x,y,z);
	while(p){
		i=p->grade_chinese-x;
		j=p->grade_math-y;
		k=p->grade_english-z;
		l+=pow(i,2);
		m+=pow(j,2);
		v+=pow(k,2);
		p=p->next;
	}
	printf("\t\t\t����\t\t%.2lf\t\t%.2lf\t\t%.2lf\n",l/n,m/n,v/n);
	printf("\t\t\t��׼��\t\t%.2lf\t\t%.2lf\t\t%.2lf\n",sqrt(l/n),sqrt(m/n),sqrt(v/n));
	p=head->next;
	a=p->grade_chinese,b=p->grade_math,c=p->grade_english;
	while(p){
		if(p->grade_chinese>a)a=p->grade_chinese;
		if(p->grade_math>b)b=p->grade_math;
		if(p->grade_english>c)c=p->grade_english;
		p=p->next;
	}
	printf("\t\t\t��߷�\t\t%d\t\t%d\t\t%d\n",a,b,c);
	p=head->next;
	x=p->grade_chinese,y=p->grade_math,z=p->grade_english;
	while(p){
		if(p->grade_chinese<a)a=p->grade_chinese;
		if(p->grade_math<b)b=p->grade_math;
		if(p->grade_english<c)c=p->grade_english;
		p=p->next;
	}
	printf("\t\t\t��ͷ�\t\t%d\t\t%d\t\t%d\n",a,b,c);
	printf("\t\t\t����������\t%d\t\t%d\t\t%d\n",num1,num2,num3);
	printf("\t\t\t��������\t%.2f\t\t%.2f\t\t%.2f\n\n",1.0*num1/n,1.0*num2/n,1.0*num3/n);
	printf("\n\t\t\t�������!\n\t\t\t����������ز˵�.");
	getch();
}	
void statistic_situation(struct student *head){	//ѧ���ɼ����ͳ�� 
	struct student *p=head->next;
	float x=0,y=0,z=0,n;
	while(p){
		x+=p->grade_chinese;
		y+=p->grade_math;
		z+=p->grade_english;
		p=p->next;
	}
	n=len(head);
	x/=n;
	y/=n;
	z/=n;
	p=head->next;
	printf("\n\t\t\tѧ��\t\t����\t\t����\t\t��ѧ\t\tӢ��\n");
	printf("\t\t\tƽ����\t\t\t\t%.2f\t\t%.2f\t\t%.2f\n",x,y,z);
	while(p){
		printf("\t\t\t%-12s\t%-8s\t",p->number,p->name);
		if(p->grade_chinese>=x+20)printf("++\t\t");
		else if(p->grade_chinese<=x-20)printf("--\t\t");
		else if(p->grade_chinese>x+5)printf("+\t\t");
		else if(p->grade_chinese<x-5)printf("-\t\t");
		else printf("=\t\t");
		
		if(p->grade_math>=y+20)printf("++\t\t");
		else if(p->grade_math<=y-20)printf("--\t\t");
		else if(p->grade_math>y+5)printf("+\t\t");
		else if(p->grade_math<y-5)printf("-\t\t");
		else printf("=\t\t");
		
		if(p->grade_english>=z+20)printf("++\t\t");
		else if(p->grade_english<=z-20)printf("--\t\t");
		else if(p->grade_english>z+5)printf("+\t\t");
		else if(p->grade_english<z-5)printf("-\t\t");
		else printf("=\t\t");
		printf("\n");
		
		p=p->next;
	}
	printf("\n\t\t\t˵����++ ���ڵ���ƽ����20�֣� + ����ƽ����5�֣� = ��ƽ��������5��֮��\n");
	printf("\t\t\t\t-- С�ڵ���ƽ����20�֣� - С��ƽ����5��\n");
	printf("\n\t\t\t�������!\n\t\t\t����������ز˵�.");
	getch();
}

//ͷ�ļ� 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#include<ctype.h>
#include<process.h>
#include<time.h>

//�ṹ�����Ͷ��� 
struct student{									//ѧ���Ľṹ�� 
	char number[20];
	char name[20];
	int year; 
	int grade_chinese;
	int grade_math;
	int grade_english;
	int Total_score;
	float average; 
	struct student *next;
};

//�������� 
int main_menu();								//�������˵��õ��û�ѡ�� 
void print_menu();								//��ӡ���˵�		
void error();									//��ӡ����ı���		
struct student *node(struct student *head);		//���Ľ��� 
struct student *create(struct student *head);	//ѧ����Ϣ�Ĵ��� 
int get();										//�õ��������� 
void get_num(char *a);							//�õ�ѧ�ţ����ַ��������� 
void judge(char *num,struct student *head);		//�ж�����ѧ���Ƿ��ظ� 

void search(struct student *head);				//��ѯ 
int search_menu();								//���ֲ�ѯ�˵����õ��û�ѡ�� 
void search_num(struct student *head);			//��ѧ�ŵ� 
int len(struct student *head);					//���㳤�ȵģ����ٸ�ѧ����Ϣ�� 
void search_name(struct student *head);			// �������� 
void print_student(struct student *p);			//��ӡһ��ѧ������Ϣ 

void update(struct student *head);				//���� 
int update_menu();								//���ָ��²˵����õ��û�ѡ�� 
void increase(struct student *head);			//���� 
void release(struct student *head);				//ɾ��һ��ѧ����Ϣ 
void cancel(struct student *head);				//ɾ��ȫ��ѧ����Ϣ 
void modefy(struct student *head);				//�޸�һ��ѧ����Ϣ 
void assign(struct student *s);					//��ֵ 

void sort(struct student *head);				//���� 
int sort_menu();								//��������˵����õ��û����� 
void sort_number(struct student *head);			 
void sort_name(struct student *head);	
void sort_chinese(struct student *head);		
void sort_math(struct student *head);	
void sort_english(struct student *head);
void sort_total(struct student *head);
void sort_year(struct student *head);

void statistic(struct student *head);			//ͳ�� 
int statistic_menu();
void statistic_number(struct student *head);
void statistic_situation(struct student *head);

void save(struct student *head);				//���� 
void print(struct student *head);				//��� 
void quit(struct student *head);				//�˳� 

//ȫ�ֱ������� 
extern sa,em;									//����ж��˳�ʱ�Ƿ���Ҫ���� 

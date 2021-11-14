//头文件 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#include<ctype.h>
#include<process.h>
#include<time.h>

//结构体类型定义 
struct student{									//学生的结构体 
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

//函数声明 
int main_menu();								//呈现主菜单得到用户选择 
void print_menu();								//打印主菜单		
void error();									//打印问题的报错		
struct student *node(struct student *head);		//结点的建立 
struct student *create(struct student *head);	//学生信息的创建 
int get();										//得到整型数据 
void get_num(char *a);							//得到学号，以字符类型输入 
void judge(char *num,struct student *head);		//判断输入学号是否重复 

void search(struct student *head);				//查询 
int search_menu();								//呈现查询菜单，得到用户选择 
void search_num(struct student *head);			//查学号的 
int len(struct student *head);					//计算长度的（多少个学生信息） 
void search_name(struct student *head);			// 查姓名的 
void print_student(struct student *p);			//打印一个学生的信息 

void update(struct student *head);				//更新 
int update_menu();								//呈现更新菜单，得到用户选择 
void increase(struct student *head);			//插入 
void release(struct student *head);				//删除一个学生信息 
void cancel(struct student *head);				//删除全部学生信息 
void modefy(struct student *head);				//修改一个学生信息 
void assign(struct student *s);					//赋值 

void sort(struct student *head);				//排序 
int sort_menu();								//呈现排序菜单，得到用户输入 
void sort_number(struct student *head);			 
void sort_name(struct student *head);	
void sort_chinese(struct student *head);		
void sort_math(struct student *head);	
void sort_english(struct student *head);
void sort_total(struct student *head);
void sort_year(struct student *head);

void statistic(struct student *head);			//统计 
int statistic_menu();
void statistic_number(struct student *head);
void statistic_situation(struct student *head);

void save(struct student *head);				//保存 
void print(struct student *head);				//输出 
void quit(struct student *head);				//退出 

//全局变量声明 
extern sa,em;									//最后判断退出时是否需要保存 

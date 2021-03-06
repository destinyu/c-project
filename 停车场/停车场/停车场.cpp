// 停车场.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stack.h"
#include "queue.h"
#include "stdlib.h"
#include <iomanip>
#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 2
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char  status;
char e;
int number, time1,money,pm;
SqStack P, L;
LinkQueue W;

int m,n,k,a,b,c,l;
void Select(char status) {
	
	InitQueue(&W);
	while (cin >> e>>number>>time1) {
		if (e == 'E') {
			cout << "退出管理系统成功"<<endl;
			break;
		}
		else if (e == 'A') {
			int s = StackLength(P);
			if (s < l) {
				Push(&P, number, time1);
				cout << "车牌为:" << number << "的车停在"<<s+1<<"号停车位" << endl;

			}
			
			else {
				
				EnQueue(&W, number);
				cout << "车牌为:" << number << "的车请在便道旁等候" << endl;
			}
		}
		else if (e == 'D') {
			GetTopdata(P, &m);
			if (m == number) {
				Pop(&P, &n,&k);
				money = pm * (time1 - k);
				//time-k
				//sub the money
				cout << "该车所停留的时间为：" << time1 - k << "分钟" << endl;
				cout << "车费为：" << money << "元" << endl;
				int s = StackLength(P);
				if(s<2){
					if (!QueueEmpty(W)) {
						//InitQueue(&W);
						DeQueue(&W, &c);
						Push(&P, c, time1);
					}
				}
			}
			else {
				Pop(&P, &n, &k);
				Push(&L, n, k);
				Pop(&P, &a, &b);
				money = pm * (time1- b);
				cout << "该车所停留的时间为：" << time1 - b << "分钟" << endl;
				cout << "车费为：" << money << "元"<<endl;//time-b
				Pop(&L, &n, &k);
				Push(&P, n, k);
				int r = StackLength(P);
				if (r<2) {
					if (!QueueEmpty(W)) {
						DeQueue(&W, &c);
						Push(&P, c,time1);
					}
				}
			}
		}
		else {
			cout << "输入有误，请重新输入：" << endl;
			break;
	}
	
	}
}

int main()
{
	for (int i = 0;i <= 20;i++) {


		cout << setw(60) << "******************************"<<endl;
		cout << setw(60) << "*                            *"<<endl;
		cout << setw(60) << "*   欢迎使用停车场管理系统   *"<<endl;
		cout << setw(60) << "*                            *"<<endl;
		cout << setw(60) << "******************************"<<endl;
		//cout <<setw(45) <<i << "%";
		system("CLS");
	}
	cout << "请输入车库的容量：";
	cin >> l;
	cout << "该停车场的容量为" << l << endl;
	cout << "请输入每小时收费标准:";
	cin >> pm;
	cout << "该停车场的收费标准为每小时" << pm << "元" << endl;
	cout << setw(80) << "**********************************************" << endl;
	cout << setw(80) << "*提示：A代表进停车场，B代表出停车场,E为退出键*" << endl;
	cout << setw(80) << "* 请依次输入该车的进出状态，车牌号与出入时间 *" << endl;
	cout << setw(80) << "*                                            *" << endl;
	cout << setw(80) << "**********************************************" << endl;
	Select(e);

    return 0;
}


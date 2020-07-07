/*
Phím Enter : 13
Phím ESC: 27
Phím Tab: 9
Mui tên lên: 72
Mui tên xuong: 80
Mui tên sang trái: 75
Mui tên sang phai: 77
Phím cách: 32

Black  | 0
Blue   | 1
Green  | 2
Cyan   | 3
Red   | 4
Magenta  | 5
Brown  | 6
Light Gray | 7
Dark Gray | 8
Light Blue | 9
Light Green | 10
Light Cyan | 11
Light Red | 12
Light Magenta| 13
Yellow  | 14
White  | 15 

329: E
493: B
698: F^
659: E^
783: G^
392: G
440: A
587: D
349: F
*/
#include "pch.h"
#include "console.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>

#pragma comment(lib, "winmm.lib")

using namespace std;
void diemcao();
void menu1(), menu2(), menu3(), menu4();
void play(), play1(), play2(), play3(), play4();
void map1(), map2(), map3(), map4();
const int maxc = 100, maxd = 100;

void size()
{
	HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
	PCONSOLE_FONT_INFOEX font = new CONSOLE_FONT_INFOEX();
	font->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(cons, 0, font);
	font->dwFontSize.X = 8;
	font->dwFontSize.Y = 26;
	SetCurrentConsoleFontEx(cons, 0, font);
}
void setdiemcao(int j, int diem, string ten[],int d[])
{
	fstream f;
	string t;
	bool kt;
	cout << "\t\tBan vua dat diem cao moi" << endl;
	do
	{
		kt = true;
		cout << "\t\tNhap ten cua ban: ";
		cin >> t;
		for (int h = 0;h < 5;h++)
			if (t == ten[h])
				kt = false;
		if (!kt)
			cout << "\t\tTen ban nhap da bi trung. Moi nhap lai" << endl;
	} while (!kt);
	for (int i = 5;i> j;i--)
	{
		ten[i] = ten[i-1];
		d[i] = d[i-1];
	}
	ten[j] = t;
	d[j] = diem;
	f.open("diemcao.txt", ios::out, ios::trunc);
	for (int i = 0;i < 5;i++)
		f << ten[i] << "\t" << d[i] << endl;
	f.close();
	diemcao();
}
void xetdiemcao(int diem)
{
	fstream f;
	string ten[10];
	int d[10];
	int i = 0;
	f.open("diemcao.txt", ios::in);
	while (!f.eof())
	{
		f >> ten[i];
		f >> d[i];
		i++;
	}
	f.close();
	for (int j = 0;j < i;j++)
		if (diem > d[j])
		{
			setdiemcao(j, diem, ten, d);
			break;
		}
}
void win(int diem)
{
	PlaySound(L"win.wav", NULL, SND_LOOP || SND_ASYNC);
	char ch;
	cout << endl << endl;
	TextColor(14);
	cout << "\t\t\tYOU WIN" << endl;
	cout << "Diem cua ban: " << diem << endl;
	xetdiemcao(diem);
	TextColor(15);
	Sleep(500);
	cout << "\t\tBan co muon choi tiep" << endl;
	cout << "\t \t y:Yes\tn:No" << endl;
	do
	{
		ch = _getch();
		if (ch == 121)
			play();
		if (ch == 110)
			menu1();
	} while (ch!=121 && ch!=110);
}
void thua()
{
	PlaySound(L"lose.wav", NULL, SND_LOOP || SND_ASYNC);
	char ch;
	cout << endl << endl;
	TextColor(14);
	cout << "\t\t\tGAME OVER" << endl;
	TextColor(15);
	Sleep(500);
	cout << "\t\tBan co muon choi tiep" << endl;
	cout << "\t \t y:Yes\tn:No" << endl;
	do
	{
		ch = _getch();
		if (ch == 121)
			play();
		if (ch == 110)
			menu1();
	} while (ch != 121 && ch != 110);
}
void vemap(int a[][maxd], int c, int d, int diem)
{
	for (int i = 0;i < c;i++)
	{
		for (int j = 0;j < d;j++)
		{
			if (a[i][j] == 0)
				cout << " ";
			if (a[i][j] == 1)
			{
				TextColor(4);
				cout << "*";
			}
			if (a[i][j] == 2)
			{
				TextColor(10);
				cout << "o";
			}
			if (a[i][j] == 3)
			{
				TextColor(11);
				cout << "|";
			}
			if (a[i][j] == 4)
			{
				TextColor(11);
				cout << "=";
			}
		}
		cout << endl;
	}
	TextColor(15);
	cout << "Diem cua ban: " << diem << endl;
	if (diem == 0)
		thua();
}
void map1()
{
	PlaySound(L"level1.wav", NULL, SND_LOOP || SND_ASYNC);
	int diem = 600;
	char ch;
	int m = 2, n = 1;
	int a[maxc][maxd] = 
	{ 
	{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
	{3,0,1,1,1,1,1,1,1,1,1,1,1,0,3},
	{3,2,0,0,0,0,1,0,0,0,1,0,0,0,3},
	{3,0,1,1,1,0,1,0,1,0,1,0,1,0,3},
	{3,0,1,0,0,0,1,0,1,0,1,0,1,0,3},
	{3,0,1,0,1,0,0,0,1,0,0,0,1,0,3},
	{3,0,1,1,1,1,1,1,1,1,1,1,1,0,3},
	{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
	};
	do
	{
		system("cls");
		vemap(a, 8, 15,diem);
		if (m == 2 && n == 1)
		{
			do
			{
				ch = _getch();
				if (ch == 27)
				{
					cout << "\t\tBan that su muon thoat" << endl;
					cout << "\t \t y:Yes\tn:No" << endl;
					do
					{
						ch = _getch();
						if (ch == 121)
							play();
						if (ch == 110)
						{
							system("cls");
							vemap(a, 8, 15, diem);
						}
					} while (ch != 121 && ch != 110);
				}
				if (ch == -32)
				{
					ch = _getch();
					if (ch == 77)
						if (a[m][n+1] == 0)
						{
							a[m][n+1] = 2;
							a[m][n] = 0;
							n++;
							diem -= 20;
						}
				}
			} while (ch != 77);
		}
		else
		do
		{
			ch = _getch();
			if (ch == 27)
			{
				cout << "\t\tBan that su muon thoat" << endl;
				cout << "\t \t y:Yes\tn:No" << endl;
				do
				{
					ch = _getch();
					if (ch == 121)
						play();
					if (ch == 110)
					{
						system("cls");
						vemap(a, 8, 15, diem);
					}
				} while (ch != 121 && ch != 110);
			}
			if (ch == -32)
			{
				ch = _getch();
				if (ch == 72)
					if (a[m-1][n] == 0)
					{
						a[m-1][n] = 2;
						a[m][n] = 0;
						m--;
						diem -= 20;
					}
				if (ch == 75)
					if (a[m][n-1] == 0)
					{
						a[m][n-1] = 2;
						a[m][n] = 0;
						n--;
						diem -= 20;
					}
				if (ch == 77)
					if (a[m][n+1] == 0)
					{
						a[m][n+1] = 2;
						a[m][n] = 0;
						n++;
						diem -= 20;
					}
				if (ch == 80)
					if (a[m+1][n] == 0)
					{
						a[m+1][n] = 2;
						a[m][n] = 0;
						m++;
						diem -= 20;
					}
			}
		} while (ch != 72 && ch != 75 && ch != 77 && ch != 80);
	} while(a[2][13]!=2);
	win(diem+20);
}
void map2()
{
	PlaySound(L"level2.wav", NULL, SND_LOOP || SND_ASYNC);
	int diem = 1500;
	char ch;
	int m = 10, n = 7;
	int a[maxc][maxd] =
	{
	{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
	{3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3},
	{3,1,0,0,0,0,0,0,0,0,0,0,0,0,1,3},
	{3,1,0,1,1,1,1,1,1,1,1,1,1,0,1,3},
	{3,1,0,0,0,0,0,0,1,0,0,0,0,0,1,3},
	{3,1,1,1,1,1,1,0,1,0,1,1,1,1,1,3},
	{3,1,0,0,0,0,0,0,1,0,1,0,0,0,1,3},
	{3,1,0,1,1,1,1,1,1,0,1,0,1,0,1,3},
	{3,1,0,0,0,0,0,0,1,0,0,0,1,0,1,3},
	{3,1,1,1,1,1,1,0,1,1,1,1,1,0,1,3},
	{3,0,0,0,0,0,0,2,0,0,0,0,0,0,0,3},
	{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
	};
	do
	{
		system("cls");
		vemap(a, 12, 17, diem);
		if (m == 10 && n == 7)
		{
			do
			{
				ch = _getch();
				if (ch == 27)
				{
					cout << "\t\tBan that su muon thoat" << endl;
					cout << "\t \t y:Yes\tn:No" << endl;
					do
					{
						ch = _getch();
						if (ch == 121)
							play();
						if (ch == 110)
						{
							system("cls");
							vemap(a, 12, 17, diem);
						}
					} while (ch != 121 && ch != 110);
				}
				if (ch == -32)
				{
					ch = _getch();
					if (ch == 72)
						if (a[m - 1][n] == 0)
						{
							a[m - 1][n] = 2;
							a[m][n] = 0;
							m--;
							diem -= 20;
						}
				}
			} while (ch != 72);
		}
		else
			do
			{
				ch = _getch();
				if (ch == 27)
				{
					cout << "\t\tBan that su muon thoat" << endl;
					cout << "\t \t y:Yes\tn:No" << endl;
					do
					{
						ch = _getch();
						if (ch == 121)
							play();
						if (ch == 110)
						{
							system("cls");
							vemap(a, 12, 17, diem);
						}
					} while (ch != 121 && ch != 110);
				}
				if (ch == -32)
				{
					ch = _getch();
					if (ch == 72)
						if (a[m - 1][n] == 0)
						{
							a[m - 1][n] = 2;
							a[m][n] = 0;
							m--;
							diem -= 20;
						}
					if (ch == 75)
						if (a[m][n - 1] == 0)
						{
							a[m][n - 1] = 2;
							a[m][n] = 0;
							n--;
							diem -= 20;
						}
					if (ch == 77)
						if (a[m][n + 1] == 0)
						{
							a[m][n + 1] = 2;
							a[m][n] = 0;
							n++;
							diem -= 20;
						}
					if (ch == 80)
						if (a[m + 1][n] == 0)
						{
							a[m + 1][n] = 2;
							a[m][n] = 0;
							m++;
							diem -= 20;
						}
				}
			} while (ch != 72 && ch != 75 && ch != 77 && ch != 80);
	} while (a[10][13] != 2);
	win(diem+20);
}
void map3()
{
	PlaySound(L"level3.wav", NULL, SND_LOOP || SND_ASYNC);
	int diem = 1800;
	char ch;
	int m = 2, n = 1;
	int a[maxc][maxd] =
	{
	{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
	{3,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,3},
	{3,2,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,3},
	{3,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,3},
	{3,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,3},
	{3,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,3},
	{3,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,1,1,0,3},
	{3,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,3},
	{3,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,3},
	{3,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1,0,3},
	{3,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,3},
	{3,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,3},
	{3,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,3},
	{3,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,3},
	{3,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,3},
	{3,0,1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,3},
	{3,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,3},
	{3,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,3},
	{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
	};
	do
	{
		system("cls");
		vemap(a, 19, 21, diem);
		if (m == 2 && n == 1)
		{
			do
			{
				ch = _getch();
				if (ch == 27)
				{
					cout << "\t\tBan that su muon thoat" << endl;
					cout << "\t \t y:Yes\tn:No" << endl;
					do
					{
						ch = _getch();
						if (ch == 121)
							play();
						if (ch == 110)
						{
							system("cls");
							vemap(a, 19, 21, diem);
						}
					} while (ch != 121 && ch != 110);
				}
				if (ch == -32)
				{
					ch = _getch();
					if (ch == 77)
						if (a[m][n + 1] == 0)
						{
							a[m][n + 1] = 2;
							a[m][n] = 0;
							n++;
							diem -= 20;
						}
				}
			} while (ch != 77);
		}
		else
			do
			{
				ch = _getch();
				if (ch == 27)
				{
					cout << "\t\tBan that su muon thoat" << endl;
					cout << "\t \t y:Yes\tn:No" << endl;
					do
					{
						ch = _getch();
						if (ch == 121)
							play();
						if (ch == 110)
						{
							system("cls");
							vemap(a, 19, 21, diem);
						}
					} while (ch != 121 && ch != 110);
				}
				if (ch == -32)
				{
					ch = _getch();
					if (ch == 72)
						if (a[m - 1][n] == 0)
						{
							a[m - 1][n] = 2;
							a[m][n] = 0;
							m--;
							diem -= 20;
						}
					if (ch == 75)
						if (a[m][n - 1] == 0)
						{
							a[m][n - 1] = 2;
							a[m][n] = 0;
							n--;
							diem -= 20;
						}
					if (ch == 77)
						if (a[m][n + 1] == 0)
						{
							a[m][n + 1] = 2;
							a[m][n] = 0;
							n++;
							diem -= 20;
						}
					if (ch == 80)
						if (a[m + 1][n] == 0)
						{
							a[m + 1][n] = 2;
							a[m][n] = 0;
							m++;
							diem -= 20;
						}
				}
			} while (ch != 72 && ch != 75 && ch != 77 && ch != 80);
	} while (a[2][19] != 2);
	win(diem + 20);
}
void map4()
{
	PlaySound(L"level4.wav", NULL, SND_LOOP || SND_ASYNC);
	int diem = 3500;
	char ch;
	int m = 3, n = 1;
	int a[maxc][maxd] =
	{
	{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
	{3,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3},
	{3,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3},
	{3,2,0,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,0,1,0,1,0,1,0,1,3},
	{3,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,3},
	{3,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,3},
	{3,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,1,1,1,0,1,0,1,1,1,1,0,1,0,1,0,1,3},
	{3,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,3},
	{3,0,1,0,0,0,0,0,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,3},
	{3,0,1,0,1,1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,3},
	{3,0,1,0,1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,3},
	{3,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,1,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,1,0,0,1,3},
	{3,0,1,0,1,0,0,0,0,0,1,1,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,0,0,1,0,1,1,3},
	{3,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1,0,0,1,3},
	{3,0,1,0,1,1,0,0,0,0,1,0,1,1,1,0,1,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,1,0,0,1,1,0,1,3},
	{3,0,1,0,0,0,0,1,1,0,1,0,0,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,1,0,1,1,0,1,0,0,1,3},
	{3,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,3},
	{3,0,1,0,1,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,1,3},
	{3,0,1,0,1,0,1,1,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,0,1,1,0,1,3},
	{3,0,1,0,1,0,0,0,1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,1,3},
	{3,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,1,3},
	{3,0,1,0,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,1,1,0,1,0,0,1,3},
	{3,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,1,1,0,1,3},
	{3,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,3},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
	{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
	};
	do
	{
		system("cls");
		vemap(a, 26, 40, diem);
		if (m == 3 && n == 1)
		{
			do
			{
				ch = _getch();
				if (ch == 27)
				{
					cout << "\t\tBan that su muon thoat" << endl;
					cout << "\t \t y:Yes\tn:No" << endl;
					do
					{
						ch = _getch();
						if (ch == 121)
							play();
						if (ch == 110)
						{
							system("cls");
							vemap(a, 26, 40, diem);
						}
					} while (ch != 121 && ch != 110);
				}
				if (ch == -32)
				{
					ch = _getch();
					if (ch == 77)
						if (a[m][n + 1] == 0)
						{
							a[m][n + 1] = 2;
							a[m][n] = 0;
							n++;
							diem -= 20;
						}
				}
			} while (ch != 77);
		}
		else
			do
			{
				ch = _getch();
				if (ch == 27)
				{
					cout << "\t\tBan that su muon thoat" << endl;
					cout << "\t \t y:Yes\tn:No" << endl;
					do
					{
						ch = _getch();
						if (ch == 121)
							play();
						if (ch == 110)
						{
							system("cls");
							vemap(a, 26, 40, diem);
						}
					} while (ch != 121 && ch != 110);
				}
				if (ch == -32)
				{
					ch = _getch();
					if (ch == 72)
						if (a[m - 1][n] == 0)
						{
							a[m - 1][n] = 2;
							a[m][n] = 0;
							m--;
							diem -= 20;
						}
					if (ch == 75)
						if (a[m][n - 1] == 0)
						{
							a[m][n - 1] = 2;
							a[m][n] = 0;
							n--;
							diem -= 20;
						}
					if (ch == 77)
						if (a[m][n + 1] == 0)
						{
							a[m][n + 1] = 2;
							a[m][n] = 0;
							n++;
							diem -= 20;
						}
					if (ch == 80)
						if (a[m + 1][n] == 0)
						{
							a[m + 1][n] = 2;
							a[m][n] = 0;
							m++;
							diem -= 20;
						}
				}
			} while (ch != 72 && ch != 75 && ch != 77 && ch != 80);
	} while (a[24][37] != 2);
	win(diem + 20);
}
void play()
{
	PlaySound(L"level.wav", NULL, SND_LOOP || SND_ASYNC);
	char ch;
	system("cls");
	cout << endl << endl << endl;
	cout << "\t \t";
	TextColor(14);
	cout << "G";
		Sleep(200);
	cout << "A";
		Sleep(200);
	cout << "M";
		Sleep(200);
	cout << "E";
		Sleep(200);
	cout << " ";
		Sleep(200);
	cout << "M";
		Sleep(200);
	cout << "E";
		Sleep(200);
	cout << " ";
		Sleep(200);
	cout << "C";
		Sleep(200);
	cout << "U";
		Sleep(200);
	cout << "N";
		Sleep(200);
	cout << "G";
	cout << endl;
	cout << "\t \t";
	Sleep(200);
	TextColor(15);
	cout << " Chon Level"<< endl;
	Sleep(200);
	TextColor(9);
	cout << "\t1\t";
	TextColor(11);
	cout << "2\t";
		Sleep(200);
	cout << "3\t";
		Sleep(200);
	cout << "4" << endl;
	do
	{
		ch = _getch();
		Beep(587, 200);
		if (ch == 13)
			map1();
		if (ch == 27)
			menu1();
		if (ch == -32)
		{
			ch = _getch();
			if (ch == 77)
				play2();
		}
	} while (ch != 13 && ch != 77);
}
void play1()
{
	char ch;
	system("cls");
	cout << endl << endl << endl;
	cout << "\t \t";
	TextColor(14);
	cout << "GAME ME CUNG";
	cout << endl;
	cout << "\t \t";
	TextColor(15);
	cout << " Chon Level" << endl;
	TextColor(9);
	cout << "\t1\t";
	TextColor(11);
	cout << "2\t3\t4" << endl;
	do
	{
		ch = _getch();
		Beep(587, 200);
		if (ch == 13)
			map1();
		if (ch == 27)
			menu1();
		if (ch == -32)
		{
			ch = _getch();
			if (ch == 77)
				play2();
		}
	} while (ch != 13 && ch != 77);
}
void play2()
{
	char ch;
	system("cls");
	cout << endl << endl << endl;
	cout << "\t \t";
	TextColor(14);
	cout << "GAME ME CUNG";
	cout << endl;
	cout << "\t \t";
	TextColor(15);
	cout << " Chon Level" << endl;
	TextColor(11);
	cout << "\t1\t";
	TextColor(9);
	cout << "2";
	TextColor(11);
	cout << "\t3\t4" << endl;
	do
	{
		ch = _getch();
		Beep(587, 200);
		if (ch == 13)
			map2();
		if (ch == 27)
			menu1();
		if (ch == -32)
		{
			ch = _getch();
			if (ch == 75)
				play1();
			if (ch == 77)
				play3();
		}
	} while (ch != 13 && ch != 75 && ch != 77);
}
void play3()
{
	char ch;
	system("cls");
	cout << endl << endl << endl;
	cout << "\t \t";
	TextColor(14);
	cout << "GAME ME CUNG";
	cout << endl;
	cout << "\t \t";
	TextColor(15);
	cout << " Chon Level" << endl;
	TextColor(11);
	cout << "\t1\t2\t";
	TextColor(9);
	cout << "3\t";
	TextColor(11);
	cout << "4" << endl;
	do
	{
		ch = _getch();
		Beep(587, 200);
		if (ch == 13)
			map3();
		if (ch == 27)
			menu1();
		if (ch == -32)
		{
			ch = _getch();
			if (ch == 75)
				play2();
			if (ch == 77)
				play4();
		}
	} while (ch != 13 && ch != 75 && ch != 77);
}
void play4()
{
	char ch;
	system("cls");
	cout << endl << endl << endl;
	cout << "\t \t";
	TextColor(14);
	cout << "GAME ME CUNG";
	cout << endl;
	cout << "\t \t";
	TextColor(15);
	cout << " Chon Level" << endl;
	TextColor(11);
	cout << "\t1\t2\t3\t";
	TextColor(9);
	cout << "4" << endl;
	do
	{
		ch = _getch();
		Beep(587, 200);
		if (ch == 13)
			map4();
		if (ch == 27)
			menu1();
		if (ch == -32)
		{
			ch = _getch();
			if (ch == 75)
				play3();
		}
	} while (ch != 13 && ch != 75);
}
void loading()
{
	system("cls");
	cout << endl << endl << endl << endl << endl;
	cout << "\t \t";
	TextColor(14);
	cout << "L O A D I N G" << endl;
	cout << "\t \t";
	TextColor(9);
	cout << "-";
		Sleep(500);
	cout << "-";
		Sleep(100);
	cout << "-";
		Sleep(100);
	cout << "-";
		Sleep(100);
	cout << "-";
		Sleep(100);
	cout << "-";
		Sleep(100);
	cout << "-";
		Sleep(1000);
	cout << "-";
		Sleep(1000);
	cout << "-";
		Sleep(500);
	cout << "-";
		Sleep(400);
	cout << "-";
		Sleep(200);
	cout << "-";
		Sleep(200);
	cout << "-";
		Sleep(200);
	play();
}
void diemcao()
{
	fstream f;
	f.open("diemcao.txt", ios::in);
	system("cls");
	TextColor(14);
	cout << endl << endl << endl;
	cout << "****** DIEM CAO ******" << endl;
	TextColor(11);
	while (!f.eof())
	{
		char temp[255];
		f.getline(temp, 255);
		string line = temp;
		cout << line << endl;
	}
	f.close();
	_getch();
}
void gioithieu()
{
	system("cls");
	TextColor(14);
	cout << endl << endl << endl;
	cout << "****** GIOI THIEU ******" << endl;
	TextColor(11);
	cout << "  De tai: Game me cung" << endl;
	cout << "  Lop: IT01" << endl;
	cout << "  Nguoi thuc hien:" << endl;
	cout << "\tNguyen Nhat Thanh\t1851050128" << endl;
	cout << "\tNguyen Le Anh Tuan\t1851050170" << endl;
	_getch();
}
void menu1()
{
	char ch;
	system("cls");
	TextColor(14);
	cout << endl << endl << endl;
	cout << "\t****** MENU ******" << endl;
	TextColor(9);
	cout << "\t    CHOI GAME" << endl;
	TextColor(11);
	cout << "\t    DIEM CAO" << endl;
	cout << "\t   GIOI THIEU" << endl;
	cout << "\t     THOAT" << endl;
	do
	{
		ch = _getch();
		Beep(659, 200);
		if (ch == 13)
			loading();
		if (ch == -32)
		{
			ch = _getch();
			if (ch == 72)
				menu4();
			if (ch == 80)
				menu2();
		}
	} while (ch != 13 && ch != 72 && ch != 80);
}
void menu2()
{
	char ch;
	system("cls");
	TextColor(14);
	cout << endl << endl << endl;
	cout << "\t****** MENU ******" << endl;
	TextColor(11);
	cout << "\t    CHOI GAME" << endl;
	TextColor(9);
	cout << "\t    DIEM CAO" << endl;
	TextColor(11);
	cout << "\t   GIOI THIEU" << endl;
	cout << "\t     THOAT" << endl;
	do
	{
		ch = _getch();
		Beep(659, 200);
		if (ch == 13)
			diemcao();
		if (ch == -32)
		{
			ch = _getch();
			if (ch == 72)
				menu1();
			if (ch == 80)
				menu3();
		}
	} while (ch != 13 && ch != 72 && ch != 80);
}
void menu3()
{
	char ch;
	system("cls");
	TextColor(14);
	cout << endl << endl << endl;
	cout << "\t****** MENU ******" << endl;
	TextColor(11);
	cout << "\t    CHOI GAME" << endl;
	cout << "\t    DIEM CAO" << endl;
	TextColor(9);
	cout << "\t   GIOI THIEU" << endl;
	TextColor(11);
	cout << "\t     THOAT" << endl;
	do
	{
		ch = _getch();
		Beep(659, 200);
		if (ch == 13)
			gioithieu();
		if (ch == -32)
		{
			ch = _getch();
			if (ch == 72)
				menu2();
			if (ch == 80)
				menu4();
		}
	} while (ch != 13 && ch != 72 && ch != 80);
}
void menu4()
{
	char ch;
	system("cls");
	TextColor(14);
	cout << endl << endl << endl;
	cout << "\t****** MENU ******" << endl;
	TextColor(11);
	cout << "\t    CHOI GAME" << endl;
	cout << "\t    DIEM CAO" << endl;
	cout << "\t   GIOI THIEU" << endl;
	TextColor(9);
	cout << "\t     THOAT" << endl;
	do
	{
		ch = _getch();
		Beep(659, 200);
		if (ch == 13)
		{
			system("cls");
			TextColor(15);
			exit(0);
		}
		if (ch == -32)
		{
			ch = _getch();
			if (ch == 72)
				menu3();
			if (ch == 80)
				menu1();
		}
	} while (ch != 13 && ch != 72 && ch != 80);
}
int main()
{
	PlaySound(L"menu.wav", NULL, SND_LOOP || SND_ASYNC);
	size();
	do
	{
		menu1();
	} while(true);
	return 0;
}
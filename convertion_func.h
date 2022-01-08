#ifndef UTILSINENCRYPTION_H
#define UTILSINENCRYPTION_H
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

string byte2bit(string byte);//字符串转比特串
string bit2byte(string bit);//比特串转字符串
string hex2bit(string hex);//十六进制字符串转比特串
string bit2hex(string bit);//比特串转十六进制字符串
void output(string s);//输出二进制字符串
string string_xor(string a,string b);//字符串异或运算




#endif // UTILSINENCRYPTION_H

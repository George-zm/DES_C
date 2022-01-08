#ifndef ENCRYTION_FUNC_H
#define ENCRYTION_FUNC_H
#include<string>
#include<fstream>

using namespace std;

typedef enum
{
    encode,decode
}Mode;

string transform(string bit, int* table, int length);//换位实现
void get_subkey(string* subkey,string key);//子密钥生成部分
string from6to4byS(string B, int i);//通过S盒将6位转为4位
string function(string R,string K);//迭代时f函数的实现
string iterative(string L, string R, string * K, Mode mode);//16次迭代过程计算函数
string Des(string data,string key, Mode mode); //单一模块DES计算
string CBC(string data, string key, string init_vector, Mode mode);//分组链接模式

#endif // ENCRYTION_FUNC_H

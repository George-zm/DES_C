#include <convertion_func.h>


string byte2bit(string byte)//字符串转比特串
{
    int length=byte.length();
    string bit(8*length,0);
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<8;j++)
        {
            bit[i*8+j]=(byte[i]>>(7-j))&1;
        }
    }
    return bit;
}
string bit2byte(string bit)//比特串转字符串
{
    int length=bit.length()/8;
    string byte(length,0);
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<8;j++)
        {
           byte[i]=(byte[i]<<1)+bit[i*8+j];
        }
    }
    return byte;
}
string hex2bit(string hex)
{//十六进制字符串转比特串
    int length = hex.length();
    string bit(length * 4, 0);
    for (int i = 0; i < length; i++)
    {
        hex[i] -= 48;
        if (hex[i] > 9)
            hex[i] -= 7;
        for (int j = 0; j < 4; j++)
            bit[i * 4 + j] = (hex[i] >> (3 - j)) & 1;
    }
    return bit;
}

string bit2hex(string bit)
{//比特串转十六进制字符串
    int length = bit.length() / 4;
    string hex(length, 0);
    for (int i = 0; i < length; i++)
    {
        hex[i] = 0;
        for (int j = 0; j < 4; j++)
            hex[i] = (hex[i] << 1) + bit[i * 4 + j];
        hex[i] += 48;
        if (hex[i] > 57)
            hex[i] += 7;
    }
    return hex;
}

void output(string s)
{//输出二进制字符串
    cout << s.length() << "\t";
    for (unsigned int i = 0; i < s.length(); i++)
    {
        if (s[i] == 1)
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
}

string string_xor(string a,string b)//字符串异或运算
{
    for(unsigned int i=0 ; i<a.length();i++)
    {
        a[i]^=b[i];
    }
    return a;
}

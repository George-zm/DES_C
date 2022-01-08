#include<encrytion_func.h>
#include<convertion_func.h>
#include<tables.h>

using namespace std;



string transform(string bit, int* table, int length)//换位实现
{
    string tmp_str(length,0);
    for(int i=0;i<length;i++)
    {
        tmp_str[i]=bit[table[i]-1];
    }
    return tmp_str;
}

void get_subkey(string* subkey,string key)//子密钥生成部分
{
    string bit_key=byte2bit(key);
    string bit_key_transformed=transform(bit_key,PC1_table,56);
    string C(bit_key_transformed,0,28);
    string D(bit_key_transformed,28,28);
    for(int i=0;i<16;i++)
    {
        C=C.substr(Move_table[i])+C.substr(0,Move_table[i]);
        D=D.substr(Move_table[i])+D.substr(0,Move_table[i]);
        subkey[i]=transform(C+D,PC2_table,48);
    }
}


string from6to4byS(string B, int i)//通过S盒将6位转为4位
{
    int row =B[0]*2+B[5];
    int col=B[1]*8+B[2]*4+B[3]*2+B[4];
    int s=S_box[i][row-1][col-1];
    string C;
    for(i=3;i>=0;i--)
    {
        C+=(int(s>>i)&1);
    }
    return C;
}

string function(string R,string K)//迭代时f函数的实现
{
    string R_E=transform(R,E_table,48);
    string BeforeS= string_xor(R_E,K);
    string f;
    for(int i=0; i<8;i++)
    {
        string B(BeforeS.substr(i*6,6));
        string C=from6to4byS(B,i);
        f+=C;
    }
    return f;
}

string iterative(string L, string R, string * K, Mode mode)//16次迭代过程计算函数
{
    if(mode==encode)
    {
        for (int i=0;i<16;i++)
        {
            string tmp(L);
            L=R;
            R=string_xor(tmp,function(R,K[i]));
        }
    }else{
        for(int i=15;i>=0;i--)
        {
            string tmp(R);
            R=L;
            L=string_xor(tmp,function(L,K[i]));
        }
    }
    return transform(L+R, IP_table_r,64);
    cout<<endl;
}

string Des(string data,string key, Mode mode)//单一模块DES计算
{
    string bit_data;
    if(mode==encode)
    {
        bit_data=byte2bit(data);
    }else{
        bit_data=hex2bit(data);
    }
    string bit_data_r =transform(bit_data,IP_table,64);
    string L(bit_data_r,0,32);
    string R(bit_data_r,32,32);

    string subkey[16];
    get_subkey(subkey,key);//子密钥生成

    string result=iterative(L,R,subkey,mode);
    if(mode==encode)
    {
        return bit2hex(result);
    }else{
        return bit2byte(result);
    }
}

string CBC(string data, string key, string init_vector, Mode mode)//分组链接模式
{
    string result;
    string block;
    string tmp;
    string vector(init_vector);
    if(mode==encode)
    {
        for(int i=0;i<int(data.length()>>3); i++)
        {
            block=data.substr(i*8,8);
            tmp=Des(string_xor(block,vector),key,mode);
            vector=bit2byte(hex2bit(tmp));
            cout << "第 " << i + 1 << " 块:\t" << "cipher: " << tmp << endl << endl;
            result+=tmp;
        }
        cout<<"final cipher:";
    }else{
        for(int i=0;i< int(data.length()>>4);i++)
        {
            tmp=data.substr(i*16,16);
            block= string_xor(Des(tmp,key,mode),vector);
            cout << "第 " << i + 1 << " 块:\t" << "plaintext: " << block << endl << endl;
            vector=bit2byte(hex2bit(tmp));
            result+=block;
        }
        cout<<"final plaintext:"<<endl;
    }
    cout<<result<<endl<<endl;
    return result;
}

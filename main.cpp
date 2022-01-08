#include <iostream>
#include<string>
#include<fstream>

#include<tables.h>
#include<convertion_func.h>
#include<encrytion_func.h>
using namespace std;


int main()
{    string plaintext("This is zzm_George's plaintext.If u see this, successfully decoded!");
     /* ifstream datafile("‪C:\\Users\\Cr\\Documents\\CBC_DES\\plaintext.txt");‬‬
         ostringstream buf;
         buf<<datafile.rdbuf();
     string plaintext=buf.str();
     这一段是文件读取版
     */
         cout<<"plaintext:"<<endl<<plaintext<<endl<<endl;

         string key("abcdefgh");

         char fixchar=0;
         while(plaintext.length()%8!=0)
         {
             plaintext+=fixchar;
         }

         string init_vector("abcdefgh");
         string cipher=CBC(plaintext,key,init_vector,encode);
         plaintext=CBC(cipher,key,init_vector,decode);

         return 0;

}

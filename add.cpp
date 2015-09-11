#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

char numToChar(int num)
{  
    if(num<=9&&num>=0)  
    {  
        num+=48;  
    }  
    else if(num>=10&&num<36) 
    {  
		num = num-10+'A';
    }
	else if(num>=36&&num<62) 
    {  
		num = num-36+'a';
    }  
    return num;  
}  
  
int charToNum(char num)  
{  
    if(num<='9'&&num>='0')  
    {  
        num -= 48;  
    }  
    else if(num>='A'&&num<='Z')  
    {  
		num = num-'A'+10;
    }  
	else if(num>='a'&&num<='z')  
    {  
		num = num-'a'+36;
    }
    return num;  
}  

int anyBinaryToDecimal(string num,int binary)  
{  
    int len=num.size();  
    int decimal_num=0;  
	for(int i=0;i<num.length();i++)  
    {  
		decimal_num *= binary;
        decimal_num += charToNum(num[i]);  
    }  
    return decimal_num;  
}  

string decimalToAnyBinary(int decimal,int binary)  
{  
    string result;
    char temp;  
    while(decimal>0)  
    {  
        temp = decimal%binary;  
        result = numToChar(temp) + result;  
        decimal = decimal/binary;  
    }  
    return result;  
}  

bool SpliteNum(const string& num,string& intPart, string& floatPart)
{
	int pos = num.find(".");
	if(pos==string::npos)
	{
		intPart = num;
		return true;
	}
	intPart = num.substr(0,pos);
	floatPart = num.substr(pos+1);
	return false;
}
int GetGCD(int m, int n)  // 最大公约数 
{
	int max = m>n?m:n;
	int min = m<=n?m:n;
	if(min==0)
		return max;
	max = max%min;
	return GetGCD(min, max);
}
int GetLCM(int m, int n) // 最小公倍数 
{
	int gcd = GetGCD(m,n);
	return m*n/gcd;
}

int FloatAdd(int& carry, string& ans, string s1, int b1, string s2, int b2)
{
	int lcm = GetLCM(b1,b2);
	int deno1 = pow(b1,double(s1.length()))+0.49;
	int deno2 = pow(b2,double(s2.length()))+0.49;
	int denoLCM = GetLCM(deno1,deno2);
	int elem = 0;
	int tmp = b1;
	for(int i=0;i<s1.length();i++)
	{
		elem += charToNum(s1[i])*(denoLCM/tmp);
		tmp *= b1;
	}
	tmp = b2;
	for(int i=0;i<s2.length();i++)
	{
		elem += charToNum(s2[i])*(denoLCM/tmp);
		tmp *= b2;
	}
	
	if(denoLCM<=elem)
	{
		carry = 1;
		elem -= denoLCM;
	}
	int step = denoLCM / lcm;
	while(elem>0)
	{
		int cnt = 0;
		if(step==0)
			break;
		while(elem-step>=0)
		{
			elem -= step;
			cnt ++;
		}
		ans.insert(ans.end(),numToChar(cnt));
		step /= lcm;
	}
	return lcm;
}
class Number
{
private:
	string mNum;
	int mBinary;
public:
	Number(string num, int bin=10)
	: mNum(num), mBinary(bin)
	{}

	string GetNumber() const
	{
		return mNum;
	}
	int GetBinary() const
	{
		return mBinary;
	}
	
	Number operator + (const Number &cNum)
	{
		string NumFirst = GetNumber();
		string NumSecond = cNum.GetNumber();
		string FirstIntPart, FirstFloatPart, SecondIntPart, SecondFloatPart;
		bool FirstIsInt = SpliteNum(NumFirst,FirstIntPart, FirstFloatPart);
		bool SecondIsInt = SpliteNum(NumSecond,SecondIntPart, SecondFloatPart);
		if(FirstIsInt&&SecondIsInt)
		{
			int intAns = anyBinaryToDecimal(FirstIntPart,GetBinary()) + anyBinaryToDecimal(SecondIntPart,cNum.GetBinary());
			string strAns = decimalToAnyBinary(intAns,10);
			return Number(strAns);
		}
		else if(FirstIsInt)
		{
			int intAns = anyBinaryToDecimal(FirstIntPart,GetBinary()) + anyBinaryToDecimal(SecondIntPart,cNum.GetBinary());
			string strAns = decimalToAnyBinary(intAns,cNum.GetBinary()) + SecondFloatPart;
			return Number(strAns,cNum.GetBinary());
		}
		else if(SecondIsInt)
		{
			int intAns = anyBinaryToDecimal(FirstIntPart,GetBinary()) + anyBinaryToDecimal(SecondIntPart,cNum.GetBinary());
			string strAns = decimalToAnyBinary(intAns,GetBinary()) + "." + FirstFloatPart;
			return Number(strAns,GetBinary());
		}
		else
		{
			int intAns = anyBinaryToDecimal(FirstIntPart,GetBinary()) + anyBinaryToDecimal(SecondIntPart,cNum.GetBinary());
			string floatAns;
			int carry = 0;
			int ansBin = FloatAdd(carry, floatAns,FirstFloatPart,GetBinary(),SecondFloatPart,cNum.GetBinary());
			string strIntAns = decimalToAnyBinary(intAns+carry,ansBin);
			return Number(strIntAns+"."+floatAns,ansBin);
		}
	}
	void PrintNum()
	{
		if(mBinary>=62)
			cout << "Error Number" <<endl;
		else
			cout << mNum << " " << mBinary <<endl;
	}
};
 
int main()
{
	Number a("10.G1",32);//Number("1",10);
	Number b("B1.3",16);
	(a+b).PrintNum();
	system("pause");
	return 0;
}

//下面的代码只是支持一些简单的整数的加减乘除运算，而且不支持浮点数，负数或者数字大于9的数字的运算，只是  
//自己简单的写一个代码，将这个过程进行的简单验证，如果需要解决复杂的计算问题，可以上网查找资料来实现！   
#include<iostream>  
#include<cstdio>  
#include<string>  
#include<stack>  
using namespace std;  

stack<char> s;   
stack<int> ss;   

int main()  
{  
    int len1, len2, len, i, j;  
    string str1, str2;//str1为中缀表达式，str2为后缀表达式   
    while (1){  
        //中缀表达式转换为后缀表达式   
        getline(cin, str1);  
        len1 = str1.length();  
        str2.clear();   
        for (i = 0; i < len1; i++){  
            if (str1[i] >= '0' && str1[i] <= '9')   
            str2.push_back(str1[i]);  
            else{  
                if (s.size() == 0 || str1[i] == '(')  
                    s.push(str1[i]);  
                else{  
					char tmp1 = s.top();  
					if (str1[i] == ')'){  
						len = s.size();   
						while (len){  
							char tmp = s.top();   
							s.pop();  
							if (tmp == '(')  
								break;  
							else   
								str2.push_back(tmp);   
							len--;   
						}   
					}   
					else{  
						if (tmp1 == '*' || tmp1 == '/'){  
							if (str1[i] == '*' || str1[i] == '/')   
								s.push(str1[i]);  
							else{  
								len = s.size();   
								while (len){  
									char tmp = s.top();   
									str2.push_back(tmp);  
									s.pop();   
									len--;   
								}  
								s.push(str1[i]);    
							}   
						}   
						else{  
							s.push(str1[i]);   
						}   
					}   
				}    
			}   
		}  
		if (s.size() != 0){  
			len = s.size();   
			while (len){  
				char tmp = s.top();   
				str2.push_back(tmp);  
				s.pop();   
				len--;   
			}   
		}   
		cout << str2 << endl;  
		//由后缀表达式计算结果   
		int temp1, temp2, temp3;   
		len2 = str2.length();  
		for (i = 0; i < len2; i++){  
			if (str2[i] >= '0' && str2[i] <= '9'){   
				int t = str2[i]-48;   
				ss.push(t);   
			}   
			else{  
					temp1 = ss.top();  
					ss.pop();  
					temp2 = ss.top();  
					ss.pop();   
				if (str2[i] == '+'){  
					temp3 = temp2 + temp1;   
				}  
				else if (str2[i] == '-'){  
					temp3 = temp2 - temp1;   
				}  
				else if (str2[i] == '*'){  
					temp3 = temp2 * temp1;   
				}  
				else if (str2[i] == '/'){  
					temp3 = temp2 / temp1;   
				}  
				ss.push(temp3);   
			}  
		}  
		cout << ss.top() << endl;   
	}   
	system("pause");  
} 

#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>

using namespace std;
int main()
{
    string s1,s2;
    int a,b;
    cin>>s1>>s2;
    s1.push_back('Y');
    s1.append("sssss");
    cout<<s1<<"    "<<s2<<"  "<<s1+s2<<endl;
    return 0;
}

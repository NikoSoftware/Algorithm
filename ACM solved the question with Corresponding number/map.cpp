#include<cstdio>
#include<cstring>
#include<iostream>

#include<map>
#include<vector>
using namespace std;

map<char,char> s;

int main()
{
    s['A']='1';
    s['B']='3';
    //s['A']++;
    printf("%d %d\n",s['A'],s['B']);
    //s.clear();
    return 0;
}

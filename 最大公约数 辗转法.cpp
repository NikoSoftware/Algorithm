

//µİ¹éÊµÏÖ
//  a%b=

int God(int a,int b)
{
    if(b==0)
    return a;
    return God(b,a%b);
}

int serch(int n,int val)
{
    int l=0,r=n-1,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(a[mid]==val)
        return mid;
        if(a[mid]>val)
        r=mid-1;
        else
        l=mid+1;
    }
    return -1
}

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b,m,n,t,temp_vm,temp_vn,bt,vm,vn;
    float dmn;
    while(cin>>a>>b>>t)
    {
        m=min(a,b);
        n=max(a,b);
        
        dmn=ceilf(n/(n-m));
        temp_vm=(t/m);
        temp_vn=(t-temp_vm*m)/n;
        bt=t;
        while(temp_vm>=0 && bt!=0)
        {  
            if((t-temp_vm*m-temp_vn*n)<bt)
            {
                bt=t-temp_vm*m-temp_vn*n;
                vm=temp_vm;
                vn=temp_vn;
            } 
            temp_vm--;
            temp_vn=(t-temp_vm*m)/n;
        }
        if(bt)
            cout<<vm+vn<<' '<<bt<<endl;
        else
            cout<<vm+vn<<endl;
    }
    return 0;
}
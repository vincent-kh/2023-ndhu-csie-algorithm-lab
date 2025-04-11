#include<iostream>
#include<cmath>
#include<iomanip>
#include <vector>
using namespace std;

const double pi=acos(-1);
vector<float> pie;

bool cal(double mid,int N,int F)
{
    double num=0;
    for (int i=0;i<N;i++)
        num+=floor(pie[i]/mid);    
    if (num>=F) return true;
    return false;
}

int main()
{
    int D,N,F;
    cin >> D;
 
    for(int j=0;j<D;j++)
    {
        cin >> N >> F;
        F+=1;
        double sum=0;
        pie.clear();
        for (int i=0;i<N;i++)
        {
            float R;
            cin >> R;
            pie.push_back(R*R*pi);
            sum+=pie[i];
        }
        
        double left=0,right=sum;
        
        while (right-left>1e-5){
            double mid=(right+left)/2;
            if (cal(mid,N,F)) {left=mid;}
            else              {right=mid;}
        }

        cout << fixed << setprecision(4) << left << endl;
    }
    return 0;
}
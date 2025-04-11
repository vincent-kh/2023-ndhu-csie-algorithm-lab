#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	vector<uint8_t> rid[10];
    int siz[10];
    int N;
    while(true)
    {
        cin >> N;
        if(N == 0)
            break;

        for(int inp = 0; inp < N; inp++)
        {
            int num;
            cin >> num;
            rid[num % 10].push_back(num);
        }
        int ct=0;
        for(int i = 0; i < 10; i++)
        {
            siz[i] = rid[i].size();
        }
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < siz[i]; j++)
            {
                int indx2 = rid[i][j] / 10;
                rid[indx2].push_back(rid[i][j]); 
            }
            rid[i].erase(rid[i].begin(),rid[i].begin()+siz[i]);
        }
        for(int out = 0; out < 10; out++)
        {
            for(int prin : rid[out])
            {
                cout << prin;
                if(ct!=N-1)
                cout<<' ';
                ct++;
            }
            rid[out].clear();
        }
        cout << endl;
    }
    return 0;
}
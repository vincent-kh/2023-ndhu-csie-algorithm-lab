#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define pdd pair<double, double>

int grace_cover(vector<pdd> &segs, double l) 
{
    sort(segs.begin(), segs.end()); // Sort segments based on starting point
    vector<pdd> segs2;

    if (segs.empty()) { return -1; } // No segments available

    segs2.push_back(segs[0]);
    while (segs2.back().second < l) 
    {
        pdd* max_seg = &segs2.back();
        bool updated = false;

        for (int i = 0; i < segs.size(); i++) 
        {
            if (segs[i].first <= 0 && segs[i].second >= l) // Full coverage in one segment
                return 1;

            if (segs[i].first <= segs2.back().second && max_seg->second < segs[i].second) {
                max_seg = &segs[i];
                cout<<"update"<<i<<':'<<max_seg->first<<" "<<max_seg->second<<endl;
                updated = true;
            }
        }

        if (updated) 
        {
            if (max_seg->first > segs2.back().first && max_seg->first <= 0)
                segs2.pop_back();
            segs2.push_back(*max_seg);
        } 
        else 
        {
            break;
        }
        
    }
    for(auto seg:segs)
        cout<<seg.first<<" "<<seg.second<<endl;
    if (segs2.back().second < l || segs2[0].first > 0)
        return -1;
    else
        return segs2.size();
}

int main() {
    int n, l;
    uint32_t w, p, r;

    while (cin >> n >> l >> w) {
        vector<pdd> segs;
        for (int i = 0; i < n; i++) 
        {
            cin >> p >> r;

            if (2 * r <= w)
                continue; // Sprinkler cannot cover the width

            double half_len = sqrt(r * r - (w * w / 4.0));
            auto seg = make_pair(p - half_len, p + half_len);
            if(segs.empty())
                segs.push_back(seg);
            else
            {
                auto it=find(segs.begin(),segs.end(),seg);
                if(it==segs.end())
                    segs.push_back(seg);
            }
        }
        sort(segs.begin(), segs.end());
        for(auto seg:segs)
            cout<<seg.first<<" "<<seg.second<<endl;
        cout<<endl;
        cout << grace_cover(segs, l) << endl;
        cout<<endl;
        
    }
    return 0;
}

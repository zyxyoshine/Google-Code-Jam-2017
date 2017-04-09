#include<bits/stdc++.h>

using namespace std;

struct PI{
    long long x,y;
    PI(long long xx,long long yy):x(xx),y(yy){}
    friend bool operator < (PI a,PI b) {
        return a.x < b.x;
    }
};
priority_queue <PI> q;

long long n,k;
int t;
void work(int ca) {
    while (!q.empty())
        q.pop();
    cin >> n >> k;
    q.push(PI(n,1));
    long long l,r;
    PI now(0,0);
    while (k > 0) {
        now = q.top();
        q.pop();
        while (!q.empty() && q.top().x == now.x) {
            now.y += q.top().y;
            q.pop();
        }
        //cout << now.x <<' ' << now.y << endl;
        if (now.x & 1) {
            l = now.x / 2;
            r = now.x / 2;
            q.push(PI(now.x / 2,now.y * 2));
            k -= now.y;
        }else{
            l = now.x / 2;
            r = now.x / 2 - 1;
            q.push(PI(now.x / 2,now.y ));
            q.push(PI(now.x / 2 - 1,now.y));
            k -= now.y;
        }
    }
    cout << "Case #" << ca << ": " << l << ' '<< r << endl;
}
int main() {
    cin >> t;
    for (int i = 1;i <= t;i++)
        work(i);
    return 0;
}

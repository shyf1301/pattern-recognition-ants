#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int random(int max_range = 1)
{
	if (max_range == 1) return rand() << 16 | rand();
	return (rand() << 16 | rand()) % max_range;
}


int main()
{
    //freopen("in.txt", "r", stdin);
    freopen("in.txt", "w", stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
int T = 10;
printf("10\n");
    while(T--) {
        int a = 1000000000;
        printf("100000 100000\n");
        for(int i = 0; i < 100000; ++i) {
            printf("%d %d\n", random(1000000000), random(1000000000));
        }
        for(int i = 0; i < 100000; ++i) {
            printf("%d %d\n", random(100000), random(100000));
        }
    }
    return 0;
}

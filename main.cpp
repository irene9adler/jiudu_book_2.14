//九度2.14 贪心算法1
#include <stdio.h>
#include <algorithm>
#define M 1000

using namespace std;
struct good
{
    double m;//价值
    double f;//重量
    double r;//性价比

    bool operator <(const good &A) const//重载데都是小于号
    {
        return r>A.r;
    }

}goods[M];

int main()
{
    double m1;
    int n;
    while(scanf("%lf%d",&m1,&n)!=EOF)
    {
        if((m1==-1)&&(n==-1)) break;
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&goods[i].f,&goods[i].m);
            goods[i].r = goods[i].f/goods[i].m;
        }

        sort(goods,goods+n);

        int id = 0;
        double ans = 0;

        while(id<=n)
        {
            if(m1>goods[id].m)
            {
                ans+=goods[id].f;
                m1-=goods[id].m;
            }

            else
            {
                ans+=(m1*goods[id].f)/goods[id].m;
                m1 = 0;
            }

            id++;
        }

        printf("%lf\n",ans);

    }

    return 0;
}

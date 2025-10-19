#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    queue<int> q;
    int	count;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        string tmp;
        cin >> tmp;
        if (tmp == "push")
        {
            int nTmp;
            scanf("%d", &nTmp);
            q.push(nTmp);
        }
        else if(tmp == "pop")
        {
            if(q.empty())
                printf("-1\n");
            else
            {
                printf("%d\n", q.front());
                q.pop();
            }
        }
        else if (tmp == "size")
            printf("%d\n", q.size());
        else if (tmp == "empty")
            printf("%d\n", q.empty());
        else if (tmp == "front")
        {
            if (q.empty())
                printf("-1\n");
            else
                printf("%d\n", q.front());
        }
        else {
            if (q.empty())
                printf("-1\n");
            else
                printf("%d\n", q.back());
        }
    }
}
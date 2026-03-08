#include<iostream>
#include<queue>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

int rand01()
{
    return rand() % 2;
}
int main()
{
    srand(time(0));
    int firstwin = 0;
    int finalwin = 0;
    for (int i = 0; i < 10000; ++i)
    {
        int choose1 = rand01();
        int choose2 = rand01();
        int choose3 = rand01();

        vector<int> first = { choose1,choose2,choose3 };
        queue<int> qfirst(deque<int>(first.begin(), first.end()));

        int choose0 = choose2 == 0 ? 1 : 0;
        vector<int> final = { choose0,choose1,choose2 };
        queue<int> qfinal(deque<int>(final.begin(), final.end()));

        vector<int> q = { rand01(),rand01(),rand01() };
        queue<int> qq(deque<int>(q.begin(), q.end()));
        while (true)
        {
            if (qq == qfirst)
            {
                firstwin++;
                break;
            }

            if (qq == qfinal)
            {
                finalwin++;
                break;
            }   
            qq.pop();
            qq.push(rand01());
        }
    }
    cout << "先手赢：" << firstwin << endl;
    cout << "后手赢：" << finalwin << endl;
    return 0;
}
// 小红在第三新北林市的学园城送外卖，学园城中有非常多的学校，学园城里有一个美食街。
// 小红每次会接一些同一个学校的订单，然后从美食街取餐出发，再骑车将外卖送到学校，最后回到美食街，以此往复。

// 学园城有n个结点，m 条道路，美食街为1号结点，剩下的结点都是学校，保证学园城中所有结点连通。给出小红每次要送外卖的学校，请计算小红最少需要骑行的距离。
// 输入描述
// 第一行输入三个整数n,m,p(1<=n,m,p<=10^5)，分别表示结点数、道路数、送外卖次数。
// 接下来 m行，每行输入三个整数u,v(1<=u,v<=n,u≠v) ,w(1<=w<=10^4) 表示结点u和v之间有一条长度为w的道路。
// 最后一行输入q个整数表示每次送外卖的学校a(2<=ai<=n) 。

// 输出描述
// 输出一个整数表示答案。

// 输入：
// 3 2 2
// 1 2 1
// 1 3 2
// 2 3
// 输出：
// 6
// 小红先从美食街骑到2号学校，再返回美食街，骑行距离为1+1=2
// 小红先从美食街骑到3号学校，再返回美食街，骑行距离为2+2=4
// 因此总共的骑行距离为2+4=6

// 经典迪杰斯特拉。直接跑一次迪杰斯特拉，求出所有点的距离，然后直接按照需要送到的学校以此查询最小值叠加即可。

#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

vector<int> djstl(vector<vector<pair<int ,int>>>& graph){

    int n = graph.size();
    vector<int> visited(n + 1, false);

    vector<int> dis(n + 1, INT_MAX);
    dis[1] = 0;
    // 广度遍历
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1}); // 起点的距离先设置为0
    
    while(!q.empty()){
        pair<int, int> next = q.top();
        q.pop();
        int u = next.second;
        int w = next.first;
        // 判断是否遍历过
        if(visited[u]==true){
            continue;
        }
        // 标记遍历过
        visited[u] = true;
        for(auto nn : graph[u]){
            int n_u = nn.second;
            int n_w = nn.first;
            if(w+n_w < dis[n_u]){
                dis[n_u] = w + n_w;
                q.push({dis[n_u], n_u});
            }
        }
    }

    return dis;
}

int main(int argc, char const *argv[])
{
    /* code */
    int n, m, q; // 结点数、道路数、送外卖次数
    cin >> n >> m >> q;
    // cout << n << m << q;
    vector<vector<pair<int, int>>> graph(n+1);   // map可以
    for (int i = 0; i < m;i++)
    {
        int u, v, w; // 表示结点u和v之间有一条长度为w的道路。
        cin >> u >> v >> w;
        // cout << u << v << w;
        // pair<int, int> p1 = {w, v};
        // pair<int, int> p2 = {w, u};
        // graph[u].emplace_back({w, v});
        // graph[v].emplace_back({w, u});  // u v 是节点，w是路径大小

        graph[u].push_back({w, v});
        graph[v].push_back({w, u});  // u v 是节点，w是路径大小
    }


    vector<int> Q(q);
    for (int i = 0; i < q;i++)
    {
        cin >> Q[i];
    }

    //迪杰斯特拉后，返回开始节点到所有节点的距离，下标是节点，值是距离
    vector<int> dis = djstl(graph);

    // 要跑的结果叠加即可
    int ans = 0;
    for (int i = 0; i < q;i++)
    {
        ans += dis[Q[i]] * 2;
    }

    cout << ans << endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m;
struct Train{
    string name;
    vector<string> link;
};

map<string,Train> train;

signed main() {
    vector<string> namespaceTrain = {"LM 等级 23","模拟加强版B型","华丽的市长号","西北列车组","模拟列车等级Zero","模拟城市快线9001","羽毛笔快线OP1","西北列车组"};
    train["LM 等级 23"].name = "LM 等级 23";
    train["LM 等级 23"].link.push_back("模拟加强版B型");

    train["华丽的市长号"].name = "华丽的市长号";
    train["华丽的市长号"].link.push_back("西北列车组");

    train["模拟列车等级Zero"].name = "模拟列车等级Zero";
    train["模拟列车等级Zero"].link.push_back("LM 等级 23");

    train["模拟加强版B型"].name = "模拟加强版B型";
    
    train["模拟城市快线9001"].name = "模拟城市快线9001";
    train["模拟城市快线9001"].link.push_back("华丽的市长号");

    train["羽毛笔快线OP1"].name = "羽毛笔快线OP1";
    train["羽毛笔快线OP1"].link.push_back("模拟列车等级Zero");

    train["西北列车组"].name = "西北列车组";
    train["西北列车组"].link.push_back("羽毛笔快线OP1");

    for(auto [name,link]:train){
        string path = "欲解锁火车" + name + "需先解锁：";
        int cnt = 0;
        auto dfs = [&](string cur,string path,auto self)->void{
            if(train[cur].link.empty()){
                cout<<path<<endl<<"共计"<<cnt<<"种火车"<<endl<<endl;
                return;
            }

            for(int i=0;i<train[cur].link.size();i++){
                cnt++;
                string to =  train[cur].link[i];
                self(to,path+to+" ",self);
            }
        };

        dfs(name,path,dfs);
    }
    return 0;
}
    
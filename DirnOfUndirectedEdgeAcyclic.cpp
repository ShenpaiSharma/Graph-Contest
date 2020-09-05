#include <bits/stdc++.h>
using namespace std;

stack<int> S;

void TopoUtil(vector<int> adj[],int s,int V,bool visit[]){
    visit[s] = true;
    for(auto it = adj[s].begin();it != adj[s].end();++it){
        if(!visit[*it]){
            TopoUtil(adj,*it,V,visit);
        }
    }
    S.push(s);
}

void Topo(vector<int> adj[],int s,int V){
    bool* visit = new bool[V];
    for(int i=0;i<V;i++){
        visit[i] = false;
    }
    
    TopoUtil(adj,s,V,visit);
}

int main() {
	int V,E;
	cin>>V>>E;
	vector<int> adj[V];
	vector<pair<int,int>> v;
	int r,e;
    for(int i=0;i<E;i++){
        int x,y,bp;
        cin>>x>>y>>bp;
        if(bp){
            v.push_back(make_pair(x,y));
        }
        else adj[x].push_back(y);
    }
    Topo(adj,0,V);
    vector<int> s;
    while(!S.empty()){
        s.push_back(S.top());
        S.pop();
    }
    
    for(int i=0;i<v.size();i++){
        for(int j=0;j<s.size();j++){
            if(s[j] == v[i].first){
                r = j;
            }
            if(s[j] == v[i].second){
                e = j;
            }
        }
        if(e > r) cout<<v[i].first<<"-->"<<v[i].second<<endl;
        else cout<<v[i].second<<"-->"<<v[i].first<<endl;
    }
	return 0;
}

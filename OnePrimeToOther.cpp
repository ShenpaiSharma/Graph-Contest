#include <bits/stdc++.h>
using namespace std;

vector<int> Sieve(int N){
    bool prime[N+1];
    memset(prime,true,sizeof(prime));
    for(int p=2;p*p <= N;p++){
        if(prime[p]){
            for(int i=p*p;i<=N;i+=p){
                prime[i] = false;
            }
        }
    }
    vector<int> v;
    for(int i=1000;i<=N;i++){
        if(prime[i]){
            v.push_back(i);
        }
    }
    return v;
}

bool compare(int num1, int num2){ 
    
    string s1 = to_string(num1); 
    string s2 = to_string(num2); 
    int c = 0; 
    if (s1[0] != s2[0]) 
        c++; 
    if (s1[1] != s2[1]) 
        c++; 
    if (s1[2] != s2[2]) 
        c++; 
    if (s1[3] != s2[3]) 
        c++; 
  
    
    return (c == 1); 
} 

int bfs(vector<int> adj[],int s,int l,int V){
    bool visit[V];
    memset(visit,false,sizeof(visit));
    int level[V];
    queue<int> Q;
    Q.push(s);
    visit[s] = true;
    level[s] = 0;
    while(!Q.empty()){
        int s = Q.front();
        Q.pop();
        for(auto it = adj[s].begin();it != adj[s].end();++it){
            if(!visit[*it]){
                visit[*it] = true;
                level[*it] = level[s] + 1;
                Q.push(*it);
            }
            if(*it == l){
                return level[*it];
            }
        }
    }
}

void Print(vector<int> adj[],int V){
    for(int i=0;i<V;i++){
        cout<<i<<"-->";
        for(auto it = adj[i].begin();it != adj[i].end();++it){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}

int ShortestPath(int n,int m){
    vector<int> v = Sieve(9999);
    vector<int> adj[v.size()];
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(compare(v[i],v[j])){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int s,l;
    for(int i=0;i<v.size();i++){
        if(v[i] == n){
            s = i;
        }
    }
    for(int i=0;i<v.size();i++){
        if(v[i] == m){
            l = i;
        }
    }
    return bfs(adj,s,l,v.size());
    //Print(adj,v.size());
}

int main() {
	int n,m;
	cin>>n>>m;
	cout<<ShortestPath(n,m);
	return 0;
}

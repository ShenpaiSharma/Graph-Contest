#include <bits/stdc++.h>
using namespace std;

template <typename T> 

class Graph{
    unordered_map<T,list<pair<T,int>>> m;
    public:
    void Addedge(T u,T v,int dist,bool bidir = true){
        m[u].push_back(make_pair(v,dist));
        if(bidir){
            m[v].push_back(make_pair(u,dist));
        }
    }
    void Print(){
        for(auto i:m){
            cout<<i.first<<"-->";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<")"<<",";
            }
            cout<<endl;
        }
        
    }
    void djisktra(T src){
        unordered_map<T,int> dist;
        for(auto j:m){
            dist[j.first] = INT_MAX;
        }
        dist[src] = 0;
        set<pair<int,T>> s;
        s.insert(make_pair(0,src));
        while(!s.empty()){
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());
            for(auto childpair:m[node]){
                if(childpair.second + nodeDist < dist[childpair.first]){
                    T dest = childpair.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f != s.end()){
                        s.erase(f);
                    }
                    dist[dest] = childpair.second + nodeDist;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        for(auto d:dist){
            cout<<d.first<<"-->"<<d.second<<endl;
        }
    }
};

int main() {
	Graph<string> india;
	india.Addedge("Amritsar","D",1);
	india.Addedge("Amritsar","J",4);
	india.Addedge("J","D",2);
	india.Addedge("J","M",8);
	india.Addedge("B","A",2);
	india.Addedge("M","B",3);
	india.Addedge("A","D",1);
	india.Print();
	cout<<endl;
	india.djisktra("Amritsar");
	
	return 0;
}

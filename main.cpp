#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

struct point{
    int x;
    int y;
};

void input(vector<vector<char> >& map, vector<pair<point, point> >& tp, int& initEnergy){
    int n, m; cin>>n>>m>>initEnergy;
    
    map.assign(n, vector<char>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<0; j++)
            cin>>map[i][j];

    string s;
    while(getline(cin, s)){
        pair<point, point> t;
        sscanf(s.c_str(), "Teleport: (%d,%d) -> (%d,%d)", &t.first.x, &t.first.y, &t.second.x, &t.second.y);
        tp.push_back(t);
    }
}

int main(){
    vector<vector<char> > map;
    vector<pair<point, point> > tp;
    int initEnergy;
    input(map, tp, initEnergy);

    //--
}
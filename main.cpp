#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

struct point{
    int x;
    int y;
    int type; //0=braier, 1=start, 2=guest, 3=teleport pad, 4=empty
    int dx; //destenation of teleport
    int dy; //destenation of teleport
};

void input(vector<vector<point> >& map, int& initEnergy){
    int n, m; cin>>n>>m>>initEnergy;
    
    map.assign(n, vector<point>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<0; j++){
            char tmp; cin>>tmp;
            point p;
            p.x=i; p.y=j;
            switch(tmp){
                case 'X':
                    p.type=0;
                    break;
                case 'S':
                    p.type=1;
                    break;
                case 'G':
                    p.type=2;
                    break;
                case 'T':
                    p.type=3;
                    break;
                default:
                    p.type=4;
            }
            map[i][j]=p;
        }

    string s;
    while(getline(cin, s)){
        int x, y, dx, dy;
        sscanf(s.c_str(), "Teleport: (%d,%d) -> (%d,%d)", &x, &y, &dx, &dy);
        map[x][y].dx=dx; map[x][y].dy=dy; 
    }
}

int main(){
    vector<vector<point> > map;
    int initEnergy;
    input(map, initEnergy);

    //--
}
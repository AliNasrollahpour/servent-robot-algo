#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

struct point{
    int x;
    int y;
    int type; //0=braier, 1=start, 2=guest, 3=teleport pad, 4=empty
    int dx=-1; //destenation of teleport
    int dy=-1; //destenation of teleport
};

struct valuePair{
    int guestsServed=-1; //-1=unassigned
    int energyLeft=-1; //-1unassigned
    int direction=0; //0=null, 1=left, 2=up
};

point input(vector<vector<point> >& map, int& initEnergy){
    int n, m; cin>>n>>m>>initEnergy;
    point start;
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
                    start=p;
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
    return start;
}

void BFS(const vector<vector<point> >& map, vector<vector<valuePair> >& valueMap, const point current);

void createNextPoint(const vector<vector<point> >& map, vector<vector<valuePair> >& valueMap, const point current){
    //down
    if(map[current.x+1][current.y].type &&
    !(valueMap[current.x+1][current.y].guestsServed>valueMap[current.x][current.y].guestsServed+map[current.x+1][current.y].type==2
    && (valueMap[current.x+1][current.y].guestsServed!=valueMap[current.x][current.y].guestsServed+map[current.x+1][current.y].type==2
        || valueMap[current.x+1][current.y].energyLeft<valueMap[current.x][current.y].energyLeft)
    )){
        valueMap[current.x+1][current.y].direction=2;
        valueMap[current.x+1][current.y].energyLeft=valueMap[current.x][current.y].energyLeft-1;
        valueMap[current.x+1][current.y].guestsServed=valueMap[current.x][current.y].guestsServed;
        if(map[current.x+1][current.y].type==2) valueMap[current.x+1][current.y].guestsServed++;
        if(map[current.x+1][current.y].type==3){
            point jumpPoint = map[current.dx][current.dy];
            createNextPoint(map, valueMap, jumpPoint);
        }
        point nextPoint=map[current.x+1][current.y];
        BFS(map, valueMap, nextPoint);
    }
    //right
    if(map[current.x+1][current.y].type &&
    !(valueMap[current.x][current.y+1].guestsServed>valueMap[current.x][current.y].guestsServed+map[current.x][current.y+1].type==2
    && (valueMap[current.x][current.y+1].guestsServed!=valueMap[current.x][current.y].guestsServed+map[current.x][current.y+1].type==2
        || valueMap[current.x][current.y+1].energyLeft<valueMap[current.x][current.y].energyLeft)
    )){
        valueMap[current.x][current.y+1].direction=2;
        valueMap[current.x][current.y+1].energyLeft=valueMap[current.x][current.y].energyLeft-1;
        valueMap[current.x][current.y+1].guestsServed=valueMap[current.x][current.y].guestsServed;
        if(map[current.x][current.y+1].type==2) valueMap[current.x][current.y+1].guestsServed++;
        if(map[current.x][current.y+1].type==3){
            point jumpPoint = map[current.dx][current.dy];
            createNextPoint(map, valueMap, jumpPoint);
        }
        point nextPoint=map[current.x][current.y+1];
        BFS(map, valueMap, nextPoint);
    }
}

void BFS(const vector<vector<point> >& map, vector<vector<valuePair> >& valueMap, const point current){
    if(valueMap[current.x][current.y].energyLeft) createNextPoint(map, valueMap, current);
}

vector<point> path(){
    //--
}

void print(){
    //--
}

int main(){
    vector<vector<point> > map;
    int initEnergy;
    point start=input(map, initEnergy);

    vector<vector<valuePair> > valueMap(map.size(), vector<valuePair>(map[0].size()));
    BFS(map, valueMap, start);

    //--
}
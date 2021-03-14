#include <iostream>
#include <queue>
using namespace std;

int r, c;
int a[1000][1000];
bool visited[1000][1000];
int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void){
    cin >> c >> r;

    queue<pair<int, int>> q;
    
    int input_int;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> input_int;
            a[i][j] = input_int;
            if(a[i][j] == 1){
                visited[i][j] = true;
                q.push(make_pair(i,j));
            }
            else if(a[i][j] == -1){
                visited[i][j] = true;
            }
        }
    }

    if(q.size() == r*c){
        cout << -1;
        return 0;
    }

    int count = 0;
    while(true){
        queue<pair<int, int>> nextQ;
        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >=0 && nx<r && ny>=0 && ny<c){//0~r-1 , 0~c-1
                    if(a[nx][ny] == 0){
                        a[nx][ny] = 1;
                        visited[nx][ny] = true;
                        nextQ.push(make_pair(nx, ny));
                    }
                    else if(a[nx][ny] == -1){
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        if(nextQ.empty()){
            break;
        }
        q = nextQ;
        count++;
    }
    bool flag = false;
    for(int i=0; i<r && !flag; i++){
        for(int j=0; j<c; j++){
            if(!visited[i][j]){
                flag=true;
                break;
            }
        }
    }
    if(!flag){
        cout << count;
    }
    else{
        cout << -1;
    }
    return 0;
}
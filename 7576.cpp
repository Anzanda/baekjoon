#include <iostream>
using namespace std;

int r, c, count;
int a[1000][1000];
int sol[1000][1000];
bool visited[1000][1000];
void check(int x, int y){
    if(x<0||x>=r||y<0||y>=c){
        return;
    }
    if(visited[x][y]){
        return;
    }
    if(a[x][y] == -1){
        visited[x][y] = true;
        return;
    }
    if(a[x][y] == 0){
        visited[x][y] = true;
        a[x][y] = 1;
        return;
    }
    if(a[x][y] == 1){
        visited[x][y] = true;
        check(x+1,y);
        check(x-1, y);
        check(x, y+1);
        check(x, y-1);
        return;
    }
}

bool solutionCheck(){
    int i, j;
    bool flag = false;
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            if(a[i][j] != sol[i][j]){
                flag = true;
                count++;
            }
        }
    }
    if(!flag){
        return true;
    }
    else{
        return false;
    }
}
int main(void){
    cin >> c >> r;

    int input_num;
    int zerozCount = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> input_num;
            a[i][j] = input_num;
            if(!input_num){
                sol[i][j] = 1;
                zeroCount++;
            }    
            else
                sol[i][j] = input_num;
        }
    }
    if(zeroCount == 0){
        cout << 0 << '\n';
        return 0;
    }

    int num=1;
    while(true){
        for(int i=0; i<r; i++){//1È®Àå!
            for(int j=0; j<c; j++){
                if(a[i][j])
                    check(i,j);
            }
        }

        int tmp = count;
        count = 0;
        if(solutionCheck()){
            cout << num << '\n';
            break;
        }
        if(tmp == count)
        {
            cout << -1 << '\n';
            break;
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                visited[i][j] = false;
            }
        }

        num++;
    }    
    return 0;
}
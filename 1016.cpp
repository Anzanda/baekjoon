#include <iostream>
#include <vector>
using namespace std;

long long a, b;
int main(void){
    cin >> a >> b;
    vector<bool> visited(b-a+1, false);

    long long  i = 2;
    long long srCount = b-a+1;
    while(i*i <= b){
        long long  start;
        if(a % (i*i) != 0){
            start = (a / (i*i)) + 1;
        }
        else{
            start = (a / (i*i));
        }
        while(start * (i*i) <= b){
            if(visited[start*(i*i)-a]){
                start++;
                continue;
            }
            visited[start*(i*i)-a] = true;
            srCount--;
            start++;
        }
        i++;
    }
    cout << srCount << endl;
    return 0;
}
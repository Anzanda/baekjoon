    #include <iostream>
    #include <list>
    using namespace std;


    void solution(list<int> &lst, list<int>::iterator it, int n, int k){
        if(n <= k){
            lst.insert(it++, n);
            solution(lst, it, n-1,k-(n-1));
            return;
        }
        else{//n>k
            lst.insert(it++, k+1);
            for(int i=1; i<=k; i++){
                lst.insert(it++, i);
            }
            for(int i = k+2; i<=n; i++){
                lst.insert(it++, i);
            }
        }
    }
    int main(void){
        int n, k;
        cin >> n >> k;
        
        list<int> lst(n);
        solution(lst, lst.begin(), n, k);
        for(auto iter = lst.begin(); iter != lst.end(); iter++){
           if(*iter == 0)  continue;
            cout << *iter << ' ';
        }
        return 0;
    }
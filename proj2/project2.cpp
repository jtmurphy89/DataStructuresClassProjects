#include <iostream>
#include <utility>
#include <map>
#include <limits>
using namespace std;
int main(int argc, char *argv[]) {
    int N, K, S, C;
    cin >> N >> K >> S >> C; 
    int demand[N];
    for(int i = 0; i < N; i++){
        cin >> demand[i];
    }
    int costMatrix[N][N];
    int orderMatrix[N][N];
    int storageMatrix[N][N];
    costMatrix[0][0] = K;
    orderMatrix[0][0] = demand[0];
    storageMatrix[0][0] = 0; 
    int block = 0; 
    map<pair<int, int>, pair<int,int> > orderInfo;

    // initialize base cases
    for(int i = 1; i < N; i++){
        int curStorage = storageMatrix[i-1][block] + demand[i];
        if(curStorage <= S){
            orderMatrix[i][block] = orderMatrix[i-1][block] + demand[i];
            storageMatrix[i][block] = curStorage;
            costMatrix[i][block] = K + storageMatrix[i][block]*C; 
        }
        else{
            block = i; 
            orderMatrix[i][block] = demand[i];
            storageMatrix[i][block] = 0;
            costMatrix[i][block] = K; 
        }
    }

    // initialize diagonal costs
    for(int i = 1; i < N; i++){
        for(int j = 1; j <= i; j++){
            if(costMatrix[i][1] != numeric_limits<int>::max()){
                costMatrix[i][j] = costMatrix[i][j-1] + (storageMatrix[i][j-1] - demand[j])*C;
                storageMatrix[i][j] = storageMatrix[i][j-1] - demand[j];
                orderMatrix[i][j] = 0; 
            }
            else{
                j=i; 

            }
        }
    }


    for(int k =1; k < N -1; k++){
        for(int left = 0; left < N - k; left++){
            int right = left + k; 
            if(demand[right] != 0){
                if(costMatrix[left][right-1] + K <= costMatrix[left+1][right] && costMatrix[left][right-1]!= numeric_limits<int>::max()){
                    costMatrix[left][right] = min(costMatrix[left][right-1] + K, costMatrix[left+1][right]);
                    orderMatrix[left][right] = demand[right];
                    storageMatrix[left][right] = 0; 
                }
                    //orderInfo.insert(make_pair(make_pair(left,right),orderInfo.find(make_pair(left, right-1));
                else if(costMatrix[left][right-1] + K > costMatrix[left+1][right] && costMatrix[left+1][right]!= numeric_limits<int>::max()){
                    costMatrix[left][right] = min(costMatrix[left][right-1] + K, costMatrix[left+1][right]);
                    orderMatrix[left][right] = 0;
                    storageMatrix[left][right] = storageMatrix[left+1][right];
                }
                else {
                    orderMatrix[left][right] = demand[right];
                    storageMatrix[left][right] = 0;
                    costMatrix[left][right] = K;
                }

            } 
            else{
                    if(costMatrix[left][right-1] <= costMatrix[left+1][right] && costMatrix[left][right-1]!= numeric_limits<int>::max()){
                    costMatrix[left][right] = min(costMatrix[left][right-1] + K, costMatrix[left+1][right]);
                    orderMatrix[left][right] = 0;
                    storageMatrix[left][right] = 0; 
                    }
                    orderInfo.insert(make_pair(make_pair(left,right),orderInfo.find(make_pair(left, right-1));
                else if(costMatrix[left][right-1] > costMatrix[left+1][right] && costMatrix[left+1][right]!= numeric_limits<int>::max()){
                    costMatrix[left][right] = min(costMatrix[left][right-1] + K, costMatrix[left+1][right]);
                    orderMatrix[left][right] = 0;
                    storageMatrix[left][right] = storageMatrix[left+1][right];
                }
                else{ 
                    orderMatrix[left][right] = 0;
                    storageMatrix[left][right] = 0;
                    costMatrix[left][right] = 0;
                }
            }  
        }
    }

    if(demand[N] != 0){
        costMatrix[0][N-1] = min(costMatrix[0][N-2] + K, costMatrix[1][N-1]);
        if(costMatrix[0][N-2] + K <= costMatrix[1][N-1]){
                orderMatrix[0][N-1] = demand[N-1];
                storageMatrix[0][N-1] = 0;
            }
        else {
                orderMatrix[0][N-1] = 0;
                storageMatrix[0][N-1] = 0; 
        }
    } 
    else{
        costMatrix[0][N-1] = min(costMatrix[0][N-2], costMatrix[1][N-1]);
        orderMatrix[0][N-1] = 0;
        storageMatrix[0][N-1] = 0;
        } 
    
    

    for(int i = 0; i < N; i++){
        for(int k = 0; k < N; k++){
            cout << costMatrix[i][k] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < N; i++){
        for(int k = 0; k < N; k++){
            cout << orderMatrix[i][k] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < N; i++){
        for(int k = 0; k < N; k++){
            cout << storageMatrix[i][k] << " ";
        }
        cout << endl;
    }



    return 0;
}
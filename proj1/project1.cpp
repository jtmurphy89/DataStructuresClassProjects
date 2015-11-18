#include <iostream>
#include <utility>
#include <map>
using namespace std;
int main(int argc, char *argv[]) {
    int curTime = 0; 
    int completionTime = 0;
    int n, a, b, c;
    map<int, pair<int, int> > jobs;
    pair<int,int> jobInfo;
    cin >> n;
    while(cin >> a){
        cin >> b >> c;
        jobInfo = make_pair(b,c);
        jobs.insert(make_pair(a,jobInfo));
    }
    while(!jobs.empty()){
        int curJob = -1; 
        for(map<int, pair<int, int> >::iterator it = jobs.begin(); it != jobs.end(); ++it){
            if(jobs[it->first].first <= curTime)
                curJob = it->first;
        }
        if(curJob == -1){
            cerr << "*" << endl;
            curTime++;
        }
        else{
            for(map<int, pair<int, int> >::iterator it = jobs.begin(); it != jobs.end(); ++it){
                if(jobs[it->first].first <= curTime && jobs[it->first].second <= jobs[curJob].second)
                    curJob = it->first;
            }
            cerr << curJob << endl;
            curTime++;
            jobs[curJob].second = jobs[curJob].second -1;
            if(jobs[curJob].second == 0){
                completionTime+= curTime;
                jobs.erase(curJob);
            }
        }     
    }
    cout << completionTime;
    return 0;   
}
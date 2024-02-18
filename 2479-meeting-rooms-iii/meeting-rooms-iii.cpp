class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& m) {
        sort(m.begin() , m.end());
        vector<int> freq(n,0) , room(n,0);
        priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>> pq;
        pq.push({m[0][1] , 0});
        freq[0]++; // 0th room given to first meeting
        room[0]++; // 1 meeting held in 0th room
        int j = 1;
        for(int i = 1 ; i < m.size() ; i++){
            if(pq.size() < n){
                // if the starting time of the second meeting is greater than the previous meeting held then the meeting will held on the same room
                // only applicable for first n meetings
                while(!pq.empty() && pq.top().first <= m[i][0]){
                    room[pq.top().second]--;
                    // cout << "pui" <<  " " << pq.top().second << endl;
                    pq.pop();
                }
                
                for(int k = 0 ; k < n ; k++){
                    if(room[k] == 0){
                        pq.push({(m[i][1]) , k});
                        room[k]++;
                        freq[k]++;
                        break;
                    }
                }    
            }else{
                int start = m[i][0] , end = m[i][1];
                long long prevEnd = 0;
                while(!pq.empty() && start >= pq.top().first){
                    room[pq.top().second]--;
                    cout << "pui" <<  " " << pq.top().second << endl;
                    pq.pop();
                }
                if(pq.size() == n){
                    prevEnd = (pq.top().first - start);
                    room[pq.top().second]--;
                    pq.pop();
                }
                for(int k = 0 ; k < n ; k++){
                    if(room[k] == 0){
                        pq.push({((long long)m[i][1] + prevEnd) , k});
                        room[k]++;
                        freq[k]++;
                        break;
                    }
                }
            }
        }
        int maxi = *max_element(freq.begin() , freq.end());
        for(int i = 0 ; i < n ; i++){
            if(freq[i] == maxi) return i;
        }

        return -1;
    }
};
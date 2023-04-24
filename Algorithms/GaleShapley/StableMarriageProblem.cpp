/***********************************************
 * Author - Abhishek
 * Roll No - B15103
 * CS 403 - Algorithm Design and Analysis
 * Assignment 1
 * Question 1
 * Stable Marriage Problem
 **********************************************/
#include <bits/stdc++.h>
using namespace std;

class Gender {
    public:
        int num;
        vector<vector<int> > priority;
        vector<int> match;

        Gender(int n, vector<vector<int> > list) {
            num = n;
            priority = list;
            match.resize(n, -1);
        }
};

vector<pair<int, int> > stable_marriage_prob(Gender men, Gender women) {
    // Gale-Shapley algorithm implementation
    int n = men.num;
    vector<pair<int, int> > result;
    vector<vector<bool> > proposed(n, vector<bool> (n, false));
    queue<int> main_queue;
    for(int i = 0; i < n; ++i) {
        main_queue.push(i);
    }
    while(!main_queue.empty()) {
        int u = main_queue.front();
        main_queue.pop();
        int w = -1;
        for(int i = 0; i < men.priority[u].size(); ++i) {
            int women_index = men.priority[u][i];
            if(!proposed[u][women_index]) {
                w = women_index;
                break;
            }
        }
        if(w != -1) {
            proposed[u][w] = true;
            if(women.match[w] == -1) {
                women.match[w] = u;
                men.match[u] = w;
            }
            else {
                int m = women.match[w];
                int m_index = -1, u_index = -1;
                for(int i = 0; i < women.priority[w].size(); ++i) {
                    if (m == women.priority[w][i]) {
                        m_index = i;
                    }
                    else if(u == women.priority[w][i]) {
                        u_index = i;
                    }
                }
                if(m_index < u_index) {
                    main_queue.push(u);
                }
                else {
                    women.match[w] = u;
                    men.match[u] = w;
                    main_queue.push(m);
                    men.match[m] = -1;
                }
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        result.push_back(make_pair(i, men.match[i]));
    }
    return result;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int> > men_priority(n, vector<int> ()), women_priority(n, vector<int> ());
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int x;
            cin>>x;
            men_priority[i].push_back(x);
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int x;
            cin>>x;
            women_priority[i].push_back(x);
        }
    }
    Gender men(n, men_priority), women(n, women_priority);
    vector<pair<int, int> > result = stable_marriage_prob(men, women);
    for(int i = 0; i < result.size(); ++i) {
        cout<<"("<<result[i].first<<", "<<result[i].second<<")"<<endl;
    }
    return 0;
}
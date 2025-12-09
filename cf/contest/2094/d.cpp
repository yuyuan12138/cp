/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-05-10 15:26:19
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-05-10 16:00:00
 * @FilePath: \Codeforces Round 1017 (Div. 4)\D.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve(){
    string p, s;
    cin >> p >> s;
    int p_size = p.size();
    int s_size = s.size();
    if(p_size > s_size){
        cout << "NO" << endl;
        return;
    }
    int p_idx = 0;
    int s_idx = 0;

    while(p_idx < p_size && s_idx < s_size){
        int num_of_L = 0;
        int num_of_R = 0;
        if(p[p_idx] == 'L'){
            // count num of L in p
            while(true){
                if(p[p_idx] == 'L'){
                    if(p_idx == p_size - 1){
                        num_of_L += 1;
                        p_idx++;
                        break;
                    }
                    p_idx++;
                    num_of_L++;
                }else{
                    break;
                }
            }
        }else{
            // count num of L in R
            while(true){
                if(p[p_idx] == 'R'){
                    if(p_idx == p_size - 1){
                        num_of_R += 1;
                        p_idx++;
                        break;
                    }
                    p_idx++;
                    num_of_R++;
                }else{
                    break;
                }
            }
        }
/////////////////////////////////////////////////////
        int _num_of_L = 0;
        int _num_of_R = 0;
        if(num_of_L != 0){
            // count num of L in s
            while(true){
                if(s[s_idx] == 'L'){
                    if(s_idx == s_size - 1){
                        _num_of_L += 1;
                        s_idx++;
                        break;
                    }
                    s_idx++;
                    _num_of_L++;
                }else{
                    break;
                }
            }
            if(_num_of_L < num_of_L || _num_of_L > 2 * num_of_L){
                cout << "NO" << endl;
                return ;
            }
        }else{
            // count num of R in s
            while(true){
                if(s[s_idx] == 'R'){
                    if(s_idx == s_size - 1){
                        _num_of_R += 1;
                        s_idx++;
                        break;
                    }
                    s_idx++;
                    _num_of_R++;
                }else{
                    break;
                }
            }
            if(_num_of_R < num_of_R || _num_of_R > 2 * num_of_R){
                cout << "NO" << endl;
                return ;
            }
        }
        // if(s_idx == s_size - 1 || p_idx == p_size - 1){
        //     break;
        // }
    }
    if(s_idx == s_size && p_idx == p_size ){
        cout << "YES" << endl;
        return ;
    }

    cout << "NO" << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}
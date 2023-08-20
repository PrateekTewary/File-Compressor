#include<bits/stdc++.h>

using namespace std;

string decToBin(int inNum) {
    string temp = "", res = "";
    while (inNum > 0) {
        temp += (inNum % 2 + '0');
        inNum /= 2;
    }
    cout << "temp- " << temp << endl;
    res.append(8 - temp.length(), '0');
    cout << "res.append(8 - temp.length(), '0')- " << res << "\t";
    for (int i = temp.length() - 1; i >= 0; i--) {
        res += temp[i];
    }
    cout << "res- " << res << endl;
    return res;
}

int main(){

    int t;  cin >> t;
    while( t-- ){
        int num;    cin >> num;

        string res = decToBin(num);
    }
    return 0;
}

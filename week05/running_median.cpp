#include <iostream>
#include <vector>
#include<algorithm>
#include <iomanip>
using namespace std;
int main() {
    int num;
    vector<int> list;
    cout<<"Enter the number(to end up enter -1) :";
    while(true){
        cin>>num;
        if(num==-1){
            break;
        }
        list.push_back(num);
        int n = list.size();
        sort(list.begin(),list.end());
        cout << "The sorted array is: [ ";
        for (int i = 0; i < n; i++) {
            cout << list[i] << " ,";
        }
        cout<<"]"<<endl;
        int median;
        if(n%2==1){
            median = list[n/2];
            cout<<"The median value is "<<median<<endl;
        }
        else{
            double median_1 = double(list[n/2]+list[n/2-1])/2;
            
            cout << "The median value is: " << fixed << setprecision(1) << median_1 << endl;
        }
        cout<<"enter another number ";
    }
    return 0;
}

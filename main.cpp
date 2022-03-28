#include <iostream>
#include <experimental/random>

using namespace std;

int main() {
    int N;
    int sum=0;
    cin >> N;
    int SourceData[N+1];
    int TargetData[N+1];

    for (int i = 0; i < N; ++i) {
        SourceData[i] = std::experimental::randint(0, N);
    }

    for (int i = 0; i < N; ++i) {
        TargetData[SourceData[i]] = SourceData[i];
    }

    for (int i = 0; i < N; ++i) {
        if (TargetData[i]&&TargetData[i+1]){
            cout<<"("<<i<<","<<i+1<<")"<<endl;
            sum++;
        }
    }
    cout<<"\n";
    cout<<"Sum is "<<sum;
}
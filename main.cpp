#include <iostream>
#include <experimental/random>

using namespace std;


struct NumNode {
    bool is_last_neighbor = false;
    bool is_next_neighbor = false;
};

int main() {
    int N;
    cin >> N;
    int sum = 0;

    int SourceData[N];
    NumNode TargetData[N + 1];


    for (int i = 0; i < N; ++i) {
        SourceData[i] = experimental::randint(0, N);
        cout << " " << SourceData[i];
    }
    cout << "\n";

    for (int i = 0; i < N - 1; ++i) {
        if (SourceData[i] - SourceData[i + 1] == -1) {
            TargetData[SourceData[i]].is_next_neighbor = true;
            sum++;
        } else if (SourceData[i] - SourceData[i + 1] == 1) {
            TargetData[SourceData[i]].is_last_neighbor = true;
            sum++;
        }
    }

    for (int i = 0; i < N + 1; ++i) {
        if (TargetData[i].is_next_neighbor)
            cout << "(" << i << "," << i + 1 << ") " << endl;
        else if (TargetData[i].is_last_neighbor)
            cout << "(" << i << "," << i - 1 << ") " << endl;
    }
    cout << "The sum is: " << sum;
}
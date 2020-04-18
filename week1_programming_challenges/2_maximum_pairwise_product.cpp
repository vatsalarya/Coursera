#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (long long first = 0; first < n; ++first) {
        for (long long second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,(long long)(numbers[first]) * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    int max_index1 = -1;
    int max_index2 = -1;
    for(int i=0; i<numbers.size(); i++){
        if((max_index1 == -1) || (numbers[i]>numbers[max_index1]))
            max_index1=i;
    }
    for(int j=0; j<numbers.size(); j++){
        if((j != max_index1) && ((max_index2 == -1) || (numbers[j]>numbers[max_index2])))
            max_index2=j;
    }
    return ((long long)(numbers[max_index1])*numbers[max_index2]);
}

int main() {
/*
    while(true){
        int n = rand()%10 + 2;
        cout<<n<<"\n";
        vector <int> a;
        for(int i=0; i<n; i++)
            a.push_back(rand()%100000); 

        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<"\n";

        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProductFast(a);

        if(res1 != res2){
            cout<<"Wrong Answer: "<<res1<<" "<<res2<<"\n";
            break;
        }else cout<<"Ok\n";
    }*/
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}

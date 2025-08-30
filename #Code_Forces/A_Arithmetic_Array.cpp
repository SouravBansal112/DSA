#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {       
        int size;
        cin>>size;
        vector<int> arr(size);
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
            sum = sum + arr[i];
        }
        if (sum == size)
        {
            cout << 0<<endl;
        }
        if (sum < size)
        {
            cout << 1<<endl;
        }
        if (sum > size)
        {
            cout << sum - size<<endl;
        }
    }
    return 0;
}
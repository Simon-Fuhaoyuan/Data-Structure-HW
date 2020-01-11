#include <iostream>

using namespace std;

int main()
{
    // table parameter
    int p, length, cnt;
    // table array
    int *arr, *time_arr;
    
    // input stage
    cin >> p >> length >> cnt;
    arr = new int[length];
    time_arr = new int[length];
    for (int i = 0; i < length; ++i)
    {
        arr[i] = -1;
        time_arr[i] = 0;
    }

    // insert stage
    int element, time = 0;
    int pos;
    for (int i = 0; i < cnt; ++i)
    {
        cin >> element;
        time = 1;
        pos = element % p;
        while(arr[pos] != -1)
        {
            pos = (pos + 1) % length;
            time++;
        }
        arr[pos] = element;
        time_arr[pos] = time;
    }

    // final output
    for (int i = 0; i < length; ++i)
        cout << i << ' ';
    cout << endl;

    for (int i = 0; i < length; ++i)
        cout << arr[i] << ' ';
    cout << endl;

    for (int i = 0; i < length; ++i)
        cout << time_arr[i] << ' ';

    delete[]arr;
    delete[]time_arr;
    return 0;
}

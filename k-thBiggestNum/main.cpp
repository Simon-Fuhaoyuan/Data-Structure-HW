#include <iostream>

using namespace std;

int divide(int *a, int low, int high)
{
    int tmp = a[low];
    while(low < high)
    {
        for (; high > low && a[high] > tmp; --high)
            continue;
        if (low < high) a[low] = a[high];
        else break;

        for (; low < high && a[low] < tmp; ++low)
            continue;
        if (low < high) a[high] = a[low];
        else break;
    }
    a[low] = tmp;
    return low;
}

void rec_quickSort(int *a, int low, int high)
{
    if (low >= high) return;

    int mid = divide(a, low, high);
    rec_quickSort(a, low, mid - 1);
    rec_quickSort(a, mid + 1, high);
}

void quickSort(int *a, int size)
{
    rec_quickSort(a, 0, size - 1);
}

int main()
{
    int *arr;
    int n, k;
    cin >> n >> k;
    arr = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    quickSort(arr, n);

    cout << arr[n - k];

    return 0;
}
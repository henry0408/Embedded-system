
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int *arr = new int[4];
    for(int i = 0; i<4; i++)
    {
        int score;
        cin>>score;
        arr[i] = score;
    }

    // for(int i = 0; i<4; i++)
    // {
    //     cout<<arr[i]<<endl;
    // }

    int maxIndex = 0;
    int minIndex = 0;
    int max = arr[maxIndex];
    int min = arr[minIndex];

    int sum = arr[0];
    for(int i = 1; i<4; i++)
    {
        if(arr[i]>max)
        {
            maxIndex = i;
            max = arr[i];
        }
        else if(arr[i]<min)
        {
            minIndex = i;
            min = arr[i];
        }
        sum+=arr[i];
    }

    
    float average = float(sum)/4;
    cout<<average<<endl;

    cout<<max<<endl;
    cout<<min<<endl;

    return 0;
}

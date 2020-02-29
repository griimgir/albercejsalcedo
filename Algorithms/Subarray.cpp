#include <iostream>

using namespace std;

int CrossSubarrSum(int *array, int start, int middle, int end){
    int sum = 0, sum2 = 0;  //Same as before initialize two different sums to make it easier to keep track of
    int left_sum = -999999999, right_sum = -999999999;
    for(int i = middle; i >= start; i--){ //traverse through the middle and decrease to start
        sum += array[i];
        if(sum > left_sum){
            left_sum = sum;
        }
    }

    for(int i = middle + 1; i <= end; i++){ //traverse from element after middle and to the end of the array
        sum2 += array[i];
        if(sum2 > right_sum){
            right_sum = sum2;
        }
    }
    int yeet = left_sum + right_sum;
    return yeet;    //we'll use thiss to compare with the rest in MaxSubarrSum
}

int MaxSubarrSum(int *array, int start, int end){
    // if(end == 1){
    //     return array[0]; //base case if the array is only size of one then there's nothing to compute.
    // }
    if(start < end){
        // int middle = end / 2;
        // int left_divide = MaxSubarrSum(array, start, middle);                   //these 2 are what I learned from divide and conquer
        // int right_divide = MaxSubarrSum(array+middle, start, (end - middle));

        int middle = start + (end-start)/2;
        // cout << middle <<endl;
        int left_divide = MaxSubarrSum(array, start, middle);
        // cout << "foo: " << left_divide << endl;
        int right_divide = MaxSubarrSum(array, middle + 1, end);
        int cross = CrossSubarrSum(array, start, middle, end);

        // cout << "bar: " << right_divide << endl;

        //-999999999
        int left_sum = -999999999; //huge negative number to compare first with sum
        int right_sum = -999999999; //huge negative number to compare first with sum2
        int sum = 0;

        //Im doing left sum
        for(int i = 0; i < middle; i++){
            sum += array[i];
            // left_sum = max(left_sum, sum);
            if(left_sum < sum){
                left_sum = sum;
            }
            else{
                left_sum = sum;
            }
            //cout << "sum" << endl;
        }

        int sum2 = 0;   //not using the same sum for the sake of tracking.
        int right_start = middle + 1; //yes this is redundednt and be put into for loop directly but this helps me follow where i am in the array.
        //Im doing right sum
        for(int i = right_start; i < end; i++){
            sum2 += array[i];
            // right_sum = max(right_sum, sum); 
            if(right_sum < sum2){
                right_sum = sum2;
            }
            else{
                right_sum = sum2;
            }
            //cout << "sum" << endl;
            //cout << "sum2" << endl;
        } 
        // int test = max(left_divide, right_divide);
        // cout << "foo: " << right_divide << " bar: " << left_divide << endl;
        return max(max((left_sum + right_sum), cross), max(left_divide, right_divide));
    }
}

int main(){
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    int sum = MaxSubarrSum(arr, 0, size - 1);

    cout << sum;
    // for(int i = 0; i < size; i++){
    //     cout << newArray << ";";
    // }

    return 0;
}
#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

vector <int> CountSubarrays(vector <int> arr) {
  
  int n = arr.size();
  
  stack<int> front;
  stack<int> back;
  vector<int> counts(n,1);
  
  // count from the left to right
  for(int i=0; i<n; ++i) {
    while(!front.empty() && arr[i] > arr[front.top()]){
      int pre_index = front.top();
      front.pop();
      counts[pre_index] += i - pre_index - 1;
    }
    front.push(i);
  }
  
  // count for those left in the monotonic descending stack
  while(!front.empty()){
    int index = front.top();
    front.pop();
    counts[index] += n - index - 1;
  }
  
  
  // count from the right to left
  for(int i = n-1; i>=0; --i){
    while(!back.empty() && arr[i] > arr[back.top()]){
      int pre_index = back.top();
      back.pop();
      counts[pre_index] += pre_index - i - 1;
    }
    back.push(i);
  }
  
  // count for those left in the monotonic descending stack
  while(!back.empty()){
    int index = back.top();
    back.pop();
    counts[index] += index ;
  }
  
  return counts;
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printIntegerVector(vector <int> array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size(); 
  int output_size = output.size(); 
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected); 
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  vector <int> test_1{3, 4, 1, 6, 2};
  vector <int> expected_1{1, 3, 1, 5, 1};
  vector <int> output_1 = CountSubarrays(test_1);
  check(expected_1, output_1);

  vector <int> test_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{1, 2, 6, 1, 3, 1};
  vector <int> output_2 = CountSubarrays(test_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
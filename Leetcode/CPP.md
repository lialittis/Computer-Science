# CPP

## Data Structure and methods

### array


#### STL : find the max element

```C++
//In the STL, std::max_element provides the iterator (which can be used to get index with std::distance, if you really want it).
int main(int argc, char** argv) {
  int A[4] = {0, 2, 3, 1};
  const int N = sizeof(A) / sizeof(int);

  cout << "Index of max element: "
       << distance(A, max_element(A, A + N))
       << endl;

  return 0;
}
```

* remark, for vector

```
int maxElementIndex = std::max_element(v.begin(),v.end()) - v.begin();
int maxElement = *std::max_element(v.begin(), v.end());

int minElementIndex = std::min_element(v.begin(),v.end()) - v.begin();
int minElement = *std::min_element(v.begin(), v.end());
```

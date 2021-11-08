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
## vector

### sum

1. loop

```
for(std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
    sum_of_elems += *it;
```
2. numeric

```
#include <numeric>

sum_of_elems = std::accumulate(vector.begin(), vector.end(), 0);
```
3. c++11 numeric

```
#include <numeric>

sum_of_elems = std::accumulate(vector.begin(), vector.end(),
                               decltype(vector)::value_type(0));
```

4. for each

```
std::for_each(vector.begin(), vector.end(), [&] (int n) {
    sum_of_elems += n;
});
```

5. range based for loop
```
for (auto& n : vector)
    sum_of_elems += n;
```

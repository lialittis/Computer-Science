
# Linear Tables

## Array


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

## heap

Heap is a special case of balaced binary tree data structure
where the root-node key is compared with its children and arranged
accordingly.

Min-Heap - Where the value of the root node is less than or equal to either of
its children

Max-Heap - Where the value of the root node is higher than or equal to either
of its children.

**!!! Node at index k in array has children at indexes 2k+1 and 2k+2,
Node at index k in array has parent at index (k-1)/2!!!**


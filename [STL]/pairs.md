* Initialization of an `array of pairs`:

```
pair<int, int> arr0[3];

pair<int, int> arr1[]={{12,25}, {10,20}, {20,30}};

pair<int, int> arr2[3]={{12,25}, {10,20}, {20,30}};
```

Mandatory to mention size at declaration, or else, it should be initialized at declaration.

<br>

* When we sort an `array of pairs`, by deafult it is sorted based upon the `first elements`. So we write a custom function if we want to sort the `array of pairs` based upon the `second element`:

```
void compare(pair<int, int> a, pair<int, int> b)
{
     return (a.second<b.second);
}
```

In C++, a custom comparator function for sorting can be defined as a function that returns a bool.
The function should return true if the first element should come before the second element, and false otherwise.
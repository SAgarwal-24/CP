## erase() function - delete elements from unordered_map
#### is used to erase elements from the unordered_map. There are three type of erase functions supported by unordered_map : erasing by iterator: It takes an iterator as a parameter and erases the key and value present at that iterator. unordered_map.

https://www.geeksforgeeks.org/unordered_map-erase-in-c-stl/

### 1. erasing by iterator: 
``` unordered_map.erase(const iterator);  ```

### 2. erasing by key:
``` unordered_map.erase(const key);  ```

### 3. erase by range:
``` unordered_map.erase(const iteratorStart, const iteratorEnd);  ```

```
// CPP program to demonstrate implementation of
// erase function in unordered_map.
#include <bits/stdc++.h>
using namespace std;

int main()
{

	unordered_map<int, bool> um;

	// Adding some elements in the map.
	um[12] = true;
	um[4189] = false;
	um[519] = true;
	um[40] = false;
	um[4991] = true;

	cout << "Contents of the unordered_map : \n";
	for (auto p : um)
		cout << p.first << "==>" << p.second << "\n";
	cout << "\n";

	// erase by iterator
	cout << "After erasing by Iterator : \n";
	um.erase(um.begin());
	for (auto p : um)
		cout << p.first << "==>" << p.second << "\n";
	cout << "\n";

	// erase by value
	cout << "After erasing by Key : \n";
	um.erase(4189);
	for (auto p : um)
		cout << p.first << "==>" << p.second << "\n";
	cout << "\n";

	// erase by range
	cout << "After erasing by Range : \n";
	auto it = um.begin();
	it++; // Returns iterator pointing to second element
	um.erase(it, um.end());
	for (auto p : um)
		cout << p.first << "==>" << p.second << "\n";
	cout << "\n";

	return 0;
}


```

## Last element of vector in C++ (Accessing and updating)
####  Using back() We can access and modify last value using back().
#### vector::front()  -> This function can be used to fetch the first element of a vector container.

```
vectorname.front()
Parameters :
No value is needed to pass as the parameter.
Returns :
Direct reference to the first element of the vector container.

vectorname.back()
Parameters :
No value is needed to pass as the parameter.
Returns :
Direct reference to the last element of the vector container.

```

```
#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v{10, 20, 30, 40, 50};
	
	// Accessing last element
	cout << v.back() << endl;

	// modifying last element
	v.back() = 100;

	cout << v.back() << endl;
        cout << v.front();
	return 0;
}

```

### Convert Int to Double in C++
learings
 - double and int - promotion  - https://stackoverflow.com/questions/13663545/does-one-double-promote-every-int-in-the-equation-to-double
 - https://en.cppreference.com/w/cpp/language/operator_precedence
 - https://linuxhint.com/convert-int-double-cpp/ (Two Categories of Conversion in C++ - Implicit Type Conversion, Explicit Type Conversion)

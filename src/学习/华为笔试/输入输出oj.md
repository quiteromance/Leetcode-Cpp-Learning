# 输入输出

## 目录

- [输入输出](#输入输出)
  - [目录](#目录)
  - [1](#1)
  - [2](#2)
  - [3](#3)
  - [4](#4)
  - [5](#5)
  - [6](#6)
  - [7 每行不定有n个整数，空格隔开](#7-每行不定有n个整数空格隔开)
    - [方法1：通过cin.get()函数来](#方法1通过cinget函数来)
    - [方法2：可以使用cin.get读取，cin.eof去终止输入](#方法2可以使用cinget读取cineof去终止输入)
    - [方法3：使用getline函数一次读取一行](#方法3使用getline函数一次读取一行)
  - [8](#8)
  - [9](#9)
  - [10](#10)

## 1

- 可以用一个while循环解决

```cpp
int a, b;
while(cin >> a >> b){ // 一个while处理多个case
    cout << a << b << endl;
}
```

## 2

输入第一行包括一个数据组数t(1 <= t <= 100)  
接下来每行包括两个正整数a,b(1 <= a, b <= 1000)

```cpp
int n;
cin >> n;
int a, b;
for(int i = 0; i < n; i++) { // 注意 while 处理多个 case
    cin >> a >> b;
    cout << a + b << endl;
}
```

## 3

```cpp
int main() {
    int a, b;
    while (cin >> a >> b && a != 0 && b!= 0) { // 注意 while 处理多个 case
        cout << a + b << endl;
    }
}
```

## 4

输入数据包括多组。  
每组数据一行,每行的第一个整数为整数的个数n(1 <= n <= 100), n为0的时候结束输入。  
接下来n个正整数,即需要求和的每个正整数。

```cpp
int n;
while (cin >> n && n != 0) { // 注意 while 处理多个 case
    vector<int> myVec(n,0);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> myVec[i];
        sum += myVec[i];
    }
    cout << sum << endl;
}
```

## 5

- 输入的第一行包括一个正整数t(1 <= t <= 100), 表示数据组数。
- 接下来t行, 每行一组数据。
- 每行的第一个整数为整数的个数n(1 <= n <= 100)。
- 接下来n个正整数, 即需要求和的每个正整数。

```cpp
int t;
cin >> t;
for(int i = 0; i < t; i++){
    int n;
    while(cin >> n){
        int num;
        int sum = 0;
        for(int j = 0; j < n; j++){
            cin >> num;
            sum += num;
        }
        cout << sum << endl;
    }
}
```

## 6

- 输入数据有多组, 每行表示一组输入数据。
- 每行的第一个整数为整数的个数n(1 <= n <= 100)。
- 接下来n个正整数, 即需要求和的每个正整数。

```cpp
int n;
while (cin >> n) { // 注意 while 处理多个 case
    int sum = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        sum += num;
    }
    cout << sum << endl;
}
```

## 7 每行不定有n个整数，空格隔开

- 输入数据有多组, 每行表示一组输入数据。
- 每行不定有n个整数，空格隔开。(1 <= n <= 100)。

注意：

```cpp
#include <iostream>
using namespace std;

int main() {
    while (1) { // 注意 while 处理多个 case
        int sum = 0;
        while(1){
            char ss;
            ss = cin.get();
            if(ss - '9' <= 0 && ss - '0' >=0){
                int num = ss - '0'; 
                sum+=num;
            }
            if(ss == '\n'){
                cout << sum << endl;
                break;
            }
        }
    }
}
```

这样写是退出不了循环的，程序不能结束

### 方法1：通过cin.get()函数来

由于读入的数据是整数-空格/回车-整数-空格/回车-...所以可以在while外面用cin>>，在while里面用cin.get()。

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a;
    int sum = 0;
    while (cin >> a) {
        sum += a;
        if(cin.get() == '\n'){
            cout << sum << endl;
            sum = 0;
        }
    }
    return 0;
}
```

### 方法2：可以使用cin.get读取，cin.eof去终止输入

cin.eof函数会在文件终止时（遇到^Z或者^D）发出信号

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int sum = 0;
    char ss;
    while (1) {
        ss = cin.get();
        if(cin.eof())break;
        if(ss <= '9' && ss >= '0'){
            sum += ss - '0';
        }
        if(ss == '\n'){
            cout << sum << endl;
            sum = 0;
        }
    }
    return 0;
}
```

### 方法3：使用getline函数一次读取一行

```cpp
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string line;
    while(true){
        getline(cin,line); // 
        if(line.empty() == 1){
            break;
        }

        istringstream iss(line);

        int num;
        int sum = 0;
        while(iss >> num){
            sum+=num;
        }
        cout << sum << endl;
    } 
}
```

注：std::istringstream 是 C++ 中的一个输入字符串流（input string stream），它是 std::stringstream 的子类，专门用于从字符串中提取数据。istringstream 的主要用途是将字符串解析为不同类型的数据，类似于如何从标准输入 (std::cin) 提取数据。

## 8

- 输入有两行，第一行n
- 第二行是n个字符串，字符串之间用空格隔开

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> myVec(n);
    for(int i = 0; i < n;i++){
        cin >> myVec[i];
    }

    sort(myVec.begin(), myVec.end());
    for(auto const &str : myVec){
        cout << str << " ";
    }
    cout << endl;

}
```

注：sort给字符串排序会按照字典顺序进行排序，当然也可以指定函数排序。

## 9

- 多个测试用例，每个测试用例一行。
- 每行通过空格隔开，有n个字符，n＜100

```cpp

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string ss;
    vector<string> myVec;
    while(cin >> ss){
        myVec.push_back(ss);
        if(cin.get() == '\n'){
            sort(myVec.begin(), myVec.end());
            for(const auto & ch : myVec){
                cout << ch << " ";
            }
            cout << endl;
            myVec.clear();
        }
    }
}
```

## 10

- 多个测试用例，每个测试用例一行。
- 每行通过,隔开，有n个字符，n＜100

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string ss;
    vector<string> myStr;
    while(cin >> ss){
        string str;
        for(int i = 0; i < ss.length(); i++){
            if(ss[i] == ','){
                myStr.push_back(str);
                str = "";
            }else{
                str += ss[i];
            }
        }
        myStr.push_back(str);

        sort(myStr.begin(),myStr.end());
        
        for(int i = 0; i < myStr.size()-1; i++){
            cout << myStr[i] << ',';
        }
        cout << myStr.back() << endl;
        myStr.clear();
    }
}
```

也可以使用getline函数来切割

```cpp
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string line;
    vector<string> myStr;
    while(getline(cin, line)){
        istringstream iss(line);
        string ss;
        while(getline(iss, ss, ',')){
            myStr.push_back(ss);
        }
        sort(myStr.begin(), myStr.end());

        for(int i = 0;i < myStr.size(); i++){
            if(i>0){
                cout << ',';
            }
            cout << myStr[i];
        }
        cout << endl;
        myStr.clear();
    }
    
}
```

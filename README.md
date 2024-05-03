# Algorithm

<div>
    <h3>
        Believe in yourself and all that you are capable of. ^.^
    </h3>
    <image src="./preview.jpg" weight=100%>
</div>

### 

### 背包问题推荐文章

背包问题中 体积至多是 j ，恰好是 j ，至少是 j 的初始化问题的研究
https://www.acwing.com/blog/content/458/

### C++11 Array
[C++11ArraySTL使用](https://blog.csdn.net/qq_38410730/article/details/102802239)


### 大根堆重载<问题
堆默认为大顶堆 ，此时 堆的 “ < ” 的含义为  ：
若 a < b 为真（返回值为真）， 则  b  排在  前面（即堆顶）

### debug.h使用
#ifdef LOCAL
#include "../../../algorithm-template/debug.h"
#else
#define debug(...) 42
#endif

本地编译的时候追加 编译参数 -D LOCAL 即可无需手动 #define LOCAL
eg: cph插件设置 or 修改编译参数
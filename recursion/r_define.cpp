递归：
简单的说递归就是一个函数直接或间接地调用本身，是为直接或间接递归。
一般来说递归需要有边界条件、递归前进段和递归返回段。
当边界条件满足时，递归返回。
注意：
1.递归就是在过程或函数里调用本身
2.在使用递归策略时，必须有一个明确的递归结束条件，称为递归出口

递归解决三类问题：
（1）数据的定于是按递归定义的（Fibonacci函数，n的阶乘）
（2）问题解法按递归实现（回溯）
（3）数据的结构形式是按递归定义的（二叉树的遍历，图的搜索）

递归缺点：
效率较低
在递归调用的过程当中系统为每一层的返回点、局部量等开辟了栈来存储，因此递归次数较多容易造成栈溢出（stack overflow）

尾递归：
尾递归就是从最后开始计算，每递归一次就算出相应的结果，也就是说，函数调用出现在调用者函数的尾部，因为是尾部，
所以根本没有必要去保存任何局部变量，直接让被调用的函数返回时越过调用者，返回到调用者的调用者去
尾递归就是把当前的运算结果（或路径）放在参数里传递给下层函数

尾递归和一般的递归不同在对内存的占用，普通递归创建stack累积而后计算收缩，尾递归只会占用恒量的内存（和迭代一样）
// 线性递归
int FibonacciRecursive(int n) {
    if (n < 2)
        return n;
    return (FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2));
}

// 尾递归
int FibonacciTailRecursive(int n, int ret1, int ret2) {
    if (n == 0)
        return ret1;
    return FibonacciTailRecursive(n - 1, ret2, ret1 + ret2);
}

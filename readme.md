## Power Flow Calc Tools

### Intro

- 潮流计算小工具，电分课间随手搓的。
- 本人人菜瘾大，代码风格粗犷，无法保证没 bug，见谅。
- 使用方法：在**终端**中打开 Release 里的 .exe 文件，并根据提示操作。

### File Menu

`G-S-Iterator-Real.cpp`:  

- 是基于实数域的 G-S 自动迭代程序。
- 迭代的方程组:

$$
\left \{
\begin{aligned}
a_{11} x_1 + a_{12} & x_2 + a_{13} x_3 + \dots = y_1\\
a_{21} x_1 + a_{22} & x_2 + a_{23} x_3 + \dots = y_2\\
a_{31} x_1 + a_{32} & x_2 + a_{33} x_3 + \dots = y_3\\
\vdots & 
\end{aligned}  
\right .
$$

- 即矩阵:

$$
\mathbf A _{n \times n} \mathbf X _{n \times 1} = \mathbf Y _{n \times 1}
$$
- 3\*3 的迭代过程示例:

$$
\left \{
\begin{aligned}
& x _1 ^{(k+1)} = \frac {1}{a _{11}} (y _1 - a _{12} x _2 ^{(k)} - a _{13} x _3 ^{(k)}) \\
& x _2 ^{(k+1)} = \frac {1}{a _{22}} (y _2 - a _{21} x _1 ^{(k+1)} - a _{23} x _3 ^{(k)}) \\
& x _3 ^{(k+1)} = \frac {1}{a _{33}} (y _3 - a _{31} x _1 ^{(k+1)} - a _{23} x _2 ^{(k+1)}) \\
\end{aligned}  
\right .
$$

- 要求矩阵 **A** 的规模不太大（10000以内）且迭代次数不太多（没试上限）。

`G-S-Iterator-Complex.cpp`:  

- 是基于复数域的 G-S 自动迭代程序。

- 对矩阵 **A** 的规模的要求比前者更加严格（1000以内）；

- 1000 以上没试过，也许可用，反正 10000 试过了，确认不行。

- 参考这里的报错信息：

- > relocation truncated to fit: R_X86_64_PC32 against symbol `__imp_Sleep' defined in .idata$5 section in xxx (我的工作目录)

- 与这里的资料：

- > GCC normally uses the "small" or "small PIC" code model on x86-64, which limits code plus static data (ie global or static ) to 2 GB.

`dummy.cpp`:  

- 是用于 debug 的标靶程序，不用管它。

`N-L-Iterator.cpp`:  

- Under Construction.

- 由于紧张的的课程及考试安排，也许还需要亿些时间来完成。。。

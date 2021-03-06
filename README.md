linux-c
=======

Here is all of my linux c code .


=====================分割线===================================

   学习日志
   
   1.13（周一）
   
    安装ubutun，熟悉系统使用
    
    熟悉vim基本使用方式：http://chloerei.com/2013/05/10/how-to-learn-vim/
    
    熟悉git使用：http://git-scm.com/book/en/Getting-Started-Git-Basics
    
    熟悉github使用：https://help.github.com/articles/set-up-git
    
    
   1.14（周二）
   
    熟悉ubutun下c语言编译，运行方式（gcc），调试（gdb）
    
    编写helloworld！并push到github
    
    进一步熟悉vim操作方式（各种快捷键）：http://coolshell.cn/articles/5426.html
    
    linux下GoAgent代理上网：https://code.google.com/p/goagent/wiki/GoAgent_Linux
    (google,github各种不稳定，我是被逼的...)
    
  
   
 以下时间主要复习一下c语言
 使用教材：Linux C编程一站式学习 http://book.douban.com/subject/4141733/
   
   1.15(周三)
   
    程序的基本概念
     
      打开gcc的-Wall选项,gcc会提示所有的警告信息
     
    常量，变量和表达式
     
      1.如果在字符串字面值中要表示单引号和冒号，既可以使用转义序列 \' 和 \? 也可以直接用字符 ' 和 ?  而要表示 \ 或者 " 则必须使用转义序列，因为 \ 字符表示转义而不表示它的字面含义  " 表示字符串的定界符而不是它的字面含义。
      2.和字符串字面中使用转义序列有一点区别，如果在字符常量中要表示双引号和问号，既可以使用转义序列，也可以直接使用字符"和?   而表示 ' 和 \ 必须使用转义序列 
      3. + - * / 左结合 ，而 = 为右结合 （如total = total_minute = hour*60+minute 等价于total = （total_minute = hour*60+minute)  ）
      4.c语言中的整数除法，无论操作数为正负，结果总是把小数部分截掉，在数轴上向零的方向取整（Truncate toward Zero）
      5.字符也可以用ASCII码转义序列表示，这种转义序列由\加上1~3个八进制数字组成，或者由\x或大写\X加上1~2个十六进制数字组成，可以用在字符常量或字符串字面值中。例如'\0'表示NUL字符（NullCharacter），'\11'或'\x9'表示Tab字符，"\11"或"\x9"表示由Tab字符组成的字符串。注意'0'的ASCII码是48，而'\0'的ASCII码是0，两者是不同的。
      6.等号左边的表达式要求表示一个存储位置而不是一个值，有的表达式既可以表示一个存储位置也可以表示一个值，而有的表达式只能表示值，不能表示存储位置，例如minute + 1这个表达式就不能表示存储位置，放在等号左边是语义错误。
      
    简单函数
    
      1.C语言的函数可以有Side Effect，这一点是它和数学函数在概念上的根本区别。
      2.使用math.h中声明的库函数还有一点特殊之处，gcc命令行必须加-lm选项，因为数学函数位于libm.so库文件中（这些库文件通常位于/lib目录下），-lm选项告诉编译器，我们程序中用到的数学函数要到这个库文件里找。本书用到的大部分库函数（例如printf）位于libc.so库文件中，使用libc.so中的库函数在编译时不需要加-lc选项，当然加了也不算错，因为这个选项是gcc的默认选项。
      3.形参相当于函数中定义的变量，调用函数传递参数的过程相当于定义形参变量并且用实参的值来初始化
      4.printf传的实参个数可以不一样，int printf(const char *format, ...)，第一个参数是const char*类型的，后面的...可以代表0个或任意多个参数，这些参数的类型也是不确定的，这称为可变参数（Variable Argument）
      5.虽然全局变量用起来很方便，但一定要慎用，能用函数传参代替的就不要用全局变量。（全局变量在任何函数中都可以访问，在程序运行过程中全局变量被读写的顺序从源代码中是看不出来的，源代码的书写顺序并不能反映函数的调用顺序。程序出现了Bug往往就是因为在某个不起眼的地方对全局变量的读写顺序不正确，如果代码规模很大，这种错误是很难找到的。）
      6.局部变量可以用类型相符的任意表达式来初始化，而全局变量只能用常量表达式（Constant Expression）初始化。
      7.全局变量在定义时不初始化则初始值是0，如果局部变量在定义时不初始化则初始值是不确定的。所以，局部变量在使用之前一定要先赋值。
      
    分支语句
    
    深入理解函数
    
      1.函数的返回值不是左值，或者说函数调用表达式不能做左值
    
   1.16(周四)
   
    循环语句
      
      1.for (控制表达式1; 控制表达式2; 控制表达式3) 语句
      如果不考虑循环体中包含continue语句的情况（稍后介绍continue语句），这个for循环等价于下面的while循环：
      控制表达式1;
      while (控制表达式2) {
   	                     语句
	                        控制表达式3;
      }
      从这种等价形式来看，控制表达式1和3都可以为空，但控制表达式2是必不可少的，例如for (;1;) {...}等价于
      while (1) {...}死循环。C语言规定，如果控制表达式2为空，则认为控制表达式2的值为真，因此死循环也可以写成for (;;) {...}。
      2.a+++++b这个表达式如何理解？
      编译的过程分为词法解析和语法解析两个阶段，在词法解析阶段，编译器总是从前到后找最长的合法Token。把这个表达式从前到后解析，变量名a是一个Token，a后面有两个以上的+号，在C语言中一个+号是合法的Token（可以是加法运算符或正号），两个+号也是合法的Token（可以是自增运算符），根据最长匹配原则，编译器绝不会止步于一个+号，而一定会把两个+号当作一个Token。再往后解析仍然有两个以上的+号，所以又是一个++运算符。再往后解析只剩一个+号了，是加法运算符。再往后解析是变量名b。词法解析之后进入下一阶段语法解析，a是一个表达式，表达式++还是表达式，表达式再++还是表达式，表达式再+b还是表达式，语法上没有问题。最后编译器会做一些基本的语义分析，这时就有问题了，++运算符要求操作数能做左值，a能做左值所以a++没问题，但表达式a++的值只能做右值，不能再++了，所以最终编译器会报错。
    
    结构体
    
    1.有些时候结构体或数组中只有某一个或某几个成员需要初始化，其它成员都用0初始化即可，用Designated Initializer语法可以针对每个成员做初始化（Memberwise Initialization），很方便。例如：struct complex_struct z1 = { .y = 4.0 }; /* z1.x=0.0, z1.y=4.0 */
    
    数组
    
    1.利用C99的新特性也可以做Memberwise Initialization：
    int count[4] = { [2] = 3 };
    2.数组和结构体虽然有很多相似之处，但也有一个显著的不同：数组不能相互赋值或初始化。例如这样是错的：
     int a[5] = { 4, 3, 2, 1 };
     int b[5] = a;
    3.如果用于初始化的字符串字面值比数组还长，比如：
     char str[10] = "Hello, world.\n";
     则数组str只包含字符串的前10个字符，不包含Null字符，这种情况编译器会给出警告。
    
     但如果用于初始化的字符串字面值比数组刚好长出一个Null字符的长度，比如：
     char str[14] = "Hello, world.\n";
     则数组str不包含Null字符，并且编译器不会给出警告

    编码风格
    
    1.indent工具可以把代码格式化成某种风格
    -kr选项表示K&R风格，-i8表示缩进8个空格的长度。如果没有指定-nut选项，则每8个缩进空格会自动用一个Tab代替。
    
   1.17(周五)
   
    gdb
    
    排序与查找
    
    栈与队列
     
 至此本书上篇结束
   

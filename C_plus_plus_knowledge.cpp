//
// Created by xx on 2023/3/26.
//
/*
 一、struct和class的区别是什么？
    总的来说，struct 更适合看成是一个数据结构的实现体，class 更适合看成是一个对象的实现体。
    区别
    最本质的一个区别就是默认的访问控制：
    1. 默认的继承访问权限。struct 是 public 的，class 是 private 的。
    2. struct 作为数据结构的实现体，它默认的数据访问控制是 public 的，而 class 作为对象的实现体，它默认的成员变量访问控制是 private 的。

 二、封装
    把客观事物封装成抽象的类，并且类可以把自己的数据和方法只让可信的类或者对象操作，对不可信的进行信息隐藏。
    关键字：public, protected, private。不写默认为 private。
    public 成员：可以被任意实体访问
    protected 成员：只允许被子类及本类的成员函数访问
    private 成员：只允许被本类的成员函数、友元类或友元函数访问

 三、继承
    基类（父类）——> 派生类（子类），主要实现重用代码，节省开发时间

 四、多态
    多态，即多种状态（形态）。简单来说，我们可以将多态定义为消息以多种形式显示的能力。
    多态是以封装和继承为基础的。
    C++ 多态分类及实现：
        重载多态（Ad-hoc Polymorphism，编译期）：函数重载、运算符重载
        子类型多态（Subtype Polymorphism，运行期）：虚函数
        参数多态性（Parametric Polymorphism，编译期）：类模板、函数模板
        强制多态（Coercion Polymorphism，编译期/运行期）：基本类型转换、自定义类型转换

 五、C++是什么？
    C++是在C语言的基础上开发的一种面向对象编程语言，支持多种编程范式：面向对象编程、泛型编程和过程化编程。

 六、C++和C的区别是什么？
    c++在c的基础上增添类，C是一个结构化语言，它的重点在于算法和数据结构。C程序的设计首要考虑的是如何通过一个过程，
    对输入（或环境条件）进行运算处理得到输出（或实现过程（事务）控制），而对于C++，首要考虑的是如何构造一个对象模型，
    让这个模型能够契合与之对应的问题域，这样就可以通过获取对象的状态信息得到输出或实现过程（事务）控制。

 七、什么是面向对象（OOP）？
    面向对象是一种对现实世界理解和抽象的方法，通过将需求要素转化为对象进行问题处理的一种思想。

 八、什么是设计模式？
    本质上就是一套被反复使用、多数人知晓的、经过分类编目的、代码设计经验的总结。
    比如单例模式，保证一个类仅有一个实例，并提供一个访问它的全局访问点。
    适用于：当类只能有一个实例而且客户可以从一个众所周知的访问点访问它时；
    当这个唯一实例应该是通过子类化可扩展的，并且客户应该无需更改代码就能使用一个扩展的实例时。
    比如工厂模式，定义一个用于创建对象的接口，让子类决定实例化哪一个类。Factory Method 使一个类的实例化延迟到其子类。
    适用于：当一个类不知道它所必须创建的对象所属类的时候；当一个类希望由它的子类来指定它所创建的对象的时候；
    当类将创建对象的职责委托给多个帮助子类中的某一个，并且你希望将哪一个帮助子类是代理者这一信息局部化的时候。

九、指针和引用的区别？
    指针繁杂、不利于开发，开发者使用引用代替指针的部分功能。主要区别：
    （1）引用即是变量的别名，作用相当于常指针，只能指向一个对象(后面不可更改)，而指针可以多次改变指向的对象。
    （2）指针可以有多级指针。

十、const和define区别
    1. define在预处理阶段进行替换，const在编译时确定其值。
    2. define – 无类型，不进行类型安全检查，可能会产生意想不到的错误；const – 有数据类型，编译时会进行类型检查。

十一、C++的编译过程是什么？
    .c源程序输入预处理器，输出为.i文件，输入编译器，输出.s汇编程序，输入汇编器，输出.o可重定位程序（二进制），输入链接器，输出可执行程序（二进制）

十二、new 和 malloc区别
    1. malloc是标准函数，new是运算符且可以调用构造函数
    2. new返回的是指定指针类型，malloc返回的是void*类型

十三、什么是内存泄露？怎么预防？
    程序在运行过程中动态申请的内存空间不再使用后没有及时释放，导致那块内存不能被再次使用。
    避免方法：及时通过delete、free释放空间，使用智能指针。

十四、什么是智能指针？
    将指针封装成类，指针对象生存周期结束时自动调用析构函数释放指针。

 十五、C++的内存分区是什么？
    栈区（stack）：主要存放函数参数以及局部变量，由系统自动分配释放。
    堆区（heap）：由用户通过 malloc/new 手动申请，手动释放。注意它与数据结构中的堆是两回事，C++的堆区分配方式倒是类似于链表。
    全局/静态区：存放全局变量、静态变量；程序结束后由系统释放。
    字符串常量区：字符串常量就放在这里，程序结束后由系统释放。
    代码区：存放程序的二进制代码。



 */
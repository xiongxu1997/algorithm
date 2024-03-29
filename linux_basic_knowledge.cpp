//
// Created by xx on 2023/3/25.
//
/*
    一、linux常用的命令
    1. cd：切换目录
    2. ls：列出当前目录下的文件和子目录
    3. pwd：显示当前工作目录的完整路径
    4. mkdir：创建新目录
    5. touch：创建新文件
    6. rm：删除文件或目录
    7. cp：复制文件或目录
    8. mv：移动文件或目录
    9. cat：显示文件的内容
    10. less：分页显示文件的内容
    11. grep：在文件中搜索指定的字符串或文本
    12. ps：显示当前系统进程的信息
    13. top：实时显示系统资源使用情况和进程信息
    14. kill：终止指定进程
    15. ifconfig：显示网络接口的配置和状态信息
    16. ping：测试网络连接
    17. ssh：远程连接到另一台Linux系统
    18. scp：通过SSH协议在本地和远程系统之间复制文件
    19. tar：创建或解压缩tar归档文件
    20. apt-get：在Debian或Ubuntu系统上安装、升级或卸载软件包
    21. chmod：修改文件或目录的访问权限
    22. chown：修改文件或目录的所有者和所属组

    二、linux的基本组件
    内核（Kernel）：Linux系统的核心组件，是操作系统的核心部分，控制硬件设备、文件系统、进程、内存等方面的操作。

    Shell：是用户与Linux系统交互的接口，提供命令行界面，用户可以通过Shell输入命令，控制Linux系统的各个方面。

    文件系统（File System）：Linux系统使用文件系统来管理文件和目录，包括虚拟文件系统、磁盘文件系统等。

    网络（Network）：Linux系统支持网络通信，可以使用TCP/IP协议等进行网络通信，支持多种网络协议和服务。

    应用程序（Applications）：Linux系统有大量的应用程序可供选择，包括文本编辑器、图形界面工具、开发工具等。

    用户账户（User Accounts）：Linux系统支持多用户和多任务，每个用户都有自己的账户和权限，可以访问系统资源并执行相应的任务。

    三、linux的体系结构
    用户空间（User Space）：包括用户进程、系统库和应用程序，提供了用户与操作系统交互的接口。用户可以在用户空间中运行应用程序、访问文件系统等。

    内核空间（Kernel Space）：包括内核代码、设备驱动程序和系统调用接口，提供了操作系统的核心功能，包括处理器管理、内存管理、进程调度、网络管理等。

    硬件层（Hardware Layer）：包括计算机的物理硬件，如处理器、内存、硬盘、网卡等。

    每个部分的作用如下：
    用户空间：提供了用户与Linux系统交互的接口，允许用户运行应用程序、访问文件系统和网络等。用户空间还包括各种应用程序和库，例如文本编辑器、Web浏览器、图像处理工具等。

    内核空间：是Linux系统的核心部分，提供了操作系统的核心功能，例如处理器管理、内存管理、进程调度、网络管理等。内核空间还包括设备驱动程序，用于控制硬件设备，以及系统调用接口，用于提供应用程序与操作系统之间的通信接口。

    硬件层：包括计算机的物理硬件，例如处理器、内存、硬盘、网卡等，为操作系统提供底层支持。

    四、linux的文件系统
    基本组成：
    根目录（/）：整个文件系统的根目录，所有的文件和目录都是从这个根目录开始分支出来的。
    标准目录（/bin、/sbin、/usr/bin、/usr/sbin）：包含了操作系统的标准命令和系统管理员用的命令。
    挂载点（/mnt、/media）：用来挂载外部设备（如U盘、光驱）的目录。
    用户目录（/home）：包含了每个用户的家目录。
    配置目录（/etc）：包含了系统配置文件，例如网络配置、用户账户信息等。
    库目录（/lib、/usr/lib）：包含了操作系统和应用程序所需的共享库文件。
    进程目录（/proc）：包含了当前正在运行的进程信息和内核信息。
    设备目录（/dev）：包含了系统中所有的设备文件，例如硬盘、打印机、鼠标等。
    日志目录（/var/log）：包含了系统和应用程序的日志文件。

    每个组成的功能：
    根目录：整个文件系统的根目录，所有的文件和目录都是从这个根目录开始分支出来的。
    标准目录：包含了操作系统的标准命令和系统管理员用的命令。
    挂载点：用来挂载外部设备（如U盘、光驱）的目录。
    用户目录：包含了每个用户的家目录，可以存放用户个人的文件和目录。
    配置目录：包含了系统配置文件，例如网络配置、用户账户信息等。
    库目录：包含了操作系统和应用程序所需的共享库文件，用于支持应用程序的正常运行。
    进程目录：包含了当前正在运行的进程信息和内核信息，可以用于监控系统状态。
    设备目录：包含了系统中所有的设备文件，用于访问硬件设备和驱动程序。
    日志目录：包含了系统和应用程序的日志文件，用于记录系统和应用程序的运行情况。

    Linux系统支持多种文件类型，包括普通文件、目录文件、设备文件、符号链接文件、管道文件、套接字文件等。

    五、linux系统中的inode是什么？
    在Linux系统中，inode（索引节点）是文件系统中用来存储文件元数据的一种数据结构。每个文件在文件系统中都对应着一个唯一的inode，
    它存储了文件的各种属性信息，例如文件类型、所有者、权限、大小、创建时间、修改时间、访问时间等等。

    当我们在Linux系统中访问一个文件时，系统需要通过文件名来查找对应的inode，然后才能获取文件的实际内容。因此，inode可以看作是
    文件系统中文件的“身份证”，它能够帮助系统管理文件，同时也可以提高文件系统的性能和效率。

    每个文件系统都有一定数量的inode，文件系统的inode数量是在文件系统格式化时就确定好的，因此，如果inode数量用完了，就无法再创建
    新的文件或目录。因此，当使用Linux系统时，我们需要了解文件系统的inode使用情况，以避免出现文件系统无法写入的情况。

    六、linux中什么是软连接和和硬链接？
    硬链接
    硬链接是指在文件系统中创建一个新的文件名，使其指向已有的文件实体。硬链接与原文件实体共享同一个inode，
    也就是说，它们具有相同的文件内容和属性，不同之处在于它们有不同的文件名和目录位置。因为硬链接与原文件实体共享inode，
    所以它们之间的文件内容始终保持同步。但是，硬链接只能针对同一个文件系统中的文件使用，不能跨文件系统链接。

    软链接
    软链接是指在文件系统中创建一个新的文件名，使其指向已有的文件路径。软链接实际上是一个特殊类型的文件，其中包含了指向原文件的路径名，
    而不是文件实体本身。因为软链接是一个独立的文件，它与原文件实体有不同的inode，因此可以跨越不同的文件系统进行链接。
    但是，如果原文件实体被删除或移动，软链接将无法访问对应的文件内容。

    在使用链接时需要注意的是，硬链接只能对文件使用，而不能对目录使用；而软链接可以对文件和目录都使用。
    同时，对于软链接，由于它只包含指向原文件的路径名，因此当原文件被删除后，软链接可能会成为“死链接”，无法访问对应的文件内容。

    七、介绍一下linux中不同目录的作用
    根目录（/）
    根目录是Linux系统中最顶层的目录，所有的其他目录和文件都位于它的下面。
    根目录中存储着系统和应用程序所需的核心文件和目录，是整个文件系统的起点。

    /bin目录
    /bin目录存储了一些最基本的系统命令和工具，如ls、cp、mv、rm等，这些命令通常可以在系统引导时就加载。

    /sbin目录
    /sbin目录存储了一些系统级别的命令和工具，如系统管理命令、网络管理命令、硬件配置命令等。这些命令通常只有系统管理员才能使用。

    /usr目录
    /usr目录是Unix Shared Resources（Unix共享资源）的缩写，存储了系统中的大部分用户级别的应用程序、库文件、文档等资源。

    /etc目录
    /etc目录存储了系统的配置文件，如网络配置、用户账号信息、服务启动脚本等。这些文件通常只能由系统管理员修改。

    /var目录
    /var目录存储了系统运行时的一些变化数据，如日志文件、邮件、临时文件等。这些数据通常是动态生成和修改的，因此需要存储在一个单独的目录中。

    /home目录
    /home目录存储了所有用户的个人目录，每个用户的个人文件和设置都存储在其个人目录中。

    /tmp目录
    /tmp目录存储了系统和应用程序运行时需要的临时文件，这些文件通常在系统重启后会被清空。

    以上仅是一些常见的目录类别及其作用，实际上Linux系统中还有很多其他目录，不同的发行版和安装方式也可能会有所不同。
    理解这些目录的作用，有助于我们更好地管理和使用Linux系统。

    八、linux系统中的用户空间和内核空间是什么？它们有什么区别？
    Linux系统中的用户空间和内核空间是指CPU运行程序时的两个不同的内存地址空间，每个空间都有其独特的特点和功能。

    用户空间（User Space）是指操作系统分配给用户程序的一部分内存空间，用于存放用户程序和用户数据。
    用户空间包含用户程序、库文件和用户数据，它们可以被普通用户访问和操作。在用户空间中，只能执行受限制的操作，例如读写文件和网络通信等。

    内核空间（Kernel Space）是操作系统内核使用的一部分内存空间，用于执行系统核心代码和驱动程序。
    内核空间可以访问系统硬件和资源，可以执行所有的系统操作，例如文件系统、进程调度、网络协议、设备驱动程序等。
    在内核空间中，可以执行特权操作，例如直接操作硬件和修改系统状态等。

    用户空间和内核空间之间的区别在于它们的访问权限和操作能力。用户程序运行在用户空间中，只能访问自己的地址空间和受限制的系统资源，
    不能直接操作硬件和内核数据结构。而操作系统内核运行在内核空间中，可以访问系统的所有资源和硬件设备，并执行所有的系统操作。

    九、计算机开机过程中，操作系统会发生什么变化？
    计算机开机时，操作系统会经历如下步骤：
    1. 加电自检（Power-On Self Test，POST）：计算机加电后，首先进行硬件自检，包括检测主板、CPU、内存、硬盘、光驱等硬件设备是否正常工作。
    2. BIOS自检：自检完成后，计算机会启动BIOS（基本输入/输出系统），BIOS会对许多硬件进行进一步的检查，并读取
    CMOS（互补金属氧化物半导体）中保存的配置信息。
    3. 启动引导程序（Boot Loader）：BIOS读取完CMOS信息后，会将控制权转交给启动引导程序。启动引导程序会搜索硬盘上的引导扇区，
    找到并读取操作系统的引导程序，将控制权转交给操作系统引导程序。
    4. 操作系统引导程序：操作系统引导程序会读取并装载操作系统内核到内存中，并跳转到内核的入口点，开始执行操作系统的初始化工作。
    5. 内核初始化：操作系统内核开始初始化各种硬件设备、驱动程序和系统服务，并启动各种系统服务。同时，内核还会建立进程调度表和内存分配表
    等数据结构，为后续的进程创建和资源管理做好准备。
    6. 用户空间初始化：一些启动时必需的用户空间进程，如 init 进程等被启动。init 进程是用户空间的第一个进程，它负责启动其他用户空间的进程，
    如系统日志进程、网络进程等等。
    7. 系统进程启动：系统进程启动完成后，操作系统就开始正式工作，提供各种服务和接口，如文件系统、网络协议栈、进程管理等等。

    十、linux系统中进程之间的通信方式有哪些？每种方式的工作原理是什么？
    1. 管道（Pipe）：管道是一种半双工通信方式，由一个进程向另一个进程传递数据。在Linux系统中，可以使用pipe系统调用创建匿名管道，
    也可以使用mkfifo系统调用创建有名管道。管道底层是基于内存实现的，数据传输速度较快。

    2. 信号（Signal）：信号是一种异步通信方式，用于通知接收进程发生了某个事件，如进程终止、用户中断等。发送进程通过kill系统调用发送信号，
    接收进程通过signal系统调用处理信号。

    3. 共享内存（Shared Memory）：共享内存是一种进程间共享数据的方式，可以通过将一块物理内存区域映射到多个进程的虚拟地址空间来实现。
    共享内存速度快，但需要进程间同步，避免数据访问冲突。

    4. 消息队列（Message Queue）：消息队列是一种消息传递机制，允许不同进程之间通过一个共享的消息队列进行通信。
    发送进程通过msgsnd系统调用向消息队列中发送消息，接收进程通过msgrcv系统调用从消息队列中接收消息。

    5. 信号量（Semaphore）：信号量是一种计数器，用于控制进程对共享资源的访问，防止多个进程同时访问同一资源。
    信号量可以通过semget、semop、semctl等系统调用实现。

    6. 套接字（Socket）：套接字是一种网络通信机制，可用于不同主机之间的进程通信。套接字通信可以使用TCP或UDP协议，常用于网络编程中。

    十一、进程所在的内存空间有哪几部分组成？每个部分的功能是什么？
    1. 代码段（text segment）：也称为只读代码段，存储进程的可执行代码。代码段通常是只读的，以保证进程的执行安全性。
    2. 数据段（data segment）：数据段存储程序中已初始化的全局变量、静态变量和常量等。数据段通常是可读写的。
    3. BSS段（BSS segment）：BSS段存储程序中未初始化的全局变量和静态变量，它通常被初始化为0。BSS段通常也是可读写的。
    4. 堆（heap）：堆用于动态分配内存，通常由malloc、realloc、calloc等库函数进行分配和释放。堆的大小可以根据需要动态扩展。
    5. 栈（stack）：栈用于存储函数调用时的临时变量和函数调用信息。每个线程都有自己的栈，栈的大小通常是固定的。
    栈通常是从高地址向低地址增长的，栈底指向栈空间的最高地址。
    6. 共享内存（shared memory）：共享内存用于实现进程之间的共享内存。多个进程可以通过共享内存来
    读写相同的物理内存空间，以达到共享数据的目的。
    7. 内核空间（kernel space）：内核空间是内核代码运行的内存空间，它不属于任何一个进程的地址空间。
    内核空间可以访问所有的硬件设备和内存空间，而用户空间只能访问自己的内存空间。

    十二、RAM和ROM分别是什么？
    RAM（Random Access Memory，随机访问存储器）是一种易失性存储器，用于临时存储计算机运行时所需的数据和指令。RAM 的数据读写速度很快，
    但是当计算机关闭电源时，RAM 中的数据也会被清除。因此，RAM 中的数据需要不断地从外部存储器（如硬盘）中加载，以保证计算机的正常运行。

    ROM（Read-Only Memory，只读存储器）是一种只读存储器，存储的数据一旦写入就无法修改，通常用于存储程序和数据，例如 BIOS 程序、
    操作系统引导程序等。ROM 中的数据在计算机关闭电源时不会丢失，因此它可以长期保存数据。ROM 的读取速度相对较慢，
    但是由于它不需要供电来保持存储的数据，因此它具有很高的可靠性和稳定性。

    因此，RAM 和 ROM 的主要区别在于数据的读写方式和数据持久性。
    RAM 可以被多次读写，但是数据不可持久；
    而 ROM 中的数据只能被读取，但是数据具有长期的持久性。

    十三、进程和线程的区别是什么？
    进程是一个独立的执行单位，而线程是进程的一部分，是CPU调度的基本单位。
    进程拥有自己独立的地址空间，而线程共享进程的地址空间。
    进程之间相互独立，一个进程崩溃并不会影响其他进程，而同一进程内的线程是共享资源的，一个线程崩溃会影响整个进程。
    进程之间要进行IPC（进程间通信）才能进行数据交换，而同一进程内的线程可以通过共享的内存区域来直接交换数据。
    进程的创建和销毁都比较耗费系统资源，而线程的创建和销毁比较轻量级，资源消耗也比较少。

    十四、进程和线程分别由什么组成？
    一个进程由以下几部分组成：
    代码段：包含进程要执行的指令。
    数据段：包含进程所使用的变量、常量等数据。
    堆：用于动态分配内存。
    栈：用于保存函数调用、局部变量等信息。
    进程控制块（PCB）：记录进程的状态信息，如程序计数器、寄存器值、内存分配等等。

    而一个线程由以下几部分组成：
    栈：用于保存函数调用、局部变量等信息。
    线程局部存储（TLS）：存储线程特有的数据。
    寄存器：存储线程执行状态信息。
    程序计数器：指示当前正在执行的指令的位置。
    需要注意的是，线程没有自己的代码段和数据段，它们共享进程的代码段和数据段。
    同时，线程还能够共享进程的打开文件、信号处理器等资源。
 */
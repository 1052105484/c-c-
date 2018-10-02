1.一维数组名称

    1.1 本质并不是一个指针

    1.2 有两种特殊情况

        1.2.1 对数组名称进行sizeof

        1.2. 对数组名称取地址，获取的指针步长是整个数组的长度
    
    1.3 除了两种特殊情况外，都是指向数组中首元素的地址的指针

    1.4 数组名，指针常量，指针的指向不可以修改

    1.5 如果将数组名称传入到函数参数中，为了提高可读性，通常写为int arr[]

    1.6 访问数组元素的时候，下标可以为负数

2.如何定义一个数组的指针

    2.1 先定义数组的类型，再通过类型创建数组指针

        2.1.1 typedef int(ARRAY_TYPE)[5];

    2.2 先定义数组指针的类型，再通过数组指针的类型创建出数组指针变量

        2.2.1 typedef int(*ARRAY_TYPE)[5];
    
    2.3 直接创建数组指针变量

        2.3.1 int(*p)[5]=&arr;
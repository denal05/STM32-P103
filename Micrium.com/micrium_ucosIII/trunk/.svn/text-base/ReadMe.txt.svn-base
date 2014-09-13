1、uCOS-III版本：V1.28.01
2、STM32F10x外设库版本：V3.5.0
3、使用ST标准外设库提供的启动文件文件和初始配置文件，位于\PubLib\CMSIS\CM3\DeviceSupport\ST\STM32F10x目录下。 启动文件为startup_stm32f10x_xx.s，其中ss为 md\hd等，表示对应的系列。在进入main函数前，调用初始配置文件system_stm32f10x.c中的SystemInit函数设置时钟。该函数采用默认的晶振和时钟配置（比如MD采用HSE为8M，配置系统时钟wie72M，CL采用HSE为25M），根据实际情况修改源代码。如果使用外部SRAM，在system_stm32f10x.c中定义宏DATA_IN_ExtSRAM，之后SystemInit函数会调用函数SystemInit_ExtMemCtl配置FMSC，该函数默使用BANK1连接SRAM，根据实际情况修改源代码。
4、适用于所有系列产品，注意更改lib文件、STM32F10X_XX宏定义、startup_stm32f10x_xx.s使之与实际使用的芯片对应。
5、使用NVIC外设库函数设置中断，更改向量表以注册ISR函数。
6、core_cm3.c/.h为CMSIS标准接口中的一些函数和定义，一些与CM3内核关联而与具体厂家产品无关的操作，可参考这两个文件，选择调用。






											刘泽勇
										      2011.9.17
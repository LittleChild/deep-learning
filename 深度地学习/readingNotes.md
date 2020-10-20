#### 基于滤波的方法

KF：kalman算法，适合用于线性的高斯分布的状态环境中

EKF：拓展的kalman滤波，解决在非高斯和非线性环境下的机器人定位算法

问题：在现实应用中计算量、内存消耗上不是很高效。

这就引出了**MCL**算法

​		**蒙特卡洛定位（MCL）**，也称为**粒子滤波器定位**，是一种机器人使用[粒子滤波器](https://en.wikipedia.org/wiki/Particle_filter)进行[定位](https://en.wikipedia.org/wiki/Robot_localization)的算法。给定环境图，该算法会估计机器人在移动并感测环境时的[位置和方向](https://en.wikipedia.org/wiki/Pose_(computer_vision))。该算法使用[粒子过滤器](https://en.wikipedia.org/wiki/Particle_filter)表示可能状态的[分布](https://en.wikipedia.org/wiki/Probability_density_function)，每个粒子表示可能的状态，即机器人所在位置的假设。该算法通常从[配置空间](https://en.wikipedia.org/wiki/Configuration_space_(physics))上的均匀均匀的粒子随机分布开始，这意味着机器人没有关于其位置的信息，并假定它同样有可能位于空间的任何一点。每当机器人移动时，它都会移动粒子以预测运动后的新状态。每当机器人感测到某物时，都会基于[递归贝叶斯估计](https://en.wikipedia.org/wiki/Recursive_Bayesian_estimation)（即实际感测数据与预测状态的相关程度）对粒子重新采样。最终，粒子应会聚到机器人的实际位置。

​		粒子滤波很粗浅的说就是一开始在地图空间很均匀的撒一把粒子，然后通过获取机器人的motion来移动粒子，比如机器人向前移动了一米，所有的粒子也就向前移动一米，不管现在这个粒子的位置对不对。使用每个粒子所处位置模拟一个传感器信息跟观察到的传感器信息（一般是激光）作对比，从而赋给每个粒子一个概率。之后根据生成的概率来重新生成粒子，概率越高的生成的概率越大。这样的迭代之后，所有的粒子会慢慢地收敛到一起，机器人的确切位置也就被推算出来了。

MCL的计算步骤：

1. **随机产生一堆粒子**：粒子可以有位置、方向和/或任何其他需要估计的状态变量。每一个都有一个权值(概率)，表明它与系统的实际状态匹配的可能性有多大。用相同的权重初始化每个变量。
2. **预测粒子的下一个状态**：根据真实系统行为的预测来移动粒子。
3. **更新**：根据测量结果更新粒子的权重。与测量值密切匹配的粒子的权重要高于与测量值不太匹配的粒子。
4. **重新采样**：抛弃高度不可能的粒子，代之以更可能的粒子的副本。
5. **计算估计值**：可选地，计算粒子集的加权平均值和协方差来得到状态估计。

粒子滤波的基本步骤为上面所述的5步，其本质是使用一组有限的**加权随机样本（粒子）来近似表征任意状态的后验概率密度**。粒子滤波的优势在于对复杂问题的求解上，比如高度的非线性、非高斯动态系统的状态递推估计或概率推理问题。

算法伪码：
$$
时间\ t,输入:先前的置信值X_{t-1}=\{x_{t-1}^{[1]},x_{t-1}^{[2]},...,x_{t-1}^{[M]} \},u_{t}一个驱动命令 ，z_{t}是从传感器接收的数据，算法输出新的置信值X_{t}。
$$

$$
\begin{align*}
&Algorithm\ MCL (X_{t-1},u_{t},z_{t}):\\     
	&\qquad{\bar{X_{t}}}=X_{t}=\emptyset \\
    &\qquad for\ {\displaystyle m=1}\ to\ {\displaystyle M}:\\
	&\qquad	\qquad	x_{t}^{{[m]}}= motion\_update(u_{t},x_{{t-1}}^{{[m]}})\\
	&\qquad	\qquad	w_{t}^{{[m]}}= sensor\_update(z_{t},x_{t}^{{[m]}})\\
  &\qquad\qquad  {\bar  {X_{t}}}={\bar{X_{t}}}+\langle x_{t}^{{[m]}},w_{t}^{{[m]}}\rangle \\
     &\qquad  endfor\\
     &\qquad  for\ m=1\ to\ M:\\
    &\qquad\qquad draw\ x_{t}^{{[m]}} from\ {\bar  {X_{t}}}\ with\ probability\ \propto w_{t}^{{[m]}}\\ 
&\qquad\qquad X_{t}=X_{t}+x_{t}^{{[m]}}\\
    &\qquad   endfor\\
     &\qquad  return\ X_{t}
\end{align*}
$$



#### 地磁定位：

**地磁定位的原理**：

​		地磁定位是行进中的载体实时采集地磁场的特征信息，并将实时采集的地磁数据与已经存储的地磁基准图进行比较，根据相应的准则获取最佳匹配结果实现载体的自主定位。

数据采集：

1. 单点采集，用指纹方法定位
2. 连续采集，通过序列定位，，只求相对的位置改变，用到DWT（动态时间规整），MCL，卡尔曼滤波等方法

**室内地磁定位的运用：**

​		地磁场由于存在局部的差异性，使得能够存在用于定位的可能，但是室外场景的地磁场的不均匀分布的差异性不够明显，在室内场景下，收到钢筋混凝土和房屋内部各种物体金属的影响，使得磁场的分布更加不均匀，增大了差异性，且相对稳定，在一段时间内不会有很大的改变，所以可以用来定位。现在的平均的精度在2m左右。

**室内地磁定位的不足**

1、地磁数据采集工作

​		地磁定位技术的使用要始于对现场地磁数据的采集，而且每当室内环境有较大的变动，比如重新装修的情况时，需要重新对现场地磁数据进行采集更新，这相当于给用户带来了较多的工作量。

2、信号干扰

​		地磁信号本身是容易受到金属物的干扰，室内环境又很难保持一成不变，假如用户周边突然出现驶过一辆汽车，现场磁场受到干扰，对其位置的获取势必有较多影响，因此地磁定位的稳定性值得商榷。

3、初始位置的获取

​		地磁定位是相对位置，所以单纯依靠地磁来定位是没法立刻获取初始位置的，很多方案都要求用户在使用定位前在室内行走5~8米，以帮助获取初始位置，也有很多方案采取其他定位技术（比如PDR/iBeacon/Wifi）来辅助获取初始位置，这也是室内地磁定位技术最难解决的问题。



因此，现在很多地磁定位都会和运动模型结合起来，为了考虑运动模型，J. Haverinen and A. Kemppainen [1]通过使用蒙特卡洛定位（MCL）将来自机器人和人类的沉船信息与地磁图融合在一起。但是，该算法是针对一维定位而开发的，而地图是仅基于航迹推算的位置构建的，因此容易发生漂移。在[2]中利用运动捕捉系统来提供精确的姿势，以创建高精度的地磁图，并基于MCL对”有腿”（行人装配到脚上）和”无腿”（车型机器人）运动进行定位。[3]

[1] J. Haverinen and A. Kemppainen, “Global indoor self-localization based on the ambient magnetic field,” Robot. Auton. Syst., vol. 57, no. 10, pp. 1028–1035, 2009.

[2] M. Frassl, M. Angermann, M. Lichtenstern, P. Robertson, B. J. Julian, and M. Doniec, “Magnetic maps of indoor environments for precise localization of legged and non-legged locomotion,” in Proc. IEEE/RSJ Int. Conf. Intell. Robots Syst. IEEE, 2013, pp. 913–920.

[3] Sen Wang, Hongkai Wen, Ronald Clark and Niki Trigoni, Keyframe based Large-Scale Indoor Localisation using Geomagnetic Field and Motion Pattern, IEEE/RSI International Conference on Intelligent Robots and Systems. Daejeon: IEEE 2016

#### WiFi定位

​		Wifi定位分两种方式：基于传输时延的，和基于指纹的方法，目前多用基于指纹的方法。基于WiFi的接入点（Access Point）彼此是互相独立的假设，定位方式又细分概率性和确定性两种。



**多径干扰**

多径效应：这其实是考虑，同一码元波形的各个分量可能通过不同的路径传播，那么不同多径分量到达接收端的时间就不同，第一个多径分量到达的时刻和最后一个多径分量到达的时刻，这之间存在一个时间差，当这个时间差超过了一个码元的宽度之后，就意味着，上一个码元的一部分多径分量，在这个码元本应该传输完毕的时候，还没有到达接收点，而是混在了下一个码元的多径分量中到达的接收点，从而对下一个码元产生了干扰——叠加的时候不仅有自己的分量，还有别人的分量。

 

RSS：是指客户端接收的无线信号强度（Received Signal Strength），属于MAC层，来自每个数据包。比如手机上，我们经常会看到 Wi-Fi 信号不满格，一般认为信号不好。我个人理解就是指 RSS 不够强。一般 RSS  的强度受到三个方面影响：1）路径衰减；2）遮挡；3）多径效应。利用当前的WiFi设备获取的RSS不太精确，不过可以利用RSS信息做一些应用，例如室内定位、目标对象移动侦测一类的。

CSI：是衡量信道情况的信道状态信息（Channel State Information）,属于PHY层，来自OFDM系统下解码的子载波。CSI是细粒度的物理信息，对环境更加敏感，所以应用于动作识别，手势识别，击键识别，跟踪等领域。



PoseNet：

loss函数定义为位置差异和角度差异的加权欧式距离，详细定义如下：
$$
loss(I)=||\hat{x}-x||_2 + \beta\left \| \hat{q}-\frac{q}{||q||} \right \|_2
$$

$$
其中,x,q和\hat{x},\hat{q}分别表示ground truth的位置(x, y, z)和角度（raw, yaw, pitch）与估计的位置和角度，\\\beta为位置和角度损失的权值。接下来就是模型的训练了，没有特别的训练策略。得到的定位结果看起来不错。
$$

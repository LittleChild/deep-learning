**torch.flatten**

torch.flatten(input, start_dim=0, end_dim=-1)
input: 一个 tensor，即要被“推平”的 tensor。
start_dim: “推平”的起始维度。
end_dim: “推平”的结束维度。
首先如果按照 start_dim 和 end_dim 的默认值，那么这个函数会把 input 推平成一个 shape 为[n]的tensor，其中 n 即 input 中元素个数。（这里注意的一点是，维度是从下标 0 开始的）
pytorch中的 torch.nn.Flatten 类和 torch.Tensor.flatten 方法其实都是基于上面的 torch.flatten 函数实现的。

torch.max()

output = torch.max(input, dim)
input输入的是一个tensor
dim是max函数索引的维度0/1，0是每列的最大值，1是每行的最大值
output 是对应的最值和对应的下标索引
对比numpy.max() ，多了下标索引的返回值
实例

import torch
import numpy as np
import matplotlib.pyplot as plt
x = torch.randn(3,3)
print(x)
max_value,index = torch.max(x,dim=1) #返回的是两个值，一个是每一行最大值的tensor组，另一个是最大值所在的位置
print(max_value,index)
max_lie_value = torch.max(x,dim=0)[0].numpy() #每一列最大值
max_hang_value = torch.max(x,dim=1)[0].numpy() #每一行最大值
print('max_lie_value:',max_lie_value,'\nmax_hang_value',max_hang_value)
输出

tensor([[ 1.0625, -0.7129,  0.0849],
        [ 0.9122, -0.5969,  1.2351],
        [-0.2937,  0.0923, -0.4093]])
tensor([1.0625, 1.2351, 0.0923]) tensor([0, 2, 1])
max_lie_value: [1.0625167  0.09232075 1.2350996 ]
max_hang_value [1.0625167  1.2350996  0.09232075]

torch.optim.lr_scheduler
用来调整学习率，提供了多种基于epoch训练次数进行学习率调整的方法


# Observe that all parameters are being optimized
optimizer_ft = optim.SGD(model_ft.parameters(), lr=0.001, momentum=0.9)

# Decay LR by a factor of 0.1 every 7 epochs
lr_scheduler.StepLR(optimizer_ft, step_size=7, gamma=0.1)
这里是每隔7个epoch，学习率×0.1
StepLR 每隔多少epoch学习率成比率下降，其实不是每个多少个epoch，你在每个batch后运行这个，他也会更新，所以是每运行多少次这个函数scheduler.step()，更新以下学习率。

torch.cat
两个tensor是A和B，想把他们拼接在一起


C = torch.cat( (A,B), dim= 0 )  #按维数0拼接（竖着拼）
C = torch.cat( (A,B), dim= 1 )  #按维数1拼接（横着拼）




torch.squeeze / torch.unsqueeze
维度进行压缩 / 扩充
就是把原来的tensor中的多余的维度去掉或者增加一个维度。

A = torch.ones([1, 2, 3, 4])
print(A.shape())
#输出（1，2，3，4）
B = A.squeeze( dim = 0 )  #将0序号位置的维度压缩，即去掉该位置的维度，如果是2则，去掉位置2的维度（前提是位置2上本来维度是1，否则不会有变化）
print(B.shape())
#输出（2，3，4）
C = A.squeeze( dim = 0 )  #将0序号位置的维度扩充，即在该位置的增加一个维度
print(C.shape())
#输出（1, 1, 2，3，4）

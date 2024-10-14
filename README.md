# GEC6818自助点餐系统
该系统具备登录、注册、广告展示、菜品选择、订单的显示和导出为文本文档等功能模块。

## 一、系统操作流程

当用户进入欢迎界面后，用户自己判断是否拥有账户，有则点击登录，没有则注册，在登录界面根据提示输入正确的信息后，系统会进行自动检测，若信息正确，用户便进入系统后，即可对其进行相关操作，否则无法登录，如图1.1所示。


![Untitled](https://github.com/user-attachments/assets/76220e21-7232-4cbb-ab4c-bb0a7bd599e9)

图1.1 系统流程图


## 二、关键代码描述

### 2.1 登录功能

设置初始账户为1234，密码为1234，并判断输入账户密码是否正确，如图2.1所示。

![登录功能](https://github.com/user-attachments/assets/9a2ab014-76fd-4def-b183-92e7fd0f2d09)
图2.1 登录功能

### 2.2 广告功能

使用线程循环播放广告，如图所示。

![广告功能](https://github.com/user-attachments/assets/d4dda0e9-3b62-4b42-ae97-f5d9fbc69da6)
图2.2 广告功能

### 2.3 点餐功能

使用if条件语句判断菜品数量加减，如图所示。

![点餐功能](https://github.com/user-attachments/assets/709db0af-dab5-4a52-980b-bdb52b77a770)
图2.3 点餐功能

### 2.4 菜品详情视频播放功能

使用视频播放器mplayer播放视频，如图所示。

![视频部分功能](https://github.com/user-attachments/assets/3a769e48-dd97-4f16-b8c0-78bfbed301f8)
图2.4 视频功能

## 三、系统登录功能测试

### 3.1 在登录界面（如图3.1），输入原始的用户名和密码时，单击登录跳转至主界面（如图3.2）；也可点击返回键，跳转至欢迎界面（如图3.3）。


<img width="517" alt="登录界面" src="https://github.com/user-attachments/assets/a19451dd-3370-45b6-9e6e-e1893011e1b7">

图3.1 登录界面


<img width="519" alt="主界面" src="https://github.com/user-attachments/assets/0c823bb7-69be-4fb5-9cef-495e9c424f6b">

图3.2 主界面


<img width="400" alt="欢迎界面" src="https://github.com/user-attachments/assets/9ab369d4-6a8a-424e-9fe1-a96a33ca2951">

图3.3 欢迎界面

### 3.2 验证用户能够成功登录自助点餐系统，并确保系统正常返回。测试方法如表3.1所示。

表3.1  登录测试方法
| 测试 | 步骤 | 结果 |
| --- | --- | --- |
| 正常登录测试 | （1）打开自助点餐系统的登录页面。（2）在用户名输入框中输入正确的用户名。（3）在密码输入框中输入正确的密码。（4）点击“登录”按钮。 | 用户成功登录系统，并跳转到主页 |
| 错误登录测试 | （1）打开自助点餐系统的登录页面。（2）在用户名输入框中输入错误的用户名。（3）在密码输入框中输入正确的密码。（4）点击“登录”按钮。 | 无法登录 |
| 空白登录测试 | （1）打开自助点餐系统的登录页面。（2）不输入用户名和密码。（3）点击“登录”按钮。 | 无法登录 |
| 返回测试 | 点击登录界面返回键 | 正常返回至欢迎界面 |

### 3.3 菜品选择功能测试

在主界面，进行菜品选择。可对菜品进行分类选择（主菜、面点、烧烤、甜点等），甜点如图3.4所示；当对菜品进行增加或减少操作时，下方订单栏（如图3.5）将显示选择的菜品信息（菜品数量、价格等）。左侧广告栏会循环播放商家投放的菜品，增加用户曝光和点击率。当点击菜品图片可弹出菜品宣传片视频（如图3.6），可中途退出。

<img width="400" alt="甜点界面" src="https://github.com/user-attachments/assets/c02471f7-835d-4a6b-bd18-587d8fb44432">

图3.4  甜点界面


![订单栏界面](https://github.com/user-attachments/assets/306ed40c-5a54-4c0b-90d4-25341afffd0c)
图3.5  订单栏界面

![视频](https://github.com/user-attachments/assets/2f306bb0-1313-47db-b70e-33f89e9dd5a1)
图3.6  视频

验证用户能够在自助点餐系统中顺利浏览和选择菜品，确保系统的菜品展示和选择功能正常运作。测试方法如图3.2所示。

表3.2  菜品测试方法
| 测试 | 步骤 | 结果 |
| --- | --- | --- |
| 菜品展示测试 | （1）用户登录到自助点餐系统。（2）浏览系统主页上的菜品分类和展示。 | 所有菜品分类清晰 |
| 菜品选择测试 | （1）用户从展示的菜品中选择心仪的菜品。（2）将选择的菜品添加到订单中。 | 用户能够顺利选择菜品，并成功添加到订单，订单内的菜品和数量显示准确。 |
| 菜品数量调整测试 | （1）用户在订单中查看已选择的菜品。（2）尝试调整菜品数量（增加或减少）。 | 系统能够准确调整菜品数量，并实时更新订单车内的总数量和总价。 |

### 3.4付款功能测试

在主界面点击付款时，后台打印小票，并跳转至付款界面（如图3.7）。若账户余额充足直接扣款（如图3.8），否则账户余额不足则弹出充值提醒（如图3.9）。


![64741DAEFFD70130A0181C415498470F](https://github.com/user-attachments/assets/e6f03c05-9b5b-414f-9f16-b18e543181c0)


图3.7  付款


![扣款](https://github.com/user-attachments/assets/2b8ca603-4984-4810-99b9-e26f0ca3cc5c)

图3.8  扣款


![余额不足](https://github.com/user-attachments/assets/8690c21c-2136-4388-8f77-120f17af55af)

图3.9  余额不足
